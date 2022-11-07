- Hashing
- [Consistent Hashing](#ch)

### Hashing
- In DHT(Distributed Hash Table), All `data=<key,value>` pairs are not stored same server, rather x number of servers are present.
- To store `data=<key,value>`, We need to find out of x on which server data should be stored. We can do using hashing
```c
key			hash-function	storage-server
ab(9798)	-->	 |ascii%3|  --> 0
bc(9899)	-->	 |ascii%3|  --> 1
ce(99101)	-->	 |ascii%3|  --> 2
					server0 [ab]
					server1 [bc]
					server2	[ce]
Server2 goes down or removed.
New Hash-Function = |ascii%2|.

RESHASHING: Data need to moved to remaining servers, existing keys are again passed thru new hash-function.

key			hash-function	  storage-server
ab(9798)	-->	 |ascii%2|	-->  0
bc(9899)	-->	 |ascii%2|	-->  1
ce(99101)	-->	 |ascii%2|	-->  1
						server0 [ab]
						server1 [bc, ce]
```
**Issue in Rehashing:** if hash function takes 1microsec and 10M keys to be rehashed. `10M * 1microsec = 10 sec`. Time is consumed in rehashing.

<a name=ch></a>
### Consistent Hashing / Consistent Hash Ring = (Solution to above problem)
- Consistent hashing is technique where only k/n keys need to be rehashed, where k is the number of keys, and n is the number of servers.
- keys are stored in ring of servers
#### Example
- server0(stores keys 0-10), server1(11-20), server2(21-30)
<img src=images/Consistent_Hashing1.png width=150/>

**Deletion of server1:**
  - server2 stores keys present on server1.
  - REHASHING: Only keys 11-20 need to rehashed not all.
<img src=images/Consistent_Hashing_Deletion.png width=150/>

**Addition of server4:**
  - server4 takes nearly half of keys stored on server1.
  - REHASHING: Only keys 11-15 need to be reshashed for storage on server4.
<img src=images/Consistent_Hashing_Addition.png width=150/>

#### Problem with Consistent Hashing
- 1 server/node can become hot, ie it can eventually hold many more keys wrt other, which leads to slow response time and increased latency
- **Solution:** Virtual nodes
  - Whenever any node goes towards becoming hotspot, new node is added which shares the keys. Hence some virtual nodes combined create 1 single node.
  - As load reduces virtual nodes are bought down.
<img src=images/Consistent_Hashing_VirtualNodes.png width=250/>
