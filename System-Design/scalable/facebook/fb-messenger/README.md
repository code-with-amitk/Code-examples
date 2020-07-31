# Facebook Messenger
- Users can send text/video/audio/image messages using laptop or mobile.

## Things to do
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
- These sizes should be delivered as 1 message.
  - text < 500 words, audio/video < 10 MB
- Chat history should be stored.  

# 2. BOE Calculations
- Consider 7 Billion people on earth. 7x10<sup>9</sup>
- 40% are using internet(2.8 Billion). Out of these 50% use facebook(1.4 Billion). 
- Let's suppose Only 10% of FB users(.14 Billion = 140 Million) send 1 chat/audio/video per day which needs to be stored.
  - 1 chat message = 500 words = 500x8 = 4k bytes
  - 1 audio message = 1 MB
  - 1 Video = 10 MB
- **Data estimations(bytes to stored)**

| Million | Billion/Giga | Trillion/Tera | Quadrillion/Peta | Quintillion/Exa | Zeta |
| --- | --- | --- | --- | --- | --- |
| 10<sup>6</sup> | 10<sup>9</sup> | 10<sup>12</sup> | 10<sup>15</sup> | 10<sup>18</sup> | 10<sup>21</sup> |

| | 1 Day storage Req(bytes) | 5 years storage Req(bytes)
| --- | --- | --- |
| Chat | 4k x 140 Million = 56 Billion | 56B x 30 x 12 x 5 = 1 Quadrillion |
| Audio | 1M x 140 Million = .14 Quadrillion | .14 x30x12x5 = 252 Quadrillion |
| Video | 10M x  14 Million = 1.4 Quadrillion | 25.2 Quadrillion |

Total space requirement for 5 years = 252+1+25.2 = 276 Quadrillion = 276 petabytes
> Not considering users who deleted chat/video/audio/account permanently. not considering compression.
