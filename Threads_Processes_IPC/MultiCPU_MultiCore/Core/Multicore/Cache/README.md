## Caches
  - **What?** Each core has its own L1 cache, it also has its own registers.
  - **Cache Coherency Problem?**
    - core-1 read variable(x=3) from main-memory and loads in its L1-cache and registers. core-2 also reads x=3 from RAM and stores in its cache/registers. Now core-1 modifies the value to x=5, core-2 will have stale value. caches are not coherent.
  - **Solution to CCP?** When (shared variable)var-1 is changed then values present at other caches should be changed. 

<img src=cache_on_core.JPG width=500 />
