## Consistent Hashing / Consistent Hash Ring
- **What?** 
  - Strategy for storing distributed keys in distributed caches. In traditional approach whenever new keys are added/removed, ie new cache servers added/removed, [Rehashing](/DS_Questions/Data_Structures/Hash_Tables) is performed over old keys.
  - But in Consistent hashing rehashing is not required hence scaling up/down are fast and easy.

## [Example (Distributed Cache Server)](Example)
