## Modes of Data Exchange
- **1. Tunnel:** New IP Header provided.
  - For Firewall-to-Firewall Delivery.
  - Consumes more CPU power. IP, TCP, App Protected.
```c
                            |-------  Encrypted   -----------|
      | New IP Hdr | ESP/AH | Old IP Hdr | TCP Hdr | App Hdr |
```
- **2. Transport:**
  - Host-to-Host Delivery. 
  - TCP & Application Protected.
```c
                                         |--  Encrypted   -------|
   | IP Hdr | ESP/AH(protocol=ESP or AH) | TCP/UDP Hdr | App Hdr |
```
