## [To Cover](/System-Design/Scalable)

**What is Instagram?** 
  - Photo,Video sharing service here users can upload photos to share them with other users.
  - Content can be shared publicly or privately.
  - **News Feed** consist of top photos of all the people the user follows.
  - **Read Heavy** This is read heavy system Read:Write=100:1

## 1. Requirements
- **Functional**
  - *1.* Users should be able to upload/download/view photos.
  - *2.* Users can perform search based on photo/video titles.
  - *3.* Users can follow other users.
  - *4.* Can see news feed.
- **Non-functional**
  - Availabe. Low Latency, Consistent, Reliable(any uploaded photo or video should never be lost)
- **Extended**
  - Adding tags
  - Commenting on photos

## 2. BOE

|World Population|Daily Internet Users(30%)|Instagram Users(20% of Internet users)|(1%)Active users Daily|Each User upload 1 photo daily|Photos/sec|
|---|---|---|---|---|---|
|7x10<sup>9</sup>//Year 2020|7B x .3 =~ 2 Billion|2B x .2 = 400 Million|4 Million|4M Photos uploaded daily|4M/24 x 60 x 60 = 4Photos/sec|

- **Storage Estimates:** 1 Photo size=200KB. 1 day = 4M x 200KB = 800 GB. 5 years = 800G x30x12x5 = 1440TB
- **Traffic Estimates:** Upload = 800GB/day. 800G/24x60x60=9MB/sec incoming

## 3. HLD

**Steps: User-1 uploading his photos, user-2 watching user-1's photos**
- *1-6.* Same as [Facebook news feed](/System-Design/Scalable/Facebook).
- *7.* Application server will forward photos to DB Updater(in some other Datacenter).
- *8.* Photos will be stored on [Object Store DB](/System-Design/Concepts/Databases)
  - We will have dedicated servers for reads and different servers for writes to ensure that uploads don’t hog the system

## 4. DB
- **1. Storing Photo information:** 
  - Photos on [HDFS](/Operating_Systems/Linux/FileSystem/HDFS_Hadoop_Distributed_File_System.md) or [S3](/System-Design/Concepts/Databases/Object_Storage/Amazon_S3.md)
  - All tables stored on [noSQL key-value-DB](/System-Design/Concepts/Databases) (Eg: [DynamoDB](/System-Design/Concepts/Databases/NOSQL/AWS_DynamoDB/README.md))
  - Will store all photos of 1 userid on 1 server [Shard](/System-Design/Concepts/Databases/Database_Scaling). UserID % 10 to find shard server.
- **[2. Generating news feed for users](/Scalable/facebook/News%20Feed/README.md):** same as fb news feed

```html
User-Table
  | userid | username(varchar) | Email | DOB | creationDate(datetime) | lastlogin_time | 
  |--------|-------------------|-------|-----|------------------------|----------------|
  |   999  |  amit             |   --  | --- |      ---               |   --           |

Photo-Table
   | Photoid(int) | userId(uint64_t) | photoPath(varchar)      | creationDate(datetime) | 
  -|--------------|------------------|-------------------------|------------------------|-------
   |  8919        |   999            |/srv/path/ (HDFS or S3)  |   ---                  |

Meta-Data-Table: Key=photoID                                            //Information where photo-object,user-object are stored
   | PhotoID | value(Location of userObject, photoObject) |
---|---------|--------------------------------------------|
   |  8919   |                                            |

User-follow                         //Information about the users which this user is following
  | Userid | Following |
  |--------|-----------|
  | 8991   | 9,2,3     |
```

## 5. Where Load Balancers will be placed?

## [6. Tradeoffs, Bottlenecks & Correction](/System-Design/Concepts/Bottlenecks_of_Distributed_Systems/Bottlenecks.md)
- **1. Can Shard on userId Fail?** Yes, if load is high on 1 shard.
  - *Solution:* Shard based on PhotoID. Each photo will have associated photoid. Which can be generated as done in [tinyurl](/System-Design/Scalable/tinyurl/Design.md)
- **2. Scaling DB for future?**
  - *Solution?* We will make multiple logical partitions on same Physical server. Initially only 1 partition will be occupied, as load increases other will fill gradually.
- **3. Loosing photo/videos of user?** Yes, if DB fails
  - *Solution:* [Replicas](/System-Design/Concepts/Databases/Database_Scaling)(loosing photo is not allowed).
- **[4. Run time news feed generation: Solution](System-Design/Scalable/facebook/News%20Feed/README.md)**

## [7. Adjusting to changing requirements](/System-Design/Concepts/Changing_Requirements/README.md)
