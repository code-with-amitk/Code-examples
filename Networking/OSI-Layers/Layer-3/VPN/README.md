- [What is VPN](#what)
- [Terms](#terms)
- [Types of VPN](Types_of_VPN)
- [Opensource VPN Implementations](#os)
- Establishment of VPN Tunnel
  - [Part-1 IKE](#part1)
  - [Part-2 IPSec](#part2)


<a name=what></a>
## VPN / Virtual Private Network
- Encrypted connection over the Internet between devices. Eg: An employee working from home connects securely to his office servers.

<a name=terms></a>
## [Terms](Terms)
Cookie, DOI(Domain on Interpretation), Nonce, PFS(Perfect Forward Secrecy), SA(Security Association), SP(Security Policy), SPI(Security Parameter Index), NAT Traversal, XAuth

<a name=os></a>
## [Opensource VPN Implementations](OpenSource_VPN_server_Clients)
Libreswan/strongswan, openvpn


## Establishment of VPN Tunnel
<a name=part1></a>
### [Part-1 IKE](Part1_IKE) 
Establish encryption keys which is used to secure data sent on VPN tunnel.

<a name=part2></a>
### [Part-2 IPSec](Part2_IPSec)
- Encrypt data & send in Tunnel or Transport mode.

- [key lifetimes](Terms)
- **[Packet Flow:](Part2_IPSec/Packet_Flow)** IPSec packet comes to interface, goes out
