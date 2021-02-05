## TRACEROUTE(Linux)/TRACERT(Windows)
- **WHAT?** 
  - This command traces the path of a packet from the source machine to destination such as Google.com by calculating the average RTT time taken each hop.
**STEPS?**
  - *a.* Traceroute sends packet with TTL=1(starts RTT timer), next hop drops the pkt(since TTL=1). Next hop sends back TTL-Time-Limit-Exceed message. As message arrive traceroute stops RTT notes the time. Traceroute sends 3 packets for any of them reach next hop. As 3 replies comes notes 3 RTTs for 1 destination.
  - *b.* Then TR sends same packet with TTL=2, now its dropped by next->next hop and same way 3 RTTs is noted.
  
<img src=./Traceroute_flow.png width="1400" />
