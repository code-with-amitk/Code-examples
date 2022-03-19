**Redis (in Memory)**
- [Cache Eviction Policies](#ce)

## Redis(Remote dictionary server) (In Memory)
<a name=ce></a>
#### Cache eviction policies
- No eviction returning an error the memory limit is reached.
- All keys LRU removing keys by the least recently used first
- Volatile LRU removing keys, that have an expiration time set, by the least recently used first.
- All keys random removing keys randomly
- Volatile random removing keys, that have an expiration time set, randomly
- Volatile TTL removing keys, that have an expiration time set, by the shortest time to live first.
