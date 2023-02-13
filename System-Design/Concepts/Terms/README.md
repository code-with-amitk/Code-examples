- [Accuracy](#ac)
- [ACID](#acid)
- [Antisnubbing](#ans)
- [Atomicity](#at)
- [Availability](#av)
- [Autoscaling](#auto)
  - [How auto scaling works?](#howa)
- [Bandwidth](#bw)
- [BASE](#ba)
- [Clock Skew Problem](#csp)
- [Consensus](Consensus)
- [Consistency](#con)
- [CAP Theorem](#cap)
- [Decentralized](/System-Design/Concepts/Decentralization)
- [Deduplication](#de)
- [Durability](#dur)
- [Fault Tolerance](#ft)
- [Flash Crowd](Flash_Crowd)
- [Gossip Protocol](#gos)
- [Hot keys / Linchpin objects](#hk)
- [Latency](#la)
- [Linearizability](#lin)
- [Orchestration](#orc)
- [PACELC Theorem](#pacelc)
- [Partition Tolerance](#pt)
- [Reliable](#re)
- [Response time](#rt)
- [Scalability](#sc)
- [Serializability](#ser)
- [Split Brain](#sb)
- [Stream](/System-Design/Concepts/MOM_ESB/Apache_Kafka/#st)
- [Tenant](#ten)
- [Throughput](#tp)
- [Transaction](Transaction)

<a name=ac></a>
### Accuracy
System is doing what's it's supposed to do.

<a name=acid></a>
### ACID
[Atomicity](#at), [Consistency](#con), [Isolation](/System-Design/Concepts/Databases/Terms/Isolation), [Durability](#dur)

<a name=ans></a>
### Antisnubbing 
snub means ignoring someone or something. Time to time, a BitTorrent peer becomes choked/blocked by all peers from which it was receiving fragments because of poor download/upload capacity or absesnce of required fragments. 
- *Solution:* Finds a better peer than any of the current ones.

<a name=at></a>
### Atomicity (better word should be Abortibilty)
> Atomic means something that cannot be broken down into smaller parts.
- [Atomic in multi-threaded program](/Threads_Processes_IPC/Terms/README.md#at) is different from Atomic in Distributed Systems.
- In Distributed systems Atomic means
  - When Application is writing to DB and some fault occurs(process crash, LAN cable loose, Disk full) then application will not see DB in inconsistent state.
- **How to achieve Atomicity?**
- Using [Transactions](Transaction), ie when some transaction fails then its Aborted and DB comes in old state.

<a name=av></a>
### Availability
```c
--System------|
              |----------> Client-1
  ..          |
  node-n down |----------> Client-2
--------------|
```
- Any client which requests data gets a response even if some of the nodes are down (without guarantee that it contains the most recent version of information).
- Whole system is up, user can RW successfully irrespective if any node in the cluster is down.
- **Availabilty Problem** System is down and it cannot take requests and send responses.
  - [Availability patterns / Solutions](/System-Design/Concepts/Databases/Database_Scaling/)
    - *a.* Fail-over: Active-Passive/Master-Slave, Active-Active/Master-Master
    - *b.* Using Replication

<a name=auto></a>
### Autoscaling
In cloud, infrastructure can increase/decrese based on demand. 
<a name=howa></a>
#### How auto scaling works?
  - A group is defined in which similar VM instances are placed.
  - Policies are defined. Example:
    - _1._ Based on CPU Utilization. Autoscalar collects CPU Utilization of VM instances in group and decides to fork new/tear a VM based on that.
    - _2._ Scaling based on HTTP load etc

<a name=bw></a>
### Bandwidth
Theoritical maximum at which data can be tranferred over link. Practical is Throughput. 
- *Bandwidth Throttling:* Intentional slowing or speeding of an internet service by an Internet service provider (ISP). 
  - *Advantages?* To reduce bandwidth congestion, To reduce a user's usage of bandwidth.

- **Biased Neighbour Selection?** BitTorrent peer chooses most of its neighbors from the local ISP and only a few peers from other ISPs reducing traffic, this is assisted by [Tracker](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md). 
  - Tracker sends 35-k times peers from same ISP. Tracker uses Internet topology maps in autonomous system (AS) mappings to identify ISP boundaries.
- **[Bootstraping?](Bootstraping)** How new node enters into network(Basically Distributed File sharing network).
- **Broker,Super Peers:** As part of middleware layer, broker/super peer will facilitate communication b/w nodes(Weak peers). Super peer can attach to other super peer for replication. Weak peer can attach to another better super peer.

<a name=ba></a>
### BASE
Basically Available, Soft state, and Eventual consistency

<a name=csp></a>
### Clock Skew Problem
- **On 1 machine:** We can write `<key,value>` at timestamp=t1, then another write on on timestamp=t2, where t2>t1. DB can safely overwrite the original value.
- **Problem of clock skew on distributed system:**
  - Different clocks(on different machines) tend to run at different rates, so we cannot assume that time t on node a happened before time t + 1 on node b .
  - 

<a name=cap></a>
### CAP Theorem ([Consistency](#con) [Availability](#av) [Partition-Tolerance](#pt))
- CAP theorem says: Only 2 out 3 can be guaranteed.
  - _1. CA:_ data is consistent between all nodes - as long as all nodes are online 
  - _2. CP:_ When nodes are partitioned, then consistency can be achieved.
  - _3. AP:_ nodes remain online even if they can't communicate with each other

<a name=con></a>
### Consistency
```c
--System--|
          |----------> Client-1
  ..      |
          |---------> Client-2
----------|
```
- Means All clients will get(same, latest data) to whatever node they connect to in system.
- **Consistency Problem?** With mutiple databases doing sync([master slave](/System-Design/Concepts/Databases/Database_Scaling) etc), client should be returned accurate and most recent information.

#### Consistency patterns

|Type|What|Use case|
|---|---|---|
|1.Weak consistency|After a write, reads may or may not see it. A best effort is done.|<ul><li>1.Web-client:Ok to see past 1-2 min data.</li></ul>|
|2.Eventual consistency|After a write, reads will eventually see it (typically within milliseconds)||
|3.Strong consistency|After a write, reads will see it. Data is replicated synchronously|<ul><li>1.Stock Exchanges or auctions</li></ul>|

<a name=de></a>
### Deduplication 
- Eliminating duplicate or redundant information. Eg: How server identifies and drops duplicate packet when recieved.
- **End Game / End Mode:** To download all end fragments, Bittorrent client sends requests to all of its peers. As soon client gets the ending fragment it sends cancel to peers.

<a name=dur></a>
### Durability
- Once [transaction](Transaction) has been committed successfully(ie data is written to DB), then that data will not be forgotten, even in case of hardware fault/ database crashes
- **How to achieve Durability?**
  - On Single node system using SSD or Hard-disks. On multinode using [Replication](/System-Design/Concepts/Databases/Database_Scaling)

<a name=ft></a>
### Fault Tolerance
- In cluster of 100 machines, when some machines/disks fail, if system can still respond to client's queries then system is fault tolerant.
- **Methods to achive Fault Tolerance:**
  - [1. Replication](/System-Design/Concepts/Databases/Database_Scaling/1.Replication)_
  - [2. Sloopy Quorum](/System-Design/Concepts/Databases/Database_Scaling/1.Replication/README.md#qrw)
  - [3. Partitions in Kafka](/System-Design/Concepts/MOM_ESB/Apache_Kafka/README.md#pr)

- **Flooding:** Searching method in distributed enviornment. Node-1 floods data to be searched to all connected nodes. Generates Huge traffic. To mitigate traffic, TTL can be used.
- **Free Riding:** Having selfish peers who do not contribute to the [swarm](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md) just wanted to take file from swarm.
  - *Solution* Node will only send packet to that whose is in his [Neighbour set(NS)](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md)
    - Example: Swarm=User-2...User-10. User-1 decides to connect user-2 for file. Now User-2 will only send file to user-1 when user-1 is in swarm downloaded from Tracker server. It means User-1 is also sending fragments.

<a name=gp></a>
### [Gossip Protocol](https://www.educative.io/answers/what-is-gossip-protocol)
- Each node maintains State Information of other nodes.
```c
State information of node-A?
  - Is node-A alive(responding to heartbeat msgs)
  - What key range node-A hold?
```
- Each node share state information about (himself and nodes it knows about) with 1 random node every second or so.
- Each node monitors a small random subset of nodes and sends data to those.
- **Seed Node**
  - Seed node is a node(Similar to [Zookeeper](/System-Design/Concepts/Databases/Database_Scaling/Sharding/README.md#cs)) which are aware about presently active nodes in cluster.
  - In cluster, some nodes may join/leave and member nodes get this information from seed node

<a name=hk></a>
### Hot Key / linchpin objects
One key/node in database that is linked to millions of other keys/nodes in DB. Eg: Celebrities have many millions of followers.

<a name=la></a>
### Latency 
Latency is time that request is waiting to be handled ie awaiting service. [Response Time](#rt) means RTT.
#### How to reduce Latency
- _1._ For read heavy system, Add more Read Replicas in [Replication](/System-Design/Concepts/Databases/Database_Scaling/1.Replication).

<a name=lin></a>
### Linearizability
- This is recency(Means MOST Recent) gurantee. All replicas only return very recent data. ie System is very very Strongly consistent.

### Local Rarest First for Piece Selection
Nodes independently maintains a list of the fragments which are least number of copies amongst [swarm](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md). Whenever a new client joins in, he is given this list and he starts downloading the rarest fragment.

### Mutation? 
Writing data from client to server's memory/disk. Specifically mutation is an operation that changes the contents or metadata of a data. Example: Write, append in distributed file system is a mutation.
  - _Long Mutation:_ Not changing the data set longer time. Keeping data persistant for longer time.

### Optimistic Unchoking
- Unselfishly provide block(s) to node(s) in Neighbour set.
- Node uses a part of its available bandwidth for sending data to random peers, so that neighbours donot fall in tit for tat problem.

<a name=pacelc></a>
### PACELC Theorem (Partition Tolerance(P) Availability(A) Consistency(C) Else(E) Latency(L) Consistency(C))
- This is extension to CAP theorem.
- _Theorem:_ In case of network partitioned, one chooses AP or CP Else(E) even when the system is running normally in absence of partitions, one has to choose between latency(L) and consistency(C)

### Partition Tolerance 
The system continues to operate despite arbitrary partitioning due to network failures

### Path Folding / Location Swapping 
- During routing(finding route to node which has data), its important to find shortest/least cost path for scalability and efficiency.
- *Disadvantage:* Man In Middle can advertise route to destination, get connected and perform attacks.

### Policy Based Search
Node keeps track of neighbours who responded positively & sends request to them again

### Random Walk
Node selects k neighbours randomly, sends key-100(data to searched) to them, again those neighbours selects k neighbours.

<a name=re></a>
### Reliable
- **Meaning?** System to continue to work correctly, even when things go wrong.(Application crash, node(s) goes down under load)
#### How to make system Reliable?
- [1. Prevent node failures: Replication](/System-Design/Concepts/Databases/Database_Scaling/1.Replication/)
- _2._ Hard Disk Failure: RAID configuration

<a name=orc></a>
### Orchestration / Cloud Orchestrator
- Since process/microservices communicate via APIs. There should be some process to authenticate/authorize them.
- cloud Orchestrator is a process/microservice which does following on cloud:
  - Policy enforcement
  - Ensure process-1 has proper permission to connect to process-2 or execute some task on cloud.

<a name=pt></a>
### Partition Tolerance
- System continues to function even if there is a "partition" (communication break) between 2/more nodes (both nodes are up, but can't communicate).
- This is fault that breaks communication between nodes.
- Solution:[Replication](/System-Design/Concepts/Databases/Database_Scaling/1.Replication)

<a name=rt></a>
### Response Time
- Measured as a round trip time ie time taken for packet to reach dest and ACK to come to source again.
- The response time is what the client sees, includes (actual time to process the request (the service time), network delays and queueing delays).

<a name=sc></a>
### Scalability
- Means System behaves normally under increased load.
- **How to achieve scalabilty?**
  - [1. Sharding/Partitioning DB](/System-Design/Concepts/Databases/Database_Scaling)
  - [2. Autoscaling](#auto)

<a name=ser></a>
### Serializability
All [transactions](Transaction) must run serially on single object. Each transaction running to completion before the next transaction starts

<a name=sb></a>
### Split Brain
In [Master slave replication](/System-Design/Concepts/Databases/Database_Scaling/), When in any situation 2 nodes think themselves as masters/leaders the probelms start occuring and that is called split brain.

<a name=ten></a>
### Tenant
#### Single Tenant 
Seperate software binary, sepearate DB for each customer.
```c
Cust1   Cust1   Cust1
/\        /\      /\
\/        \/      \/
App       App     App
/\        /\      /\
\/        \/      \/
DB        DB      DB
```
#### Multi Tenant
Virtualization on cloud. Software, DB shared by all customers. [SaaS](/System-Design/Concepts) uses multi-tenant. Eg: Microsoft Suite, Dropbox, Google Apps.
```console
                   Cust1   Cust1   Cust1
                      |       |        |
                       -------|---------
                            App
                       -------|---------
                       |      |        |
                       DB    DB       DB
JAMS case:

  (site-1)JAMS_Kallactor-1 ------\
                                  \
  (site-2)JAMS_Kallactor-2 --------- JAMS-Sarver //This is Multi-tenant
                                   / 
  (site-3)JAMS_Kallactor-3 -------/
```

<a name=tp></a>
### Throughput
  - Rate of successful message delivery over a communication channel(Ethernet, wifi etc).
  - Measured in Bits/sec(bps), data packets per second (p/s or pps).
- **Tit for Tat Strategy:**  if the node-1 was cooperative, then node-2 is also cooperative. if node-1 is not cooperative then node-2 is also not.
