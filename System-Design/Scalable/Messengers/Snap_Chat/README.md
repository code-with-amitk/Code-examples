## Snap Chat
- This messenger sends snaps. Plain text cannot be sent or send very rarely.
  - snap = Text + Video OR 
  - snap = Text + Image. 
- [See How snapchat is different from whatsapp](..)

## [To Cover](/System-Design/Scalable)
## 1. Requirements
- **Functional**
  - _a. Sending snaps:_ User-A can send snap(Video, images, text) to user-B.
  - _b. Holding & Deleting snaps:_ 
    - Snapchat service should hold the message for 24 hours, if in case user is not online and snap cannot be delivered instantly. Eg: User is Flight, once user comes online snap gets delivered to him, then snapchat server can delete from its DB.
    - if user is online, service will deliver message and delete snap instantly from DB.
  - _c. Searching a user:_ Unique userId is provided to users and all users are searched on basis of userId not phone numbers.
- **Non-Functional**
  - _a._ User-A can add any user as his friend based on userid and send snap.
  - _b._ **[Thumbnail](/System-Design/Scalable/Common_Features)** to be shown to reciever.
  - _c._ Normal filters on video,image provided to sender
  - _d._ System should be [Eventual consistent & Highly available](/System-Design/Concepts/Terms)
- **Extended**
  - _a._ Blocking the users
  - _b._ [Following a user](DB_Design)

## 2. BOE
> snapchat revleaved in 2018 that number of snaps sent per day = 4 Billion. Assumed in 2021 = 10 Billion
- **QPS(Queries per second)**
  - 10 Billion / 86400 = 10<sup>10</sup> / 10<sup>5</sup> = 10<sup>5</sup> = 1 lac queries per second
- **Storage Estimates:** Will try overestimate
```c
App Message: Metadata:75 bytes, Video:1MB
  Dst_user_id(10 bytes)   Allowed 20 characters. 1 character:4 bytes
  self_user_id(10 bytes)  Apart from IP address, client will send its unique user id
  timestamp(4 bytes)      Time elapsed from epoch(1 Jan 1970) in seconds
  Text(50 bytes)          Text sent with vieo or image
  Video(1 MB)             Video message

|App message|TCP(20 bytes)|IP(20 bytes)|DL(18 bytes)|         
//Note TCP,IP,DL Headers are not stored, these are used by router not snapchat.

                    1 day         //Assuming snapchat stores offline user data for 24 hours only
Metadata  = 75B x 10 Billion = 750 Billion  = .7 TB   //1 High end computer having 1 TB Hard disk
Videos    = 1MB x 10 Billion = 10 pow 15    = 1 PB    //1000 High end computers having 1 TB Hard disk
```

## 3. API Design
- All API's should be extensible, ie if in future want to add new parameters that can be added). [Variadic Templates C++](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Polymorphism/Static_CompileTime/Templates/Variadic), kwargs in python, va_list in c
### A. Sender call these APIs
- **[Deduplication](/System-Design/Concepts/Terms) is avoided using messageId.** if server finds messageId already in DB, it will consider message as duplicate and discard it.
```c
sendMessage ( string dst_user_id,
              string src_user_id,
              uint32_t timestamp,           //sec elapsed from Epoch(1/1/1970)
              string text,                  //
              uint8_t video, 
              uint32_t messageId)           //Identifies every message Uniquely.
```
### B. Reciever call these APIs 
- Reciever will get snaps from server in 2 ways:
  - _a. PUSH:_ Whenever reciever comes online, server pushes the pending messages.
  - _b. PULL:_ Whenever reciever want to get messages it refreshes and takes message from server.
```c
struct Message_details {
  string text,
  string video_url_on_object_store,
  string src_user_id
}
GetMessages (string self_user_id,        //Pull API
             uint32_t get_messages_after_timestamp,
             Message_details[]
)

PushAllMessages (Message_details[])    //Push API
```

## 4. HLD
> Requirement-1: Sending snap from UserA to UserB Steps(7-10)
- _1. to 3._ Same as [FB News Feed](/System-Design/Scalable/Facebook)
- _4._ User-A creates a snap(Video+Text), searches User-B and sends to App-Server using ISP
```console
App-Server                                                                                  User-A
      <- HTTPS(UserA_id, dst=UserB_id, timestamp, text, Video, messageId) | TCP | IP | DL |-
```
- _5._ HTTPS message is decrypted using SSL Terminators.
- _6._ [Load Balancer](/System-Design/Concepts/Load_Balancer) selects App server based on [Least Response Time Scheduling algo](/System-Design/Concepts/Load_Balancer) and sends packet.
- _7._ Application-Server will send User_B_id, timestamp, messageId to DBFinder service.
- **8. DBFinder:** 
  - *Purpose of DBFinder?* 
    - Find and searches DB which stores table of User_B, that messageId exists or not, if not updates DB  //See DB Design
    - Respond to AppServer, if messageId exits its duplicate else not
  - *Avoiding Deduplication?*
    - Every user's snaps are stored in DB until he reads them. Eg: When User_A sends snap to User_B. This snap is stored in User_B's table in DB.
    - AppServer will check User_B's SQL Database table that `messageId` exists in table or not?
      - Worldwide all snapchat clients But once message is delivered, AppServer will inform clients to reuse/reset the messageId
    - if messageId exists then its duplicate message, drop it.
  - We will place a [Cache(Eg: Redis, Memcached)](/System-Design/Concepts/Cache) between Application server and DB.
- _9._ Video,text,images are stored in different Databases(See DB Design), user-B,timestamp are pushed on MOM, user is acknowledged using zookeeper.
- _10._ **Sender Service** will be subscriber to MOM and recieves (userB, timestamp). It will read DB_userB and send video,image,text to userB.

> Requirement-2: Holding & Deleting snap (Steps 11,12)
- _11._ After sender service receives ACK from user that message is read, it will push MessageId, userId on MOM.
- _12._ **Deletor service** gets notifcation, reads messageID,userID from MOM, checks same in DB and deletes promptly.
  - cronjob would be running on Database to delete the contents if age>24 hours.

> Requirement-3: Searching the user
- Application server will delegate task to DB-Finder to search userB database, if database is not found this means user is not present.

<img src=snapchat.jpg width=1300/>

## [5. DB Design](DB_Design)
