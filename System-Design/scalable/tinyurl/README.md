# Step 1: Requirements clarifications
## a. Functional:
* Given a URL, our service should generate a shorter and unique alias of it
* When users access short link, our service should redirect them to the original link.
* Users should be able to pick a custom short link for their URL.
* Links should expire after default time span.
## b. Non-Function:
* Highly available. 
* Minimum latency
## c. Extended requirements:
* Analytics; e.g., how many times a redirection happened?
    
    
/////////Step 2: Back-of-the-envelope estimation///////////
This is read heavy application.
Consider 100:1 Read/Write requests.
a. [Writes] 10k new URL shortning requests/sec. 10k*60*60*30=1 billion requests/month
b. [Read/Redirection] 1000k reads/sec = 1 M reads/sec. 1M*60*60*30 = 100 billion reads/month.
STORAGE Estimate:
- Let's assume long & short URLs are stored for 5 years.
- Long URL length=256 bytes, Short URL=6 bytes. 
    - 1 request requires 256+6=262 bytes to be stored
    - For 5 years. Total requests = 10k/sec*60*60*30*12*5 * 262 = 10k*1.5G = 10 Tera bytes
CACHE Estimates:
 - To improve performance lets cache some URLs. Let's assume we will cache data for 1 day.
 - Following 80:20 rule, 20% of URLs are often hit.
    Total requests/day. 10k*60*60 = 36 Million. 20% of 36 Million = 7.2 Million * 262 = 1.8 GB
    
    
//////////Step-3: System APIs////////////////////
a. creating the short URL:
    createURL(api_dev_key, original_url, custom_alias=None, user_name=None, expire_date=None)   //REST API 
      Parameters
        api_dev_key(string): Developer key of registered account.
        original_url(string): To be shortened
        custom_alias(optional): Custom key for URL
        user_name(optional): Username to be used for encoding
        expire_date(string): Optional expiration date of URL
      Returns
        short_url(string)
b. Deleting short and long URL pair from DB
    deleteURL(api_dev_key, url_key)
      Parameters:
        url_key: shortened URL to be retrieved & removed
        
        
////////Step-4:Database Design////////////////////
- Number of tables = 2
Table-1 Stores URL mappings.
    original_url(512)   creation_date   expiration_date     userID
Table-2 Stores user’s data who created the short link
        user_name   user_email  creationDate    lastLogin

- Type of DB: noSQL
Why? Billions of rows should be saved on noSQL


///////////Step-5: SYSTEM DESIGN/////////////////
>>>>HOW KEY GENERATION WORKS<<<<<<
USING BASE-64 Number System:
    - Short-url can be 8 characters long. Any character from [0-9][a-z][A-Z][+/] can come in short url.
    - These are 64 different characters. So, BASE-64 number system. 64^8 = 2.8*10^14 = 280 Trillion possible strings.
STEPS:    
    Step-1:     
        long-url > |SHA3-Hash|  > 512bit            //We can take SHA3-Hash OR
        long-url > |MD5-Hash|  > 128bit             //Let's consider this
        
    Step-2: Converting to Base-64    //See How to convert Hexadecimal number to base-62 on Number system page
        - Base-2 uses 2 bits to create a word : 2=2^1
        - Base-8 uses 3 bits to create word : 8=2^3
        - Base-16 uses 4 bits to create word: 16=2^4
        - Base-64 uses 6 bits to create word: 64=2^6
        128/6 = 21.33 = 21 characters or words. But we need only 8 characters as Output short-url.
        
    Step-3: Getting 8 character short-url from 21 characters.
        - Return 1st 8 characters from 21 characters.
        Problem: Differnt long URL's can produce same 1st 8 characters.
        Solution: Append timestamp or userId with longURL and then generate the short url
        
    Step-4: Store short URL in DB
        client          server         encoder              DB
             -long url->    -long url->
                                       encoded
                                            --short url-->
                                            <-Duplicate-
                                    regenerate & store
        
        
>>>>>>>OFFLINE KEYS<<<<<<<<<<<<
