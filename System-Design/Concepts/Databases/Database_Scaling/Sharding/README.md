**Partition / Shard(MongoDB,ElasticSearch) / Region(HBase) / Bigtable(Tablet) / vNode(Cassandra) / vBucket(CouchBase)**
- [Partitioning improves Scalabilty](#h)
- [Partitioning with Replication](#pr)
- **Types**
  - [1. By Keys Range](#kr) 
  - [2. By Hash of Keys](#hk)
  - [3. By Reverse indexes](#si)
- **Rebalancing Partitions**
  - [1. Fixed number of partitions](#r1)
  - [2. Dynamic partitioning](#r2)
- **Request Routing** 
  - [1. Round Robin](#rr)
  - [2. Routing Tier First](#rt)
  - [3. Direct Connect](#dc)
  - [4. Coordinator Service(Zookeeper)](#cs)
- **Terms**
  - [Skewed](#sk)
  - [Hotspot](#hs)

# Partitioning/Sharding
- Replication(Multiple copies of the same data on different nodes). For very large datasets, breaking the data & storing into partitions is called partitioning or sharding.
- Breaking the Huge data into pieces and storing on different servers.
```c
hello world come here

|hello|     |world|     |come|        |here|
node-1      node-2      node-3        node-4
```
<a name=h></a>
#### How Partioning achieves Scalabilty
- Different partitions can be placed on different nodes hence a large dataset is distributed across many disks, and the query load can be distributed across many machines/processors.
- With partitioning we speard query load evenly across nodes. That means 10 nodes should be able to handle 10 times read & write throughput wrt 1 node.

<a name=pr></a>
#### Partitioning with [Replication](/System-Design/Concepts/Databases/Database_Scaling/1.Replication)
- Keeping copies of each partition at multiple nodes improves fault tolerance.
- if master/slave replication is used with partitioning, Each node may be master for 1 dataset while slave for other
```c
  |             Node-1             |      |             Node-2             |
  |partition1 partition2 partition3|      |partition3 partition2 partition1|
  | (master)   (slave)    (slave)  |      | (master)   (slave)    (slave)  |
```

## Types
<a name=kr></a>
### 1. Partitioning by Key range
- Each partition/shard holds range of `<key, value>` for particular range.
- If we know which partition is assigned to which node, then we can make request directly to the appropriate node.
```c
       |Partition-1|   |Partition-2|   |Partition-3|
keys   |a-e        |   |f-o        |   |p-z        |
```
- **Adv:** Keys can be kept in sorted order inside the partition.
- **Disadv:**
  - _1. Certain types of keys can turn partition into [Hotspot](#hs):_
    - Example: if key=timestamp(and IoT devices sending data) and there is huge load in 1 hour then 1 shard will recieve all data, while other will sit idle.

<a name=hk></a>
### 2. Partitioning by Hash of Keys
- Hash function takes the key, generates the Hash. Hash is evenly distributed, even for very similar keys, different hash is generated. Hash points to a Partition.
- Hashes are evenly distributed and points to seperate shard. Each partition now holds range of hashes(rather than range of keys).
```c
  key -> |Hash Function| -> Hash
```
<img src=Partitioning_by_hash_of_keys.PNG width=500/>

- **Adv:**
  - _1. Reduced Hotspots:_ See Disadv of [Partitioning by Key range](#kr), that is removed. Since for similar keys different hashes are generated.
- **Disadv:**
  - _1. Range based key search property is lost._ ie Advantage of [Partitioning by Key range](#kr) is lost.
  - _2. Hotspots still exists:_ In extreme conditions, where keys differ by millisec, same hash gets generated and all load goes to same shard.

<a name=si></a>
### 3. Partitioning with [reverse/secondary indexes](/System-Design/Concepts/Databases/Indexing)
#### 3.1 Document Based / Per Node Indexing
- [keyword to key mapping](/System-Design/Concepts/Databases/Indexing) is created.
- if someone want to search keyword, all partitions need to be queried.

#### 3.2 Term Based / Global Indexing
- Rather than storing indexes on every partition, We can construct a global index that covers data in all partitions.
- We should not store that index on one node, since it would likely become a bottleneck and defeat the purpose of partitioning.
- Example:
  - Colors from `a to r` from all partitions stored at partition=0.
  - Colors from `s to z` stored on partition 1.
<img src=Partitioning_by_term.PNG width=600 />

- **Disadv:**
  - _1. Slower/complicated writes:_ Write to a single document(on 1 partition) may now affect multiple partitions of the index (every term in the document might be on a different partition, on a different node).

### Rebalancing Partitions
- if partition fails(as nodes do fail) then how to move data to other node? 
**Strategies for rebalancing**
<a name=r1></a>
#### 1. Fixed number of partitions
- Create more partitions on 1 node. In cluster of 10 nodes, create 1000 partitions. ie Every node contains 10 partitions.
- Whenever new node joins it takes few partitions from existing node(until partitions are fairly distributed once again).
<img src=rebalancing_fixed_no_of_partitions.PNG width=500/>

<a name=r2></a>
#### 2. Dynamic partitioning
> Eg: HBase, RethinkDB perform this.
- if partition size grows above threshold(HBase 10GB) it splits into 2 halves.
- Conversely, if lots of data is deleted and a partition shrinks below some threshold, it is merged with an adjacent partition.
- **Adv:** Adjusts to load. 
- **Disadv:** Until it hits the point at which the first partition is split, all writes processed to single node while the other nodes sit idle.

### Request Routing
How client sends/routes the request to a Parititon/Shard?
<a name=rr></a>
#### 1. Round Robin
- Allow clients to contact any node/partition (e.g. via a round-robin load balancer).
- If that node coincidentally owns the partition to which the request applies, it can handle the request directly; otherwise it forwards the request to the appropriate node.

<a name=rt></a>
#### 2. Routing tier first
- Send all requests from clients to a routing tier first, which determines the node that should handle the request and forwards it accordingly
- This tier is parition aware load balancer

<a name=dc></a>
#### 3. Direct Connect
Clients aware of partitioning and the assignment of partitions to nodes. Client can connect directly to the appropriate node, without any intermediary.

<img src=request_routing.PNG width=600/>

<a name=cs></a>
#### 4. Coordinator Service(Zookeeper)
- **Problem In Above 3 approaches:** How routing decision making component knows about changes in the assignment of partitions to nodes?
- Coordinator service(Zookeeper) will:
  - Keep track of cluster metadata(ie mapping of partitions to nodes)
  - Every node in cluster will register to Zookeeper.
- Examples: LinkedIn's Helix, HBase, SolrCloud and Kafka uses zookeeper.

<img src=zookeeper.PNG width=600 />

### Terms
<a name=hs></a>
#### Hotspot
Cluster has become highly [skewed](#sk), all load ends up on 1 partition. 9 out of 10 nodes are idle, and bottleneck is the 1 busy node. The partition with disproportion ately high load is called a hot spot.

<a name=sk></a>
#### Skewed
When partitioning becomes unfair some partitions have more data or queries than others. This makes the partitioning much less effective, this can lead to [hotspot](#hs)
