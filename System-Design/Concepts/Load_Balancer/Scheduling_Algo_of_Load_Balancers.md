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
- **8. DNS Delegation:**    
  - Delegate `www.example.com` to subdomain whose domain are served by same servers. Server1(one.example.org A 192.0.2.1)    Server2(two.example.org A 203.0.113.2)      Server3(three.example.org A 203.0.113.2)
- Zone file on each of servers contains A record which points to server itself.        Server-1(@ in a 192.0.2.1)        Server-2(@ in a 203.0.113.2)
- Now when web client tries to connect the server(www.example.com) and Server1 is down, its DNS will not respond and the web service does not receive any traffic. Furthermore, the quickest DNS response to the resolver is nearly always the one from the network's closest server, ensuring geo-sensitive load-balancing
 D. CLIENT SIDE RANDOM LOAD BALANCING:    Deliver a list of server IPs to the client, and then to have client randomly select the IP from the list on each connection. This essentially relies on all clients generating similar loads. 
 E. SERVER SIDE LOAD BALANCERS: Load balancer binds and listens on port. Forwards the request to all backend servers, which ever responds 1st. it caters the request. It have security benefits by hiding the structure of the internal network and preventing attacks on the kernel's network stack or unrelated services running on other ports
 F. IP ADDRESS BASED:    If request comes from IP Address within range from (x to y) forward packet to backend server-1, if request comes from IP Address range from (a to c) forward packet to backend server-2 and so on.
 G. LAYER 5 AWARE:    These load balancers are layer-5 protocol aware(Eg: HTTP). They can look into HTTP-header can decide what to do with packet whether to send to server-1 or 2.
