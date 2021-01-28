## Consistent Hashing / Consistent Hash Ring
- **WHAT?** Very useful strategy for distributed caches for storing keys. When new keys are added/removed, ie new cache servers added/removed, rehashing is not required. Hence scaling up/down are fast and easy.
- **ADVANTAGE?** Avoids rehashing.

### Example: DISTRIBUTED CACHE SERVER
- Consider 3 cache servers(A,B,C). Cache server limit = 2500 keys 
- All <key,value> from 0-2500 will stored on server-B. From 2501 to 5000 on server-C so on. Now user want to store key=6000. It will be stored on Cache-server-A. A stores (5000-7500) keys.
- **Addition of New Cache Server?** Now someone wants to store 7501? There is no space on existing Cache-Servers. Cache Server D is pushed and all keys from 7501 to 10000 are added on it. Other cache servers are not touched.
- **Deleting a Cache Server?** Now server is getting less hits, decided to remove a cache server. Keys present on server-A are removed. No rehashing is required.

<img src="https://i.ibb.co/DwM0CZM/Consistent-Hashing.png" width=700 />
