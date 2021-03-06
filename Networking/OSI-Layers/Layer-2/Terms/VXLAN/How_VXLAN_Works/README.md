## How VXLAN Works
- **VTEP(VXLAN Tunnel Endpoint)/vSphere Host**:
  - VTEP learns about MAC address of other VTEP connected to VLAN. Sends the packet by filling IP Address of other VTEP.
  - This encapsulates/decapsulates the Original L2 Frame into VXLAN header. Tunnel is established between VTEPs. 
  - VTEP has 2 interfaces.
    - 1 end is connected to Physical Switch VLAN. 
    - 2nd to IP sending end of hypervisor.
  - VTEP consists of 3 modules:
    - *1. VIB(VMWare Installation bundle):* This consists of functionality of VTEP. 
      - Functions: Encap/Decap of packets, keeping forwarding tables upto date.   
    - *2. vmknic Virtual Adapter:* Carries control traffic includes multicast joins, DHCP, ARP Req. unique IP address is assigned per host. This is VXLAN IP. 
      - VXLAN makes use of IP multicast protocol to populate forwarding table of VTEP.    
    - *3. VXLAN Port Group:* Configured during VXLAN configuration process. Includes: 
      - physical NICs, VLAN information. These port groups defines how VXLAN traffic is carried in/out of VTEP Hosts through physical NICs

**Working**
- Host-1(192.168.1.1) on VM-1 wants to communicate with Host-3(192.168.1.3) on VM-3. 
- Note: Each VM will have separate IP Address, a Virtual NIC(means separate MAC Address)
- Pre-requites: Each host virtual NIC (ie MAC layer) have created a MAC-IP table already

<img src=vxlan-setup.png width=900 />

```c
 Host-1(On VM1)                                                    [VTEP-1]                                                                                                             
            -srcMAC=0e, dstMAC=0f | srcIP=.1, dstIP=.3 | L4 | L5 |->
                                                               Encapsulates packet
                                                     New IP Hdr srcIP=self, dstIP=VTEP-3
                                                  New MAC dstMAC=directly connected Router
                                               Performs Lookup for NextHop to forward for VTEP-3.                                                      

 <-|srcMAC=--, dstMAC=-- | srcIP=.31, dstIP=.33 | UDP | VXLAN hdr | ORIGINAL |-
[ROUTER-1] 
Changes src, dst MAC
         -->          [VTEP-3]
                   Decapsulates Pkt & Forwards to VM-3 --> [VM3]                                                                
```
