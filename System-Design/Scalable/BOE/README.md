**Back of Envelope / QPS+Storage**
- [Twitter](#t)

<a name=t></a>
### Twitter
#### QPS(Queries per second)
|World population|Internet users|DAU(Daily Active Users)|Active Users/sec (Tweets/sec)|Peak Day Tweets (`*2`)|
|---|---|---|---|---|
|7 Billion = 7x10<sup>9</sup>|40%=28x10<sup>8</sup>|(10% of Internet users)=280 Million=300M|300M/86400=300M/100000=3000|~6000|

#### Storage Estimates
- Average Tweet size: media(1M)+text(1KB)+TweetId(64bytes) = 1 MB
- Storage
  - Per day = 1M x 300M = 300 TB
  - Five year = 300TB x 5x365 = 300TB x 2000 = 600 PB

#### Number of Servers
> Assuming 1 server can cache is 1TB. 
- 600 PB/1TB = 600k servers (huge)
