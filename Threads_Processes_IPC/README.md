- [Thread vs Process](#vs)
- [Thread usecases](#uc)
- [Multiprocessing vs Multitasking](#vs1)
- [Hyperthreading](#ht)

<a name=vs></a>
### Thread(miniprocess) vs Process
- [Memory Layout of process](https://code-with-amitk.github.io/Motherboard/Memory/Processes.html)
```c
                         UserSpace Thread                                    |                             Process                           |
-------|------------------------------------------------------------------ --|---------------------------------------------------------------|
Weight | Light(Since no duplication of process space)                        | Heavy(Complete process space(CS,DS,SS,HS) duplicated to child |
Speed  | Fast.                                                               | Slow.
         - No Context Switch:                                                |   - Context Switch needed:
           Switching from Thread-1 to Thread-2 does not need context         |     Memory cache flushing needed, Trap needed and to achieve 
           Switch,No memory cache flush, No Trap instruction.                |     these control need to go into kernel space
           bcoz: Everything is inside process(No need to go in kernel space) |
           Process can decide his own scheduling algo 
Disadv |If 1 thread blocks, whole process blocks. [See userspace, kernel Threads]
```

<a name=uc></a>
### Thread Usecases
- **1. Editing/Displaying/(Storing on cloud) Big word document at same time**
  - Suppose user is editing 10000 lined word document online. if he edits 9000th page and click save, word process need to search from starting text changed, pick and store the diff on cloud. If user want to scroll to some other page while word process is saving on cloud(Since this is single threaded) this will hang the Word Document(making user annooyed).
  - **Solution** 3 threads, 1 for diplay, 1 for saving on cloud, 1 for editing the file(ie picking up the changes). Benefits of 3 threads: while thread-2 is saving on cloud. Thread-1 can still display contents of user without delay.
- **2. Webserver:** if webserver is single threaded, then it has to wait everytime to get resource from DB/backend while incoming connections keep on getting discarded.
- **3. Downloading big file:** Suppose client want download 2-GB file from Internet. File is available from mirror servers, each can deliver 512 MB. With Threads we can download all chunks parallely, but again if there's a single network link shared by all threads, this can become bottleneck as the number of threads becomes very large.

<a name=vs1></a>
### Multiprocessing vs Multitasking
```c
                 Multiprocessing          |               Multitasking
----------|-------------------------------|-------------------------------------------
What      |                               | - Only 1 processor, multiple threads are run in time sliced manner.
```

<a name=ht></a>
### Hyperthreading / SMT(Simultaneous Hyper Threading)
Split a core into virtual [cores](/Threads_Processes_IPC/MultiCPU_MultiCore) and assign a thread to each of core.
