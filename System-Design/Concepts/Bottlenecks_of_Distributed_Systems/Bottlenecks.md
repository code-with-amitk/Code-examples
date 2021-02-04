# Bottlenecks
## 1. Admission Control
  - Mechanism is needed to authenticate a node before allowing admission into distributed system. (using: kerberos)
  
## 2. Communication Control
  - **1. Rekey** Node should validate(at proper intervals) before communicating with another group member or intruder. (IKE rekey)
  - **2. Group Communication:** Is node allowed to talk to other group to whom its not member of?
  
## 3. Size Scaling
- In distributed systems 1 or 2 services maybe implemented to run on single server(Single Threaded). This service will become a bottleneck as load increases.
- Why this service will become bottleneck?
  - **1. Limited CPU:** (Eg: Google maps) if service is single threaded and running in 1 machine(high end), it will come down on load.
    - **Solution:** Vertical Scaling. Increasing memory, upgrading CPUs, or replacing network modules
  - **2. I/O transfer rate** (Eg: Bing) Search engine is IO bound. SE need to match a query against an entire data set. Even with Advanced [Indexing Techniques](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Indexing/README.md) 1 machine will come down on load.
    - **Solutions:**
      - Writing async applications
      - Doing majority of task on client side(If application cannot be written asyncrounsly). Eg: submitting form to web server.
  - **3. Network scalability:** (Eg:youtube) Need to stream high-quality video to multiple users. if N/W is slow and high requests hit, service becomes bottleneck.
    - **Solutions:**
      - *a. Paritioning & Distribution.* (Eg: DNS as nameservers distribute work.) Do not keep all work at 1 node, paritition & distribute across multiple nodes.
      - *[b. Replication](https://github.com/amitkumar50/Code-examples/tree/master/System-Design/Concepts/Databases/Database_Scaling):* Replication increases
availability, but also distributes the load between components leadning to better performance.
      - *[c. Caching](https://github.com/amitkumar50/Code-examples/tree/master/System-Design/Concepts/Cache/Where_Cache_Can_Be_Placed):* Placing data near to client.
    
## 4. Geographical Scalabilty
  - **Synchronous/Blocking Communication not good on WAN** socket is created as blocking and blocks on read()/write() system calls. client will block until reply from server.
    - **LAN** This approach works on LAN, where server will send responses faster.
    - **WAN** On WAN, client server are seperated by(lossy, limited Bandwidth internet), which may cause client to block indefinetly.
    - Solution: Writing non-blocking applications. `fcntl(sockfd, F_SETFL, O_NONBLOCK);`

## 5. Administrative Scalability
  - Multiple, independent administrative domains having conflicting policies for resource usage, payment management and security.
  - **Example:** A computational(often expensive) equipment is segregated as [Federation](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Databases/Database_Scaling/README.md) where Program_1(Orgnization_1) can access resources of DB_2(Organization_2).
    
## 6. Consistency Problem
