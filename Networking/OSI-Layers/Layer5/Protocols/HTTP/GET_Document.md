## HTTP
-  Layer-5 protocol works on client-server model. Default port 80, other can be used. Uses TCP, can also use UDP.

## GET Http document
```html
    BROWSER
    www.cs.washington.edu        ---DNS Query-->    DNS
                     <--A record(a.b.c.d)---
                     
         ---------------- TCP 3-Way handshake port 80 -----------> SERVER(a.b.c.d)
         ------GET www.test.com/index.html HTTP/1.1------------->
         <-----HTTP/1.1 200 OK ContentType:txt/html ContentLen:988 [........988 bytes txt]--
    if page has URL's, Videos
    fetches using same process
         ----------------    TCP-FIN    ---------------------------->
```
