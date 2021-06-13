## Size Scaling
- In distributed systems 1 or 2 services maybe implemented to run on single server(Single Threaded). This service will become a bottleneck as load increases.
- Why this service will become bottleneck?
  - **1. Limited CPU:** (Eg: Google maps) if service is single threaded and running in 1 machine(high end), it will come down on load.
    - **Solution:** Vertical Scaling. Increasing memory, upgrading CPUs, or replacing network modules
  - **2. I/O transfer rate** (Eg: Bing) Search engine is IO bound. SE need to match a query against an entire data set. Even with Advanced [Indexing Techniques](/System-Design/Concepts/Indexing) 1 machine will come down on load.
    - **Solutions:**
      - Writing async applications
      - Doing majority of task on client side(If application cannot be written asyncrounsly). Eg: submitting form to web server.
  - **3. Network scalability:** (Eg:youtube) Need to stream high-quality video to multiple users. if N/W is slow and high requests hit, service becomes bottleneck.
    - **Solutions:**
      - *a. Paritioning & Distribution.* (Eg: DNS as nameservers distribute work.) Do not keep all work at 1 node, paritition & distribute across multiple nodes.
      - *[b. Replication](/System-Design/Concepts/Databases/Database_Scaling):* Replication increases
availability, but also distributes the load between components leadning to better performance.
      - *[c. Caching](/System-Design/Concepts/Cache/Where_Cache_Can_Be_Placed):* Placing data near to client.
