# IGMP (Internet Group Management Protocol)
## A. What
- This is a protocol with which host advertises his multicast group membership to neighboring switches/routers.
- Host and router both should be on same LAN.
- Protocol no:2
- TTL: 1 (Means IGMP Host is directly connected to IGMP Router)
- Multicast management on **IPv6 networks** is handled by **Multicast Listener Discovery (MLD)** which is a part of ICMPv6.

## B. MESSAGE TYPES

| Name | Meaning |
| --- | --- |
| Report | send by Host to Router to express intrest in recieving multicast packets of particular group |
| Query | <ul><li>Send by Router to hosts to ask whether you are still intrested in particular multicast group traffic or not</li></ul> <ul><li>Always sent on `224.0.0.1`</li></ul> | Leave | Whenever a Host want to leave a multicast group it sends this message to Router on `224.0.0.2` |

