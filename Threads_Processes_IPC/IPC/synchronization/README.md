- [Synchronization](#sy)
- [Types](#ty)
- [Mutex vs Semaphore vs spinlock](#vs)

<a name=sy></a>
## Synchronization
Coordination b/w processes/threads to access shared resources so that [deadlock & race conditions](/Threads_Processes_IPC/Terms) can be avoided.
- **Why?** When multiple threads need to modify a shared resource(eg: global variable) we should lock the resource to guarantee at most 1 thread can do modification.

<a name=ty></a>
## Types of synchronization
- Conditional variables, mutex, semaphore, spinlock, XCHG, TSL lock

<a name=vs></a>
### Mutex vs Semaphore vs Spinlocks
Suppose Thread-1 is in Critical Section and Thread-2 wants to enter in.

                   Mutex(Locked=Blocked=Sleep) |                     Semaphore          |   Spin-lock(Busy Wait){Fastest}
-------------|---------------------------------|----------------------------------------|---------------------------  
What         | Puts thread-2 in blocked state  | Signalling mechanism. Thread1 can      | Thread-2 keeps checking the lock
                                               |  signal Thread2, once done in Critical | continously in while(1). This 
                                               |  section.                              | consumes CPU.
                                               |                                        |  
```c
Fast         |                                 |                                        | Fastest, 3 times faster than mutex.
IPC          |           yes                   |              yes                       |                                                                                 
             |                                 |                                        |
CPU Intesive | No. sleeping thread doesn't     | More wrt mutex                         | more wrt mutex
             | consume CPU
Implemented  | On top of kernel futex()
               {Mutual exclusion}
ISR          |                                 |                                        | synchronization in ISR is achieved using
                                                                                          spinlocks. Since these are Fastest.
```
