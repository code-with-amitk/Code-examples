**There are two places to implement threads: user space and the kernel.**

## User Space Threads
- Kernel is not aware about UST
- Kernel see it as ordinary, single-threaded process.
- Each process will need its own **Thread Table**(to keep track of threads in process). 
### Thread Table
  - **What?** When thread is moved to sleep or blocked state(ie it finished its execution for moment), it state information is stored in thread-table so that later thread can come back to running state.For example thread1 waiting for input from thread2.
  - This is Similar to process table containing following entries:
```c
 Each thread’s program counter, stack pointer, registers, state etc
```


||User Space Threads|Kernel Space Threads|
|---|---|---|
||Kernel is not aware about UST|
|Advatange|<ul><li>UST can be implemented on OS which does not support threads</li></ul><ul>Lli>Each process can have its own customizes scheduling algo</li></ul>|
