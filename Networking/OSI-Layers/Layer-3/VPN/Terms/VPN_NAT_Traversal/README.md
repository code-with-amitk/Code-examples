## VPN [NAT](/Networking/OSI-Layers/Layer-3/Routing) Traversal
- **Problem in IPSec-ESP packet crossing NAT GW**
  - NAT router doing [PAT](/Networking/OSI-Layers/Layer-3/Routing/NAT) when recieves a IPSec packet. It cannot find UDP-Header(to get port number from it).
```c
                                 |------ encrypted --------------|
    | New-IP-Header | ESP-Header | old-IP-header | TCP/UDP | App |
                                 |                               |
                        ||
                        \/
                     [NAT(PAT) Router] 
               Cannot find Port number.. Drop
```
- **Solution: NAT-T(NAT Traversal)**
  - Add extra UDP Header over ESP with port=4500(identifying NAT-T)
```c
                                                       |------ encrypted --------------|
    | New-IP-Header | UDP-header port=4500| ESP-Header | old-IP-header | TCP/UDP | App |
                                                       |                               |
                        ||
                        \/
                     [NAT(PAT) Router] 
                  Successfully done NAT
                              ------------ pkt----------->  VPN-GW
                                                        Finds UDP-port=4500(ok NAT-T)
```
