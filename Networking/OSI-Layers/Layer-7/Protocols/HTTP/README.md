**HTTP (Hyper Text Transfer Protocol)**
- [Features](#fea)
- [Design Issues](/Networking/OSI-Layers/README.md)
- [HTTPv1 vs HTTPv2 vs HTTPv3](#vs)
- [Advatanges, Disadvatanges of HTTP](#adv)
- [Message Format](#format)
- [Caching](#cache)
- [Headers](#hea)
- [Methods](#mea)
  - [GET example](#get)
  - [POST example](#pe)
- **HTTP Terms**
  - [Cookie](#cok)
  - [PAC File](#pac)
- [Plugin, Helper Application, MIME](#mime)


## HTTP
Client-server/Request-Response protocol. Default port 80, other can be used. Uses TCP, does not use UDP. [Google's QUIC](/Networking/OSI-Layers/Layer-4/Protocols) uses HTTP over UDP
- HTTP Clients: Web-browser, Any process can create socket and get information from server.

<a name=fea></a>
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
### Message Format
> [Method](#mea), [Request-Header](#hea), Request-URI: Web page or resource
```html
  METHOD space REQUEST_HEADER space REQUEST_URI space HTTP_VERSION crlf

Examples:
  GET Accept www.test.com/index.html HTTP/1.1
  PUT Cookie www.test.com/abc.html HTTP/1.1
```

### Features

<a name=cache></a>
### HTTP Caching
- *Why?* User(s) often request same Web page that they have used before and page contents(eg: images, CSS, scripts) donot change so often. Its network BW consumption and time wastage to fetch these resources again when browser has a copy.
- *What?* Caching less frequently changing pages need to be cached.

- **Cache Design** Conditional GET is sent with [Request Header (if Modified)](#hea)
```http

<-------------------Web Browser------->
  User    front-end   Cache(Hard-Disk)                
   - page1 ->
            --- Find page-1 ->
                       Cache Valid?
            <-- Page-1 ------
                       Else                                          WEB-SERVER
                          -------------- Conditional GET ----------> (Program)  //Cache asks is my copy valid(using REQUEST HEADER)?
                          <-----------  Page Not Modified   -------- 
                          <---- Modified Page(Expires Header=1 day)-      //Expires header tells Http when to fetch the page again.
```

<a name=hea></a>
### Headers
- **Request Header?** The request line (e.g., the line with the GET method) may be followed by additional lines with more information.
- **Reponse Header?** Responses may also have response headers.
- **Headers**
```c
User-Agent:    Request Information about the browser and its platform
Accept:     Request The type of pages the client can handle
Accept-Charset:    Request The character sets that are acceptable to the client
Accept-Encoding:    Request The page encodings the client can handle
Accept-Language:    Request The natural languages the client can handle
If-Modified-Since:    Request Time and date to check freshness
If-None-Match:    Request Previously sent tags to check freshness
Host: Request   The server’s DNS name
Authorization:    Request A list of the client’s credentials
Referer Request:   The previous URL from which the request came
Cookie:  Request Previously set cookie sent back to the server
Set-Cookie:    Response Cookie for the client to store
Server:    Response Information about the server
Content-Encoding:    Response How the content is encoded (e.g., gzip)
Content-Language:    Response The natural language used in the page
Content-Length:    Response The page’s length in bytes
Content-Type:    Response The page’s MIME type
Content-Range:     Response Identifies a portion of the page’s content
Last-Modified:     Response Time and date the page was last changed
Expires Response:    Time and date when the page stops being valid
Location Response:     Tells the client where to send its request
Accept-Ranges:     Response Indicates the server will accept byte range requests
Date:    Both Date and time the message was sent
Range:     Both Identifies a portion of a page
Cache-Control:     Both Directives for how to treat caches
ETag:    Both Tag for the contents of the page
Upgrade:     Both The protocol the sender wants to switch to
```

<a name=mea></a>
### HTTP Supported Methods
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
#### GET example
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
#### POST message example
To Send data to server. Used when forms are submitted.
```c
  Client                                              Server
  	---- POST data ----->
```

### HTTP Terms
<a name=cok></a>
#### HTTP Cookie / Web cookie / Internet cookie / browser cookie
This is a file _created by Web browser_ & placed on the user's computer.
- **why?** 
  - Web Server asks web browser to store some information locally so that when Web Browser again queries web server, Web server can identify:
    - Whether it's same web browser or different.
    - Whether it's same information asked by web browser or different.
  - To track the user's browsing activity(clicking particular buttons, recording which pages were visited in the past). 
  - Saving info user entered in forms: names, addresses, passwords(stored as hashed), and payment card numbers.
```c
  Web Browser                                   Web server
         -- GET /sample_page.html HTTP/2.0 ->
            Host: www.example.org
	    
         <------- HTTP/2.0 200 OK---------------
                 Content-Type: text/html
                 Set-Cookie: yummy_cookie=choco       //Store cookie
                 Set-Cookie: tasty_cookie=strawberry
                 [page content]
		 
 store information
 in Cookie file
```
- **Where Cookie is stored on my Computer?**
  - _Path:_ "C:\Users\user_name\AppData\Local\Google\Chrome\User Data\Default\Network\Cookie(SQL Lite DB)"
  - _In Browser:_ Right-click on your browser window > Inspect > Applications tab > Cookies > Check installed cookies
```c
creation_utc      top_frame_site_key  host_key      name  encrypted_value  path    expires_utc     secure httponly  last_access_utc  expires persistent  priority
13268758066855308		    .microsoft.com  MC1    129109aksknz1   /    13300294067855308   1	    0      13292307116001488  1        1          0
```
- **Stolen Cookie?** If hacker steals and installs your cookies into their web browser, hacker will get access your account.
  - _How cookie theaft can be avoided?_ Cleaning cookies every 7-14 days.

<a name=pac></a>
#### PAC(proxy auto-configuration) File
- This is a Javascript file that instructs a browser to forward traffic to a particular [proxy server](/System-Design/Concepts/Proxy_Servers), instead of directly to the destination server. All browsers support PAC File.
- This configures [Explicit Proxy](/System-Design/Concepts/Proxy_Servers/#exp) in browser.
- **Limitations of PAC**
  - Can only send web traffic, not other(eg: video, audio).
  - Admin user can change proxy address(to which requests need to go) in PAC. Also admin can completely disable it.
```c
//Example of PAC File
function FindProxyForURL(url, host) {

// If the hostname matches, send direct.
	if (dnsDomainIs(host, "intranet.domain.com"))
		return "DIRECT";

// If the protocol or URL matches, send direct.
	if (url.substring(0, 4)=="ftp:")
		return "DIRECT";

// If the requested website is hosted within the internal network, send direct.
	if (isPlainHostName(host) ||
		isInNet(dnsResolve(host), "10.0.0.0", "255.0.0.0") ||
		isInNet(dnsResolve(host), "172.16.0.0",  "255.240.0.0") ||
		isInNet(dnsResolve(host), "192.168.0.0",  "255.255.0.0") ||
		isInNet(dnsResolve(host), "127.0.0.0", "255.255.255.0"))
		return "DIRECT";

// If the IP address of the local machine is within a defined
// subnet, send to a specific proxy.
	if (isInNet(myIpAddress(), "10.10.5.0", "255.255.255.0"))
		return "PROXY 1.2.3.4:8080";

// DEFAULT RULE: All other traffic, use below proxies, in fail-over order.
	return "PROXY 4.5.6.7:8080; PROXY 7.8.9.10:8080";

}
```


<a name=mime></a>
### Plugin, Helper Application, MIME
**How Browser Display Information?** Using MIME Type
- When a server returns a page, it also returns some additional information(MIME type) about the page. MIME type tells how browser should display the page.
- A page may consist of a video(MPEG format), a document(PDF format), a photograph(JPEG format) or any one of hundreds of other file types.
  - *1.* Pages of type text/html are just displayed directly, as are pages in a few other built-in types. 
  - *2.* For MIME type=pdf/flash/mpeg/jpg browser uses plugins or helper applications to display the content.
- **Plug-in?** is a third-party module that is installed as an extension to the browser which helps to display/process the contents. Eg: PDF reader. Browsers usually come preloaded with popular plug-ins.
- **Helper application?** This is large program, running as a separate process. Eg: Microsoft Word or PowerPoint. If URL points to a PowerPoint file, and when the user clicks on it, PowerPoint is automatically started and handed the content to be displayed. Browsers can be configured to handle a virtually unlimited number of document types with no changes to themselves.
