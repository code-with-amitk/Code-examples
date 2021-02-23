## Normal Pooling, Long Pooling, Web Sockets

### 1. Normal Pooling
- Web client repeatedly pools web server for data. Implemented using XMLHttpRequest or JSON
- **Diadv:** lot of BW and resource wastage	
```html
  Web-Client                Web-Server
    timer(){
        <----3-Way-Handshake-->
        -----HTTP GET-------->
        <------data----------          
    }
```

### 2. Long Pooling
- server holds client’s connection open for as long as possible. Data is delivered to web client once becomes available or threshold timer expired
- **Disadv:** Server may run out of file descriptor
```html
  Web-Client                Web-Server
        <----3-Way-Handshake-->
          
        -----HTTP GET-------->
        <------data----------          
                              
        -----HTTP GET-------->
        <------data----------          
```

## 3. Web Sockets
- Full duplex bidirectional data transfer. Enhanced version of Http,can work over TCP.
