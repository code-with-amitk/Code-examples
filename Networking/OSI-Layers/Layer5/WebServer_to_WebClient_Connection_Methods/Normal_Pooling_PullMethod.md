## Normal Pooling/Pull Method/Ajax Pooling
- Web client repeatedly pools web server for data. Implemented using XMLHttpRequest or JSON
- **Flow**
  - *a.* Client-server completes 3-way-handshake. Connection established.
  - *b.* Client asks data from server(page1). Data is not available at the moment. Connection is closed.
  - *c.* Again client establishes connection (connect()) and asks for data.
- **Diadv:** 
  - When resource is not found, server sends a empty message(which actually is of no use). This wastes N/W BW and resources.
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
