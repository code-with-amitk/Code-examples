# Twitter Design

## A. REQUIREMENTS
### 1. FUNCTIONAL
  1. **Search**
     - Any twitter user can search any other twitter user by name.
  2. **Adding myself as Follower**
     - Let's suppose user-1 searches user-2, then user-1 can add himself as follower of user-2.
     - User-1 can see the tweets(text,videos,photos) of people he follow on their timeline.
     - Any user can mark any tweet as favourite.
     - User can reply to tweets.
  3. **Posting Tweets**
     - Any user can post tweet < 150 characters.
     
### 2. NON-FUNCTIONAL
  - S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
    - Scalable, Secure, SOA
    - Logging, Load, Latency
    - Cache(Invalidation, negative cache)
    - Available, Accurate, Analyze, Authenticate
    - Reliable, Redundant(Using DB)
    - Fast

## B. SYSTEM APIs
1. Search user
```
pointer_to_follower_struct *searchUser(toBeSearched_userId)
```

2. Add follower
```
successOrFail addFollower(toBeFollowed_id, follower's_id)
```

3. Posting tweet 
```
string publishTweet(tweet_message, *tweet_photo, *tweet_video, userId, user_location)
Parameters:
  - userLocation(optional): (Lattitude, Longitude) of user adding the tweet
Return:
  - Location to stored tweet, else HTTP error.
```

## C. BOE Calculations (should be done after HLD)
  - Total world population = 8 Billion = 8x10<sup>9</sup>
  - **Daily Active Twitter users**
    - Out of 8 Billion 40% have internet connection = 32x10<sup>8</sup>
    - Out of 40% only 10% active are Twitter users = 32x10<sup>7</sup> = 320 Million user
    - Let's 10% be daily active user. 320 Million user = 32 Million users.
  - **Storage Requirements**
    - ***For Storage of Text Tweets***
      - 10% of user does 1 tweet per day. 32x10<sup>5</sup>
      - Let's each tweet has 150 characters. 1 character takes 2 bytes of storage. 300 bytes/tweet.
      - 32x10<sup>5</sup> x 300 = 9x10<sup>8</sup> / day
      - 9x10<sup>8</sup> x 30 x 12 x 5 = 1x10<sup>12</sup>/year = 1 TB/5 years
    - ***For Storage of Photo Tweets***
      - Let's assume every 5th tweet has photo on it. Photo size = 200kb
      - Total photo tweets = 32x10<sup>5</sup> / 5 = 64x10<sup>4</sup> photo tweets per day
      - 64x10<sup>4</sup> x 30 x 12 x 5 x 200kb= 6000 TB / 5 years = 6 Trillion bytes
    - ***For Storage of Video Tweets***
      - Let video takes 2MB of data and every 10th is a video tweet.
      - Video tweets per day = 32x10<sup>4</sup> / day
      - 32x10<sup>4</sup> x 30 x 12 x 5 x 2MB = 1 Quadtrillion = 10<sup>15</sup> bytes / 5 years
    - This is read heavy system, since much higher data is read wrt written to the system.      

## D. HLD/DESIGN & DB SCHEMA
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
  
### E. DATA SHARDING

     
