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
    BROWSER							SERVER(www.freebsd.org)
         ------ GET www.test.com/index.html HTTP/1.1------------->
GET / HTTP/1.1
Host: www.freebsd.org
User-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.7.7) Gecko/20050414 Firefox/1.0.3
Accept: text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5
Accept-Language: en-us,en;q=0.5
Accept-Encoding: gzip,deflate
Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7
Keep-Alive: 300
Connection: keep-alive
If-Modified-Since: Mon, 09 May 2005 21:01:30 GMT
If-None-Match: "26f731-8287-427fcfaa"

         <----- HTTP/1.1 200 OK ----------------------------------
								HTTP/1.1 200 OK
								Date: Fri, 13 May 2005 05:51:12 GMT
								Server: Apache/1.3.x LaHonda (Unix)
								Last-Modified: Fri, 13 May 2005 05:25:02 GMT
								ETag: "26f725-8286-42843a2e"
								Accept-Ranges: bytes
								Content-Length: 33414
								Keep-Alive: timeout=15, max=100
								Connection: Keep-Alive
								Content-Type: text/html
	<----- Text HTML ------------------------------------------
		<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
    		"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
		<html>
			<!-- Rest of the HTML Page Here -->
		</html>

    if page has URL's, Videos
    fetches using same process
         ----------------    TCP-FIN    ---------------------------->
```

<a name=pe></a>
#### POST message
To Send data to server. Used when forms are submitted.
```c
  Client                                              Server
  	---- POST data ----->
```
