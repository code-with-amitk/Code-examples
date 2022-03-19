**Memcached(In Memory Cache)**


## Memcached
- Open-source caching project using huge hash-table. It is helpful for websites caching data/objects in RAM from Databases. Can store upto 1 Million entries.
- **How it stores data?**
  - Stores data as <key,value> pair. Implemented as LRU. 
  - If the caching strategy is efficient, the number of trips to memcached wrt DB (10:1).  
  - cache aside/lazy loading? Only requested data is cached, which avoids filling up the cache with data that isn't requested.     https://software.intel.com/content/www/us/en/develop/articles/enhancing-the-scalability-of-memcached.html
- **Where it sits?** Anywhere between Web-server & DB.

### Architecture 
- Multiple servers work in conjunction to act as single larger logical data cache. 
```c
    Web-server/DB-Client                 DB-frontEnd        memCached(servers)    DB
                    -------query table1--->     -----table1---->
                                                <--NULL------
                                             --------query table1----------------->
                                           <-table1-     table1|expiry-time  <-table1-
```                                                                                    

### Data structures used by Memcached?
- a. Cache item: Data structure for holding the <key, data, flags, and pointers>
- b. Hash table: to locate a cache item. Implemented as Separate chaining
- c. Least Recently Used (LRU): determine cache item eviction order when the cache is full.
- d. slab allocator: Memory manager for cache item data structures.
```c
                                    cache-item-1 > cache-iten2 > NULL
                                       |
                                |    |    |    |    |    |    |    |
                                  0    1   ...                9   Hash-table
```                                  
