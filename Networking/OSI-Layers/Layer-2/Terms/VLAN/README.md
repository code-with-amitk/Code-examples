## VLAN
- This is virtual [Broadcast Domain](../Broadcast_Domain)
- It may be sometime not required by All devices in Broadcast domain to receive all broadcast traffic. 
- Hence Devices creates smaller Broadcast Domains inside Bigger Broadcast domain of Switch. 
- Group of devices on one or more LANs that are configured to communicate as if they were attached to the same wire, when in fact they are located on a number of different LAN segments.
- **How to Achieve?**  Lets suppose a switch has 21 ports.
  - VLAN-1(Port 1-7): If packet comes on port 2. It will be forwarded on 1,3,4,5,6 only.    
  - VLAN-2(Port 8-17)
  - VLAN-3(Port 18-21)

Typical VLAN uses 12 bits of Tag, Making 4096 VLANs present at a time

```c
//802.11Q Tag identifies VLAN Header
  Inter-Frame-Gap | Dst_MAC_Addr | Src_MAC_Addr | 802.11Q Tag(4byte) | Ether type|IPHdr|
```
<img src=VLAN.jpg width=900 />

- **Types of Ports on VLAN Switch?**
  - *1. Access Ports:* This belongs to 1 VLAN. Nodes/devices in 1 VLAN are connected using this
  - *2. Trunk Port:* They carry data b/w VLAN Switches. Each VLAN sets different value in 802.1Q, means each VLAN is identified by different 802.1Q. 
