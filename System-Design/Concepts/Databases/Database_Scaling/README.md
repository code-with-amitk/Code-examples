**DB Scaling Techniques**
- [1. Replication](#repl)
  - [1.1 Master/Leader Slave](#ms)
  - [1.2 Master Master](#mm)
  - [1.3 Consistency problems in replication](#cp)
- [2. Federation](#fed)
- [3. Sharding](#shard)
- [4. Range Based Partitioning](#rbp)

<a name=repl></a>
# 1. Replication
Replication means keeping a copy of the **same data** on multiple machines. Each node that stores the copy is called Replica.

## Types of Replication
<a name=ms></a>
### 1.1 Master/Leader Slave
- 1 node is designated as Leader/master. Client does RW operations with master, and only Read on any of slave. If master goes down slaves serve as RO DB. Slaves can also replicate among themselves.
- **How it works**?
  - Master stores session in it'd DB 1st then master writes(or slave reads) data to replicas/slaves(as replication log or change stream).
  - Each slave takes the log from master and updates its local copy of the database in the same order as they were processed on the leader.
- **Disadv:**    
  - _a._ Logic is required to promote slave to master    
  - _b._ If high number of slaves, more write operations can lead to replication lag.
```c
//Write only to Master
                                       |-Write--> RO-SlaveReplica-DB-1
  client  ----Write----->  MasterDB ---|                           
                           /\          |-Write--> RO-SlaveReplica-DB-2
                           |                      /\
  client  ----Read---------|-----------------------|
//Read to Master or Replica(any)
```
<img src=master_slave.PNG width=600/>

<a name=mm></a>
### 1.2 Master-Master
- All databases in master-master can RW with client.
- **Disadv:** 
  - _a._ Load balancer maybe required in front to configure client where to send the requests.    
  - _b._ conflicts becomes more and more as more write nodes comes into picture.
```c
  client-1  <----RW------->    MasterDB
                                  |RW
  client-2  <----RW-------->  masterReplica-DB-1
```

<a name=cp></a>
### [1.3 Consistency Problem in Replication](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)

<a name=fed></a>
## 2. Federation/Functional Parition
- Splitting DB by functions. 
- **Adv:** 
  - _a._ Less RW to individual DB    
  - _b._ Less data in DB leads to more cache hits
- **Disadv:** 
  - *a.* Useless if schema requires huge tables.
  - *b.* Extra application logic required to determine which DB to be RW
  - *c.* Joining data from 2 DBs is complex.
```c
                                                 ----------------
                        |--user query-->         |   User-DB    |
  client    <--RW--->  -|                        |              |
                        |--product query->       |  ProductDB   |
                                                  --------------
```                                                                                           

<a name=shard></a>
## 3. Sharding
- Data is distributed across the databases, so that each DB only manages subset of data.
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

## D. Denormalization
- Opposite to normalization, denormalization writes redundant copies to data to multiple databases. This improves reads wrt writes. Read:Write ratio increases to 1000:1.

## E. SQL Tuning
- Remove the bottlenecks of DB. Optimization those can be performed: Tighten the schema:Use CHAR for fixed length fields instead of VARCHAR, avoid storing large blobs(instead store their location addresses), 
