## Places where Load Balancers can be placed?
- *1.* Between client and Application servers.
  - Each application server might be serving some subset of users. LB will forward request to appropriate AS.
```html
    App-server1
    App-server-2    Load-Balancer         client
    App-server-n
```
- *2.* Between App-servers and cache. Since we can have 100s of cache servers, those needed load balancing.
- *3.* Between cache and DB servers. Since DB servers can be upto 256 LB in front of it is good.
