## Load Balancer
- **What** Improves the distribution of workloads across multiple computers. (eg: ngnix, Amazon ELB)

### RP vs LB

| | RP | LB |
|---|---|---|
|When needed|<ul><li>Only 1 backend server</li></ul><ul><li>Its web url is same as backend server</li></ul>|<ul><li>Multiple servers handling incoming requests</li></ul><ul>All servers mostly hold same content</li></ul>|
|Advantages|<ul><li>Increased security: No information about your backend servers is visible outside. Rejecting traffic from particular client IP addresses (blacklisting)</li></ul><ul><li>Web Accelaration:Reducing time it takes to generate a response and return it to the client.Techniques: Caching,Compression,SSL Termination</li></ul>|<ul><li>Handle more users than with a single server.</li></ul><ul><li>Redundancy: if one server fails, others are available to ensure the application stays online.</li></ul>|
