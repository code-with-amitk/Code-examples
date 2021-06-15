## Snap Chat
- This messenger sends snaps. Plain text cannot be sent or send very rarely.
  - snap = Text + Video OR 
  - snap = Text + Image. 
- [See How snapchat is different from whatsapp](..)

## [To Cover](/System-Design/Scalable)
## 1. Requirements
- **Functional**
  - _a._ User-A can send snap to user-B.
  - _b._ Support multimedia(video, images).
  - _c._ Snapchat service should hold the message for 24 hours, if in case user is not online and snap cannot be delivered instantly. Eg: User is Flight, once user comes online snap gets delivered to him, then snapchat server can delete from its DB.
  - _d._ Normal filters on video,image provided to sender
  - _e._ Unique userId is provided to users and all users are searched on basis of userId not phone numbers.
  - _f._ Once snap is delivered to reciever, it should be deleted from snapchat server.
  - _g._ **[Thumbnail](/System-Design/Scalable/Common_Features)** to be shown to reciever.
- **Non-Functional**
  - _a._ User-A can add any user as his friend based on userid and send snap.
- **Extended**
  - _a._ Blocking the users

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
- _1. to 6._ Same as [FB News Feed](/System-Design/Scalable/Facebook)
```console
                Application-Server                                            User-A
                                  <-src=UserA_id, dst=UserB_id, timestammp
                                    text, Video, messageId
```
