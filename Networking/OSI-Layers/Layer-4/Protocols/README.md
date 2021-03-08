## TCP vs UDP

||TCP|UDP|
|---|---|---|
|Header size|Min(20 bytes), Max(60 bytes)|8 bytes|
|Connection| Connection Oriented | Connectionless|
|Reliabilty| Reliable (have ACKs)|Unreliable (no ACKS)|
|Ordering| Yes, Seq Numbers| No ordering, Duplicates can be there|
|Error checking|Yes in TCP, Checksum in Header | performed at App Layer|
|Applications|[TCP_Applications](TCP)|[UDP_Applications](UDP)|
|Delay|More wrt UDP|Less|
|Retransmissions|Yes|No|
|Multicast support|No|Yes|
|Network BW|Consumes More, Bigger Header.More ACKS|Less|
|Focus on|Relaibilty|Packet Delivery|

