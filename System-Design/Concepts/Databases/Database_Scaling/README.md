# DB Scaling Techniques

## A. Replication
### Types of Replication
- **1. Master Slave:** Client does RW operations with master DB, master writes data to replicas/slaves. If master goes down slaves serve as RO DB. Slaves can also replicate among themselves.
  - **Disadv:**    a. Logic is required to promote slave to master    b. If high number of slaves, more write operations can lead to replication lag.
```c
                               |-----Write-------->  RO-SlaveReplica-DB-1
  client  <----RW------->  MasterDB                            
                               |-----Write---------> RO-SlaveReplica-DB-2
```

- **2. Master-Master:** All databases in master-master can RW with client.
  - **Disadv:** a. Load balancer maybe required in front to configure client where to send the requests.    b. conflicts becomes more and more as more write nodes comes into picture.
```c
  client-1  <----RW------->    MasterDB
                                  |RW
  client-2  <----RW-------->  masterReplica-DB-1
```
### [Consistency Problem in Replication](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)

## B. Federation/Functional Parition
- Splitting DB by functions. 
- **Adv:** a. Less RW to individual DB    b. Less data in DB leads to more cache hits
- **Disadv:** a. Useless if schema requires huge tables.    b. Extra application logic required to determine which DB to be RW    c. Joining data from 2 DBs is complex.
```c
                                                 ----------------
                        |--user query-->         |   User-DB    |
  client    <--RW--->  -|                        |              |
                        |--product query->       |  ProductDB   |
                                                  --------------
```                                                                                           

## C. Sharding
- **What?** Data is distributed across the databases, so that each DB only manages subset of data.
- **Adv:** a. Less data/DB hence more cache hits.
- **Disadv:** a. If 1 DB goes down, replica should be up and running.    b. Complex SQL queries    c. Joining data from multiple shards is more complex.
```c
  ------------------         ------------------        -----------------          -----------------
  | db1 Users(A-G) |         | db2 User(F-L) |        | db3 Users(M-T) |         | db4 Users(U-Z) |
  ------------------         ------------------        ------------------         ------------------
```

## D. Range Based Partitioning
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
