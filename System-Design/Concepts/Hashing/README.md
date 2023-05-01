- Hashing
- [Consistent Hashing](#ch)
  - [Problems in Consistent Hashing](#p)
  - [Solutions](#sol)

## Hashing
- In DHT(Distributed Hash Table), All `data=<key,value>` pairs are not stored 1 server, rather on n number of servers.
- To store `data=<key,value>`, We need to find out on which server data should be stored. We do this using hashing.
```c
key			hash-function	storage-server
ab(9798)	-->	 |ascii%3|  --> 0
bc(9899)	-->	 |ascii%3|  --> 1
ce(99101)	-->	 |ascii%3|  --> 2

		     |
		     |
           |Hash function = ascii%3|
		     |
	 ---------------------------
	 |	     |		   |
	\/ab	    \/bc	   \/ce
 -----------	 -----------	 -----------
| server-0 |	| server-1 |	| server-2 |
 ----------	 ----------	 -----------
```
### Issues in Hashing
#### Rehashing
- Suppose Server2 goes down or removed. New Hash-Function = |ascii%2|.
- Rehashing: Existent data need to moved to remaining servers, existing keys are again passed thru new hash-function.
```c
key			hash-function	  storage-server
ab(9798)	-->	 |ascii%2|	-->  0
bc(9899)	-->	 |ascii%2|	-->  1
ce(99101)	-->	 |ascii%2|	-->  1
						server0 [ab]
						server1 [bc, ce]
```
**Issue in Rehashing:** if hash function takes 1microsec and 10M keys to be rehashed. `10M * 1microsec = 10 sec`. Time is consumed in rehashing.

<a name=ch></a>
## Consistent Hashing / Consistent Hash Ring = (Solution to above problem)
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

<a name=p></a>
### Problems with Consistent Hashing
#### 1. Hotspot
- One server/node can become hot
- 1 server/node can eventually hold many more keys wrt other, which leads to slow response time and increased latency

#### 2. Adding and removing nodes
- Time, administrative cost of removing/adding node in cluster is high(which can lead to customer revenue loss).

#### 3. Node rebuilding
- When a node dies, it data is copied to other new node(which comes up).
- This consumes node's resources(cpu, memory) which will lead to node's performance degradation.

<a name=sol></a>
### Solution
#### 1. Virtual nodes (vnodes)
- Whenever any node becomes hotspot, new node(s) are added which shares the keys. Hence some virtual nodes combined create 1 single node.
- Earlier S1 was storing keys(500-2000), but now 4 nodes(S1_a, S1_b, S1_c, S1_d) distributes keys amongst themselves and stores a subrange.
- As load reduces virtual nodes are bought down.
- _Fault Tolerance:_ vnodes can carry other node's data for fault tolerance.
<img src=images/Consistent_Hashing_VirtualNodes.png width=250/>

- **Advantages of vnodes:**
  - _1. Data distributed more evenly:_ if a node dies less number of rehashing need to be done, since hashes are divided into smaller subranges and stored on vnodes.
  - _2. Cluster can contain less powerful machines:_ In vnodes some can be high power, while some can be low powerful machines. Since hash subranges can be smaller, its not required to have high end machine.
  - _3. Reducing hotspot probability:_ Hotspot probability is much less wrt consistent hashing, because in CH big range goes to 1 machine.
