## Semaphore
- **What?** A integer whose atomicity is maintained by kernel.
```c
  if (variable==1)
    //Entrance allowed into Critical section 
  if (variable==0)
    //Entrace blocked. Wait
```
- **[Types of Semaphores](Types_of_Semaphores):** Binary, Counting
- SystemV Semaphore APIs(heavy wait)    semget(), semop(),
