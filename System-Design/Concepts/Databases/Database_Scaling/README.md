**DB Scaling Techniques**
- [1. Replication](1.Replication)
- [2. Federation](#fed)
- [3. Sharding](Sharding)
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

## D. Denormalization
- Opposite to normalization, denormalization writes redundant copies to data to multiple databases. This improves reads wrt writes. Read:Write ratio increases to 1000:1.

## E. SQL Tuning
- Remove the bottlenecks of DB. Optimization those can be performed: Tighten the schema:Use CHAR for fixed length fields instead of VARCHAR, avoid storing large blobs(instead store their location addresses), 
