## Distributed System
- **What** 
  - A distributed system is a collection of computing elements that appears to its users as a 1 system.
  - It should have single-system view means that end users should not even notice that they are dealing with processes, data and control are dispersed across the nodes.
- **ACID:** All transactions in distributed systems Follow ACID.
  - **Atomic:** Each transaction is atomic
  - **Consistent:** Each transaction is consistent
  - **Isolated:** Concurrent transactions do not interfere with each other
  - **Durable:** Once a transaction commits, the changes are permanent  
- **Middleware**
  - This layer provides same interface to application running on any node. Also it hides he differences in H/W and OS from each application.  
<img src="https://i.ibb.co/4f6xC82/distributed-system-middleware-layer.png" width=700 />


## Types of Distributed Systems
- **1. HIGH PERFORMANCE DISTRIBUTED COMPUTING**
- **2. CLUSTER COMPUTING:** Simple computers connected on high-speed network, does parallel processing of task. Eg: Hadoop.
- **3. GRID COMPUTING:** Nodes can be anything. Databases, High end machines(super computers), normal processor, sensors, telescopes etc.
- **4. CLOUD COMPUTING:** Customer upload tasks to a data center and charged on a per-resource basis. 3 types of services to customers.
  - **A. IaaS(INFRASTRUCTURE AS SERVICE):**  Providing virtual machines(H/W, S/W, servers, storage) over internet. Cloud provider will give access to OS of server/Virtual Machine, you can install/remove/do anything on Server. Highest order of control.
  - **B. PaaS(PLATFORM AS SERVICE):** Dashboard is provided to you, upload button is provided you can upload your website.
  - **C. SaaS(SOFTWARE AS SERVICE):** Software hosted on Virtual machine on cloud. It is sometimes referred to as "on-demand software". SaaS is typically accessed by users using a thin client via a web browser.
