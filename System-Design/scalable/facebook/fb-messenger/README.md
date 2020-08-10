# Facebook Messenger
- Users can send text/video/audio/image messages using laptop or mobile.

| Million 10<sup>6</sup> | Billion/Giga 10<sup>12</sup> | Trillion/Tera 10<sup>15</sup> | Quadrillion/Peta 10<sup>18</sup> | Quintillion/Exa 10<sup>15</sup> | Zeta 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

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
- User can send messages to friends, Message should be delivered instantly.
- User can search unblocked people, can send friend requests.
- User can see online/offline friends. Seen/Unseen messages.
- These sizes can be delivered as 1 message.
  - {text < 650 characters} {audio < 1 min/10 MB}   {video < 45min/1 GB}
- Chat history should be stored.  

# 2. BOE Calculations

|World Population=7x10<sup>9</sup> //Year 2020|InternetUsers = 40% = 2.8 Billion|FB Users= 60% of Internet users = 1.68 Billion|
|---|---|---|

|Users Sending|Text message|Audio Messages| Audio Messages |Video Messages|
|---|---|---|---|---|
|per day|60% = 1.68x0.6 = 1 Billion|20% = 1.68x0.2 = 336 Million|5% = 1.68x0.05 = 84 Million|
  
- **Data estimations(bytes to stored)**

| | 1 Day storage Req(bytes) | 5 years storage Req(bytes)
| --- | --- | --- |
| Chat | 1 Billion(messages) x 650x8(size) = 5.2 Trillion | 5.2 x 30 x 12 x 5 = 9.3 peta Bytes |
| Audio | 330Million(audio messages) x 10MB(size) = 3.3 Exa bytes | 3.3x30x12x5 = 6 Zeta bytes |
| Video | 84Million(video messages) x 1GB(size) = 84 Exa bytes | 84x30x12x5 = 151 zeta bytes |

Total space requirement for 5 years = 157 zeta bytes
> Not considering users who deleted chat/video/audio/account permanently. not considering compression.

# 3. HLD
## 3A. 2 users on same LAN
- user-1(192.168.1.2), user-2(192.168.1.3) provided by router
- Write 
