Packet Capture


## Packet Capture
**[Running wireshark on linux](/Operating_Systems/Linux/Troubleshooting/Network/ConnectionRefused_Overflow_Underflow/)**

**Running wireshark on Windows**
- _1._ Select interface on which packets need to be captured. Capture > Options > Start  //List all interfaces, take 1 interface to apply capture
  - You can Disable promiscious mode(Since this captures all packets on LAN)
- _2._ Apply Display Filter. `ip.src == ip-address`
