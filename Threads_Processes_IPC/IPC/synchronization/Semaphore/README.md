## Semaphore
- **What?** 
  - A integer whose atomicity is maintained by kernel.
  - if variable==1(entrance allowed in Critical section), if variable==0(Entrace blocked)
- **[Types of Semaphores](Types_of_Semaphores):** Binary, Counting
- SystemV Semaphore APIs(heavy wait)    semget(), semop(),
