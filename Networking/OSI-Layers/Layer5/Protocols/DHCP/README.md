## Dynamic Host Configuration Protocol
- **Why?** 
  - Configuring IP addresses on machines in LAN without physically visiting them. DHCP server will do this. 
  - Make TCP/IP Settings->Automatic. Without DHCP,  Admin need to go to each PC and configure the IP. 
  - This manual configuration is  good in small environment, But in Big Environment this will not work because it can take lot of time, Errors may occur.
- **How it works?** 
  - Works on Client-Server Model. Client listens on Port: 68. Server communicates on port:67. Uses DORA (Discover, Offer, Request, Acknowledgement)
