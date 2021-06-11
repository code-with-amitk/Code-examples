### Mutex vs Semaphore vs Spinlock
> Suppose Thread-1 is in Critical Section and Thread-2 wants to enter in.

||Mutex(Locked=Blocked=Sleep)|Semaphore|Spin-lock(Busy Wait)|
|---|---|---|---|
|What|Puts thread-2 in blocked state|Signalling mechanism. Thread1 can signal Thread2, when he's done in Critical section.|Thread-2 keeps checking the lock continously in while(1). This consumes CPU but is 3 times faster than Mutex.|
|IPC|Yes|Yes||
|CPU Intensive?| No, sleeping thread does not consume CPU|more wrt mutex|more wrt mutex|
|Implemented|On top of kernel futex() {Mutual exclusion}||
