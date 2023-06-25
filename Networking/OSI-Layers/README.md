## Layers, Design Issues

|Layer|Design Issues|Duties|Protocols|
|---|---|---|---|
|Application|sending large information. eg: 5gb, caching:how long fetched data is valid and when to query back?, security, slow client or server|User services(eg: Emails, video share etc)|DNS,DHCP,HTTP,LDAP|
|Presentation(Handles any conversions between data formats required by users such as different character sets, encodings, compression, encryption, etc)||Presentation of data(ie syntax, semantics of data received)|
|Session||Establish sessions(eg: token management etc) b/w hosts on different machines|
|Transport(App to App)|Services provided to upper layer|Process to process delivery, Congestion & flow Control, Error detection|TCP,UDP|
|Network(Host to Host)|Store/Forward pkt, Implementation of connectionless/connection-oriented|Handling congestion|IP,ICMP,IGMP|
|Between L3,L2|||ARP|
|Data Link(Hop to Hop)|Framing, Error control, Flow control|Detect/correct PHY layer errors. Used to deliver data frame within same network|L2TP|
|Physical(Electrical or Optical Cabling)|Making sure sender sends 1 and recr receives 1 not 0|Send 0,1s on network|

## Header Sizes

|Ethernet Header|IP Header|TCP Header|UDP Header| Total
|---|---|---|---|---|
|18 bytes|Min(20 bytes), Max(60 bytes)|Min(20 bytes), Max(60 bytes)|8 bytes|<ul><li>Using TCP:138 bytes</li></ul><ul><li>Using UDP:86 bytes</li></ul>|
