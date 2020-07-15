# Comparison
| | Unicast | Broadcast | Multicast |
| --- | --- | --- | --- |
| What | 1 Sender, 1 Receiver | 1 Sender to All connected Receivers/Nodes | 1/More Sender to 1/More receiver |
| Protocols | <ul><li>http, smtp, ftp, telnet</li></ul> <ul><li>TCP Supports Only Unicast</li></ul>| ARP | PIM-SM, PIM-DM |
| Underlying Protocol | any | - | UDP Must be used |
| IP Address | <ul><li>Every Node has atleast 1 Unicast+1 Broadcast Add</li></ul> | 224.0.0.0 - 239.255.255.255 |
