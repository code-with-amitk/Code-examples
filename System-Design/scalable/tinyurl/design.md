## 1: REQUIREMENT CLARIFICATION
#### a. Functional:
- Given a URL, our service should generate a shorter and unique alias of it
- When users access short link, our service should redirect them to the original link.
- Users should be able to pick a custom short link for their URL.
- Links should expire after default time span.
#### b. Non-Function:
- Highly available. 
- Minimum latency
#### c. Extended requirements:
- Analytics; e.g., how many times a redirection happened?


## 2. BACK-OF-ENVELOPE CALCULATIONS

> This is read heavy application. Consider 100:1 Read/Write requests.

#### Writes

10k new URL shortning requests/sec. 10k*60*60*30=1 billion requests/month

#### Read/Redirection

1000k reads/sec = 1 M reads/sec. 1M*60*60*30 = 100 billion reads/month.

#### STORAGE Estimate
- Let's assume long & short URLs are stored for 5 years.
- Long URL length=256 bytes, Short URL=6 bytes. 
    - 1 request requires 256+6=262 bytes to be stored
    - For 5 years. Total requests = 10k/sec*60*60*30*12*5 * 262 = 10k*1.5G = 10 Tera bytes
    
#### CACHE Estimates
 - To improve performance lets cache some URLs. Let's assume we will cache data for 1 day.
 - Following 80:20 rule, 20% of URLs are often hit.
    Total requests/day. 10k*60*60 = 36 Million. 20% of 36 Million = 7.2 Million * 262 = 1.8 GB
    
    
## 3. SYSTEM APIs
### creating the short URL
```
    //REST API
    createURL(api_dev_key, original_url, custom_alias=None, user_name=None, expire_date=None)    
      Parameters
        api_dev_key(string): Developer key of registered account.
        original_url(string): To be shortened
        custom_alias(optional): Custom key for URL
        user_name(optional): Username to be used for encoding
        expire_date(string): Optional expiration date of URL
      Returns
        short_url(string)
```        
        
### Deleting short and long URL pair from DB
```    
    deleteURL(api_dev_key, url_key)
      Parameters:
        url_key: shortened URL to be retrieved & removed
```        
        
## 4. DATABASE DESIGN
> Number of tables = 2

#### Table-1 Stores URL mappings(long URL to short URL)

| Original_url(512) | Creation_date | Expiration_date | UserID |
| --- | --- | --- |  --- |
| <long-url> | timestamp | timestamp |        |
    
#### Table-2 Stores user’s data who created the short link
| user_name | user_email | creationDate | lastLogin |
| --- | --- | --- | --- |
|    |   |   |   |

####  Type of DB: noSQL
Why? Billions of rows should be saved on noSQL


## 5. SYSTEM DESIGN (Generating Keys)

### 5.1 Method-1: Generating keys on Runtime
ie As system gets request to generate short-url, it creates short-key and returns.

#### Steps to generate keys on runtime

##### Step-1: Calculate hash of long URL
> long-url > |SHA3-Hash|  > 512bit            //We can take SHA3-Hash OR

long-url > |MD5-Hash|  > 128bit             //Let's consider this
        
##### Step-2: Converting 128bit hash to Base-64  format

> What is BASE-64 Number System?
> Short-url can be 8 characters long. Any character from [0-9][a-z][A-Z][+/] can come in short url.
> These are 64 different characters. So, BASE-64 number system. 64^8 = 2.8*10^14 = 280 Trillion possible strings.
> See How to convert Hexadecimal number to base-62 on Number system page

- Base-2 uses 2 bits to create a word : 2=2^1
- Base-8 uses 3 bits to create word : 8=2^3
- Base-16 uses 4 bits to create word: 16=2^4
- Base-64 uses 6 bits to create word: 64=2^6
- 128/6 = 21.33 = 21 characters or words. But we need only 8 characters as Output short-url.
        
##### Step-3: Deducing 8 character short-url from 21 characters.
- Return 1st 8 characters from 21 characters.
- Problem: Differnt long URL's can produce same 1st 8 characters.
- Solution: Append timestamp or userId with longURL and then generate the short url
        
