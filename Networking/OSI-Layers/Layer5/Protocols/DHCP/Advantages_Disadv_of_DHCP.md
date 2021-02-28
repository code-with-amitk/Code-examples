## Advantages of DHCP
- Configuration of large/medium sized networks is made simple.
- Eliminates the chance of human errors.
- IP addresses are conserved because DHCP assigns them only when a client requests one.

## Pitfalls / Disadvatanges of DHCP
- One DHCP server can become a single point of failure.
  - *Solution* Multiple DHCP servers in [Master Slave Config](/System-Design/Concepts/Databases/Database_Scaling)
- Microsoft Windows Server 2003's DHCP server is not compatible with all DHCP clients.
- If the DHCP server is malformed(ie hasincorrect information) it will automatically be delivered to all of your DHCP clients.
  - *Solution:* Timely check of DHCP server.
