### Cache Lines/Cache Block
  - **What?** CPU Cache content which is copied from RAM to cache. Data is transferred from RAM to CPU cache and is stored as cache line.
```c
Cache line 0 = 0 to 64 bytes
Cache line 1 = 65 to 127 bytes
so on
4095
```
  - **Cache Hit?** When the CPU want to RW data from RAM, it first checks for a data in cache. if data is found its cache hit else its cache miss
  - **Cache Miss?** CPU goes to RAM to read the data. After data is read from RAM, entry is Cache is updated.
  - **Number of Cache lines?**
    - Typically 4096 with each holding 64 bytes of data.
