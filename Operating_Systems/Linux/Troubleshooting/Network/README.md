### [Machine Not Reachable](Machine_Not_Rechable)
  - *1.* Is server Pingable(ping command)?
  - *2.* Can remote port be connected (telnet command)?
  - *3.* Do src have route to dst (traceroute command)?
  - *4.* Does kernel routing table have route to dst (route command)?
### [ConnectionRefused Overflow Underflow](ConnectionRefused_Overflow_Underflow)
  - *1.* Number of TCP/UDP connections to/from my machine (netstat)
    - Get number of active connections
    - Get number of connections per ip address
    - Get all IP Address connected to your host
  - *2.* Are packets getting dropped at Hardware Level (ip -s link)?
  - *3.* Is Network Bandwidth(bits/second) low and Latency(RTT) high (qperf)?
  - *4.* tcpdump

