## Versions

||Http-1.1|Http-2|Http-3|
|---|---|---|---|
|Year|1997|2015|2019|
|Transport Protocol|TCP|TCP|UDP|
|Connections|HTTP client(Browser) makes different connection for every request with server|Sends multiple requests on 1 connection only|Sends packets over UDP|
|Bandwidth consumption|More|Less. Less headers are sent|Even less|

### Problems in HTTP-2
- **1. Sending Multiple requests in 1 packet:** if you send req-1(page1), req-2(page2), req-3(page3) in 1 packet and that packet is lost. None of page can be loaded, Everything comes to halt. We need to send whole packet again. This is called HEAD OF LINE BLOCKING.
  - *Solution:* HTTP-3 using UDP. Every packet on different UDP.

