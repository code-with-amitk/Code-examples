Million=10^6. Billion=10^9. Trillion=10^12, Quadtrillion=10^15

## 1. REQUIREMENT COLLECTION
  - **Functional**
    - Users can upload, view, search
    - Service can do stat collection: no of vistors, views, likes, dislikes.
    - User can like/dislike the videos.
  - **Non-functional**
    - S<sup>3</sup>
      L<sup>3</sup>
      C<sup>2</sup>
      A<sup>3</sup>
      R<sup>2</sup>
      F
      - SOA, Secure, Scalable
      - Load, Latency, Logging
      - Cache(Cache invalidation, Negative cache)
      - Available, Authentication, Analyze, 
      - Reliable, Redundant(using DB), 
      - Fast(Lambda)

| | CDN | AWS Cloud |
| --- | --- | --- |
| SOA/modular | API G/W | ECS (containerized) |
| Secure | WAF, Shield | SSL-Term: https, encrypt(Web-server on ECS), 
least privileges(22 for SSH to only whitelisted IPs), 
Create a private subnet, smartcard access |
| Scaling | | |
| Logging | | cloudwatch-logs |
| Load | | Autoscalar, Elastic-LB |
| Cache | | ElasticCache, varnish(not aws product) |
| Combine & Derive | | Sagemaker |
| Authentication | S3 Auth frontend  | |
| Analyze | | Kinetics |
| Redundant | | DynamoDB(noSQL), Aurora(SQL) |
| Fast | Lambda | Lambda |
| User-pass-store | Cognito | |

(Web-server on ECS)
- least privileges(22 for SSH to only whitelisted IPs). 
-Create a private subnet
- smartcard access
    
## 2. CAPACITY ESTIMATIONS/BOE CALCULATIONS
  - ***Read/Write*** or View/Upload = 200/1
    - Read = Views: 50k/sec
    - Uploads = 250/sec. 15000/min = 15k/min. 900k/hour. 27 Million/month. 9 Billion/Year. 50 Billion/5 years.
  - ***Storage Requirements***
    - 1 sec video need 1 MB
    - 250 sec = 250 MB
    - 5 year = 50*10^9*10^6 = 50*10^15 = 50 Quadtrillion bytes
      - But this will change when video compression is done at storage

## 3. SYSTEM APIs
- Upload API
```
uploadVideo(api_dev_key, video_title, vide_description, tags[], category_id, default_language, 
                        recording_details, video_contents)
Parameters:                        
api_dev_key (string): The API developer key of a registered account. This will be used to, among other things, throttle users based on their allocated quota.
video_title (string): Title of the video.
vide_description (string): Optional description of the video.
tags (string[]): Optional tags for the video.
category_id (string): Category of the video, e.g., Film, Song, People, etc.
default_language (string): For example English, Mandarin, Hindi, etc.
recording_details (string): Location where the video was recorded.
video_contents (stream): Video to be uploaded.                

Returns: (string)
- A successful upload will return HTTP 202 (request accepted)
- once the video encoding is completed the user is notified by email with a link to access the video. 
```

- Search API
```
searchVideo(api_dev_key, search_query, user_location, maximum_videos_to_return, page_token)
Parameters:
api_dev_key (string): The API developer key of a registered account of our service.
search_query (string): A string containing the search terms.
user_location (string): Optional location of the user performing the search.
maximum_videos_to_return (number): Maximum number of results returned in one request.
page_token (string): This token will specify a page in the result set that should be returned.

Returns(JSON)
A JSON containing information about the list of video resources matching the search query. 
Each video resource will have a video title, a thumbnail, a video creation date, and a view count.
```

- Stream video
```
streamVideo(api_dev_key, video_id, offset, codec, resolution)
api_dev_key (string): The API developer key of a registered account of our service.
video_id (string): A string to identify the video.
offset (number): We should be able to stream video from any offset; this offset would be a time in seconds from the beginning of the video.
codec (string) & resolution(string): We should send the codec and resolution info in the API from the client to support play/pause from multiple devices. Imagine you are watching a video on your TV’s Netflix app, paused it, and started watching it on your phone’s Netflix app. In this case, you would need codec and resolution, as both these devices have a different resolution and use a different codec.

Returns: (STREAM)
A media stream (a video chunk) from the given offset.
```

## 4. HIGH LEVEL DESIGN
### UPLOADING VIDEO/WRITE OPERATION
- Thumbnails
  - Each video can have thumbnails of other videos. we can assume each video will have 5 other thumbnails.
- Metadata of video:
  - title
  - file path in the system
  - uploading user
  - total views
  - likes, dislikes
```
User                App-server        
    --- video-n---->
    TCP(fragments)             -------Processing-Queue----------
                      -video-n->  video-k   ......    video-1     ---->  | Encoder |
                               ---------------------------------                ------Video---->  DB(HDFS or GlusterFS)
                                  Enqueued for encoding                         --meta data----> Video-Metadata-DB(MySQL)
                                  & storage later                                                [Master-Replica-Pairs]
                                                                                ---thumnails---> BigTable
                      ----user information------> User-DB(MySQL)
                      <---------------Video,metaData,thumnails uploaded----------
            CDN <--Pushing ----
<-Your Video--
```

- **HOW VIDEOS ARE STORED?**
  - Store videos on multiple DB backends using sharding.
    1. [Approach-1, Wll not follow] Sharding based on userId's
        - userID > |Hash Func| > hash-value(maps to a DB)
        - `[Drawback]` if some user becomes hugely popular, then only 1 server will be loaded while others are free.
    2. [Approach-2, Wll not follow] Sharding based on Video's ID
        - Each video has a videoID
        - videoID > |Hash Func| > hash-value(maps to a DB)
        - `[Drawback]` if some video becomes most popular, this will overload few servers.
    3. [Appraoch-3] Consistent Hashing (will follow)
        - CH is used to balance load among servers.
- Less popular videos (1-20 views per day) that are not cached by CDNs can be served by our servers in various data centers.      
### PLAYING VIDEO/READ OPERATION
```
  user        
    -videoID->  CDN                     [Cache]==[App-server]         <<<DB-servers>>       
            video not here                      |                         |
                  --videoID--> |Hash-fun|-> Hash-value  ----Hash value--> |
                                                |                         |
                                                |                       hash found at server1,server3..
                                                | <-Ranked List of Videos-|
        <---------ranked video list-------------|
```
      
- **DETECTING DUPLICATE VIDEOS**
  - At time of uploading the videos, a service can run video matching algorithms (e.g., Block Matching, Phase Correlation, etc.) to find duplications.
      


## 5. DATABASE SCHEMA
### 5.1 Video-Metadata-DB(MySQL)
- ***Table for each video***

| VideoID | Title | Description | Size | thumbnail | Uploader | No of Likes | Dislikes | Views |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

- ***Table for each video comment***

| CommentID | VideoID | UserID | Comment | TimeOfCreation |
| --- | --- | --- | --- | --- |

- ***User table, storing user information***

| UserID | Name | email | Age| Registration detials |
| --- | --- | --- | --- | --- |


## 6. LOAD BALANCING
- Load between cache servers is balanced using ***[Consistent Hashing](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Hashing/Consistent_Hashing.md)***

## 7. CACHE
- memcached in front of 'App-servers'.
- Cache Eviction Policy: LRU. Discard least recently viewed contents from cache.


