# Data, Control, Management Plane

## A. What is Plane?
- Conceptual model used by routers and switches. Planes describe how packets travel to, from, and through a device.

## B. Comparison of Planes
|  | Control Plane | Data/Forwarding Plane | Management |
| --- | --- | --- | --- |
| Also called | Slow Path | High speed path | |
| Traffic | <ul><li>Traffic for myself. I need to respond.</li></ul> <ul><li>I need to generate message myself and participate in conversation.</li></ul> <ul><li> Eg: Routing traffic:OSPF, ping, </li></ul> | Forward the traffic to adjacent router, not my traffic. | 
| How its achieved | | <ul><li> Layer-3:FIB</li></ul> <ul><li>Layer-2: RIB</li></ul> <ul><li>Layer-1: Specialized ASICs</li></ul>| |
