**Partition / Shard(MongoDB,ElasticSearch) / Region(HBase) / Bigtable(Tablet) / vNode(Cassandra) / vBucket(CouchBase)**
- [Partitioning improves Scalabilty](#h)
- [Partitioning with Replication](#pr)

### Partitioning/Sharding 
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

### Terms
<a name=hs></a>
#### Hotspot
Cluster has become highly [skewed](#sk), all load ends up on 1 partition. 9 out of 10 nodes are idle, and bottleneck is the 1 busy node. The partition with disproportion ately high load is called a hot spot.

<a name=sk></a>
#### Skewed
When partitioning becomes unfair some partitions have more data or queries than others. This makes the partitioning much less effective, this can lead to [hotspot](#hs)


- **Adv:** a. Less data/DB hence more cache hits.
- **Disadv:** 
  - *a.* if 1 user or some users becomes hot, then a DB will become hugely loaded and other will remain empty.
  - *b.* If 1 DB goes down, replica should be up and running.
  - *c.* Complex SQL queries
  - *d.* Joining data from multiple shards is more complex.
```c
  ------------------         ------------------        -----------------          -----------------
  | db1 Users(A-G) |         | db2 User(F-L) |        | db3 Users(M-T) |         | db4 Users(U-Z) |
  ------------------         ------------------        ------------------         ------------------
```

<a name=rbp></a>
## 4. Range Based Partitioning
- One Database is used to store all keys starting from particular character.
- **Problem:** Since keys are generated on the fly, 1 DB can be hugely loaded and others are free.
  - *Solution:* [Consitent Hashing](/System-Design/Concepts/Hashing/Consistent_Hashing.md)
```c
  ---------------------------------     --------------------------------- 
  | Db-1 All-Keys(starting with A) |    | Db-2 All-Keys(starting with B) |    ..
  ----------------------------------    ----------------------------------
```
