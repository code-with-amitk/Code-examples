
# A. What is multicast
- Sending packet by 1/More Sender to 1/More receiver.

# B. How it works?
- Multicast packets are replicated in N/W at a point where Paths Diverges by Router enabled by PIM(Protocol Independent Multicast) & Other supporting multicast protocols.
- Multicast addresses are used as destination addresess only, source addresses are always unicast.
- **Multicast Groups?** These are arbitrary group of receivers that expresses interest in receiving certain data stream. These hosts joins the Groups using IGMP.

# C. Applications
- Video Conferencing, Corporate Communication, Distance Learning, Stock Quotes, Distribution of S/W, news.

# D. Popular multicast addresses
| Address | Meaning |
| --- | --- |
| 224.0.0.1 |	All systems on subnet |
| 224.0.0.2 |	All routers on subnet |
| 224.0.0.5 |	OSPF Routers |
| 224.0.0.6 |	OSPF Designated Routers |
| 224.0.0.12 | DHCP Server/Relay Agents |
| 224.0.1.0 - 238.255.255.255 |	Globally scoped Addresses Used by organizations to send data across the internet. |
| 224.0.1.1 | NTP |
| 232.0.0.0/8 | Source Specific Multicast |
| 233.0.0.0/8  | GLOP Addresses |
| 239.0.0.0/8  | Limited Scoped Addresses or Administrative scoped Addresses |
