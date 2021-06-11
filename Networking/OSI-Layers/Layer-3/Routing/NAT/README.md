## NAT / Network Address Translation
- **What?** 
  - _SOURCE NAT:_ Changing Private Source IP address of outgoing packet to Public IP Address.
  - _DESTINATION NAT:_ When packet comes to router, dst IP is set to Router's IP(as in IPSec Tunnel). Router changes this IP to pvt IP.
- **Why?** if a PC inside pvt n/w want to commnicate over internet, organization may not have enough Public IP Addresses to make all pvt nodes assign seperate public IP to communicate with External servers. But even NAT is not permanent Solution. IPv6 is.
- **[Types of NAT](Types_of_NAT)**
