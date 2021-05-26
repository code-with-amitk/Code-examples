## ARP / Address resolution Protocol
- **Why?** 
  - Before sending packet on same LAN, router/switch finds that does it has [MAC Address]() corresponding to Dest IP Address? 
  - If has ok, else router sends ARP message on LAN to know MAC Address of destination node where packet needs to be sent.
- ARP protocol works in Request-response fashion. ARP always works in same LAN, ie nodes connected to same switch.
- **[Example Scenario](Scenario)**
- **[ARP Packet Format](ARP_Packet_Format)**
- **[Messages in ARP](Messages_in_ARP):** ARP Probe, ARP Announcements.
- **[Terms](Terms)** ARP Spoofing(This is ARP Vuneariblity)
