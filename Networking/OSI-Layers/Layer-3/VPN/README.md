## VPN / Virtual Private Network
- **What?** Encrypted connection over the Internet between devices. Eg: An employee working from home connects securely to his office servers.
- **[Types of VPN](Types_of_VPN):**   *1.* Site to Site, *2.* Remote Access
- **[Terms](Terms):** Cookie, DOI(Domain on Interpretation), Nonce, PFS(Perfect Forward Secrecy), SA(Security Association), SP(Security Policy), SPI(Security Parameter Index)
- **[Opensource VPN Implementations](OpenSource_VPN_Implementations):** Libreswan/strongswan, openvpn
### Establishment of VPN Tunnel
- **[Part-1 IKE:](Part1_IKE)** Establish encryption keys which is used to secure data sent on VPN tunnel.
- **[Part-2 IPSec:](Part2_IPSec)** Encrypt data & send in [Tunnel or Transport mode](Part2_IPSec/Modes_Tunnel_Transport).
- **[Packet Flow:](Part2_IPSec/Packet_Flow)** IPSec packet comes to interface, goes out
