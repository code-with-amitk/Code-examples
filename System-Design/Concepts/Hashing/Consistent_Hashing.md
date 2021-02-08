## Consistent Hashing / Consistent Hash Ring
- **What?** Very useful strategy for distributed caches for storing keys. When new keys are added/removed, ie new cache servers added/removed, [Rehashing](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Hashing/Hash_Table.md) is not required. Hence scaling up/down are fast and easy.
- **Advantage?** Avoids [Rehashing](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/Hashing/Hash_Table.md)

### Example: Distributed Cache Server
> Consider 3 cache servers(A,B,C). Cache server limit = 2500 keys 
- All <key,value> from 0-2500 will stored on server-B. From 2501 to 5000 on server-C so on. Now user want to store key=6000. It will be stored on Cache-server-A. A stores (5000-7500) keys.
- **Addition of New Cache Server?** Now someone wants to store 7501? There is no space on existing Cache-Servers. Cache Server D is pushed and all keys from 7501 to 10000 are added on it. Other cache servers are not touched.
- **Deleting a Cache Server?** Now server is getting less hits, decided to remove a cache server. Keys present on server-A are removed. No rehashing is required.

<img src="https://i.ibb.co/DwM0CZM/Consistent-Hashing.png" width=700 />

- **Searching Node in Ring** O(logn). This is [DAG(Directed Acyclic Graph)](https://github.com/amitkumar50/Code-examples/tree/master/DS_Questions/Data_Structures/Graphs/DAG)
