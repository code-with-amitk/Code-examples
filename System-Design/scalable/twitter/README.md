| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

# [To Cover](https://github.com/amitkumar50/Code-examples/tree/master/System-Design/scalable)

## A. Requirements
- **A1. Functional**
  - *1.* User can post tweet < 150 characters.
  - *2.* Any user can search any other user by name.
  - *3.* Any user can can Add himself as follower & can see the tweets(text,videos,photos) of followed person.
  - *4.* Mark Tweet as favoriate.
  - *5.* Retweets, replies.
- **2. Non-Functional:** S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F

## B. System APIs

|Search user|Add follower|Posting tweet|
|---|---|---|---|
|pointer_to_follower_struct `*`searchUser(toBeSearched_userId)|bool addFollower(toBeFollowed_id, follower's_id)|<ul><li>string publishTweet(tweet_message, *tweet_photo, *tweet_video, userId, user_location)</li></ul><ul><li>Parameters: userLocation(optional): (Lattitude, Longitude) of user adding the tweet</li></ul><ul><li>Return: Location to stored tweet, else HTTP error.</li></ul>|

## C. BOE Calculation
  - World population = 8 Billion
  - Internet users = 40% = 8 x .4 = 3.2
  - Twitter users = 10% = 0.32 Billion 
  
- **Storage Estimates**
  - 1 tweet/day. 320 x 1 = 320 Million
  - Each Text tweet = 150 characters. 1 character takes 4 bit of storage. 75 bytes/tweet. 0.32 x 75 = 24 GB/day. 24x30x12x5 = 43 TB/5years
  - Each Photo tweet. Size=200kB. .32 x 200k = 6.4 TB/day. 6.4x30x12x5 = 11 PB/5 years      //But users tweeting photos would be lesser.
  - Each Video tweet. Size=2MB. .32 x 200k = 6.4 TB/day. 6.4x30x12x5 = 11 ExaBytes/5 years. //But users tweeting videos would be lesser.
  - **Total bytes stored for 5 years:** 12 Exa bytes/5 years
- This is read heavy system, since much higher data is read wrt written to the system.

# D. HLD/DESIGN & DB SCHEMA
### D1. 5, 100, 10k Users Design
  1. **Searching for users** A(normal person) want to search B(politician). 
     - User's list is stored in `user-list.txt`. All users with name B would be shown to A.
  2. **Adding myself as follower**
     - After sucessful search, click on button to add myself as follower of B.
  3. **Posting Tweet** 
     - User-2(politician) posts the tweet. 
     - Tweets are stored in a tweet-file, with meta data. Each user has its seperate tweet-file.
     - Tweet+metadata is pushed to followers using above vector.

| Design | Searching for User | Adding myself as follower | Posting a Tweet |
| --- | --- | --- | --- |
| 5 Users(A,B,C,D,E) | LL of user_info structs=5 | struct user_info (see below) | 5 files storing tweets of 5 users (see below) |
| 100 Users | LL of user_info structs. size=1000 | vector size=1000 | 100 files |
| 10k Users | File search is slow | Huge vector, may not handle | 10k files immposible to maintain |

<img src="https://i.ibb.co/jTbD4FK/tw2.png" alt="tw1" border="0">

```
2. ADDING MYSELF AS FOLLOWER
struct user_info{
  vector<STRUCT followers> f;   //List of followers of this user
  uint selfUserId;
  string username;               //self username
  file1 *ptr;                   //All self posted tweets
  file2 *ptr;                   //my home timeline
};
f.push_back(user-1);

3. POSTING THE TWEET
  [File-B]
    meta-data + Tweet-1
    meta-data + Tweet-2
    
  [File-A]    
```

### D2. 1 Million Users Design
  - **Old Structure Based Design**
    - LL size becomes 1 million. 
      - Very slow in searching. if some user tweeted and system want to post on follower's timeline.
    - 2 million files
      - RW slow.
    - if each user follows 5 people, 5 million vector space.
  - **Migrate to New DB based design**
    - **User Table** (Replaces LL of user_info struct)
      - Storing user information, people they are following, all self created tweets pointer.
    - **Tweets Table-1** (Replaces files for storing tweets)
      - Stores the actual tweet content in varchar format.
    - **Tweet Table-2** 
      - Stores all tweets created by particular user.
      
 **USER TABLE**
 
| userID(uint) | username(varchar) | email | creationDate | lastLogin | Following(same as vector) | All created selfTweets |
| --- | --- | --- | --- | --- | --- | --- |
| amit1222 | amit | amit@greatest.com | <> | <> | person1,person2.. | 0x4581(takes from tweet-table-2) |
| test56 | test | test@sandbox.com | <> | <> | personx,persony.. | 0x891 |

- **Following** people can be stored on Graph Datastructure(Eg: Neoj4).


 **TWEET TABLE-1** Stores actual tweet content
  
| TweetId | tweet-content(varchar) | creationDate | userlattitude | userLongitude | ptr-to-Tweet |
| --- | --- | --- | --- | --- | --- |
| t5 | abcddefghij... | <> | <> | <> | 0x45912 |

**Tweetid** We don’t want to store tweet creation time separately, hence `TweetId = epochTime + autoIncrementInteger`


**TWEET TABLE-2** stores all tweet IDs created by particular user

| UserName | Tweets //All self posted tweets | UniqueId/Address |
| --- | --- | --- |
| amit1222 | t1,t5,t6,t9 | 0x4581 |
| test56 | t3, t49, t89 | 0x891 |
  
**Big Picture**

![ImgURL](https://i.ibb.co/XzKZ1Rj/tw3.png)  

# E. DATA SHARDING
- UserId is passed to hash function, which gives DB server Id on which Tweet should be stored. All tweets of particular user are co-located. This helps in fanning out tweets to followers.
- Tweet is stored on DB server got in above step and address/pointer of stored tweet is returned.
- User's tweets can be stored on multiple servers.
- ***Replication*** 
  -  we can have multiple secondary database servers for each DB partition.
  - Secondary servers will be used for read traffic only.
  - All writes will first go to the primary server and then will be replicated to secondary servers. 
  - This scheme will also give us fault tolerance, since whenever the primary server goes down we can failover to a secondary server.

# F. USE CASES
### F1. User storing the tweet on server
![ImgURL](https://i.ibb.co/rsZvt8F/twitter1.png)

# G. CACHE
### G1. Caches can be placed at:
**1. At Database Servers** 
  - Storing hot tweets and users. Eg: Memcached.
  -  Application servers, before hitting database, can quickly check if the cache has desired tweets.
  - Based on clients’ usage patterns we can determine how many cache servers are needed.
**2. Application servers**
  - Most frequently used contents can be stored at this cache
### G2. Cache Eviction policy:
  - LRU(Least recently used) older tweets can be discarded.
### G3. Cache Storage policy (80-20 rule)
  - 20% of users will generate mostly used tweets, we need to store these tweets only in cache.
  
# H. LOAD BALANCING
### H1. Places of adding load balancers
1. Between client and application servers
2. Between application servers & DB
3. Between Aggregation servers & cache servers.
### H2. Scheme of Load balancing
- Simple round robin.

# I. MONITORING
- Monitoring means collecting the data to find whether system is Dead/slow/active?
- Metrics/counters to get an understanding of the performance of our service:
  - New tweets per day/second, what is the daily peak? 
  - Timeline delivery stats, how many tweets per day/second our service is delivering
  - Average latency that is seen by the user to refresh timeline. 
