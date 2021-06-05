## IPSec (over TCP)
- **What?** Set of open standards for ensuring secure private communication over Internet. IPSec does not support broadcast & multicast.
- *VPN Tunnel is established in 2 Parts:*
  - _Part-1:_ Key Exchange for Data Encryption + Peer Authentication. Eg: [IKE](../)
  - _Part-2:_ Encrypting the data in [Tunnel or Transport Mode](Modes_Tunnel_Transport) with Keys exchanged in part-1. Eg: AH, ESP

||Authentication Header/AH|Encapsulating Security Payload/ESP|
|---|---|---|
|Support|Integrity check|Integrity, Encryption|
|IPv6 support|no|Yes|
|Encryption|No|Yes|

- **[Packet Flow:](Packet_Flow)** IPSec packet comes to interface, goes out

