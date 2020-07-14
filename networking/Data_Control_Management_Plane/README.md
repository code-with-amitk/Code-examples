# Data, Control, Management Plane

## A. What is Plane?
- Conceptual model used by routers and switches. Planes describe how packets travel to, from, and through a device.

## B. Comparison of Planes
|  | Control Plane | Data OR Forwarding Plane | Management Plane |
| --- | --- | --- | --- |
| Also called | Slow Path | High speed path | |
| Kind of Traffic | <ul><li>Traffic for myself. I need to respond.</li></ul> <ul><li>I need to generate message myself and participate in conversation.</li></ul> <ul><li> Eg: Routing traffic:OSPF, ping, management etc</li></ul> | Forward the traffic to adjacent router, not my traffic. | <ul><li>Management traffic going thru device</li></ul> <ul><li>Eg: SSH, SNMP, Telnet</li></ul> <ul><li>This is still **control plane** traffic but this should be treated seperately.</li></ul>|
| How its achieved | | <ul><li> Layer-3:FIB</li></ul> <ul><li>Layer-2: RIB</li></ul> <ul><li>Layer-1: Specialized ASICs</li></ul>| |
| Controls | <ul><li>How data is forwarded into network.</li></ul> <ul><li>This is brain of network.</li></ul> | 

## C. Why router is seperated in planes?
- If everything is done by 1 software only, things might get messed/mixed at high load.
- Technologies can be developed independetly.
- Control plane features are not locked in data plane.
  - Eg: **SDN**. Here Data plane & control plane are seperate & hence control plane is moved out of device.
