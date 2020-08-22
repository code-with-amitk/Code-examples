| Million 10<sup>6</sup> | Billion/Giga 10<sup>12</sup> | Trillion/Tera 10<sup>15</sup> | Quadrillion/Peta 10<sup>18</sup> | Quintillion/Exa 10<sup>15</sup> | Zeta 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

# Facebook Messenger
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

# 1. REQUIREMENTS
## FUNCTIONAL
- (1st) User can see all of his friends and can send message to any of his friend.
- (2nd) Chat history should be stored.  
- (3rd) User can send message to any person on facebook provided target person has not blocked incoming messages
- These sizes can be delivered as 1 message.
  - {text < 650 characters} {audio < 1 min/10 MB}   {video < 45min/1 GB}

# 2. BOE Calculations

|World Population=7x10<sup>9</sup> //Year 2020|InternetUsers = 40% = 2.8 Billion|FB Users= 60% of Internet users = 1.68 Billion|
|---|---|---|

|No of Users Sending|Text message|Audio Messages| Audio Messages |Video Messages|
|---|---|---|---|---|
| |per day|60% = 1.68x0.6 = 1 Billion|20% = 1.68x0.2 = 336 Million|5% = 1.68x0.05 = 84 Million|
  
- **Data estimations(bytes to stored)**

| | 1 Day storage Req(bytes) | 5 years storage Req(bytes)
| --- | --- | --- |
| Chat | 1 Billion(messages) x 650x8(size) = 5.2 Trillion | 5.2 x 30 x 12 x 5 = 9.3 peta Bytes |
| Audio | 330Million(audio messages) x 10MB(size) = 3.3 Exa bytes | 3.3x30x12x5 = 6 Zeta bytes |
| Video | 84Million(video messages) x 1GB(size) = 84 Exa bytes | 84x30x12x5 = 151 zeta bytes |

Total space requirement for 5 years = 157 zeta bytes
> Not considering users who deleted chat/video/audio/account permanently. Compression, new users added.

# 3. HLD
## 3A. 2 users
```
User-1               Chat-Server              
  |----  Register -------->|
  |-Login(userid/password->|
  |                 Read following information from files
  |                - friends of userId.  {Req-1} //server maintains a file-1 containing friend list(encrypted/compressed)
  |                - chat History  {Req-2} //(file-2) is maintained/userId containing all chats userId done with friends/world.
  |                                        //Chats are stored in chornological order with timestamps.
  |                - See all unblocked people on fb. {Req-3}   //A global file-3 containing all userId present on system.
  |                      |                                     //Each userId is associated with hidden field, allows/blocks userId to be seen in searches.          
  | <-show friends-------|
  | <-show chat history--|
  |                      | 
  |--search user n-----> |
  |                  check user is present in file-3
  |                  if present, check hidden flag?
  |<--user-2 information-|                 

- Server will need?
  - 
  
```
