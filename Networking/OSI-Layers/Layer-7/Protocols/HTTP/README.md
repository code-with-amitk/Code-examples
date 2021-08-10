**HTTP (Hyper Text Transfer Protocol)**
- [Design Issues](/Networking/OSI-Layers/README.md)
- [HTTPv1 vs HTTPv2 vs HTTPv3](#vs)
- [Advatanges, Disadvatanges of HTTP](#adv)
- [HTTP Message Format](#format)


## HTTP
Client-server/Request-Response protocol. Default port 80, other can be used. Uses TCP, can also use UDP.
- HTTP Clients: Web-browser, Any process can create socket and get information from server.

<a name=vs></a>
### HTTPv1 vs HTTPv2 vs HTTPv3
||Http-1.1|Http-2|Http-3|
|---|---|---|---|
|Year|1997|2015|2019|
|Transport Protocol|TCP|TCP|UDP|
|Connections|HTTP client(Browser) makes different connection for every request with server|Sends multiple requests on 1 connection only|Sends packets over UDP|
|Bandwidth consumption|More|Less. Less headers are sent|Even less|

- **Problems in HTTP-2**
  - *1. Sending Multiple requests in 1 packet:* if you send req-1(page1), req-2(page2), req-3(page3) in 1 packet and that packet is lost. None of page can be loaded, Everything comes to halt. We need to send whole packet again. This is called HEAD OF LINE BLOCKING.
    - *Solution:* HTTP-3 using UDP. Every packet on different UDP.

<a name=adv></a>
### Advatanges, Disadvatanges/pitfalls of HTTP
- **Advantages of HTTP**
  - *1. Flexible.* Whenever there are additional capabilities needed by an application, HTTP has the capability to extend. These can include Flash players and Acrobat reader.
  - *2. Less connections.* With HTTP2 and HTTP3 multiple requests can be sent in 1 packet.
  - *3. Network BW:* Less dues to less connections as HTTP2, HTTP3 sends multiple requests in 1 connection.
  - *4. Error reporting:* Reports errors without closing the TCP connection.
- **Disadvantages of HTTP**
  - *1.* Can only be used for point to point connection.
  - *2.* Does not have push capabilities as in [Long Pooling or server sent Events](/Networking/OSI-Layers/Layer5/WebServer_to_WebClient_Connection_Methods).
  - *3.* HTTPv2 does not offer reliable exchange (without retry logic).

<a name=format></a>
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
