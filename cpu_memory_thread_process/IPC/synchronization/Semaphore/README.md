## Semaphore
- **What?** This is simply a integer whose atomicity is maintained by kernel. if its value==1 then thread can enter CS else not.
- **Types of Semaphores?**
  - *a.* Binary: Can take only 2 values (0 or 1).
  - *b.* Counting: n number of threads can enter critical section
- SystemV Semaphore APIs(heavy wait)    semget(), semop(),
