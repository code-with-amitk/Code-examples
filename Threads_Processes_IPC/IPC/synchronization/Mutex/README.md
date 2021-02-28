## Mutex
- **What?** Mutual exclusion or Locking mechanism
- **Internal Implementation?**
  - This is kernel maintained lock that we set before using a shared resource and release after using it.
  - When the lock is set, no other thread can access the locked region of code.
  - Mutex lock will only be released by the thread who locked it.
- **Mutex Problems**
  - *1. Priority Inversion:*   Higher priority thread has to wait behind lower priority thread to get mutex lock & resource.
  - *2. Easy Deadlock:* if order of mutex locking/unlocking is not correct, that can led to easy dead-lock situation. See Dead-lock example.  
  
### Mutex Types
  - **a. Non-Recursive:** They cannot be locked more than once. Deadlock: if thread that has already locked the mutex tries to lock again, It will enter deadlock(waiting state).
  - **b. Recursive:** Allows thread holding lock to acquire the lock again. Helpful for recursive algorithms.
  - **c. Reader/Writer:** Multiple Readers can acquire Lock Simultaneously. If single reader is in, Writer access is blocked.  Writer is allowed only when all readers exits.
  - **d. Queuing:** FIFO is maintained for acquiring the mutex.     
  