##### Step-4: Store short URL in DB
```
        **client        App-server         encoder              DB**
             -long url->    -long url->
                                       encoded
                                            --short url-->
                                            <-Duplicate-
                                    regenerate & store
```
        
### 5.2 Method-2 Generate and store offline keys, use them at runtime
**KGS(Key generation service)**

KGS will generate the 6-letter keys beforehand and keep in key-DB.

##### Advantages of before hand key generation:
1. Run Time calculations saving. Hash & conversion to Base-64 will be saved.
2. Collions will be saved. We already have generated keys in place hence risk of same key generation is 0

##### Databases used by KGS
KGS will keep keys in 2 seperate databases.

| used keys DB |        //DB stores all allocated keys
| --- |
| xya123 |
    
| unused keys DB |      //DB storing unused keys
| --- |
| KHma45 |
    
###### Size of Key-DB
Base-64 will have 2^64 = 68.7 Billion unique six letters short urls.

1 key = 6 characters = 6 bytes.

Total storage = 6 * 68.7 Billion = 412 GB

###### Is KGS Single point of Failure? 
Yes
Solution: Take replicas/standby servers of KGS, replicas can take over to generate and provide keys.

###### Can App-Server cache some keys from KGS
> Yes


## 6. DB PARTIONING & REPLICATION
> To store billions of long URL to short URL mapping, we need distributed DB.

#### 6.1 Range based Partitions
DB-1 will store all short urls starting from 'A' and 'a'.
DB-2 will store all short urls starting from 'B' and 'b'.
..

###### Drawback of this approach
1 DB can be hugely loaded while other maybe free.
For example, we decide to put all URLs starting with letter ‘E’ into a DB partition, but later we realize that we have too many URLs that start with the letter ‘E’.

#### 6.2 Hash based Partitions
short-url is generated. Now hash value (between 1-256) is calculated from short-url as well and based on hash one of DB servers is selected for storage of long-url to short-url mapping.

###### Drawback of this approach
Again all times only 1 hash can be generated overloading only 1 server.

####### Solution
Consistent hashing

#### Cleaning/Purging of DB
- short-url to long-url mapping should be removed after 30 days or when user tolds.

## 7. CACHE
- Frequently asked long-url to short-url mappings would be stored in cache.

### How much cache memory is required
- Let's start with 20% of traffic storage
- **Traffic flowing in**
  - 10k new URL shortning requests/sec
  - 10k*60*60*24*7 = 6x10^9 = 6 billion requests/week
- **Cache size**
  - 1 incoming request size = 256 characters. = 256*4 = 1k bytes
  - 1 short URL size = 6 characters = 6*6 = 36 bytes
  - For 6 billion = 55296 billion bytes = 55 TB
- Cache can be fitted into number of smaller machines.  
- **Cache Eviction Policy**
  - When the cache is full, ***LRU*** will be used.
  
## 8. LOAD BALANCERS  
- Places where Load Balancers can be placed?
  1. Between client and Application servers.
  2. Between App-servers and cache. Since we can have 100s of cache servers, those needed load balancing.
  3. Between cache and DB servers. Since DB servers can be upto 256 LB in front of it is good.
  
## Final Architecture
![Imgur](https://i.ibb.co/rtNRtTd/tiny-url.png)
```
                                        **KGS(Key Generation Service)**
                                        - Generate 68.7 Billion short urls
                                        
                                        short-url > |Hash| > hash between 1-256
                                        //Let's suppose Hash=50, store on DB50
                                        
                                        Store short-url into respective DB using hash
                                        
                                                   ---store short url->   
                                                                        Unused
                                                                        Key-DB1
                                                                        Key-DB2
                                                                        Key-DB3
                                                                        ..
                                                                        Key-DB256

                                                   
        **client        (APP-SERVER(s)  +  cache(s)[Memcached])            KGS
             -long url--->        
                            ----long url->
                                        if mapping is found
                            <--return short url--
                                        else
                                            -----------long url------>
                                                                Map long-url to short-url
                                                                Move short-url to Used-DB
                             <--------------short url------------------          
```
