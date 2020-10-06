| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

![ImgURL](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/scalable/facebook/fb-messenger/Fb-get-friendlist.PNG)

- Users can send text/video/audio/image messages using laptop or mobile.

## To Cover
- Requirements: Functional, Non-functional, Extended(Group chat)
- Back of Envelope Calculations
- HLD: For 2, 100, 1 lac users
- Database schema
- S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
  - Scalable, Secure, SOA
  - Logging, Load, Latency
  - Cache(Invalidation, negative cache)
  - Available, Accurate, Analyze, Authenticate
  - Reliable, Redundant(Using DB)
  - Fast

## 1. Requirements
### Functional
- (1st) User can see all of his friends and can send message to any of his friend.
- (2nd) Chat history should be stored.  
- (3rd) User can send message to any person on facebook provided target person has not blocked incoming messages.
- These sizes can be delivered as 1 message.
  - {text < 650 characters} {audio < 1 min/10 MB}   {video < 45min/1 GB}

## 2. BOE Calculations

|World Population=7x10<sup>9</sup> //Year 2020|InternetUsers = 40% = 2.8 Billion|FB Users= 60% of Internet users = 1.68 Billion|
|---|---|---|

- **No of users sending**

|Text message/day|Audio Messages/day|Video Messages/day|
|---|---|---|
|60% = 1.68x0.6 = 1 Billion|20% = 1.68x0.2 = 336 Million|5% = 1.68x0.05 = 84 Million|
  
- **Data estimations(bytes to stored)**

| | 1 Day storage Req(bytes) | 5 years storage Req(bytes)
| --- | --- | --- |
| Chat | 1 Billion(messages) x 650x8(size) = 5.2 Tera bytes | 5.2 x 30 x 12 x 5 = 9.3 peta Bytes |
| Audio | 330Million(audio messages) x 10MB(size) = 3.3 Exa bytes | 3.3x30x12x5 = 6 Zeta bytes |
| Video | 84Million(video messages) x 1GB(size) = 84 Exa bytes | 84x30x12x5 = 151 zeta bytes |

Total space requirement for 5 years = 157 zeta bytes
> Not considering users who deleted chat/video/audio/account permanently. Compression, new users added.

- **Bandwidth Capacity Estimations**

| |1 second incoming data = 1 day/24x60x60|
|---|---|
|chat|60x10<sup>6</sup>|
|Audio|70x10<sup>9</sup>|
|Video|972x10<sup>9</sup>|
|Total|10<sup>9</sup> = 1 Giga bytes|
> We will need a link recieve/send(upload/download) 1GB/second.

# 3. HLD
## 3A. 2 users
### User-1 sending chat Message to User-2
```c
User-1                    Registrar
Browser+FbClient            |
  |----  Register --------->|
  |<---200 ok---------------|
  |                              Auth-Server+DB(Kerberos)
  |-Login(Id/hash of password)-------->|
  |                             check hash ok
  |<-------------TGT-------------------|                             
{Req-1}Open UI to see live users                   Ticket-Granting-Server
  |---(Message=Check Live users)+TGT---------------------->|
  |<-----Service Ticket(for Live user service)-------------|            Live-User-Checker(service-1)
  |                                                                     Keeps list of live users/zone
  |                                                                     using keepalive messages sent on
  |                                                                     web sockets
  |------------------------------------Service Ticket+Message=Check Live Users---->|
  |                                                                      Check Live friends of User-1--------> DB or file-1(encrypted,compressed)
  |<------------------Live friends(User ids)+Service Ticket 2----------------------|<---------------------------------|
  |                                                                                                         File-1 contains friend list
{Req-2}Chat with Live User  
  |                                                                    Chat-Server
  |-(Self userID, Friend UserId + message + scanReport + Service Ticket-2)-->|                              Queue
  |                                                                          |--userid-1, userid-2, Message-->|
  |                                                                                                           |
  |                                                                               Connector <---------------->|
  |                                                                           Read from queue
  |                                                        Spawn new non-blocking thread to handle 1k connections
  |                                                                             Thread-n    
  |                                                                                  |--send/recv message------>User-2
  |                - chat History  {Req-2} //(file-2) is maintained/userId containing all chats userId done with friends/world.
  
For 2 user approach
  - A global file-3 containing all userId present on system.
  - Each user chats can be stored in chornological order with timestamps in seperate file. 
```
- **Communication**
  - **1. Online User to server**
    - Client and server will communicate over web sockets, ie client will hold open connection with server.
    - Server will maintain a hash table <key=userId, value=Connection-Structure>. When message comes for userId, server will search in O(1) and send message to userId.
  - **2. Offline User**
    - The server will store the message for a while and retry sending it once the receiver reconnects.

