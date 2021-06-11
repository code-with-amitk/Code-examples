## [sem_wait / Block](https://man7.org/linux/man-pages/man3/sem_timedwait.3.html)
- lock a semaphore.
```c
#include <semaphore.h>
int sem_wait(sem_t *sem);
int sem_trywait(sem_t *sem);
int sem_timedwait(sem_t *restrict sem, const struct timespec *restrict abs_timeout);

Return:
  Sucess: 0 on success
  Error: -1, semaphore is left unchanged, errno is set to indicate the error.
```
- **How it works?**
  - _1._ semaphore variable is 1 and sem_wait is called. 
  - _2._ sem_wait() decrements variable, 
  - _3._ if (semaphore_variable == 0)  
    - wait until becomes 1 (Done by sem_post()) or 
    - wait until interrupt handler provide interrupt
```c
  sem_t s = 1;                //1
  sem_wait(s);
  
  sem_wait(sem_t* s){
    --s;                      //2
    while (s == 0);           //3
  }
```
