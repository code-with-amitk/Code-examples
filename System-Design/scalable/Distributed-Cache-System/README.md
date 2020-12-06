| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

# Distributed Cache (Redis, Memcached)
- **What** software between web server and database, which sores most recent qeuries. Since cache returns data from main-memory(RAM/hence fast) wrt DB(hard disk)
```c
[App/Webserver] <--->[Cache]<-->[Database]
```

## 1. Requirements
1. S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F (Scalable, Secure, SOA, Logging, Load, Latency, Cache(Invalidation, negative cache), Available, Accurate, Analyze, Authenticate
Reliable, Redundant(Using DB), Fast)
2. store recent data
3. distributed for Google, Twitter

## 2. BOE
### 2a. QPS(Queries Per second)
  - 10 Million (twitter, google has this data)
### 2b. Distributed Cache size = 30 TB
  - 1 Machine can have 72GB or 144GB (twitter, google).
  - Number of machines required to build cache = 30 TB / 72G = 420 machines(minimum)

/////////1. BOE CALCULATIONS///////////////
- Store terabytes of data (10pow12)
- Read/Write Requests: 50k - 1M/sec
- Latency: 1ms (GET or POST)
- Eviction: LRU
- Availability: 100%
- Scalable

