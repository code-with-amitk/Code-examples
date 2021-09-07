**Load Balancer**
- [Reverse Proxy vs Load Balancer](#lb)
- [Types of Load Balancing](#ty)

## Load Balancer
- LB improves the distribution of workloads across multiple computers. Examples Ngnix, Amazon ELB
  - Multiple IP addresses are associated with a single domain name(google.com is associated with IP1, IP2, IP3). Whenever client want to connect using DNS, IP are given based on [scheduling algo](Scheduling_Algo_of_Load_Balancers.md)
**Advantages of LB**
- *a.* Handle more users wrt single server.
- *b.* Redundancy: if one server fails, others are available to ensure the application stays online.

<a name=vs></a>
### Reverse Proxy vs Load Balancer
```c
            |   Reverse Proxy                                           |            Load Balancer
------------|-----------------------------------------------------------|------------------------------------
When needed | Only 1 backend server                                     | Multiple servers handling incoming requests
              Its web url is same as backend server                     | All servers mostly hold same content
Advantages  | 1. Increased security: No information about your backend  | 1. Handle more users than with a single server.
              servers is visible outside.                               | 2. Redundancy: if one server fails, others are available to ensure the application stays online.
              2. Blacklisting: Reject traffic from particular client IP |
              3. Web Accelaration: Reducing time to generate a response
                & return it to the client. Techniques: Caching, 
                Compression,SSL Termination
```

<a name=ty></a>
### Types of Load Balancing
**A. LOAD BALANCER?**  
- Traffic is divided using IP Address or Port numbers. if load-balancer-1 fails traffic gets routed using load-balancer-2.

**B. CHANNEL BONDING?** 
- Implies a division of traffic between physical interfaces at layer1(per packet division) or layer2(data link layer with a protocol like shortest path bridging).
  

### RP vs LB

| | RP | LB |
|---|---|---|
