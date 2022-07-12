**Rate Limiter**
- Comparisons
  - [RL vs Load Balancer](#vs1)
  - [RL vs Reverse Proxy](#vs2)
- [Requirements](#r)
- [HLD](#h)
- [Algorithms](#a)

### Rate Limiter
- Rate limiter blocks bots, or applications to overload web server(DoS Attack). Rate limiting can stop certain kinds of bot attacks.
- Because Application server has a limit to server x number of connections/sec. if more connections comes in server can crash.

<a name=r></a>
### Requirements
#### Functional
- _1._ System handles 50 requests/sec.
- _2._ System should return error if more than 50 requests are sent.
#### Non-Functional
Highly available, Latency should be minimum.

<a name=h></a>
### HLD
#### Services
- **1. Client Identifier Builder Service**
  - This builds clientID based on clientIP, Port(or some combination that identifies the client)
- **2. Rules Retriever Service**
  - Every client is allowed x requests/sec, this is stored in DB retrieved by this service
  - Stores rules in Memory
- **3. Rate Limiter Service**
  - Recieves client_id's key from client_id_builder service, checks in Cache
- **4. DB Handler Service:**
  - Frontend of DB which performs CRUD operations on DB
```c
    if(key is found in cache) {
      if (number_of_requests/sec > x)
        return Http error
    }
    else
      Ask from Rules Retriever
```
**Design**
```c
Client    internet        
      -----request------> |CLIENT_IDENTIFER_BUILDER_SERVICE|
                          1. Builds <key, client_id>
                                      -------------- key --------> |RATE_LIMITER_SERVICE|
                                                                   2. Checks rules in Cache ----> |Cache|
                                                                           <----- Rule Found--------
                                                                         if (requests/sec > x)
                                                                          Http Error Code
                                                                         else
                                                                          Allow
                                                                          
                                                                           <----- Rule not found----
                                                                   3. Get Rule for user
                                |RULES_RETRIEVER_SERVICE| <----- key -----
                                4. Is rule in Cache
                 |Cache| <------ key --
                      ------ miss ---->
                                5. Query DB for Rule
           |DB_HANDLER|<----- Key ----
  |Cache|<-- 6. Is rule
              in Cache
         --no->
  DB <-----  7. Read key
  |-->|Cache|
    |----------> Rules for user -------------------------------------> 8. Updates Cache
                                                                           if (rule==server_busy)
                                                                            Cache packet
                                                                           else if (server_free)
                                                                            Allow packet
                                                                           else if (server_unreachable)
                                                                            Drop Packet
                                                                                    ---- Rule ---> |FIREWALL|
```
<a name=a></a>
#### Algorithms
- **1. Sliding Window Protocol**
  - Application server will convey window size to Rate Limiter. Rate limiter will send packet as per window size.
- **2. Token Bucket Algorithm**
  - Rate Limiter or Application server will maintain a Token bucket, based on available tokens packets can be forwarded to Application server.
