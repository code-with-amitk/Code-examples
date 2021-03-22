## CDN(Content delivery network)
- **What?**
  - This is Web hosting service, It hosts web pages across multiple servers on multiple sites near to client machines. Hosted documents are replicated across servers.
  - CDN is [Overlay Network](/Networking/OSI-Layers/Layer5/P2P_OverlayNetwork) 
- **What CDN stores?** 
  - Each Web document(main HTML file) consists of several other embedded documents(Eg: images, video and audio etc) which donot change often. These should be cached.
  - These embedded documents are accessed using [URLs](/Networking/OSI-Layers/Layer5/Protocols/README.md)
- **Virtual Ghost**
  - The URLs of above mentioned resources(embedded documents) does not point to actual resource/origin server. But it points to CDN servers. These CDN servers are called Virtual ghosts.
- **Example**
  - [CDN serving Webpage to Browser](Examples)

