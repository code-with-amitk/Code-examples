- **Twitter?** Social networking site, where people can post short messages(called tweets 150 characters), follow other people etc.

## [To Cover](/System-Design/scalable)

## 1. Requirements
- **Functional**
  - *1.* User can post tweet text < 150 characters, photos, videos.
  - *2.* Any user can search any other user by name.
  - *3.* Any user can can Add himself as follower & can see the tweets(text,videos,photos) of followed person.
  - *4.* Mark Tweet as favoriate.
  - *5.* Retweets, replies.
- **Non-Functional:** S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
- **Extended:** Searching tweets, tagging other users, AI powered suggestion(whom to follow)

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

## 3. System APIs
- SOAP or REST APIs to expose the functionality of service.
```c
post_new_tweet(api_dev_key, tweet_data, tweet_location, user_location, media_ids)
  api_dev_key (string): The API developer key of a registered account. This will be used to, among other things, throttle users based on their allocated quota.
  tweet_data (string): The text of the tweet, typically up to 140 characters.
  tweet_location (string): Optional location (longitude, latitude) this Tweet refers to.
  user_location (string): Optional location (longitude, latitude) of the user adding the tweet.
  media_ids (number[]): Optional list of media_ids to be associated with the Tweet. (all the media photo, video, etc. need to be uploaded separately).
  
pointer_to_follower_struct `*`searchUser(toBeSearched_userId)

bool addFollower(toBeFollowed_id, follower's_id)
```

## 4. HLD
### D1. 5 Users design
> Approach gets slow for 100, 1k users

|Requirement|How Implemented?|
|---|---|
|1. Searching: user1 search user2|User's list is stored in `user-list.txt`. All users with name B would be shown to A.|
|2. Adding Follower| After sucessful search, click on button to add myself as follower of B.|
|3. Posting Tweet|user2 posts a tweet & stored in tweet-file+meta data. Each user has its seperate tweet-file|

<img src="https://i.ibb.co/jTbD4FK/tw2.png" alt="tw1" border="0">

### D2. 1 Million Users Design
- **1. User DB Table** Storing user information, people they are following, all self created tweets pointer.

| userID(uint) | username(varchar) | email | creationDate | lastLogin | Following(same as vector) | All created selfTweets |
| --- | --- | --- | --- | --- | --- | --- |
| amit1222 | amit | amit@greatest.com | <> | <> | person1,person2.. | 0x4581(takes from tweet-table-2) |
| test56 | test | test@sandbox.com | <> | <> | personx,persony.. | 0x891 |

**2. Tweet Table** stores all tweet IDs created by particular user

| UserName | Tweets //All self posted tweets | UniqueId/Address |
| --- | --- | --- |
| amit1222 | t1,t5,t6,t9 | 0x4581 |
| test56 | t3, t49, t89 | 0x891 |

- **3. Actual Tweet content** Can be stored on Object store.

| TweetId | tweet-content(varchar) | creationDate | userlattitude | userLongitude | ptr-to-Tweet |
| --- | --- | --- | --- | --- | --- |
| t5 | abcddefghij... | <> | <> | <> | 0x45912 |

**Tweetid** We don’t want to store tweet creation time separately, hence `TweetId = epochTime + autoIncrementInteger`

<img src="https://i.ibb.co/XzKZ1Rj/tw3.png" width="400" />

## E. Data Sharding
- UserId is passed to hash function, which gives DB server Id on which Tweet should be stored. All tweets of particular user are co-located. This helps in fanning out tweets to followers.
- Tweet is stored on DB server got in above step and address/pointer of stored tweet is returned. User's tweets can be stored on multiple servers.

## F. Replication
-  we can have multiple secondary database servers for each DB partition. Secondary servers will be used for read traffic only.
- All writes will first go to the primary server and then will be replicated to secondary servers. This scheme will also give us fault tolerance, since whenever the primary server goes down we can failover to a secondary server.

## F. User storing the tweet on server
![ImgURL](https://i.ibb.co/rsZvt8F/twitter1.png)

## G. Cache
- **1. Cache between Web-Server & Database Servers** 
  - Storing hot tweets and users. Eg: Memcached. Application servers, before hitting database, can quickly check if the cache has desired tweets.
  - Based on clients’ usage patterns we can determine how many cache servers are needed.
- **2. Cache at Web servers:** Most frequently used contents can be stored at this cache
### G2. Cache Eviction policy:
  - LRU(Least recently used) older tweets can be discarded.
### G3. Cache Storage policy (80-20 rule)
  - 20% of users will generate mostly used tweets, we need to store these tweets only in cache.
  
## H. Load Balancing
### H1. Places of adding load balancers
1. Between client and application servers
2. Between application servers & DB
3. Between Aggregation servers & cache servers.
### H2. Scheme of Load balancing
- Simple round robin.

## I. Monitoring
- Monitoring means collecting the data to find whether system is Dead/slow/active?
- Metrics/counters to get an understanding of the performance of our service:
  - New tweets per day/second, what is the daily peak? 
  - Timeline delivery stats, how many tweets per day/second our service is delivering
  - Average latency that is seen by the user to refresh timeline. 
