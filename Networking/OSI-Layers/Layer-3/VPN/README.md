## VPN / Virtual Private Network
- **What?** Encrypted connection over the Internet between devices. Eg: An employee working from home connects securely to his office servers.
- **[Types of VPN](Types_of_VPN):**   *1.* Site to Site, *2.* Remote Access
- **[Terms](Terms):** Cookie, DOI(Domain on Interpretation), Nonce, PFS(Perfect Forward Secrecy), SA(Security Association), SP(Security Policy), SPI(Security Parameter Index)
- **Establishment of VPN Tunnel**
  - **[Part-1 IKE:](IKE)** Establish encryption keys which is used to secure data sent on VPN tunnel.
  - **[Part-2 IPSec:](Security/IPSec)** Encrypt data & send in [Tunnel or Transport mode](Security/IPSec/Modes_Tunnel_Transport).
- **[Opensource VPN Implementations](OpenSource_VPN_Implementations):** Libreswan/strongswan, openvpn
- **[Packet Flow:](Security/IPSec/Packet_Flow)** IPSec packet comes to interface, goes out
