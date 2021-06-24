- [1. Core / Multicore](#multicore)
  - [1.1 Caches with Core?](#cache)
- [2. MultiCPU](#multicpu)

<a name="multicore"></a>
## 1 Core / Multicore
- **What?** Miniprocessor(mini chip) on CPU chip which can act as complete processor by itself. 1 CPU chip can have 4, 8, or more cores on them. *[GPU](/Motherboard/CPU/GPU)* can have 1000's of tiny cores on them.
  - *Dual Core?* 2 CPU's on  Single CPU Chip
  - *Wuad Core?* 4 CPU's on Single CPU Chip
  - *Octa Core?* 8 CPU's on Single CPU Chip.
- *Max cores?* Intel Xeon Phi supports 60 cores/processor. Each core can have AT-MAXIMUM 2 threads. Total threads = 120
- *Are More cores better?* Think core as hands of a person. octa-cored(8 core/hand) person can work fast wrt dual-core.
- *Threads?* 1 core can have 2 threads.
- [Applications](/Motherboard/CPU/GPU/GPU/Applications_Advantages_Disadv.md)

<a name="cache"></a>
### 1.1 Caches with core
- **What?** Each core has its own L1 instr, L1 data cache, own L2 cache and shared L3 cache.
- **Cache Coherency Problem?** core-1 read variable(x=3) from main-memory and loads in its L1-cache and registers. core-2 also reads x=3 from RAM and stores in its cache/registers. Now core-1 modifies the value to x=5, core-2 will have stale value. caches are not coherent.
  - **Solution to CCP?** When (shared variable)var-1 is changed then values present at other caches should be changed. 

<img src=multicore.JPG width=600 />

<a name="multicpu"></a>
## 2. Multi CPU
- Instead of 1, there are n CPU Sockets. Additional H/W to connect all CPU's to RAM. 
- Found in Supercomputers. Eg: SuperMicro-7089 have 8 CPU/Processor. 28 core/CPU -> 228 cores -> 456 threads
