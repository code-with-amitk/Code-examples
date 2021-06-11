## [sem_post](https://man7.org/linux/man-pages/man3/sem_post.3.html)
- unlock a semaphore
```c
#include <semaphore.h>
int sem_post(sem_t *sem);

Return:
  sucess: 0; 
  Error: -1, value of semaphore is left unchanged, errno is set to indicate the error.
```
- **How it works?**
  - _1._ Thread calls sem_post with semaphore value=1
  - _2._ sem_post increments the value. Now sempahore becomes 1.
    - Thread waiting on sem_wait wakes up.
```c
  sem_t s = 0;
  sem_post(s);                //1
  
  sem_post(sem_t* s){
    ++s;                      //2
  }
```
