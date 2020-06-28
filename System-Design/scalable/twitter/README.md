## Twitter Design

### A. REQUIREMENTS
#### A1. FUNCTIONAL
  1. **Search**
     - Any twitter user can search any other twitter user by name.
  2. **Adding myself as Follower**
     - Let's suppose user-1 searches user-2, then user-1 can add himself as follower of user-2.
     - User-1 can see the tweets(text,videos,photos) of people he follow on their timeline.
     - Any user can mark any tweet as favourite.
     - User can reply to tweets.
  3. **Posting Tweets**
     - Any user can post tweet < 150 characters.
     
#### A2. NON-FUNCTIONAL
  - S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
    - Scalable, Secure, SOA
    - Logging, Load, Latency
    - Cache(Invalidation, negative cache)
    - Available, Accurate, Analyze, Authenticate
    - Reliable, Redundant(Using DB)
    - Fast

### B. SYSTEM APIs
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

### C. HLD
#### C1. 5 users(A,B,C,D,E) Design
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
| 5 Users | user-list.txt A,B,C,D,E | struct user_info (see below) | 5 files storing tweets of 5 users (see below) |
| 1000 Users | user-list.txt 1000 users | vector size=1000 | 100 files |
| 1 Million Users | File search is slow | Huge vector, may not handle | 1 million files immposible to maintain |

```
2. ADDING MYSELF AS FOLLOWER
struct user_info{
  vector<STRUCT followers> f;   //List of followers of this user
  tweet-file *ptr;
};
f.push_back(user-1);

3. POSTING THE TWEET
  [File-B]
    meta-data + Tweet-1
    meta-data + Tweet-2
    
  [File-A]    
```

### C. BOE Calculations (should be done after HLD)
  - Total world population = 8 Billion = 8x10<sup>9</sup>
  - **Daily Active Twitter users**
    - 40% have internet connection = 32x10<sup>8</sup>
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
     
