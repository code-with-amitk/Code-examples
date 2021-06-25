- [Terminology](#terms)
  - NAT
- [1. Router](#router)
- [2. Routing table](table)
  - [2.1 Associated Terms](#terms)
  - [2.2 Example Routing Table](#example)


<a name=terms></a>
## Terminology
  - [NAT](NAT)

<a name=router></a>
## 1. Router
- Router is a networking device that forwards packets into n/w. When packet comes to a router it reads dstIP & finds on which interface packet should be sent.
- Router changes following feilds before forwarding.
  - TTL: Decremented by 1
  - Checksum: To check header has error or not.

<a name=table></a>
## 2. Routing Table/Routing inforamtion base(RIB)
- This contains the routes to particular network destinations & metrics(distances) associated with those routes.
- Atleast RT will contain these 3 coloumns:
  - network ID: This is destination subnet.
  - metric/cost: Metric of the path through which the packet is to be sent. lowest metric path would be selected.
  - next hop/gateway: Address of the next router to which the packet is to be sent.

<a name=terms></a>
### 2.1 Terms associated with Routing Table
- **Metric/Cost/Distance:** This field is filled by routing protocol. Route with lowest Metric should be chosen. Factors for calculation of Metric: Number of Hops, Speed of Path, Packet Loss, Link Utilization, Latency, BW, Throughput, Load etc.
- **Route Type**
  - Static Route: Administrator adds routes to Routing table.    To Add Static route of Cisco ASA:           #ip  route   dest_ip     n/w_mask           next_hop       
  - Default Route: Send all packets towards configured gateway.
  - Dynamic Route: Networking Protocols populate these routes to routing table.

<a name=example></a>
### 2.2 Example Routing Table
```c
 [D](18)--------172.16.1.0----------(1)[A](1)----------172.16.2.0----------(2)[B](1)---------192.168.1----------(2)[C]172.16.4.1    
 
N/W Destination 	N/W Mask 	Next Hop/Gateway 	Interface 	Metric/Cost 	Protocol 	 
  0.0.0.0           /0      172.16.2.1        1           46 	 	                    //DEFAULT ROUTE.Send Pkt to G/W If no specific Next Hop is Listed in Table.
255.255.255.255     /32     172.16.2.1        1           296           Direct 	                  //BROADCAST
  127.0.0.1         /32     127.0.0.1 	      127.0.0.0.1 4531          Local 	    //LOOPBACK 
  172.16.4.0        /24     192.168.1.2 	    0           30            STATIC 	    //This is Manually Configured 
  172.16.2.1       /24      172.16.2.1 	      1           30            OSPF 	 
  172.16.1.18      /24      172.16.2.1 	      172.16.2.2  92            OSPF 	 
```
