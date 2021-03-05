## Configuring IPv6 on Node
- There are 2 methods:
- **1. Static configuration**
- **2. Dynamic/DHCPv6 Configuration:** In DHCP there are 2 methods
  - **a. Using ff002 :: 1 : 2** This is All DHCP Server Link Local Multicast Group. All DHCP Servers on LAN are members of this multicast group. Now DHCP server will send reply on 546/UDP port on which client must be listening.
  - **b. SLAAC(Stateless Address Auto Configuration):**             radvd package in RHEL 7 provides SLACC
```c
                      - Host brings LL address on fe80 :: /64
                      - Sends Router Solicitation message to ff02 :: 1 : 2
                      - DHCP routers responds with N/W prefix and other information.
                      - Host uses N/W prefix with N/W ID to construct IPv6 address.
``` 
