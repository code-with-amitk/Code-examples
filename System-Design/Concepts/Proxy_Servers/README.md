**Proxy**
- Types
  - [1. Forward/Web/Server Proxy](#fow)
    - [Why needed](#whyf)
  - [2. Reverse Proxy](#rev)
    - [Why needed](#whyr)


## Types of Proxy

<a name=fow></a>
### 1. Forward/Web/Server Proxy
Node sitting in front of client machines. When user computer make requests to sites/services on Internet, the proxy server intercepts those requests and then communicates with web servers on behalf of clients.
```c
    User-Computer-1 ------>
    User-Computer-2 ------>  Forward-Proxy            internet            Destination-server(www.test.com)
    User-Computer-3 ------>
```  
<a name=whyf></a>
#### Why Forward Proxy needed
- *a.* User Restrictions: Some schools/companies use firewalls to give limited access to Internet(eg: blocked for some sites). 
- *b.* To protect their identity online: In some cases, users want increased anonymity online.

<a name=rev></a>
### 2. Reverse Proxy 
Node sitting in front of 1 or more web servers. User requests will reach Reverse proxy. RP will query WS and send response to users.
```c
    User-Computer-1 --->                                                                        Origin/Web-Server-1
                                                     internet                Reverse-Proxy      Origin/Web-Server-2
    User-Computer-2 --->                                                                        Origin/Web-Server-3
```
<a name=whyr></a>
#### Why reverse Proxy needed?**
- *a. Load Balancing:* A website receiving millions of connections need to distribute load among different backend servers, reverse proxy can provide a load balancing solution
- *b. Attack Protection:* Origin server's IP addresses are not exposed to attackers, making it difficult to intrude. Eg: DDOS attacks
- *c. Caching:* RP can cache data, resulting in faster performance.
- *d. SSL Encryption:* encryption/decryption is expensive at origin server. RP can be configured to decrypt all incoming and encrypt all outgoing responses, freeing up valuable resources on the origin server.
