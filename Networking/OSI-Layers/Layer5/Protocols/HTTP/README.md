## HTTP (Hyper Text Transfer Protocol)
- Layer-5 working on client-server/Request-Response model. Default port 80, other can be used. Uses TCP, can also use UDP.
- HTTP Clients: Web-browser, Any process can create socket and get information from server.
- [Design Issues](/Networking/OSI-Layers/README.md)
- [HTTP Versions](HTTPv1_v2_v3.md)
- [Advatanges, Disadvatanges/pitfalls of HTTP](Advantages_Disadv_of_HTTP.md)

### Format
> [Method](./HTTP_Methods.md), [Request-Header](./Request_Response_Header.md), Request-URI: Web page or resource
```html
  METHOD space REQUEST_HEADER space REQUEST_URI space HTTP_VERSION crlf

Examples:
  GET Accept www.test.com/index.html HTTP/1.1
  PUT Cookie www.test.com/abc.html HTTP/1.1
```

### Features
- **1. CONNECTIONLESS:** HTTP-client(browser) initiates an HTTP request and after a request is made, the client disconnects from the server and waits for a response. server processes the request and re-establishes the connection with the client to send a response back.
- **2. MEDIA INDEPENDENT:** Any type of data can be sent by HTTP as long as both the client and the server know how to handle the data content.
- **3. STATELESS:** No session information is stored either by client or server.
- **4. Persistant & Parallel Connection:**  2 access requests can be sent back-2-back without waiting for response to arrive.
```html
  Client                         Server
     <-----TCP-3-way-handshake---->
     --------GET Page-1----------->
     --------GET Page-2----------->
     <-------Page-1---------------
     <-------Page-2---------------
```
