## VXLAN / Virtual Extensible LAN
- VXLAN helps in connecting Virtual Machines/VMWare Hosts on different clusters/Machines using VLAN.
- **Why?** VLANs does not satisfy the needs/capacity of data centers. Current VLAN can only support upto 4096 VLANs, Hence VXLAN came in. With 24bit VXLAN 16 Million VLANs can be constructed inside data center.
- **VXLAN Packet Format**      (MAC in UDP Encapsulation)   
```c
 <-----------        MAC Hdr           -------------------->        <---------    UDP        ----------------->   <------VXLAN Hdr    ------------>  <-Original pkt ->
 | dst MAC | src MAC | VLAN type | VLAN ID tag | ether type|   IP   | src port | VXLAN port | UDP Len| chksum |  |RRRR1RRR Reserverd | VNID | Res |  [L2][L3][L4][L5]   FCS
```                 
- **[How VXLAN works](How_VXLAN_Works)**
