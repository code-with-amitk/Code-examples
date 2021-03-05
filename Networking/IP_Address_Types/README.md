# Comparison
![ImgURL](https://i.ibb.co/17gSHNw/uni.jpg)
| | Unicast | Broadcast | Multicast |
| --- | --- | --- | --- |
| What | 1 Sender, 1 Receiver | 1 Sender to All connected Receivers/Nodes | 1/More Sender to 1/More receiver |
| Protocols | http, smtp, ftp, telnet. TCP Supports Only Unicast | ARP | PIM-SM, PIM-DM |
| Underlying Protocol | any | - | UDP Must be used |
| IP Address | Every Node has atleast 1 Unicast+1 Broadcast Add. Eg:46.255.255.255 | Any IP in range 224.0.0.0 - 239.255.255.255 |
