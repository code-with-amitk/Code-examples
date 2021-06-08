## Dynamic NAT
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
