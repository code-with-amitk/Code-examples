**Twitter**
- [1. Requirements](#r)
- [2. BOE](#boe)
- [3. System APIs](#sa)
- [4. HLD](#hld)
- [5. Database](#db)
- [6. Load Balancers](#lb)
- [7. Overall Tradeoffs/Bottlenecks & correction](#ot)
- [8. Adjusting to changing requirements](/System-Design/Concepts/Changing_Requirements)

**Twitter?**
Social networking site, where people can post short messages(called tweets 150 characters), follow other people etc. This is read heavy system.

## 1. Requirements
#### Functional
  - *1.* User can post tweet text < 150 characters, photos, videos.
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

|World Population|InternetUsers(60%)|Twitter users(50%)|Daily Active users(10~12%)|Only 50% users Tweet(text) daily|
|---|---|---|---|---|
|7 Billion //Year 2020|7 x 0.6 = 4.2 Billion|4.2 x 0.5 = 2 Billion |2 x .12 = 240 Million|240 x .5 = 120 Million Tweets/daily|
  
- **Storage Estimates:** 1 text Tweet=150 characters. 2 bytes to store 1 char. 1 Tweet=300 bytes.
  - Daily Text Tweets = 120M x 300 = 36GB. For 5 years = 36 x 30 x 12 x 5 = 64TB
  - (Audio=200KB, Video=2MB). 5% does photo Tweet. 1% does video tweet
    - Daily Audio Tweet = 240M x .05 = 12M. 12M x 200KB = 2.4GB
    - Daily Video Tweet = 240M x .01 = 2.4M. 2.4M x 200KB = 4.8GB

- **Bandwidth Estimates:** 
  - Writes/Incoming data. Daily Text=36GB, Audio=2.4GB, Video=4.8GB ~= 45GB. IncomingData/sec = 45/24x60x60 = 520KB/sec
  - Reads/Outgoing data. 
    - Assume user visits his timeline 2 times/day and watches 5 other people timelines and 10 tweets on their timelines. Total timelines viewed
      - 240M x (5+2) x 10 = 16800M = 17 Billion Tweets viewed/day. 1 tweet=300bytes. 17B x 300 ~= 5PB/day. 5PB / 24x60x60 = 57MB/sec

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

<a name=db></a>
## 5. DB 
#### DB Tables
```c
1. User Table: Storing user information, people they are following, all self created tweets.
  - Self created tweets would be stored in map<key=timestamp, value=<pointer where tweets is stored on object store, tweetid>

|userID| username(varchar)|email| creationDate | lastLogin | Following | All selfcreated Tweets |
| 111  |  amit | amit@test.com | <> | <>       | person1,person2..     | map<timestamp, <pointer_to_object_stored_tweet, tweet_id>> |

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
