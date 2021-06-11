## Synchronization
- **What?** Coordination b/w processes/threads to access shared resources so that deadlock & race conditions can be avoided.
- **Why?** 
  - When multiple threads need to modify a shared resource(eg: global variable) we should lock the resource to guarantee at most 1 thread can do modification, 
  - thread-1 cannot interfere with other thread-2 and leads to unexpected behaviors.
- **[Mutex vs Semaphore vs Spinlocks](Mutex_vs_Semaphore_vs_Spinlock.md)**
