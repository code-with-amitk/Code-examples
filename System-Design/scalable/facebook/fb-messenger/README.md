| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

## Facebook Messenger
- Users can send text/video/audio/image messages using laptop or mobile.

### To Cover
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

## 1. REQUIREMENTS
### FUNCTIONAL
- (1st) User can see all of his friends and can send message to any of his friend.
- (2nd) Chat history should be stored.  
- (3rd) User can send message to any person on facebook provided target person has not blocked incoming messages
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

## 3. HLD
### 3A. 2 users
- **User-1 sending chat to user-2**
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
