## Terms
- **[Atomic Operation(Uninterrupted Operation)](Atomic_Operation)**
- **Bound Waiting:** Process-2 waits outside critical section while process-1 is executing inside.
- **CPU Bound:** Process spends most of time with CPU executing instructions. From Source: Program doing lot of calculations Eg: finding all possible permutations of a string.
- **IO Bound?** Process spends most of time in IO. From source: Program doing lot of File RW operations.
```c
Q: Find whether a process is IO Bound or CPU Bound?
 top command has %cpu column(Total CPU time used by process from when its started). CPU bound will have high %cpu.
 while (i<100){    ++i;                //Its %cpu = 100
    if(i==98)
        i=0;
 }
 ```
- **Critical Section(requires Mutual Exclusion):** 
  - Piece of code where 2 processes/threads are not allowed to execute concurrently. 
  - Ex: shared data structures, peripheral device, or network connection. CS should be accessed using synchronization. Eg: semaphore
- **[Deadlock](Deadlock)**
- **Pareto Principle** 90% of CPU cycles are spent in 10% of code. Means we have to focus & parallelly implement this 10% of code
- **Race Condition?** 2 or more threads/processes are accessing/writing same shared resource(file, global variables etc) then at end result is unpredictable or wrong.
- **[Reentrant](/Threads_Processes_IPC/Threads/Terms/)**


