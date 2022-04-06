**ElastiCache**
- [Architecture](#ar)


## ElastiCache
- Web service acting as in-memory cache in the cloud. 
- This improves the performance of web applications by allowing you to retrieve information from fast, managed store.
- ElasticCache supports two types of data stores: Redis and Memcached: memcached, redis
- **Replication Support** supports master-slave replication, multi-AZ deployments

<a name=ar></a>
### Architecture
```c
  Client
  
  mobile  <------>  [ELB]   <------>  [App-server]        <--------->   [mySQL-DB]
  PC                                   ElastiCache-master
                                       ElastiCache-slave
```
