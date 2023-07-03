- [Broadcast Domain](#bd)
- [VLAN](#vlan)

<a name=bd></a>
### Broadcast Domain
- A Logical network in which all nodes will receive Broadcast packet, if one node in domain sends it.
- This is Implemented using Switch, Nodes connected using Switch are in same broadcast domain. If 1 device sends Broadcast packet that will be received by all other devices

<a name=vlan></a>
### VLAN
- This make 1 single switch to function as if it were multiple switches
- VLANs enable a switch to carry multiple [broadcast domains](#bd). VLANs are commonly used for network segmentation.
- Group of devices on one or more LANs that are configured to communicate as if they were attached to the same wire, when in fact they are located on a number of different LAN segments.
- **How to Achieve?** Lets suppose a switch has 21 ports.
```c
VLAN-1(Port 1-7): If packet comes on port 2. It will be forwarded on 1,3,4,5,6 only.
VLAN-2(Port 8-17)
VLAN-3(Port 18-21)
```
<img src=images/VLAN.jpg width=500/>
- Typical VLAN uses 12 bits of Tag, Making 4096 VLANs present at a time
```
//802.11Q Tag identifies VLAN Header
  Inter-Frame-Gap | Dst_MAC_Addr | Src_MAC_Addr | 802.11Q Tag(4byte) | Ether type|IPHdr|
```
- Types of Ports on VLAN Switch?
  - 1. Access Ports: This belongs to 1 VLAN. Nodes/devices in 1 VLAN are connected using this
  - 2. Trunk Port: They carry data b/w VLAN Switches. Each VLAN sets different value in 802.1Q, means each VLAN is identified by different 802.1Q.
- **Trunking:** Devices that support trunking can also communicate on multiple VLANs through a single physical port.
