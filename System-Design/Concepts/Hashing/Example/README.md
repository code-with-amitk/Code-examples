## Example (Distributed Cache Server)
> Consider 3 cache servers(A,B,C). Cache server limit = 2500 keys

<img src="Consistent Hashing.png" width=500 />

### 1. Storage of Data 
  - All <key,value> from 0-2500 will stored on server-B, 2501-5000 on C. Now user want to store key=6000. It will be stored on Cache-server-A. A stores (5000-7500) keys.

### 2. Addition of New Cache Server 
  - Now someone wants to store 7501? There is no space on existing Cache-Servers. Cache Server D is pushed and all keys from 7501 to 10000 are added on it. Other cache servers are not touched.
  - When a node joins it often contacts a well-known node to obtain a starting list in the system.

### 3. Searching Node in Ring  (Considering 10k nodes)
  - Every node maintains directed shortcut to every other node forming [DAG(Directed Acyclic Graph)](/DS_Questions/Data_Structures/Graphs/Terms) complexity O(nlogn)
  - **Search:** Suppose key-100 is requested by user and request comes to node-1, <key-100,value-100> is stored on node-100. Now node-1 need to find node storing value-100, get the value-100 & return to requestor. 
    - [Appproaches to search node storing data:](/System-Design/Concepts/Terms) Flooding, Random Walk, Policy Based Search, Broker/Super Peers.

|Approach|What|Disadv/Problem|
|---|---|---|
|1. Flooding||
|2. Random Walk|||
|3. Policy Based Search|||
|4. **Brokers/Super Peers**|<ul><li>As part of middleware layer, broker/super peer will facilitate communication b/w nodes(**Weak peers**). Super peer Maintains indexes</li></ul><ul><li>Super peer can attach to other super peer for replication</li></ul><ul><li>Weak peer can attach to another better super peer</li></ul>|<ul><li>Leader Election Problem: How to select a node eligible to become super peer</li></ul>|

### 4. Deleting a Cache Server?
    - Now server is getting less hits, decided to remove a cache server. Keys present on server-A are removed. No rehashing is required.
