**Load Balancer**
- [Advantages of LB](#adv)
- [Reverse Proxy vs LB](#vs)
- [Types](#ty)
  - [1. ALB/Layer-7/Application LB](#alb)
  - [2. NLB/Layer-3,4/Network LB](#nlb)
- [Places where LB can be placed?](#p)
- [Scheduling Algorithms at LB](#s)

## Load Balancer
- LB distributes workload across multiple computers. Examples Ngnix, Amazon ELB
- Multiple IP addresses are associated with a single domain name(google.com is associated with IP1, IP2, IP3). Whenever client want to connect using DNS, IP are given based on [scheduling algo](#s)
- Load Balancers can be run as array of servers, these can be auto scaled when needed, and released when don't needed.
```c
                      Server Farm/Pool
			   	              \/
	            		 |- |Web Server-1|
  ---------------	 |		
  |Load-Balancer|- |- |Web Server-2|
  ---------------  |
       			       |- |Web Server-3|
			             | ....
			             |- |Web Server-n|
```
<a name=adv></a>
### Advantages of LB
- _1. Performance:_
There are physical bound on how much 1 computer can do task. Millions of users can only be supported on multiple machines not 1
- _2. Availability:_
Machine failure happens. We should avoid single points of failure whenever possible.
- _3. Economy:_
Its always cheaper to buy 5 small comodity machines as compared to 1 big machine.
- _4. Redundancy:_
Multiple machines are of same capacity, if 1 fails others are ready and up, While in Vertical scaling(if 1 machine fails) system is down.
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
## Types of Load Balancing
<a name=alb></a>
### 1. ALB/Layer-7/Application LB (Also called Reverse Proxy)       //Layer-7=Application
LB looks into Layer-7 Application packet(Eg: HTTP/HTTPS) and performs load balancing based on Header content.
<a name=nlb></a>
#### 2. Layer 3,4 LB / NLB(Network LB)   //Layer-4=Transport
Operate at transport layer(TCP, UDP, TLS). Packet is routed based on Src,dst Ports(without looking into packet).
#### Layer3 VPN LB
LB decision is made based on IP Address
#### CHANNEL BONDING?
Implies a division of traffic between physical interfaces at layer1(per packet division) or layer2(data link layer with a protocol like shortest path bridging).

<a name=p></a>
## Places where Load Balancers can be placed
- **1. Between client and Application servers:** Each application server might be serving some subset of users. LB will forward request to appropriate AS.
- **2. Between App-servers and cache:** Since we can have 100s of cache servers, those needed load balancing.
- **3. Between cache and DB servers:** Since DB servers can be upto 256 LB in front of it is good.
```html
                          App-server1
                          App-server-2    LB    client
                          App-server-n

          cache-1
          cache-2   LB    App-server 
          cache-n

DB-1  
DB-2  LB  cache
DB-n
```

<a name=s></a>
## Scheduling Algorithms at Load Balancers
- **1. ROUND ROBIN:**    
  - Send request one after other.
- **2. LEAST CONNECTIONS:**
  - Sends requests to the server with the lowest number of active connections.
- **3. LEAST TIME:** 
  - Sends requests to the server selected by a formula that combines the fastest response time and fewest active connections.
- **4. HASH:** 
  - Distributes requests based on a key you define, such as the client IP address or the request URL.
- **5. IP HASH:** (HTTP only) 
  - Distributes requests based on the first three octets of the client IP address.
- **6. RANDOM WITH 2 CHOICES:**
  - Picks two servers at random and sends the request to the one that is selected by then applying the Least Connections algorithm.
- **7. DNS Round Robin Load Balancing?** 
  - Yes its different from Round robin.
  - Mapping multiple servers(IP-1, IP-2, IP-3) to same hostname, so that when users visit `foo.example.com` multiple servers are available to handle their request.
  - Now client Requests will gets distributed across a group of server machines.
- **8. Sub domain DNS Delegation with Round Robin:**    
  - When we have multiple subdomains (hr.example.com, payroll.example.com) inside main domain(example.com). subdomains have their own nameservers. Now when request comes in for resource inside hr.example.com primary nameserver(example.com) will forward to subdomains nameservers. This will improve response times, as the DNS protocol will automatically look for the fastest links.
- **9. Client side random load balancing**
  - Deliver a list of server IPs to the client, and then to have client randomly select the IP from the list on each connection. This essentially relies on all clients generating similar loads. 
- **10. Server side load balancers:** 
  - Load balancer binds and listens on port. Forwards the request to all backend servers, which ever responds 1st. it caters the request. It have security benefits by hiding the structure of the internal network and preventing attacks on the kernel's network stack or unrelated services running on other ports
- **11. IP ADDRESS BASED:**    
  - If request comes from IP Address within range from (x to y) forward packet to backend server-1, if request comes from IP Address range from (a to c) forward packet to backend server-2 and so on.
- **12. LAYER 5 AWARE:**    
  - These load balancers are layer-5 protocol aware(Eg: HTTP). They can look into HTTP-header can decide what to do with packet whether to send to server-1 or 2.
