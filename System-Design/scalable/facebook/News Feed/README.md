# Facebook News Feed
- **What?** Whenever someone logs into account. He finds content posted on his network using new feed.
  - friend activities(status updates, photos, videos etc)
  - profile changes, upcoming events
  - news(if subscribed).

| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

# To Cover
- *1.* Requirements: Functional(Basic functionality, should work), Non-functional(defines quality), Extended
- *2.* Back of Envelope Calculations
  - Storage estimates
  - Traffic estimates
- *3.* HLD: For 2, 100, 1 lac users
- *4.* Database schema
- *5.* S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
  - Scalable, Secure, SOA
  - Logging, Load, Latency
  - Cache(Invalidation, negative cache)
  - Available, Accurate, Analyze, Authenticate
  - Reliable, Redundant(Using DB)
  - Fast

## 1. Requirements
- **1A. Functional**
  - *a.* User should see his new feed as he logs in.
  - *b.* Newsfeed should be custommizable, whatever user wants to subscribe/not.
- **1B. Non-Functional**
  - *a.* News feed should give soothing/smiling effect to user.
  - *b.* Option for extending news feed once news feed gets over.
- **1C. Extended**
  - *a.* Option to hide/disable news feed.
  - *b.* AI powered user specific search items

## 2. Back Of Envelope Calculations

- **People using Facebook**

|World Population|InternetUsers(60%)|FB Users(80-85% of Internet users)|
|---|---|---|
|7 Billion //Year 2020|7 x 0.6 = 4.2 Billion|4.2 x 0.8 = 3.5 Billion|

- **News Feed Usage statistics** Every person will have a news feed. 
  
### 2A. Storage Estimates
- Photos/Videos/Messages/Posts would be stored on different Object store DB(Eg: amazon S3, ceph) for every user. This will not be considered as part of news feed.
- In relational DB(Eg: PostGRE or mySQL) there will be Mapping-table(Hash-Table) which holds information about friends. This is considered as part of new feed.
  - As soon there is change in any field of Mapping-table, updater service(which keeps watch on Mapping-Table) will send information to Poller service(So Pool for user), as soon user comes online poller will update his new feed.
  - **Mapping Table**     //on Relational DB  
```c
| UserName/UserId | Ptr to LL of Friends | Ptr to LL of Subscribed news | LL of sports | LL of personalities |
--------------------------------------------------------------------------------------------------------------
|     amit        |       0x5681821      |        0x01291               |     none     |        ..           |
|     john        |       0x02100aa      |        none                  |     0x28981  |        ..           |
     
vivek-> anil -> anuj ..       amit -> tiware -> jv ..   
0x5681821                     0x02100aa
     
abp->cnn->al jazeera          dd->star->espn
0x01291                       0x28981
     
//Better DS will be decided  
```
- *Storing Mapping Table* 
  - Pointer=8 byte address and 50 linked list pointers per user.  400 bytes/user.   400 x 3.5 = 1400 Billion bytes = 1400 GB = 1.4 TB
- *Storing Seperate LL per user*
  - Actual LL will store Ids of names.  1 ID = 8 bytes.
  - if 1 person can have Max=5000 friends and subscribed to 5000(different groups). Total 10000 ids. 10000 x 8 = 80000 bytes/user. 80000 x 3.5 Billion = 280000 Billion bytes = 1 PB
- **Overall Storage Estimate** 1 PB + 1.4 TB = 1 BB. if limit of max friends, max subscribed channels increases this will also increase.

### 2B. Traffic Estimates
- As soon user logs in, his news feed has to be shown with least delay. Most data is sent from server to user/browser/FB app.
- Considering user has 5000 friends, 5000 channels subscribed, As soon as user comes online, pooler service will send encrypted data to user over websockets.
- Considering 75% of fb users (3.5 x 75% = 2.5 Billion) are active every moment/every second.
  - **Data pumped into FB servers per second**
    - User/browser/FB app opens a Websocket to server as comes online. (HTTP GET size = 2KB). 2KB x 2.5 = 5k Billion Bytes = 5TB bytes/sec comes to FB servers worldwide.
    - 193 countries in world, considering 1 data center per country(on average). 5TB/193 = 25 Giga Bytes/second (pumped into 1 data center per second)
  - **Data reaching browser/FB App = 550kb**
    - Considering 5000 friends, 5000 channels.
```c
 On average:
{Friends} 2500 friends does 1 photo upload, 2000 shared a post, 500 uploaded a video. 
Http-response{XML or JSON}. Let XML contains 5000 links(shortened URLs). Ex: https://test.com/10-characters-shortened-url
1 URL size = Total characters = (test.com=8 + 10) = 20. Each character occupies 4 bits. 80 bits = 10 bytes.
5000 URLs size = 50000 bytes. 50 KB.
      
{Channels} Every channel posted 10 Links. 5000 x 10 = 50000 links
1 URL Size = 10 bytes
Total size = 50000 x 10 = 500 KB
```    

## 3. High Level design
### A. 2 Users, 2 channels
  - Each user stores 10000 Photos. Each photo size = 50KB. 50KB x 10000 x 2 = 5GB
  - Each user stores 5000 videos. Each video size = 1GB. 1GB x 5000 x 2 = 1TB
- **Storing Photos, Videos on Object Store**
```c
  1. Object-Store-1(Video)   //uses Storage-Hash-Table
  
  |Shortened URL|Virtual Address of Video File in Memory|
  |-------------|---------------------------------------|
  | 2412as | 0x004 |
  | aw1as2 | 0x505 |       
  
  |meta-data|video|...|meta-data|video|
  0x004               0x505
  
  2. Object-store-2(Photos)
```
- **How Photo/Video is linked to user**
```c
  User-Hash-table
  | User-Id | Hash-Table-of-Photos |
  |---------|----------------------|
  | userId1 | |photo1|2412as| 
              |photo2|aw1as2|

  | userId2 | |photo1|xuyyaa| 
              |photo1|xyoaos|
```
- **How friend-list is stored**
```c
  Friend-Hash-table
  | User-Id | ordered_set_of_friends |      //Searching O(logn)
  |---------|----------------------|
  | userId1 |       sachin
                  /      \
                amit      ziad                 
```
- **How channel subscriptions are stored**
```c
  Friend-Hash-table
  | User-Id | ordered_map_of_channels |      //Searching O(logn)
  |---------|----------------------|
  | userId1 |      <news, address-of-sports-news>
                  /    \
                country    sports
```
- **How news feed works for 2 users**
  - UserId1 adds a new photo,video to his album.
    - *1.* New object allocated on object store. Entry created in *Storage-Hash-Table*, *User-Hash-table*
