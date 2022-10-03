**Hashing**

### Hashing
- To store `data=<key,value>` on server, We need to find which server we need to store data.
- **Problem:** When a server is added/removed all keys need to be rehashed, and if 10 million keys & reshash takes 1 microsec. Time taken=10 seconds.
```c
//4 servers storing data
 key    Hash-Function=key%4            Server0   Server1   Server2   Server3
  0     0%4 = 0              keys=>   0,4      1,5       2,6        3,7
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
- keys are stored in ring of servers
#### Example
- server0(stores keys 0-10), server1(11-20), server2(21-30)
<img src=images/Consistent Hashing1.png width=400/>

**Deletion of server1:**
 - server2 stores keys present on server1.
 - REHASHING: Only keys 11-20 need to rehashed not all.
<img src=images/Consistent Hashing_Deletion.png width=400/>

**Addition of server4:**
 - server4 takes nearly half of keys stored on server1.
 - REHASHING: Only keys 11-15 need to be reshashed for storage on server4.
<img src=images/Consistent Hashing_Addition.png width=400/>

#### Problem with Consistent Hashing
- 1 server/node can become hot, ie it can eventually hold many more keys wrt other, which leads to slow response time and increased latency
- **Solution:** Virtual nodes
 - Whenever any node goes towards becoming hotspot, new node is added which shares the keys. Hence some virtual nodes combined create 1 single node.
 - As load reduces virtual nodes are bought down.
<img src=images/Consistent Hashing_VirtualNodes.png width=400/>
