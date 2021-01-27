| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

## Distributed Cache 
> Eg: Redis, Memcached
- **What** Cache is faster than Hard-disk or DB, because its size is small(wrt hard disk) hence search time is less. Cache stores recent queries only.
- **Place where cache can be placed?**
  - *1.* Between Web server & database.
  - *2.* Before web-server, to serve recent contents.
```c
 App/Webserver --- Cache -- Database
 Loadbalabncer --- Cache -- WebServer
```

## [To Cover](https://github.com/amitkumar50/Code-examples/tree/master/System-Design/scalable)

## 1. Requirements
- **Functional**
  - *1.* Store recent data
  - *2.* Low latency. (Latency: Delay between last packet sent and 1st packet received)
- **Non-Functional:** Consistent, Should be distributed
- **Extended:** S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F

## 2. BOE
- World Population: 8 Billion (2021). 
- 60% use internet. 8 x.6 = 4.8 Billion users/day.
- 30%(let's assume) have Twitter accounts = 4.8 x .3 = 1.34 Billion users
- {Note} Twitter's Limit: 2400 Tweets/day
- Activities per day(on twitter):
  - *1.* Tweets per day:
    - 50% post 1 to 5 Tweet/day. Considering 5 tweets = 1.34 x .5 x 5 = 3.35
    - 1% post 20-25 Tweets/day. Considering 25 tweets = 1.34 x .1 x 25 = 3.35
    - Total tweets = 6.7 Billion
  - *2.* Re-tweets per day: Assuming people retweet 20% of tweets. 6.7 x .2 = 1.34 Retweets / day
  - **Total API calls/Day** 2.01 + 1.005 = 8.04 Billion Tweets/Retweets per day  
  
### Traffic Estimates
  - Twitter will use SSL to encrypt traffic. See [Header Sizes](https://github.com/amitkumar50/Code-examples/blob/master/networking/OSI-Layers/README.md)
### Storage Estimates

#### 2a. QPS(Queries Per second)
  - 10 Million (twitter, google has this data)
#### 2b. Distributed Cache size = 30 TB
  - 1 Machine can have 72GB or 144GB (twitter, google).
  - Number of machines required to build cache = 30 TB / 72G = 420 machines(minimum)
#### 2c. Latency  
  - Latency: 1ms (GET or POST)
  
## 3. HLD
### 3a. 1 User/1 Thread
- [LRU Cache](https://github.com/amitkumar50/Code-examples/blob/master/ds_questions/questions/random/LRUCache/lru_cache_key_and_value.md)

### 3b. 100-1Lac Users
