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
### 2. Long Pooling / Half Duplex
- Client sends an HTTP request. The server holds the request open until new data is available, sends a response, and closes it. The client immediately opens a new request.
- Half-duplex/simulated: Client must always initiate the request cycle repeatedly.
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
- WebSocket: An application-layer protocol that runs on top of TCP. It starts as a standard HTTP request with an upgrade header. Once the server accepts via a handshake, the connection switches ("upgrades") to the WebSocket protocol, reusing that exact same TCP socket for framed, bidirectional message passing.
- Client performs an HTTP handshake, then the TCP connection stays open permanently for continuous two-way data flow.
- Full-duplex: Either client or server can push data asynchronously at any time.
- Network overhead: Low. Headers are tiny after the initial handshake, sending only compact data frames.
- Latency: Near-zero/Real-time (instantaneous push/receive).
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
### 4. Server Sent Events / unidirectional (one-way, server-to-client only).
- Data format: Text only (usually formatted as JSON)
- Limited by HTTP/1.1 limits (max 6 per browser/domain), though HTTP/2 removes this limit.

<a name=ws></a>
## Web Service
Web service is process/service running inside web server(hosted over cloud) reachable at port on web server, that provides any information needed. Eg: Whether report.
```c
    Web Client                                  {Web Service} On US Server
  rest-api call() ----Give me Temp of NY------>    |
                 <-NY temp (JSON or XML format)--- |        
//Now-a-days RESTful API are used. Before REST everyone was using SOAP.
```
