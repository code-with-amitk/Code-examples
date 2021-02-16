# Facebook News Feed
- **What?** Whenever someone logs into account. He finds content posted on his network using new feed.
  - friend activities(status updates, photos, videos etc)
  - profile changes, upcoming events
  - news(if subscribed).

## [To Cover](/System-Design/Scalable/README.md)

## 1. Requirements
- **1A. Functional**
  - *a.* User should see his new feed as he logs in.
  - *b.* Newsfeed should contain posts from the people, pages, groups that a user follows.
  - *c.* Feeds can have text, images, videos.
- **1B. Non-Functional**
  - *a.* News feed should be generated on the fly. Max latency should not be more than 2 sec.
  - *b.* News feed should give soothing/smiling effect to user.
  - *b.* Option for extending news feed once news feed gets over.
- **1C. Extended**
  - *a.* Option to hide/disable news feed.
  - *b.* AI powered user specific search items

## 2. Back Of Envelope Calculations

|World Population|InternetUsers(60%)|FB Users(80-85% of Internet users)|Active FB Users(20%)|
|---|---|---|---|
|7 Billion //Year 2020|7 x 0.6 = 4.2 Billion|4.2 x 0.8 = 3.5 Billion|3.5 x .2 = 700 Million|

- **Traffic Estimateds**
  - 700 Million pulling their new feed 5 times a day. Total New feed requests = 700 x 5 = 3500 Million requests/day.
  - 3500/24x60x60 = Around 39,000 Requests/sec.
  
- **Storage Estimates**
  - **Cache/CDN** 
    - Suppose We want to keep 500 posts/user on [CDN](/System-Design/Concepts/CDN/README.md) for quick fetch.
    - Total posts to be stored. 500 x 700 Million = 350 Billion.
    - Let's assume on average each posts is 1 KB in size. Total bytes = 350 TB
    - Assuming 1 server can cache is 100GB. Total servers needed = 350 TB / 100 GB = 3500 Machines needed in total

- **[Extended BOE](./Extended_BOE.md)**    

## 3. System APIs
```c
GetUserNewsFeed(string User_key, string user_id, string since_id, int count, max_id, exclude_replies)
Parameters:
	|- User_Key (string): Fetching user feed quickly
	|- user_id (string)
	|- since_id (string): Optional; returns results with an ID higher than (that is, more recent than) the specified ID.
	|- count (number): Optional; specifies the number of feed items to try and retrieve up to a maximum of 200 per distinct request.
	|- max_id (number): Optional; returns results with an ID less than (that is, older than) or equal to the specified ID.
	|- exclude_replies(boolean): Optional; this parameter will prevent replies from appearing in the returned timeline.

Returns: (JSON) Returns a JSON object containing a list of feed items.
```

## 4. High Level design
> FB stores users,posts,comments using [TAO](/System-Design/Concepts/Databases/NOSQL/Graph_DB/Facebook_TAO/README.md)
- There are 2 parts to design.
  - *A.* User creating a post.
  - *B.* Backend system generating news feed for his friends/followers.  //FEED GENERATION
  - *c.* Publishing feed to user.            //FEED PUBLISHING
  
### 4B. Feed Generation
- *1.* User-1 posts text,audio,viudeo. System triggers new feed generator for all friends/followers of User-1.
- *2.* Amit is friend of user-1. Generating feed for Amit.
  - *2a.* Retrieve all users that Amit follows.
  - *2b.* Retrieve latest, most popular and relevant posts for those IDs. 
  - *2c.* Rank these posts based on the relevance to Amit (in maxHeap).
  - *2d.* Push these feed to CDN to be posted to Amit.
  - *2e.* Fan-out feed to Amit's device. Once 1st 20 posts on feed are pushed, push next 20.
  
## 4C. Feed publishing

### Architecture
- **[Web Server](/Networking/OSI-Layers/Layer5/ApplicationServer_WebServer/README.md)** To maintain a connection with the user. This connection will be used to transfer data between the user and the server.
- **[Application server](/Networking/OSI-Layers/Layer5/ApplicationServer_WebServer/README.md):** Handle storing new posts in the DB servers.
- **Metadata database and [Cache]():** To store the metadata about Users, Pages, and Groups.
- **Databases:** [TAO](/System-Design/Concepts/Databases/NOSQL/Graph_DB/Facebook_TAO/README.md) for posts. [noSQL](/System-Design/Concepts/Databases/README.md) for video,photos.
- **News feed genreator:** To generate newsfeed and store in the cache. This service will also receive live updates and will add these newer feed items to any user’s timeline.
- **Fanout service:** to push news feed to users on their phones.
- **[9. MOM/SQS](/System-Design/Concepts/MOM_ESB/README.md)** Amazon SQS
- **10.**
    
## [5. DB Schema/TAO](/System-Design/Concepts/Databases/NOSQL/Graph_DB/Facebook_TAO/README.md)

## [6. Tradeoffs/Bottlenecks & correction](/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)

## [7. Adjusting to changing requirements](/System-Design/Concepts/Changing_Requirements/README.md)
