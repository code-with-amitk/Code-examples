# Distributed Cache / Cooperative Cache
> Eg: [Redis](/System-Design/Concepts/Cache/DB_Caches/Redis/README.md), [Memcached](/System-Design/Concepts/Cache/DB_Caches/Memcached/README.md)
- **What** Cache is faster than Hard-disk or DB, because its size is small(wrt hard disk) hence search time is less. Cache stores recent queries only.
- **Place where cache can be placed?** Consider twitter Application example.
  - *1.* On Web Proxy serving Web client.
  - *2.* Between Web server & database.
  - *3.* Before web-server, to serve recent contents.
```c 
 App/Webserver --- Cache -- Database
 Loadbalabncer --- Cache -- WebServer
```

## 1. [Requirements](/System-Design/Scalable)
- **Functional**
  - *1.* Store recent data
  - *2.* Low latency. (Latency: Delay between last packet sent and 1st packet received)
- **Non-Functional:** Consistent, Should be distributed
- **Extended**

## 2. [BOE](/System-Design/Scalable/twitter/README.md)
- Assuming Cache is deployed at twiteer. BOE same as twitter
- **Traffic Estimates**: same as twitter
- **Storage Estimates:**
  - 1 Machine can store 10TB to 50TB.
  - Number of machines required to build Distributed cache = (Total storage for 1 day = 300TB)/10TB = 300-400. 
- **Latency** 1ms (GET or POST)
  
# 3. HLD
- **3a. Where Cache Fits?**
- Cache will only be used during fannout of tweets, ie updating timelines. While storing tweets to DB cache will only be updated.
<img src="Distributed_Cache_overall.png" width="1000" />

- **3b. [Places where cache fits](/System-Design/Concepts/Cache/Where_Cache_Can_Be_Placed/README.md)**
  
- **3c. [Distributed Cache:Memcached](/System-Design/Concepts/Cache/Where_Cache_Can_Be_Placed/README.md)**
  - [1. Cache Purging: LRU](/DS_Questions/Questions/random/LRUCache/lru_cache_key_and_value.md)
    - LRU uses Doubly Linked List and Hash Table to achieve O(1) for search/insert/remove `<key=priority,value=Address>`
  
- **[Types of Cache](/System-Design/Concepts/Cache)**

## 4. [Tradeoffs/Bottlenecks of Distributed systems and overcoming bottlenecks](/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)

## [5. Adjusting to changing requirements](/System-Design/Concepts/Changing_Requirements)
