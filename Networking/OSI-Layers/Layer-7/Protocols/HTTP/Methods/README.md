**Methods**
- [GET](#get)
- [POST](#pe)


### HTTP Methods
- **Method?** Operations are called methods for requesting web page or content.
- **Safe methods?** Those which donot change state of server. Eg: GET, HEAD
- **Read only methods?** GET, OPTIONS, HEAD
- **Idempotent methods?** A operation that will produce the same results if executed once or multiple times. Eg: GET, HEAD, PUT, DELETE, TRACE, OPTIONS
- **CRUD Operations:** Protocol should support minimum these operations/methods.
```c
  Create = POST
  Read = GET
  Update = PUT
  Delete = DELETE
```
|Method|Description|Example|
|---|---|---|
|GET| Reading data(page,object etc) from web server|GET `www.test.com/index.html` HTTP/1.1|
|HEAD| Read a Web page’s header(not page). For checking validity of URL|
|POST| Send data to server, Server will create entry. Eg: Form submittion.|POST `www.test.com/form.html` HTTP/1.1 |
|PUT| Update existing data on web server.|
|DELETE| Remove data from web server|
|TRACE| For debugging. Instructs the server to send back the message. Useful when requests are not processed correctly and the client wants to know what request the server actually got|
|CONNECT| Connect to server using proxy or web cache|
|OPTIONS| Query options(What methods,headers can be used for the page) from server|
|PATCH|Make partial update on resource. As compared to `PUT method` PUT should only be used if you’re replacing a resource in its entirety and PATCH for partial update.|
|HEAD| it requests the headers that are returned if the specified resource would be requested with an HTTP GET method. Usage of this method is to decide to download a large resource(or not) to save bandwidth|

<a name=get></a>
#### GET
- [_Step-1._ DNS Resolution](/Networking/OSI-Layers/Layer-7/Protocols/DNS/). got IP address.
- [_Step-2._ TCP Connection Estbd SYN,SYNACK,ACK](/Networking/OSI-Layers/Layer-4/Protocols/TCP#estb)
- _Step-3._ Broweser sends this plain text to server
```html
    Client						SERVER(www.freebsd.org)
GET /hello.txt HTTP/1.1 --------------------------------->
User-Agent: curl/7.64.1
Host: www.example.com
Accept-Language: en, mi

         <----- HTTP/1.1 200 OK ----------------------------------
							HTTP/1.1 200 OK
							Date: Mon, 27 Jul 2009 12:28:53 GMT
							Server: Apache
							Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT
							ETag: "34aa387-d-1568eb00"
							Accept-Ranges: bytes
							Content-Length: 51
							Vary: Accept-Encoding
							Content-Type: text/plain
			Hello World! My content includes a trailing CRLF.
         ----------------    TCP-FIN    ---------------------------->
```

<a name=pe></a>
#### POST message
To Send data to server. Used when forms are submitted.
```c
  Client                                              Server
  	---- POST data ----->
```
