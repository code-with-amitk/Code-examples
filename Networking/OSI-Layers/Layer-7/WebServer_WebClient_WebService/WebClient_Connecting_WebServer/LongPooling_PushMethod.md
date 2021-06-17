## Long Pooling/Push Method/Hanging GET
- Server holds client’s connection open for as long as possible. Data is delivered to web client once becomes available or threshold timer expired.
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
