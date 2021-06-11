## [sem_init](https://man7.org/linux/man-pages/man3/sem_init.3.html)
- Initialize semaphore
```c
#include <semaphore.h>
int sem_init(
     sem_t *sem          // pointer to semaphore variable    ,
     int pshared         // If = 0: can be used in threads only, else in process,
     unsigned int value  // initial value of the semaphore counter
);

Return:
  Success: 0 
  Error: -1, errno is set to indicate the error.
```
