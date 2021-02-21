## HTTP (Hyper Text Transfer Protocol)
- Layer-5 working on client-server/Request-Response model. Default port 80, other can be used. Uses TCP, can also use UDP.
- HTTP Clients: Web-browser, Any process can create socket and get information from server.

### Features
- **1. CONNECTIONLESS:** HTTP-client(browser) initiates an HTTP request and after a request is made, the client disconnects from the server and waits for a response. server processes the request and re-establishes the connection with the client to send a response back.
- **2. MEDIA INDEPENDENT:** Any type of data can be sent by HTTP as long as both the client and the server know how to handle the data content.
- **3. STATELESS:** No session information is stored either by client or server.
- **4. Persistant & Parallel Connection:**  2 access requests can be sent back-2-back without waiting for response to arrive.
```bash
  Client                         Server
     <-----TCP-3-way-handshake---->
     --------GET Page-1----------->
     --------GET Page-2----------->
     <-------Page-1---------------
     <-------Page-2---------------
```

### Supported Methods
- **Method?** Operations are called methods for requesting web page or content.

|Method|Description|Example|
|---|---|---|
|GET| Server sends a Web page/object|GET `www.test.com/index.html` HTTP/1.1|
|HEAD| Read a Web page’s header(not page). For checking validity of URL||
|POST| Upload data to server. Used when forms are submitted.|POST `www.test.com/form.html` HTTP/1.1 |
|PUT| Update existing Web page on server.||
|DELETE| Remove the Web page||
|TRACE| For debugging. Instructs the server to send back the message. Useful when requests are not processed correctly and the client wants to know what request the server actually got||
|CONNECT| Connect to server using proxy or web cache||
|OPTIONS| Query options(What methods,headers can be used for the page) from server||
|PATCH|Make partial update on resource. As compared to `PUT method` PUT should only be used if you’re replacing a resource in its entirety and PATCH for partial update.|
||HEAD| it requests the headers that are returned if the specified resource would be requested with an HTTP GET method. Usage of this method is to decide to download a large resource(or not) to save bandwidth|
