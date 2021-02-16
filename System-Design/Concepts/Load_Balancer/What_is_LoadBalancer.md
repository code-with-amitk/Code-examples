## Load Balancer
- **What** Improves the distribution of workloads across multiple computers.
- **Examples** Ngnix, Amazon ELB

### Types of Load Balancing
- **A. LOAD BALANCER?**  
  - Traffic is divided using IP Address or Port numbers.
  - if load-balancer-1 fails traffic gets routed using load-balancer-2. Usually load balancers are implemented in high-availability pairs which may also replicate session persistence data. 
  - Load Balancers know which machines are:Available, Healthy(Healthcheck packets are sent, similar to ping requests. Servers reply with their state), Not overloaded
 - **B. CHANNEL BONDING?** 
  - Implies a division of traffic between physical interfaces at layer1(per packet division) or layer2(data link layer with a protocol like shortest path bridging).
  
### Advantages of LB
  - *a.* Handle more users than with a single server.
  - *b.* Redundancy: if one server fails, others are available to ensure the application stays online.

### RP vs LB

| | RP | LB |
|---|---|---|
|When needed|<ul><li>Only 1 backend server</li></ul><ul><li>Its web url is same as backend server</li></ul>|<ul><li>Multiple servers handling incoming requests</li></ul><ul>All servers mostly hold same content</li></ul>|
|Advantages|<ul><li>Increased security: No information about your backend servers is visible outside. Rejecting traffic from particular client IP addresses (blacklisting)</li></ul><ul><li>Web Accelaration:Reducing time it takes to generate a response and return it to the client.Techniques: Caching,Compression,SSL Termination</li></ul>|<ul><li>Handle more users than with a single server.</li></ul><ul><li>Redundancy: if one server fails, others are available to ensure the application stays online.</li></ul>|
