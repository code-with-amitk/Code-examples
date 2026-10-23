**Rate Limiter**
- Comparisons
  - [RL vs Load Balancer](#vs1)
  - [RL vs Reverse Proxy](#vs2)
- [Requirements](#r)
- [HLD](#h)
- [Algorithms](#a)

# Rate Limiter 

<a name=r></a>
## Requirements
### Functional
- _1._ RL should thortle(block) 51st requests. ie only 50 requests/sec are allowed.
- _2._ RL should inform user who is thortled.
### Non-Functional
- Highly available
- Low Latency. After placing RL system should return HTTP response in least time.

<a name=h></a>
## HLD
### 1 requests/sec design
```c                     
  HTTP-Client              RL-Service                   Cache(Redis)
      |   ---HTTP GET--->       -------- HTTP GET ------->
                                                       if (counter>1)
                                                          reject
                                                       else {
                                                          counter++
                                                       }
                                <---- Allow -----------
                              ------------------ HTTP GET -------------------> Application_Server
      |   ---HTTP GET--->       -------- HTTP GET ------->
                                                        (counter==1)
                                                            drop
    <-HTTP429(too many req)-
```
### 1lac requests/sec design
#### RL can use **[Token Bucket Algorithm](https://github.com/amitkumar50/pvt-research/blob/master/Projects/3.Clear2Pay/Projects/2.LeakyBucket_TokenBucket_RTShaper/README.md)**
#### RL Server Side Design
- RL will sit on cache
- Counters(How many requests allowed to go thru etc) stored in redis cache
```c
Client            
 ---------- HTTP GET -------> LB  -|---> RL-1(pod1) -|
                                   |                 |
                                   |---> RL-2(pod2) -|
                                                     |
                                                    Redis(Cache)
```
