**Hashing**

### Hashing
- To store `data=<key,value>` on server, We need to find which server we need to store data.
- **Problem:** When a server is added/removed all keys need to be rehashed, and if 10 million keys & reshash takes 1 microsec. Time taken=10 seconds.
```c
//4 servers storing data
 key    Hash=key%4            Server0   Server1   Server2   Server3
  0     0%4 = 0       keys=>   0,4      1,5       2,6        3,7
  1     1%4 = 1
  2     2%4 = 2
  3     3%4 = 3
  4     4%4 = 0

//Let server1 goes down, then Hash=key%3 and all keys need to be rehashed
 key    Hash=key%3            Server0   Server2   Server3
  0     0%3 = 0       keys=>   0,3      1,4         2           //Note key=4 was on server0 now on server2. key=2 now on server3
  1     1%3 = 1
  2     2%3 = 2
  3     3%3 = 0
  4     4%3 = 1
```

### Consistent Hashing / Consistent Hash Ring = (Solution to above problem)
- Consistent hashing is technique where only k/n keys need to be rehashed, where k is the number of keys, and n is the number of servers.
- **What?** 
  - Strategy for storing distributed keys in distributed caches. In traditional approach whenever new keys are added/removed, ie new cache servers added/removed, [Rehashing](/DS_Questions/Data_Structures/Hash_Tables) is performed over old keys.
  - But in Consistent hashing rehashing is not required hence scaling up/down are fast and easy.

#### [Example (Distributed Cache Server)](Example)