## 3B. User-1 sending Chat message to 100th or 1 Lac'th User
### 1. Authentication to service
```c
- Registration and getting TGT flow is same.
{Req-1}Open UI to see live users                   Ticket-Granting-Server
  |---(Message=Check Live users)+TGT---------------------->|
  |<-----Service Ticket(for Live user service)-------------|
  |                                                                   Live-User-Checker(service-1)
  |                                                                   - Get list of friends of user-1 from different databases  
  |                                                                   - Send keepalive(about friend's of user-1) to distant servers  
  |                                                                   - Distant servers responsded
  |                                                                   - Maintain hashMap <user, associated-server>
  |                                                                   - Send message over web sockets.
  |<-------------Your live friends----------------------------------------------|
  |
  {Req-2} Send chat to live user
  |                                                                    Chat-Server
  |-(Self userID, Friend UserId + message + scanReport + Service Ticket-2)-->|                        Queue-Datacenter-1
  |                                                                          |--userid-1, userid-2, Message-->|
                                                                                                              |
                                                                        Local-Checker<---------------Read Queue
                                                                             |
                                                             Does any user falls in List served locally?
                                                             Yes-> Connect to user on web sockets
                                                             No-> Copt message to global queue
                                                                             |                         Global-Send-Queue
                                                                             |-copy message to global Queue->|
                                                                                                             |
                                     Group-of-DB                    Distributor<-------------------------Read Queue
                        stores connection info <--userId--------->      |             
                                                        Checks which user belongs to which
                                                        geographical domain?
                                                        Send (message,username) to that particular
                                                        geographical server.
                                                                        |                         Geographical-server
                                                                        |-------username,message---------->|
                                                                                                           |--------deliver to user2-->|
                                                                 ACK-Receiver                              |
                                                                        |<---------message delivered-------|
                                                                        |
                                                                        |                       Global-ACK-Queue
                                                                        |----Add ACK to queue---------->|
                                                                                                        |------>ACK-distributor
                                                                   Local-ACK-Reciever                                 |
                                                                        |<------(username, ACK)-----------------------|
                                                                 check friends of username
                                                                        |
                                                                        |--username--------------->Shared-DB(Based on username)
                                                                        |<---friends of username-------------|
User-1-Local-Cache                                                                        
           |<----------------------------usernme for whom chat was sent-|
           |---user-2-------------------------------------------------->|
User-1
  <---------------------------response of chat message------------------|
```

### 2. Get Friend List of user

![ImgURL](https://i.ibb.co/z4J4Pnn/Fb-getlive-friendlist.png)

### 3. User-1 sending "Hi" to user-2

- **Which Database**
  - We need to have very high rate of small updates and also fetch a range of records quickly.
  - RDBMS like MySQL or NoSQL like MongoDB are not useful because read/write a row from the database every time a user receives/sends a message is not efficient in RDBMS.
  - We will use wide-column noSQL-database like HBase. HBase runs over Hadoop Ditributed file system(HDFS).
    - HBase groups data together to store new data in a memory buffer and, once the buffer is full, it dumps the data to the disk.
- **Knowing which users are online/offline?**
  - 

#### 3C. How many Chat servers are needed
- Asumming 1 Billion incoming text messages. 1 server can handle 1 lac connections. 1 Billion/1 lac = 10k chat servers.
