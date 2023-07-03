**Bridge**
- [Bridging](#b)
- [Types of Bridges: Internal, External](#ty)
- [Layer 2 Loops](#l2l)

## Bridging
- Bridging means 2 interfaces of router or switch are placed on same network(ie part of same broadcast domain) as if they were connected to the same switch.
- **Why bridging?** This is done so that two interfaces will act as though they are on the same flat network using the same IP subnet, for example(wireless interface and wired interface).

<a name=ty></a>
## Types of Bridges
### 1. Internal Bridge
- Internal bridge connect 2 local interfaces such as 2 LAN interfaces or a LAN interface and a wireless interface
```c
  |  |  |
  switch-1(LAN1)---|
                  Bridge
  switch-2(LAN2)---|
  |  |  |
```

### 2. Internal/External Bridge / Tranparent firewall
- connect a LAN to a WAN. This is used to insert firewall between 2 devices

<a name=l2l></a>
### Layer2 Loops
- A layer 2 loop is when, either directly or indirectly, the switch has a connection back to itself.
- Spanning Tree Protocol (STP) avoid these.
