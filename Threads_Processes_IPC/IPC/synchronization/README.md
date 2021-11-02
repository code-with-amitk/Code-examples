**Synchronization**
- [Mutex vs Semaphore vs Spinlocks](#vs)

## Synchronization
Coordination b/w processes/threads to access shared resources so that deadlock & race conditions can be avoided.
- **Why?** When multiple threads need to modify a shared resource(eg: global variable) we should lock the resource to guarantee at most 1 thread can do modification.

<a name=vs></a>
### Mutex vs Semaphore vs Spinlocks
> Suppose Thread-1 is in Critical Section and Thread-2 wants to enter in.
```c
- Suppose Thread-1 is in Critical Section and Thread-2 wants to enter in.

                   Mutex(Locked=Blocked=Sleep)   |                     Semaphore          |   Spin-lock(Busy Wait)
-------------|---------------------------------|----------------------------------------|---------------------------  
What         | Puts thread-2 in blocked state  | Signalling mechanism. Thread1 can      | Thread-2 keeps checking the lock
                                                 signal Thread2, once done in Critical  | continously in while(1). This 
                                                 section.                               | consumes CPU but is 3 times faster
                                                                                        | than Mutex.
IPC          |           yes                   |              yes                       |                                                                                 
             |                                 |                                        |
CPU Intesive | No. sleeping thread doesn't     | More wrt mutex                         | more wrt mutex
             | consume CPU
Implemented  | On top of kernel futex()
               {Mutual exclusion}
```
