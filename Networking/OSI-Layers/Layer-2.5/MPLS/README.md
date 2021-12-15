**MPLS(Multi Label Protocol Switching)**


## MPLS (between layer 2,3)
- **What** 
  - This is packet forwarding technique where every data packet is assigned a LABEL and Packet is forwarded without looking into contents of packet or routing table(ie before reaching layer-3). which connects organizational sites together but just using label.
  - LABEL is placed in Layer-2 header. 
```c
site-1  --------------- internet --------------- site-2
comp1 -connect to comp2->                         comp2
```
- **Advantages**
  - _1. Less delay_ Since with layer-2 header we can do routing.
  - _2. Protocol Independent:_ MPLS can encapsulate packets of various n/w protocols hence called Multi-protocol.
  - _3. QOS:_
- **How it works**
  - Each router assigns a label to itself, advertises the lable to its neighbours, builds a label based forwarding table and forwards using that.
