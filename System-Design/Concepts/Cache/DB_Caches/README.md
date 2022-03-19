**DB In Memory Caches**
- [Where DB Cache sits](#w)
- [Memcached vs Redis](#vs)
  
### DB Caches
Examples: Redis, Memcached, AWS Elastic Cache

<a name=w></a>
#### Where DB Cache sits
```c
                                                            Redis/
    Web-server/DB-Client                 DB-frontEnd        memCached(servers)    Databases
                    -------query table1--->     -----table1---->
                                                <--NULL------
                                             --------query table1----------------->
                                           <-table1-     table1|expiry-time  <-table1-


	                 |- |Web Server-1| -------\        Server-1             DB-1
  ---------------  |                         \          |                  |
  |Load-Balancer|- |- |Web Server-2| ------> DB-Cache(redis)/Server-2 --- DB-2(Postgres)
  ---------------  |                         /          |                  |
                   |- |Web Server-n| -------/       Server-n              DB-n
```

<a name=vs></a>
#### Memcached(in Memory) vs Redis(in Memory)
||Memcached|Redis(Recommended bcoz of speed)|
|---|---|---|
|Key-value pair| y (key<250B, value<1MB)| y (key<512MB, value<512MB)|
|Overhead|less. It does not have any inbuilt datatypes|More. Bcoz it supports datatypes as(string,hash,list,set)|
|opensource | y | y |
|Language|C|C|
|How internally implemented|Slab Allocator|encapsulated version of the malloc/free|
|Scaling|Multi-threaded. Scales vertically. Give more cores, more memory|Single Threaded. Scales horizontally|
|Replication||2 slave nodes with master|
|Cache Eviction policies|Only 1(LRU)|6 different policies|
|Speed|less|more(since it supports different datatypes)|
