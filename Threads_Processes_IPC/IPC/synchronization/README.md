## Synchronization
- **Why?** 
  - When multiple threads need to modify a shared resource(eg: global variable) we should lock the resource to guarantee at most 1 thread can do modification, such that a thread-1 cannot interfere with other thread-2 and leads to unexpected behaviors. 
  - Example: Thread-1 is in Critical section and thread-2 wants to enter inside
- **What?** Coordination b/w processes/threads to access shared resources so that deadlock & race conditions can be avoided.

### Mutex vs Semaphore vs Spinlock
> Suppose Thread-1 is in Critical Section and Thread-2 wants to enter in.

||Mutex(Locked=Blocked)|Semaphore|Spin-lock(Busy Wait)|
|---|---|---|---|
|What|Puts thread-2 in sleep/blocked state|Signalling mechanism|Thread-2 keeps checking the lock continously in while(1). This consumes CPU but is 3 times faster than Mutex.|
|IPC|Yes|Yes||
|Critical Section|Only 1 thread can be in|n threads can enter CS||
|Acquire-Release|Holded and released by same thread|1 can acquire other can release. Suitable for producer-consumer problem.|
|CPU Intensive?| No, sleeping thread does not consume CPU|more wrt mutex|more wrt mutex|
|Implemented|On top of kernel futex() {Mutual exclusion}||
