**DB Scaling Techniques**
- [1. Replication](1.Replication)
- [2. Federation](#fed)
- [3. Sharding](#shard)
- [4. Range Based Partitioning](#rbp)

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
