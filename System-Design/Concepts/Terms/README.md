- [Accuracy](#ac)
- [Antisnubbing](#ans)
- [Availability](#av)
- [Autoscaling](#auto)
  - [How auto scaling works?](#howa)
- [Bandwidth](#bw)
- [Consistency](#con)
- [CAP Theorem](#cap)
- [Deduplication](#de)
- [Fault Tolerance](#ft)
- [Flash Crowd](Flash_Crowd)
- [Latency](#la)
- [Orchestration](#orc)
- [Partition Tolerance](#pt)
- [Reliable](#re)
- [Response time](#rt)
- [Scalability](#sc)
- [Stream](/System-Design/Concepts/MOM_ESB/Apache_Kafka/#st)
- [Tenant](#ten)
- [Throughput](#tp)

<a name=ac></a>
### Accuracy
System is doing what's it's supposed to do.

<a name=ans></a>
### Antisnubbing 
snub means ignoring someone or something. Time to time, a BitTorrent peer becomes choked/blocked by all peers from which it was receiving fragments because of poor download/upload capacity or absesnce of required fragments. 
- *Solution:* Finds a better peer than any of the current ones.

<a name=av></a>
### Availability
- Access data from cluster even if any node in the cluster is down.
- OR Every request receives a response, without guarantee that it contains the most recent version of information. 
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

<a name=cap></a>
### CAP Theorem ([Consistency](#con) [Availability](#av) [Partition-Tolerance](#pt))
Only 2 out 3 can be guaranteed.

<a name=con></a>
### Consistency
- Data is the same across all clusters, so you read/write from/to any node and get the same data.
- OR With multiple copies of data maintained between master and replicas. Every read receives the most recent write or an error.
- **Consistency Problem?**
  - With mutiple databases doing sync([master slave](/System-Design/Concepts/Databases/Database_Scaling) etc), client should be returned accurate and most recent information.

#### Consistency patterns

|Type|What|Use case|
|---|---|---|
|1.Weak consistency|After a write, reads may or may not see it. A best effort is done.|<ul><li>1.Web-client:Ok to see past 1-2 min data.</li></ul>|
|2.Eventual consistency|After a write, reads will eventually see it (typically within milliseconds)||
|3.Strong consistency|After a write, reads will see it. Data is replicated synchronously|<ul><li>1.Stock Exchanges or auctions</li></ul>|


<a name=de></a>
### Deduplication 
Eliminating duplicate or redundant information. Eg: How server identifies and drops duplicate packet when recieved.

- **End Game / End Mode:** To download all end fragments, Bittorrent client sends requests to all of its peers. As soon client gets the ending fragment it sends cancel to peers.

<a name=ft></a>
### Fault Tolerance
In cluster of 100 machines, when some machines/disks fail, if system can still respond to client's queries then system is fault tolerant.

- **Flooding:** Searching method in distributed enviornment. Node-1 floods data to be searched to all connected nodes. Generates Huge traffic. To mitigate traffic, TTL can be used.
- **Free Riding:** Having selfish peers who do not contribute to the [swarm](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md) just wanted to take file from swarm.
  - *Solution* Node will only send packet to that whose is in his [Neighbour set(NS)](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md)
    - Example: Swarm=User-2...User-10. User-1 decides to connect user-2 for file. Now User-2 will only send file to user-1 when user-1 is in swarm downloaded from Tracker server. It means User-1 is also sending fragments.

<a name=la></a>
### Latency 
Latency is time that request is waiting to be handled ie awaiting service. [Response Time](#rt) means RTT.

- **Local Rarest First for Piece Selection**
  - Nodes independently maintains a list of the fragments which are least number of copies amongst [swarm](/System-Design/Scalable/Distributed_Downloading_Systems/BitTorrent/Terms.md). Whenever a new client joins in, he is given this list and he starts downloading the rarest fragment.
- **Mutation?** Writing data from client to server's memory/disk. Specifically mutation is an operation that changes the contents or metadata of a data. Example: Write, append in distributed file system is a mutation.
  - _Long Mutation:_ Not changing the data set longer time. Keeping data persistant for longer time.
- **Optimistic Unchoking:** Unselfishly provide block(s) to node(s) in Neighbour set.
  - Node uses a part of its available bandwidth for sending data to random peers, so that neighbours donot fall in tit for tat problem.
- **Partition Tolerance:** The system continues to operate despite arbitrary partitioning due to network failures
- **Path Folding / Location Swapping:** During routing(finding route to node which has data), its important to find shortest/least cost path for scalability and efficiency.
  - *Disadvantage:* Man In Middle can advertise route to destination, get connected and perform attacks.
- **Policy Based Search:** Node keeps track of neighbours who responded positively & sends request to them again
- **Random Walk?** Node selects k neighbours randomly, sends key-100(data to searched) to them, again those neighbours selects k neighbours.

<a name=re></a>
### Reliable
- System to continue to work correctly, even when things go wrong. Eg a application:
  - Can tolerate the user making mistakes or using the software in unexpected ways.
  - Its performance is good enough for the required use case, under the expected load and data volume.
  - The system prevents any unauthorized access and abuse.
#### How to make Hard-disk at datacenter Reliable?
- At datacenter, Hard disks crash, power grid has a blackout, someone unplugs the wrong network cable. 
- Hard disks have MTTF(mean time to failure) of about 10 to 50 years. Thus, on a storage cluster with 10,000 disks, we should expect on average one disk to die per day.
- How to keep reliabilty?
  - Add redundancy to the individual hardware components. Disks may be set up in a RAID configuration.
  - Servers may have dual power supplies and hot-swappable CPUs, and datacenters may have batteries and diesel generators for backup power. 
  - When one component dies, the redundant component can take its place while the broken component is replaced.

<a name=orc></a>
### Orchestration / Cloud Orchestrator
- Since process/microservices communicate via APIs. There should be some process to authenticate/authorize them.
- cloud Orchestrator is a process/microservice which does following on cloud:
  - Policy enforcement
  - Ensure process-1 has proper permission to connect to process-2 or execute some task on cloud.

<a name=pt></a>
### Partition Tolerance
Cluster continues to function even if there is a "partition" (communication break) between two nodes (both nodes are up, but can't communicate).

<a name=rt></a>
### Response Time
- Measured as a round trip time ie time taken for packet to reach dest and ACK to come to source again.
- The response time is what the client sees, includes (actual time to process the request (the service time), network delays and queueing delays).

<a name=sc></a>
### Scalability
- System’s ability to cope with increased load.
- Scalability means considering questions like “If the system grows in a particular way, what are our options for coping with the growth?” and “How can we add computing
resources to handle the additional load

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


