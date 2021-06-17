## Headers
- **Request Header?** The request line (e.g., the line with the GET method) may be followed by additional lines with more information.
- **Reponse Header?** Responses may also have response headers
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
