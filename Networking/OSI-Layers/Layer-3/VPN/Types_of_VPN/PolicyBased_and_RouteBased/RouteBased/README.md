## Route Based
- These uses a Virtual Interface(called secure tunnel interface (st0 interface)).
- All traffic routed into the interface will be sent into a VPN.
- Traffic to be sent into st0 is decided on routing, hence name route-based VPN.

### Types of Route Based VPNs
- **1. Point To Point VPN**
- There are only 2 hosts in VPN communication channel. Host-1 interface connects to Host-2 using secure interface.
- Host-1 may have other interface connected to other subnets.

- **2. Point to Multipoint**
- One interface can connect to multipoint VPN servers.
