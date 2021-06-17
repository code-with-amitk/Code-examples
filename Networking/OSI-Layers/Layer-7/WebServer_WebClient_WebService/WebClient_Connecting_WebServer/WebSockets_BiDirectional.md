## Web Sockets/Bi-Directional/Full Duplex
- Any (Web client or Web server) can do TCP Connect() and start sending the data.
- Full duplex bidirectional data transfer. Enhanced version of Http,can work over TCP.
- **Flow**
  - *a.* Client establishes a WebSocket connection through a process known as the WebSocket handshake.
  - *b.* Client asks data from server(page1). server sends page1 back to client and connection is closed.
  - *c.* Client asks page4 from server, which is not available at server. Unlike [Long Pooling]() server does not keep connection open, rather closes it
  - *d.* When Page4 becomes available server does websocket handshake sends data page4 to client and close() connection.
- **How server maintains open connections?**
  - Server will maintain hash-table <key=sockfd, value="Requested Page">
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
