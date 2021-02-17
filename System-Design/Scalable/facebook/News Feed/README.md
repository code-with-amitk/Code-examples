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

 There are 3 parts to design.
  - *A.* User creating a post, backend stores the post.		//POST STORAGE
  - *B.* Backend system generating news feed for his friends/followers.  //FEED GENERATION
  - *c.* Publishing feed to user.            //FEED PUBLISHING

### Steps
- *1.* Mobile/App enters facebook.com in browser. Browser gets IP address using [DNS](/Networking/OSI-Layers/Layer5/Protocols/DNS/How_DNS_Works.md)
  - Browser can have [Cache](/System-Design/Concepts/Cache/Where_Cache_Can_Be_Placed/README.md) But assuming cache is stale.
- *2.* [HTTPS](/Networking/OSI-Layers/Layer5/Protocols/HTTP/GET_Document.md) Packet is created by Browser `GET www.facebook.com/index.html HTTP/1.1`, sent to [Forward Proxy](/System-Design/Concepts/Proxy_Servers/README.md) server hosted by ISP/Office Server. ISP forward request to next router in internet.
- *3.* [CDN](/System-Design/Concepts/CDN/README.md) will be hosting homepage, periodically updating the page from Web Server. CDN renders the home page.
- *4.* User creates a post, upload a photo, Video. Browser creates a [HTTP POST](/Networking/OSI-Layers/Layer5/Protocols/HTTP/GET_Document.md) message packages post,video in JSON/XML and sends to server.
- *5.* SSL Terminator decrypts packet and sends to Load Balancer. Before sending TCP-3-way handshake must be completed.
- *6.* [Load Balancer](/System-Design/Concepts/Load_Balancer/What_is_LoadBalancer.md) selects Web server based on [Round Robin scheduling algo](/System-Design/Concepts/Load_Balancer/Scheduling_Algo_of_Load_Balancers.md) and sends packet.
- **Post Storage:**
  - *7. [Web Server](/Networking/OSI-Layers/Layer5/ApplicationServer_WebServer/README.md)* maintain connection-DB(struct {sockfd, ip, connection_time, expiry}) for each user and creates entry for user. This connection will be used to transfer data between the user and the server.
  - *8. [Application server](/Networking/OSI-Layers/Layer5/ApplicationServer_WebServer/README.md):* Handle storing new posts in the DB servers.
  - *9. Database updater* DB Frontend which manages updating the DB. Sends acknowledgment using zookeeper.
  - *10. [TAO(Graph DB)](/System-Design/Concepts/Databases/NOSQL/Graph_DB/Facebook_TAO/README.md)* stores Posts, comments, users. *[NOSQL](/System-Design/Concepts/Databases/README.md)* stores photos, videos.
- **Feed Generation:** Backend system generating news feed for his friends/followers
  - *11. Database updater* Will also update [Message Queue(MOM)](/System-Design/Concepts/MOM_ESB/README.md) with newly updated UserId's ie any userId who have newly added edges on TAO.
  - *12. Fetcher service(subscriber in MOM)* gets notification and starts fetching edges of userId posts,photo,videos URL's and forwards to News Feed Generator service.
  - *13. New Feed Generator Service* Will create JSON/XML Content for HTTP message.
- **Feed Publishing:** Publishing feed to user. 
```c 
  - FB need to retrieve all friends of person who commented/posted.
  - Retrieve latest, most popular and relevant posts for those IDs. Rank these posts based on the relevance to Amit (in maxHeap).
  - Once 1st 20 posts on feed are pushed, push next 20.
```
  - *14. Fanout Service* Will get connection information from web-server and sends HTTP message on that socket.
    - When new connection comes in, session-id is generated and attached to user-id. UserId stored on TAO. Using this session-id, information can be fetched from connection-db.
  - *15. SSL Encryptor* Encrypts the message and using CDN[(write thru cache)](/System-Design/Concepts/Cache/Types_of_Distributed_Caches/README.md) sends New feed to client.

<img src="./facebook_newsfeed.png" width=900 />
    
## [5. DB Schema/TAO](/System-Design/Concepts/Databases/NOSQL/Graph_DB/Facebook_TAO/README.md)

## [6. Tradeoffs/Bottlenecks & correction](/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)

## [7. Adjusting to changing requirements](/System-Design/Concepts/Changing_Requirements/README.md)
