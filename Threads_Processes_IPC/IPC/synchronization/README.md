- [Synchronization](#sy)
- **Differences**
  - [Mutex vs Semaphore vs spinlock vs Condition Variable](#vs)
  - [Binary Semaphore vs Mutex](#vs1)
  - [Mutex vs Rwlock](#vs2)

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

|   |Mutex(Locked=Blocked=Sleep) | Semaphore | Spin-lock=[Busy Waiting](/Threads_Processes_IPC/Terms#busyw) | Conditional Variable |
|---|---|---|---|---|
|What| Puts thread-2 in blocked state | Signalling mechanism. Thread1 can signal Thread2, once done in CS. | Thread-2 keeps checking the lock continously in while(1). This consumes CPU.|Same as Semaphore|
| Fast | | | Fastest, 3 times faster than mutex||
| CPU Intesive | No. sleeping thread doesn't consume CPU | More wrt mutex | more wrt mutex ||
| Implemented | On top of kernel futex(){Mutual exclusion} | | ||
| ISR | | | synchronization in ISR is achieved using spinlocks. Since these are Fastest.||

<a name=vs1></a>
### Binary Semaphore vs Mutex
```c
```

### Mutex vs Rwlock
||Mutex|Rwlock|
|---|---|---|
|Multiple readers allowed in CS| no | yes(At a time n readers are allowed inside CS. or 1 writer) |
|Distinguishes reader and writer|no|yes|
