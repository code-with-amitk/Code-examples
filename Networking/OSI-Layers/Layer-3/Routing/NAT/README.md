- [NAT](#nat)
- [Type of NAT](#types)
  - [A. Static/Basic NAT](#snat)
  - [B. Dynamic NAT](#dnat)
  - [C. Port Address Translation](#pat)

<a name=nat></a>
## NAT / Network Address Translation
- if a PC inside pvt n/w want to commnicate over internet, organization may not have enough Public IP Addresses to make all pvt nodes assign seperate public IP to communicate with External servers. But even NAT is not permanent Solution. IPv6 is.
- **Types**
  - _SOURCE NAT:_ Changing Private Source IP address of outgoing packet to Public IP Address.
  - _DESTINATION NAT:_ When packet comes to router, dst IP is set to Router's IP(as in IPSec Tunnel). Router changes this IP to pvt IP.

<a name=types></a>
## Types of NAT
```c
    INSIDE N/W                                  
       PC1                                            
    [10.0.0.2]------------------                       
                                |                 
       PC2             10.0.0.1 | 179.2.2.80                    
    [10.0.0.3]----------------[Router]-----------------Internet-----------[213.31.80.2]Host4
                                |                  
       PC3                      |                    
    [10.0.0.4]------------------    
```

<a name=snat></a>
### A. Static/Basic NAT
  - One-to-One Translation of IP Addresses.
  - Private Address Space/Pool has corresponding Public Address Space/Pool. 
  - Every computer on the network must be allocated a single dedicated routable IP address.

<a name=dnat></a>
### B. Dynamic NAT
- Pool of Public IP Addresses is reserved at beginning. 
- And at run-time Router picks up the IP Address from Pool for address translation.
```c
1. PC2 wants to send Pkt to  Host4          SrcIP=10.0.0.3, DstIP=213.31.80.2
2. Packet reaches Router, Changes Src IP. Creates a NAT table
        SrcIP=179.2.2.80, DstIP=same

|Inside Local IP| Inside Global IP|	Outside Global IP |
----------------|-----------------|---------------------
|   10.0.0.3    |   179.2.2.80	  |   212.31.80.2 
|   10.0.0.4    |   179.2.2.69 	  |   212.31.80.2 

3. Reply comes from Host4, Router checks NAT table converts Dst IP and forwards 
```

<a name=pat></a>
### C. Port Address Translation / PAT / IP Masquerading / NAPT(N/W address & Port Translation)/ NAT Overloading
- Router will use only Single Public IP Address.
```c
|Inside Local IP:Port| Inside Global IP:Port |	Outside Global IP:Port |
|---|---|---|
|10.0.0.3: 1650 |	179.2.2.80: 1650|213.31.80.2: 80|
10.0.0.4: 1722|179.2.2.80: 1722|213.31.80.2: 80|
```
