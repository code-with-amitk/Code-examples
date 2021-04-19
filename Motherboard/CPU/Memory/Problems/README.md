- **1.** Consider a computer system which takes following times:
  - 1 nsec to access a word from the cache. Cache hit rate=95%
  - 10 nsec to access a word from the RAM. RAM hit rate(after a cache miss)=99%
  - 10 ms to access a word from the disk. 
  - What is the average time to access a word?
```html
Average access time =
    0.95 × 1 nsec (word is in the cache)
  + 0.05 × 0.99 × 10 nsec (word is in RAM, but not in the cache)
  + 0.05 × 0.01 × 10,000,000 nsec (word on disk only)
  = 5001.445 nsec = 5.001445 μsec
```
