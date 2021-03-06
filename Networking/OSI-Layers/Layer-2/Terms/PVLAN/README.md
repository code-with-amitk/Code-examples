## PVLAN / Private VLAN/ Port Isolation
- A switch is divided into [VLANs](../VLAN). Lets suppose [3 VLANs as taken in example](../VLAN). In each VLAN a port is reserved (designated as Private Port).
- This Private Port will ONLY communicate with uplink(Router, Server etc).
- **Frames received on Pvt Port** All packets received on private port are forwarded to uplink port, regardless of VLAN id or dest MAC.
- **Frames received from uplink** Forwarded in normal way. Either to     
  - *1.* Port connected to dest MAC Add    
  - *2.* All ports of VLAN for broadcast frame.
