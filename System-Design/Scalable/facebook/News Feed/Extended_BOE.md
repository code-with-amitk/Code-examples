## Extended BOE
- This is extensive BOE calculations which may not be needed.

- **People using Facebook**

|World Population|InternetUsers(60%)|FB Users(80-85% of Internet users)|
|---|---|---|
|7 Billion //Year 2020|7 x 0.6 = 4.2 Billion|4.2 x 0.8 = 3.5 Billion|

- **News Feed Usage statistics** Every person will have a news feed. 
  
### 3A. Storage Estimates (47~50PB)
- Photos/Videos would be stored on different [Object store](/System-Design/Concepts/Databases/Object_Storage/README.md) DB(Eg: amazon S3, ceph) for every user. This will not be considered as part of news feed.
- Storing users/comments/posts is part of new feed.
 #### 3A1. Object Table  //6 billion entries.
  - *1. Id:* We will use 62 different characters arranged at 6 positions.
```c
if we take 3 characters(a,b,c) and 2 positions _ _. How many unique Id's can be formed?
a a     b a     c a
  b       b       b   //3pow2 = 9 ways
  c       c       c

Each position of Id can have any of 62 characters.
  0-9 = 10
  A-Z = 26
  a-z = 26
	--------
	      62 characters
        
2 positions = 62pow2,  3 positions = 62pow3 ... 
6 positions = 62pow6 = 56 Billion combinations

////////////////Bytes to store///////////////
2 bits = 2 different numbers generated
4 bits = 16, 5 bits = 32
6 bits = 64. We will need 6 bits to store per character.

6 x 6 = 36 bits to store 6 characters. Assume 40. 5 bytes to store 1 id
- 5 x 6 billion = 30 GB to store Ids
```
  - *2. otype(string):* Considering max string length = 20 characters. 
```c
 a = 97 (In memory). If read as int its 97, if read as character its a.
 z = 122
 
 7 bits = 128. To represent any character between a to z. We need 7 bits per character. 140 bits for 20 characters = 18 bytes
 18 x 5 billion = 80 GB to store object-type
```
  - *3. data-type(byte)* 
    - username:
      - 3 Billion users. Each username can be max upto 50 characters. 150 Billion characters. 
      - 7 bits to represent each character(consider 1 byte). 150 GB
    - Post:
      - 1 Billion posts(assumed). Each post can have max 63206 characters. Total 63206 Billion = 6 Trillon characters.
      - 7 bits to represent each character(consider 1 byte). 6TB
    - Comments:
      - 2 Billion comments(supposed). Each comment can have max 8000 characters. Total 2x8000 = 16 Trillon characters.
      - 7 bits to represent each character(consider 1 byte). 16TB   
  - **Total bytes needed to store Object Table = 30GB(ids) + 80GB(otype) + 150GB(datatype=username) + 6TB(datatype=posts) + 16TB(datatype=comments) => 22TB**

 #### 3A2. Edge/Association Table  //12 billion entries.
  - *1. Id:* 5 bytes to store 1 id(calculated above). 12 Billion association table will have 24 billion ids. 24x5 = 120GB
  - *2. Edge-type* Considering max string length = 20 characters. 1 byte/character. 20 bytes x 12 Billion = 240GB
  - *3. key-value* Considering 100 characters. 1 byte/character. 100 bytes x 12 Billion = 1TB
  - **Total bytes needed to store Edge Table = 120GB + 240GB + 1TB => 2TB**  

**Total bytes needed to store Object Table+Association Table = 24~25TB. 25x30x12x5=47PB**
  
### 3B. Traffic Estimates
- As soon user logs in, his news feed has to be shown with least delay. Most data is sent from server to user/browser/FB app.
- Considering user has 5000 friends(max allowed friend's limit=5000), 5000 channels subscribed, As soon as user comes online, pooler service will send encrypted data to user over [WEBSOCKETS](/Networking/OSI-Layers/Layer5/LongPooling_WebSockets.md). Pooler service keeps pooling for user to get online.
- Considering 75% of fb users (3.5 x 75% = 2.5 Billion) are active every moment/every second.
  - **Data pumped into FB servers per second**
    - User/browser/FB app opens a Websocket to server as comes online. (HTTP GET size = 2KB). 2KB x 2.5 = 5k Billion Bytes = 5TB/sec comes to FB servers worldwide.
    - 193 countries in world, considering 1 data center per country(on average). 5TB/193 = 25GB/sec (pumped into 1 data center per second)
  - **Data reaching browser/FB App = 550kb(calculations below)**
```c
Considering 5000 friends, 5000 channels.

 On average:
Out of 5000 Friends, 2500 does 1 photo upload, 2000 shared a post, 500 uploaded a video. 
Http-response{XML or JSON}. Let XML contains 5000 links(shortened URLs). Ex: https://test.com/10-characters-shortened-url
1 URL size = Total characters = (test.com=8 + 10) = 20. Each character occupies 4 bits. 80 bits = 10 bytes.
5000 URLs size = 50000 bytes. 50 KB.
      
{Channels} Every channel posted 10 Links. 5000 x 10 = 50000 links
1 URL Size = 10 bytes
Total size = 50000 x 10 = 500 KB
```
