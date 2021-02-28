## ICMP / Internet Control Message Protocol
- **Why?** 
  - Used by network devices(eg routers) to send Messages(Error, informational) indicating(Success or failure) when communicating with another IP address.
  - On receiving ICMP message, ICMP error message need to be delivered to application responsible for transmitting the IP packet. 
- **TCP UDP Port?** No TCP or UDP port number is associated with ICMP packets as these numbers are associated with the transport layer.
- **Commands using ICMP?** ping, [traceroute](Trace_Route.md).
- **[ICMP packet format?](ICMP_Header.md)**
- **[Terms? Ping Sweep, ICMP Redirect](ICMP_Terms.md)**

- COMMON FLAWS IN ICMP: See ICMP Vulnerabilities.
