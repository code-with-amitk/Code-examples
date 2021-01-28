## Typeahead Suggestions
  - What?
    - Typeahead suggestions enable users to search for known and frequently searched terms.
      - if user types `bad`, our system should suggest `bad`, `badminton`, `badla movie` etc.
    - It’s not about speeding up the search process but rather about guiding the users and lending them a helping hand in constructing their search query.
    
### 1. FUNCTIONAL REQUIREMENTS
  - Provide fast, correct 10 top suggestions.
  
### 2. BOE CALCULATIONS
  - World population = 8 Billion.
  - 10% of people using internet actively daily. 8 Billion search request per day
  - 8 billion / 24*60*60 = 92k request/second. Assuming 100k
  
### 3. SYSTEM DESIGN
  - System will store all strings to be suggested to user.
  - We ***cannot use Database***(since results should be very fast)
    - System will store information in fast-memory.
#### 3.1 **STORING DATA**
  - **Trie** is most appropriate data structure for typeahead
``` 
              root
               /
              b
             /  
            a 
           / 
          d
         / \
        m   l
       /     \
      i       a
     /
    n
   /
  t
 /
o
/
n
``` 
  - To save space, nodes can be merged as well.
```
                root
                /
               b
              /
             a
            /
           d
         /  \  \
       boys la minton
```

#### 3.2 FINDING TOP SUGGESTIONS
  - There can be 2 different approaches to it.
    1. Displaying results in alphabetical order.
    2. Sorting most searched results to top internally
       - For example if past 500 users searched `badla` more then next search result will show `badla` above `bad boys` even `bad boys` is a head in dictionary wrt `badla`.
       - We can store `TOP 10 SUGGESTIONS` at every node. This will increase data storage hugely.
       - This top 10 suggestions can be passed from children to parent and parent can build his top 10 suggested words using it.
       
#### 3.3 HOW OFTEN TO UPDATE TRIE
  - if we think of updating trie after every request(100k times in 1 sec) its huge and will cause performance impact.
  - Either we can log every query or 1000th query. Note 1000 queries and then update the trie.
    - We can use `map-reduce` to process all logging data every hour.
  - We will update trie with suggestion from Map-Reduce after taking current snapshot.
  
#### 3.4 REMOVING WORD FROM TRIE
  - Let's suppose a word needed to be removed from trie based on `piracy` or `hatered` or `adulterage`.
  - Those words from trie can be removed when update happens on whole tree.'
  - We can also add `Filtering Layer` on every server before it sends such words to user.
  
#### 3.5 REBUILDING TRIE IN CASE OF LOSS
  - Since we are storing trie in memory, we should be storing trie on file as well so in case of machine scheduled restart trie is not lost.
![ImgUrl](https://i.ibb.co/VSJ8zBj/trie.png)
  - We can store this data in file `“C2,A2,R1,T,P,O1,D”` and can rebuild trie from it.
  - Please note, storing top suggestions and their counts with each node is very hard.
  
### 4. SCALE ESTIMATION
  - Out of 100k queries/sec(See BOE calculations). About 80% would be duplicate and only 20% would be unique.
  - We can build [index](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Indexing/README.md) for frequently searched terms.
  
### 5. STORAGE ESTIMATIONS
  - Assuming average word/term size = 10 character.
    - 2 bytes to store 1 character. 10x2 = 20 bytes/word
  - if we assume we have `100 million` unique terms/words. 100 millionx20 bytes = 2GB storage
  - Assuming 2% growth in words/terms everyday.
  - Removing 1% of words which are not searched everyday.
  - 1% of 100 million = 10 million/everyday.  300 million/month.  1200 million/year.  6000 million/5 year.
    - So, in 5 years we can expect 6000 million new words to be added.
    - 100 million -> 2GB
    - 6000 million -> `2*60`  = 120 GB space needed for 5 years.
    
### 6. DATA PARTITION
  - Although `Trie` can fit on 1 server, we can partition it for higher efficiency and lower latencies.
  - Strategies of paritioning
    a. Range-based partition
       - All letters/terms starting with `A` are stored on 1 DB server.
       - All letters/terms starting with `B` are stored on 1 DB server.
       - We can store all letters having less words on 1 server also.
    b. Partition based on server capacity.
       - DB-1 will store all words starting with ABC
       - DB-2 will store all words with DEFG and so on.
       
### 7. CACHING
  - Caching top searched terms will be helpful here. Memcached in front of Trie server will be good.

### 8. HLD
```
                                                                                             Storing-trie
  typeahead-Clients       Load-Balancer-pairs     App-servers   Load-Balancers    memcached==DB-Servers-master
                                                                                                |
                                                                                             DB-servers-replicas
```

### 9. TYPEAHEAD-CLIENTS
  - Server should only be reached if the user has not pressed any key for 50ms.
  - Client can pre-fetch some data from server to give fast results in future.
  - Clients should store recent history locally. Recent history always has very high rate of being reused.
  - Early connection with server is the key.  As user opens borwser, the client should connect() the server, hence when user starts typing in, client should not waster time in connecting to server.
  - CDNs should be used by server to push data near to client.
  
### 10. PERSONALIZED SUGGESTIONS
  - Users will recieve suggestions based on historical searches, preferences, location etc.
  - These can either be stored on client or on server.
  - Personalized searches always comes before others.
