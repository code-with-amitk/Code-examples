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
    - [Appproaches to search node storing data: Flooding, Random Walk, Policy Based Search, Broker/Super Peers](/System-Design/Concepts/Terms)

### 4. Deleting a Cache Server?
  - Now server is getting less hits, decided to remove a cache server. Keys present on server-A are removed. No rehashing is required.
