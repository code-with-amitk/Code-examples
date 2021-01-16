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
- **1A. Functional**
  - *a.* User should see his new feed as he logs in.
  - *b.* Newsfeed should be custommizable, whatever user wants to subscribe/not.
- **1B. Non-Functional**
  - *a.* News feed should give soothing/smiling effect to user.
  - *b.* Option for extending news feed once news feed gets over.
- **1C. Extended**
  - *a.* Option to hide/disable news feed.
  - *b.* AI powered user specific search items

## 2. Back Of Envelope Calculations

- **People using Facebook**

|World Population|InternetUsers(40%)|FB Users(60% of Internet users)|
|---|---|---|
|7x10<sup>9</sup> //Year 2020|2.8 Billion|1.68 Billion|

- **News Feed Usage statistics**
  - Every person will have a news feed. 
  - 10% are superactive, see news feed every hour. 90% see news feed once in 7 days.
  
### 2A. Storage Estimates
- Photos/Videos/Messages/Posts would be stored on different Object store for every user. This will not be considered as part of news feed.
- In relational DB there will be mapping-table which holds information about friends. This is considered as part of new feed.
  - As soon there is change in any field of mapping-table, updater service will send information to poller service, as soon user comes online poller will update his new feed.
```c
Mapping Table     //on Relational DB

| User-name | ptr to LL of Friend's | ptr to LL of subscribed news | LL of sports | LL of personalities |
| amit | 0x5681821 | 0x01291 | none | .. |
| vivek | 0x02100aa | none | 0x28981 | .. |

LL of friends =                 //Better DS will be decided
  0x5681821   vivek -> anil -> anuj ..   
  0x02100aa   amit -> tiware -> jv ..   
LL of subscribed news channels = 
  0x01291  abp->cnn->al jazeera
  0x28981   dd->star->espn
```
- Pointer=8 byte address and 50 linked list pointers per user.  400 bytes/user.   400 x 1.68 = 672 Billion bytes = 672 GB
- Actual LL will store Ids of names.  1 ID = 8 bytes.
  - 1 person has 500 friends (on average), subscribed to 100(different groups) = 600 x 8 = 4800 bytes/user. 4800 x 1.68 = 8064 Billion bytes = 8 TB
- Overall 8 TB + .6 TB = 9 TB

### 2B. Traffic Estimates
