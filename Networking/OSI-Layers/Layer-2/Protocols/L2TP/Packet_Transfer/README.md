## Packet Transfer
- L2TP tunnel is established between the **LAC(L2TP Access Concentrator)** and the **LNS(L2TP Network Server (LNS)**.
- An IPSec tunnel is also established between these devices and all L2TP tunnel traffic is encrypted using IPSec.
- **Steps?**
  - The dial up user initiates a PPP session with the LAC over the analog telephone system.
  - After the user is authenticated, the LAC initiates an L2TP tunnel to the LNS.
  - The tunnel end points, LAC and LNS, authenticate each other before the tunnel is created.
  - Once the tunnel is established, an L2TP session is created for the dialup user. Encryption is done using IPSec.
<img src=L2TP.jpg width=900 />
