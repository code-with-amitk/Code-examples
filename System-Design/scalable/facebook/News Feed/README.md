# Facebook News Feed
- **What?** Whenever someone logs into account. He finds content posted on his network using new feed.
  - friend activities(status updates, photos, videos etc)
  - profile changes, upcoming events
  - news(if subscribed).

| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

# To Cover
- *1.* Requirements: Functional(Basic functionality, should work), Non-functional(defines quality), Extended
- *2.* Back of Envelope Calculations
  - Storage estimates
  - Traffic estimates
- *3.* HLD: For 2, 100, 1 lac users
- *4.* Database schema
- *5.* S<sup>3</sup> L<sup>3</sup> C<sup>2</sup> A<sup>3</sup> R<sup>2</sup> F
  - Scalable, Secure, SOA
  - Logging, Load, Latency
  - Cache(Invalidation, negative cache)
  - Available, Accurate, Analyze, Authenticate
  - Reliable, Redundant(Using DB)
  - Fast

## 1. Requirements
### 1A. Functional
- *a.* User should see his new feed as he logs in.
- *b.* Newsfeed should be custommizable, whatever user wants to subscribe/not.
### 1B. Non-Functional
- *a.* News feed should give soothing/smiling effect to user.
- *b.* Option for extending news feed once news feed gets over.
### 1C. Extended
- *a.* Option to hide/disable news feed.
- *b.* AI powered user specific search items

## 2. Back Of Envelope Calculations

- **People using Facebook**
  - Every person will have a news feed.

|World Population|InternetUsers(40%)|FB Users(60% of Internet users)|
|---|---|---|
|7x10<sup>9</sup> //Year 2020|2.8 Billion|1.68 Billion|

### 2A. Storage Estimates
