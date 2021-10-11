**Twitter**
- [1. Requirements](#r)
- [2. BOE](#boe)
- [3. System APIs](#sa)
- [4. HLD](#hld)
  - [fanout](#fo)
- [5. Database](#db)
- [6. Load Balancers](#lb)
- [7. Overall Tradeoffs/Bottlenecks & correction](#ot)
- [8. Adjusting to changing requirements](/System-Design/Concepts/Changing_Requirements)

**Twitter?**
Social networking site, where people can post short messages(called tweets 150 characters), follow other people etc. This is read heavy system.

<a name=r></a>
## 1. Requirements
#### Functional
  - *1.* User can post tweet text < 150 characters, photos, videos.
  - _2._ User can view his Home timeline any number of times in a day.
  - *2.* Any user can search any other user by name.
  - *3.* Any user can can Add himself as follower & can see the tweets(text,videos,photos) of followed person.
  - *4.* Mark Tweet as favoriate.
  - *5.* Retweets, replies.
#### Non-Functional 
S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
#### Extended
Searching tweets, tagging other users, AI powered suggestion(whom to follow)

<a name=boe></a>
## 2. BOE Calculation //Near to grooking
```
World Population                    :     7 Billion //Year 2020
Internet users(60%)                 :     7 x 0.6 = 4.2 Billion
Twitter users(70%)                  :     4.2 x 0.7 = 2.94 Billion = 3 Billion
Daily Active users(20~25%)          :     3 x .25 = 750 Million
a. Daily Users posting tweets(80%)
  - Daily                           :     750 x .8 = 6000 Million Tweets/daily
  - Posted Tweets/sec               :     6000M/86400 => 6.9k requests/sec                            //WRITES
b. Daily home timeline view requests:     750M * 30 = 25000M    //every user requests home timeline min=3 to max=30 times.
  - Daily                           :     25 Billion requests/daily
  - Home Timeline view/sec          :     300k requests/sec                                           //READS, FANOUT

//Data Released by Twitter in 2012
Posted Tweets/sec                   :     4.6k requests/sec. 13k requests/sec at peak
Home timeline views                 :     300k requests/sec

//Assumed 2021(4-5 times)               
Posted Tweets/sec                   :     25k requests/sec. 75k requests/sec at peak
Home timeline views                 :     1500k requests/sec
```
  
**Storage Estimates:** 1 text Tweet=150 characters. 2 bytes to store 1 char. 1 Tweet=300 bytes.
- Daily Text Tweets = 6000M x 300 = 1.8TB. For 5 years = 1.8 x 30 x 12 x 5 = 1800TB
- (Audio=200KB, Video=2MB). 5% does photo Tweet. 1% does video tweet
  - Daily Audio Tweet = 6000M x .05 = 300M. 300M x 200KB = 60000TB = 60PB
  - Daily Video Tweet = 6000M x .01 = 60M.  60M x 200KB = 12000GB  = 12PB

**Bandwidth Estimates:** 
- Posting Tweets = Writes/Incoming data. Daily Text=1.8TB, Audio=60PB, Video=12PB. IncomingData/sec = 72PB/24x60x60 = 833MB/sec
- Writing on Timeline = Outgoing data = Fanout
  - Assumed timeline has 50-100 new entries everytime. 1 entry=150 character. 100 entries = 15k characters. 1 char=2 bytes. 15k=30k bytes.
  - User refreshes 3-30 times his hometime line daily. 30times = 900kbytes/user
  - 300k/requests/sec = 900k * 300k = 270000M = 270GB/sec (fanout)

<a name=sa></a>
## 3. System APIs
SOAP or REST APIs to expose the functionality of service.
```c
post_new_tweet(api_dev_key, tweet_data, tweet_location, user_location, media_ids)
  api_dev_key (string): The API developer key of a registered account. This will be used to, among other things, throttle users based on their allocated quota.
  tweet_data (string): The text of the tweet, typically up to 140 characters.
  tweet_location (string): Optional location (longitude, latitude) this Tweet refers to.
  user_location (string): Optional location (longitude, latitude) of the user adding the tweet.
  media_ids (number[]): Optional list of media_ids to be associated with the Tweet. (all the media photo, video, etc. need to be uploaded separately).
  
pointer_to_follower_struct *searchUser(toBeSearched_userId)

bool addFollower(toBeFollowed_id, follower's_id)
```

<a name=hld></a>
## 4. HLD
- *1-6.* Same as [Facebook news feed](/System-Design/Scalable/facebook/News%20Feed).
- *7.* Webserver will provide UI to user and Application server will search DB Updater and push on its [MOM](/System-Design/Concepts/MOM_ESB).
- *8.* DB Updater will store Tweet on Object store and update UserTable on meta-data server SQL. DB Updater will push on userId, timestamp on ACK Sender service MOM.
  - Meta-data is data about data. Eg: For each tweet meta-data can be Userid, timestamp, tweetid.
- *9.* ACK sender service will get connection information from conn_db and send ACK to Application.

<img src=Twitter.jpg width=1000 />

<a name=fo></a>
#### Fanout
- _1._ UserId=x posts a tweet. Cache is maintained for all users following userid=x. See [DB tables](#db)
- _2._ Push tweet to follower's timeline using web api.
- **Celebrity case (40M followers or above)**
  - if we try to write tweet to all followers, we need to write single tweet 40M times.
  - Solution: Fetch celeb tweet seperately and merge with follower's timeline

<a name=db></a>
## 5. DB 
#### DB Tables
```c
1. User Table: Storing user information.
| userID | screen_name | Actual_name | profile_image |
|  1     | celeb       | celeb       | test.jpg      |
|  2     | amit        | amit        | test1.jpg     |

2. Tweets table: Cache of each user having tweets of all users he's following.
- Maintain a cache for each user’s home timeline which is like a mailbox of tweets for each recipient user. 
- When a user posts a tweet, look up all the people who follow that user, and insert the new tweet into each of their home timeline caches. 
- The request to read the home timeline is then cheap, because its result has been computed ahead of time.
|user id | pointer|
| 2      |  0xabc |
| 3      |  0xdef |

| userId | tweet_done_by | Tweet Text | timestamp |
| 2      |    1 (celeb)  |  ...       | ..        |
0xabc
```

#### Storing Tweets(text,photos,videos)
can be stored on [Shard-DB](/System-Design/Concepts/Databases/Database_Scaling) based on userId, TweetId. But all approaches has issues
  - *a.* As mentioned in [Shard-DB Disadv point-a](/System-Design/Concepts/Databases/Database_Scaling).
  - *b.* if we shard by userId and try generating timeline. App server need to visit every shard and will create latency.
    - We can create tweetID = timestamp+tweetid = xxx 0001
- **[Replication](/System-Design/Concepts/Databases/Database_Scaling):** Master slave
#### Cache 
Application servers, before hitting database, can quickly check if the cache has desired tweets. Memcache
  - [Where Cache can be placed?](/System-Design/Concepts/Cache) 
  - [Cache Eviction LRU](/DS_Questions/Questions/Random/LRUCache)
  - Cache Storage policy (80-20 rule): 20% of users will generate mostly used tweets, we need to store these tweets only in cache.

<a name=lb></a>
## 6. Load Balancers
  - [Where Load Balancer can be placed?](/System-Design/Concepts/Load_Balancer)
1. Between client and application servers
2. Between application servers & DB
3. Between Aggregation servers & cache servers.

<a name=to></a>
## 7. [Overall Tradeoffs/Bottlenecks & correction](/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)
- *1.* If high number of clients are connected system may respond slow.
  - *Solution:*
    - Provide MOM between Application server & clients which will queue client requests.
    - Provide MOM between synchronization server & clients. MOM can queue millions of requests.
- *2.* Sharding based on Hash of tweetid/userid can fail on overloaded environment.
  - Solutions: 
    - Consistent hashing
    - Monitoring the load using [Artificial Intelligence](https://sites.google.com/site/amitinterviewpreparation/machine-learning) based models, New tweets per day/second, what is the daily peak, Timeline delivery stats, how many tweets per day/second our service is delivering, Average latency that is seen by the user to refresh timeline.
  - *3.* Efficient timeline generation system
    - *Solution:* fb news feed timeline generation
  - *4.* Effective tweet ranking solution?
  - *5.* Suggestion to user for Whom to follow? 
    - This feature will improve user engagement. We can suggest friends of people someone follows, Famous people for the suggestions, people having more followers. As only a few suggestions can be made at any time, use Machine Learning (ML) to shuffle and re-prioritize
  - *6.* How to show top news? 
    - Use crawler to search (news, support, financial, entertainment, etc.) use [ML – supervised learning or Clustering](https://sites.google.com/site/amitinterviewpreparation/machine-learning).

## 
