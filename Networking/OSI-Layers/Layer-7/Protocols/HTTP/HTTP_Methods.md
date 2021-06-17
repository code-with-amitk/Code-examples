## Supported Methods
- **Method?** Operations are called methods for requesting web page or content.
- **Safe methods?** Those which donot change state of server. Eg: GET, HEAD
- **Read only methods?** GET, OPTIONS, HEAD
- **Idempotent methods?** A operation that will produce the same results if executed once or multiple times. Eg: GET, HEAD, PUT, DELETE, TRACE, OPTIONS

|Method|Description|Example|
|---|---|---|
|GET| Server sends a Web page/object|GET `www.test.com/index.html` HTTP/1.1|
|HEAD| Read a Web page’s header(not page). For checking validity of URL|
|POST| Upload data to server. Used when forms are submitted.|POST `www.test.com/form.html` HTTP/1.1 |
|PUT| Update existing Web page on server.|
|DELETE| Remove the Web page|
|TRACE| For debugging. Instructs the server to send back the message. Useful when requests are not processed correctly and the client wants to know what request the server actually got|
|CONNECT| Connect to server using proxy or web cache|
|OPTIONS| Query options(What methods,headers can be used for the page) from server|
|PATCH|Make partial update on resource. As compared to `PUT method` PUT should only be used if you’re replacing a resource in its entirety and PATCH for partial update.|
|HEAD| it requests the headers that are returned if the specified resource would be requested with an HTTP GET method. Usage of this method is to decide to download a large resource(or not) to save bandwidth|
