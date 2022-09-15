**Rate Limiter**
- Comparisons
  - [RL vs Load Balancer](#vs1)
  - [RL vs Reverse Proxy](#vs2)
- [Requirements](#r)
- [HLD](#h)
- [Algorithms](#a)

### Rate Limiter
#### What is RL
- Restricts number of incoming HTTP GET/REST API calls from client to server, which can overload the server.
  - Eg: Only 2 HTTP Posts/sec, 10 accounts creation allowed from same IP address.
  - Companies: Twitter allows 300 tweets/3 hours, Google docs 300 read users/1min.
- RL thortles(control) requests based on IP, user ID, other properties. RL can inform users who are thortled.
#### Advatanges of RL
- Prevents intentional,unintentional DDoS attacks.
- Reduces costs. if more requets come in, more servers will be spawned and more cost.
#### Types of RL
- **1. Client side:** We might not have much control over client side implementation.
- **2. Server side**

<a name=r></a>
### Requirements
#### Functional
- _1._ RL should thortle(block) 51st requests. ie only 50 requests/sec are allowed.
- _2._ RL should inform user who is thortled.
#### Non-Functional
- Highly available
- Low Latency. After placing RL system should return HTTP response in least time.

<a name=h></a>
### HLD
> journey of 1000 miles begins with 1 step
#### 1 requests/sec design
- Let our RL service only allows 1 req/sec, on 2nd it drops & send HTTP 429(too many requests) to client
```c
  HTTP-Client         RL-Service          Application
      |   --------->     |      -------->     |
      |
      |   --------->    
      |   <-HTTP429-
  
```
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
