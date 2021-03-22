## CDN serving web page to Browser
  - *1.* Client requests web page from origin server/web server.
  - *2.* Origin server responds with Page and references to embedded documents(ie hostnames of servers having ref docs)
  - *3.* Browser finds IP of Authoritative DNS servers using regular [DNS lookup](/Networking/OSI-Layers/Layer5/Protocols/DNS/Name_Resolution).
  - *4.* Browser sends DNS Query to CDN-DNS-Server, which responds with IP address of nearst,best matching DNS server to client.
  - *5.* Browser sends [HTTP GET](/Networking/OSI-Layers/Layer5/Protocols/HTTP) for reference document
  - *6.* CDN Server checks if he has reference documents sends the docs, if not asks web server, caches the docs and then sends to client.
  ```html
    [Client/Web-Browser]                          [Origin-Server]
        ------------1. GET youtube.com HTTP/1.1-------->   
        <-2. HTTP Body(With refs to embedded documents)-
              embedded docs are available at hostname=a.com
             
  Find IP of a.com
        -----3. Regular DNS Query---> [Name-server]
        <-Authoritative_DNS server x.y.z.a----              //DNS Redirection
        
          ----4. DNS Query hostname=a.com--->  [CDN-DNS-Server]
          <--Nearst,Best Matching CDN-Server-8(x.y.z.p)----
                
        ----------------------5. GET embedded docs HTTP/1.1---------> [CDN-Server-8](Close to Client)
                                                                        if (I have docs)
                                           [Web Server] <---GET embedded docs--- No  
                                                        -------docs----------->Cached
                                                                        else
         <----------------Embedded docs------------------------------------                                                           
  ```
