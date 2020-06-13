## ElastiCache
  - **What**
    - This is a web service acting as in-memory cache in the cloud.
    - This improves the performance of web applications by allowing you to retrieve information from fast, managed
    - Caching improves application performance by storing information/data that is most often queried by the end user
  - **Compliant with memcached, redis**
    - Mem cached: A widely adopted memory object caching technology
    - Redis is a open-source in-memory key-value store that supports data structures like lists.
  - **Replication Support**
    - supports master-slave replication
    -  multi-AZ deployments
    
### Architecture
```
  Client
  
  mobile  <------>  [ELB]   <------>  [App-server]        <--------->   [mySQL-DB]
  PC                                   ElastiCache-master
                                       ElastiCache-slave
```
