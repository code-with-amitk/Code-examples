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
- Message should be delivered instantly.
- User can see online/offline friends. Seen/Unseen messages.
- These sizes should be delivered as 1 message.
  - text < 500 words, audio/video < 10 MB
- Chat history should be stored.  

# 2. BOE Calculations
- Consider 7 Billion people on earth. 7x10<sup>9</sup>
- 40% are using internet. 28x10<sup>8</sup>
- Out of these 50% use facebook. 14x10<sup>8</sup>
- Only 10% of FB users do chat/send audio video per day. 14x10<sup>7</sup> users
- Each chat message=500 words=500x8 bytes.
- Data estimations(bytes to stored)

| | Per day | Per 5 years |
| --- | --- | --- |
| Text/Chat | 4000x14x10<sup>7</sup> | 56x10<sup>10</sup>x30x12x5 |
| Video | 
