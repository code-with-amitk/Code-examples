## Data, Control, Management Plane
- **What is Plane?** Conceptual model used by routers and switches. Planes describe how packets travel to, from, and through a device.
- **Why router is seperated in planes?**
  - If everything is done by 1 software only, things might get messed/mixed at high load.
  - Technologies can be developed independetly.
  - Control plane features are not locked in data plane. *Eg: SDN*. Here Data plane & control plane are seperate & hence control plane is moved out of device.

## Plane comparison
|  | Control/Slow path/RE(Routing Engine) | Data/Forwarding/High Speed Path | Management | Service |
| --- | --- | --- | --- |---|
| Kind of Traffic | <ul><li>Traffic for myself. I need to respond.</li></ul> <ul><li>I need to generate message myself and participate in conversation.</li></ul> <ul><li> Eg: Routing traffic:OSPF, ping, management etc</li></ul> <ul><li>This is CPU intensive task</li></ul> | <ul><li>This is not my packet, I just need to forward</li></ul> <ul><li>Less CPU intensive task, hence faster.</li></ul> | <ul><li>Management traffic coming to device</li></ul> <ul><li>Eg: SSH, SNMP, Telnet</li></ul> <ul><li>This is **control plane** traffic if meant for myself.</ul></li> <ul><li>This becomes **data plane** traffic if need management of some other device, ie passing from myself to other device.</li></ul>|Most security features implemented here|
|How Implemented|Can be physical card or VM running|Mostly Hardware(Eg: NIC)|||
| How its achieved | | <ul><li> Layer-3:FIB</li></ul> <ul><li>Layer-2: RIB</li></ul> <ul><li>Layer-1: Specialized ASICs</li></ul>| ||
| Controls | <ul><li>How data is forwarded into network.</li></ul> <ul><li>This is brain of network.</li></ul> | |

