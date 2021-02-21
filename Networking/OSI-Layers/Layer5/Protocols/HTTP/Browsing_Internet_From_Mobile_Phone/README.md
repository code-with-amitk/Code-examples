## Browsing internet from Mobile phone

### Issues in Browsing internet from mobile phone wrt Desktop
- *1.* Small screens to display large pages and large images.
- *2.* Limited input capabilities on mobile. Hard to enter URL.
- *3.* Network bandwidth is limited over wireless links. Downloads are expensive.
- *4.* Connectivity may be intermittent.
- *5.* CPU power is low wrt desktop.
- *6.* Low battery life, heat dissipation

### Solutions
- **1. Web server to maintain 2 version of page(1 for desktop and other for mobile**
  - *a.* Web servers detects whether User is on Desktop or mobile Phone using [Request-Header(User Agent)](/Networking/OSI-Layers/Layer5/Protocols/HTTP/Request_Response_Header.md)
  - *b.* Web Server maintains 2 versions of page (1 for desktop and other for mobile) & return respective page.
  - Mobile web page will have small images, less text, and simpler navigation.
- **2. Using XHTML Basic**
  - XHTML basic is subset of XHTML and designed to be used on mobile phones, televisions, PDAs, vending machines, pagers, cars, game machines, and even watches.
- **3. Content transformation/Transcoding** 
  - Device sitting in between mobile and web server(Eg: ISP) will transforms web contents for mobile phone. Eg: Reduce the size of large images etc.
- **4. Header compression technologies**
  - such as ROHC (RObust Header Compression) used on low BW network.
