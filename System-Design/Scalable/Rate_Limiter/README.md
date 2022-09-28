**Rate Limiter**
- Comparisons
  - [RL vs Load Balancer](#vs1)
  - [RL vs Reverse Proxy](#vs2)
- [Requirements](#r)
- [HLD](#h)
- [Algorithms](#a)

# Rate Limiter (API GW is RL)
#### What is RL
- Restricts number of incoming HTTP GET/REST API calls from client to server, which can overload the server.
  - Eg: Only 2 HTTP Posts/sec, 10 accounts creation allowed from same IP address.
  - Companies: Twitter allows 300 tweets/3 hours, Google docs 300 read users/1min.
- RL thortles(control) requests based on IP, user ID, other properties. RL can inform users who are thortled.
#### Advatanges of RL
- Prevents intentional,unintentional DDoS attacks.
- Reduces costs. if more requets come in, more servers will be spawned and more cost.
#### Types of RL
- **1. Client side:** We might not have much control over client side implementation, hence its not good place to keep RL.
- **2. Server side:** Good place to keep RL, bcoz we have full control.

<a name=r></a>
## Requirements
### Functional
- _1._ RL should thortle(block) 51st requests. ie only 50 requests/sec are allowed.
- _2._ RL should inform user who is thortled.
### Non-Functional
- Highly available/Fault Tolerant
- Low Latency. After placing RL system should return HTTP response in least time.

<a name=h></a>
## HLD
> journey of 1000 miles begins with 1 step
### 1 requests/sec design
- Let our RL service only allows 1 req/sec, on 2nd it drops & send HTTP 429(too many requests) to client
- Counters(How many requests allowed to go thru etc) stored in redis cache
```c                     
  HTTP-Client              RL-Service                   Cache(Redis)
      |   ---2req/sec--->       -------- 2 requests ------->
                                                      for requests:
                                                       if (counter>1)
                                                          reject
                                                       else {
                                                          counter++
                                                          send Allowed
                                                       }
                                <---- Allow 1 -----------
                              ------------------ req-1 -------------------> Application_Server
    <-HTTP429(too many req)- For req-2
```
### 1lac requests/sec design
#### RL can use **[Token Bucket Algorithm](https://github.com/amitkumar50/pvt-research/blob/master/Projects/3.Clear2Pay/Projects/2.LeakyBucket_TokenBucket_RTShaper/README.md)**
- _How many buckets needed?_ 
  - A. Thortle based on API Requests: 1 bucket/REST endpoint.
    - Endpoints Examples(Twitter): Post(), become_follower(), like_post()   //3 buckets, ie 1 per REST Endpoint
  - B. Thortle based on IP Address: 1 bucket/IP Address
  - C. Thortle incoming packets: 1 global bucket
#### RL Server Side Design
- RL will sit on seperate middleware. RL will be multithreaded application(multipod), all will communicate with same Cache(Redis)
- Counters(How many requests allowed to go thru etc) stored in redis cache
```c
Client            DNS
    - fb.com ->
 <- ip of nearst DC-
 ---------- HTTP GET -------> LB  -|---> RL-1(pod1) -|
                                   |                 |
                                   |---> RL-2(pod2) -|
                                                     |
                                                    Redis(Cache)
```
- **Available/Fault Tolerant:** Running RL on multipod (multi data center env).
- **Low Latency:** Multipod, multithreaded.
- **Monitoring:** After RL is running, it is important to gather analytics data to check whether the rate limiter is effective. Primarily, we want to make sure:
  - The rate limiting rules are effective, not too strict(many valid requests are dropped). In this case, we want to relax the rules a little bit. I
  - For flash crowd we may replace the algorithm to support burst traffic. Token bucket is a good fit here.
#### RL Client Side
- Use client cache to avoid making frequent API calls.
- Understand the limit and do not send too many requests in a short time frame.
- Include code to catch exceptions or errors so your client can gracefully recover from exceptions.
- Add sufficient back off time to retry logic.

### Design-2
#### Services
- **1. Client Identifier Builder Service:** This builds clientID based on clientIP, Port(or some combination that identifies the client)
- **2. Rules Retriever Service:** Every client is allowed x requests/sec, this is stored in cache
- **3. Rate Limiter Service:** Recieves client_id's key from client_id_builder service, checks in Cache
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
