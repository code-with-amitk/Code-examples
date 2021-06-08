## Dead Peer Detection
- **Dead Peer?**
  - Sudden failure of the VPN peer during communication.
  - Since VPN gateway does not typically initiating traffic it does not notice if or when the VPN has failed.
- **Solution to Dear Peer?** Configure DPD on Gateway
  - DPD sends UDP messages at defined intervals, and if messages are not responded to, the peer is considered to be down.
- **Exception to DPD**
  - DPD is used when dynamic routing is not used(e.g., OSPF), because dynamic routing protocols can both detect a failure and default over to another path without the need for DPD.
