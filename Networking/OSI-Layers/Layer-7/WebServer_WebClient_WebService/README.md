- **[Comparison](#vs)**
- **Ways Web Client connect to Web Server**
  - [1. Normal Pooling / Pull Method](#m1)
  - [2. Long Pooling/Push Method](#m2)
  - [3. WebSockets](#m3)
  - [4. Server Sent Events](#m4)
  - _5._ Webhooks = HTTP POST. Send data as its available
- **[Web Service](#ws)**
- Web Servers
  - [Nginx Web Server](https://code-with-amitk.github.io/Networking/OSI-Layers/Layer-7/WebServers/Nginx/)
  - [Apache Web Server](https://code-with-amitk.github.io/Networking/OSI-Layers/Layer-7/WebServers/Apache/)

## Methods of Connection
<a name=vs></a>
#### Comparison
```c
      Method      | Keeps Connection open |  Bidirectional(server can initiatiate connection) | Recommended to use
------------------|-----------------------|---------------------------------------------------|-----
1. Normal Pooling |             no        |   no                                              |
2. Long Pooling   |             yes       |   no                                              |
3. Websockets     |             no        |   yes                                             | yes
4. Server Sent    |             yes       |   yes                                             | yes
Events
```

<a name=m1></a>
### 1. Normal Pooling / AJAX Pooling / Pull Method
Web client repeatedly pools web server for data. Implemented using XMLHttpRequest or JSON
- **Flow**
  - *a.* Client-server completes 3-way-handshake. Connection established.
  - *b.* Client asks data from server(page1). Data is not available at the moment. Connection is closed.
  - *c.* Again client establishes connection (connect()) and asks for data.
- **Diadv:** When resource is not found, server sends a empty message(which actually is of no use). This wastes N/W BW and resources.
```html
  Web-Client                Web-Server
    timer(){
        <----3-Way-Handshake-->
        -----HTTP GET(page1)--->
        <----not found(empty)----close()

        <----3-Way-Handshake-->
        -----HTTP GET(page1)--->          
        <------page1----------          
    }
```

<a name=m2></a>
### 2. Long Pooling/Push Method/Hanging GET
Server holds client’s connection open for as long as possible. Data is delivered to web client once becomes available or threshold timer expired.
- **Flow**
  - *a.* Client-server completes 3-way-handshake. Connection established.
  - *b.* Client asks data from server(page1). Data is not available at the moment. Connection is not closed.
  - *c.* Client asks page4 from server. Requests are pushed on queue.
  - *d.* Page1 becomes available, server sends page1 back to client
- **Disadv:**
  - Server may run out of file descriptor.
  - Each long pooling request has a timeout, client need to reconnect again to get the data.
- **Adv:** Latency is reduced.
```html
  Web-Client                Web-Server
        <----3-Way-Handshake-->
                            sockfd open for time-x
        -----HTTP GET(page1)-------->
                              
        -----HTTP GET(page4)-------->
          
        <------Page1------ server sends data as it becomes available
                           
                            timer-x expired
                            close(sockfd)
```

<a name=m3></a>
### 3. Websockets / Web Sockets / Bi-Directional / Full Duplex
- (Web client or Web server) can do TCP Connect() and start sending the data.
- Full duplex bidirectional data transfer. Enhanced version of Http,can work over TCP.
- **Flow**
  - *a.* Client establishes a WebSocket connection through a process known as the WebSocket handshake.
  - *b.* Client asks data from server(page1). server sends page1 back to client and connection is closed.
  - *c.* Client asks page4 from server, which is not available at server. Unlike [Long Pooling]() server does not keep connection open, rather closes it
  - *d.* When Page4 becomes available server does websocket handshake sends data page4 to client and close() connection.
- **How server maintains open connections?** Server will maintain hash-table <key=sockfd, value="Requested Page">
- **Adv:**
  - Server need not to keep open file descriptor as it need to do with [Long Pooling](). Server will not run out of socket descriptors.
  - Unlike [Normal Pooling]() server does not send empty message when resource is not available and hence n/w BW is saved.
```html
  WEB-CLIENT                  WEB-SERVER
        <--WebSocket-Handshake-->           //a
          
        -----HTTP GET(page1)-------->       //b
        <-----page1-----------------close() 
                                            
        -----HTTP GET(page4)-------->       //c
                                  close()
                                 
        <--WebSocket-Handshake-->           //d
        <-----Page4-----------------close()
```

<a name=m4></a>
### 4. Server Sent Events / Bidirectional
This is also bidirectional as [WebSockets](#m3) but unlike wbesockets connection is persistently maintained, ie connection is not closed.


<a name=ws></a>
## Web Service
Web service is process/service running inside web server(hosted over cloud) reachable at port on web server, that provides any information needed. Eg: Whether report.
```c
    Web Client                                  {Web Service} On US Server
  rest-api call() ----Give me Temp of NY------>    |
                 <-NY temp (JSON or XML format)--- |        
//Now-a-days RESTful API are used. Before REST everyone was using SOAP.
```
