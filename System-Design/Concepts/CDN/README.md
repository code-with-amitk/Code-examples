## CDN(Content delivery network)
- **What?** This is Web hosting service, It hosts web pages across multiple servers on multiple sites near to client machines. Hosted documents are replicated across servers. 
- **What actually CDN stores?** 
  - Each Web document(main HTML file) consists of several other embedded documents(Eg: images, video and audio etc) which donot change often. These should be cached.
  - These embedded documents are accessed using [URLs](/Networking/OSI-Layers/Layer5/Protocols/README.md)
- **Virtual Ghost**
  - The URLs of above mentioned resources(embedded documents) does not point to actual resource/origin server. But it points to CDN servers. These CDN servers are called Virtual ghosts.
  
  ### Example
  ```c
    [Client/Web-Browser]                          [Origin-Server]
        ------------GET youtube.com HTTP/1.1-------->
        <-HTTP Body(With refs to embedded documents)-
              embedded docs are available at hostname=a.com
  Find IP of a.com
        -----Regular DNS lookup---> [Name-server]
        <--------x.y.z.a--------
        
          ----GET embedded docs ---x.y.z.a--->  [CDN-DNS-Server]
          <--Nearst,Best Matching CDN-Server-8-------
                
        --------------------------------------GET embedded docs---------> [CDN-Server-8](Close to Client)
                                                                        if (I have docs)
                                           [Web Server] <---GET embedded docs--- No  
                                                        -------docs----------->Cached
                                                                        else
         <----------------Embedded docs------------------------------------                                                           
  ```
