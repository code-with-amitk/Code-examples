**Semaphore**
- [How it works](#how)
- **Types of Semaphores**
  - [Binary](#b)
    - [Thread1 signals Thread2 to enter Critical Section, when Thread1 is done](#t1st2)
  - [Counting](#c)
- [Datastructures](#ds)
- [APIs](#api)
  - [sem_init](#si)
  - [sem_post](#sp)
  - [sem_wait](#sw)

## Semaphore
A integer whose [atomicity](/Threads_Processes_IPC/Terms) is maintained by kernel.
```c
  if (variable==1)            //sem_post
    //Enter in Critical section 

  if (variable==0)            //sem_wait
    //Entrace blocked. Wait
```
<a name=how></a>
## How it works
Similar to mutex only 1 thread can enter Critical section, But Thread-1 will signal Thread-2 once he's done. [Code](#t1st2)
```c
  Thread-1()      Critical_Section()      Thread-2()
      ---execute---->                     waiting
                   Thread-1 Done
                   
  signal Thread-2 ------------------------->
  waiting
                      <--------execute--------                  
```
## Types of Semaphores
<a name=b></a>
### Binary
Can take only 2 values (0 or 1).
<a name=t1st2></a>
#### Thread1 signals Thread2 to enter Critical Section, when Thread1 is done
```c++
#include<iostream>
#include<thread>
#include<unistd.h>
#include<semaphore.h>
sem_t sem;

void CriticalSection() {
  std::cout<<"Critical section\n\n";
  sleep(1);
}

void thread1(int a){
  for(;;) {
    std::cout<<"Thread1 inside ";
    CriticalSection();                //2. Thread1 goes into Critical Section, does processing
    sem_post (&sem);                  //3. Thread1 informs Thread2, that Thread1 is out of Critical Section
  }
}
void thread2(int a){
  for (;;) {
    sem_wait(&sem);
    std::cout<<"Thread2 inside ";
    CriticalSection();                  //4. Thread2 enters Critical Section
  }
}

int main(){
  std::thread t1(thread1, 5);            //1. Two Threads created.
  std::thread t2(thread2, 5);
  t1.join();
  t2.join();
}

# .a/out
Thread1 in Critical section
Thread2 in Critical section
Thread1 in Critical section
Thread2 in Critical section
```
<a name=ds></a>
## Datastructures
**sem_t:** volatile unsigned char
```c
# cat semaphore.h
typedef volatile unsigned char atomic_t
typedef atomic_t 	sem_t
```
<a name=api></a>
## APIs
<a name=si></a>
#### [sem_init](https://man7.org/linux/man-pages/man3/sem_init.3.html)
Initialize semaphore
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
<a name=sp></a>
### [sem_post](https://man7.org/linux/man-pages/man3/sem_post.3.html)
unlock a semaphore
```c
#include <semaphore.h>
int sem_post(sem_t *sem);

Return:
  sucess: 0; 
  Error: -1, value of semaphore is left unchanged, errno is set to indicate the error.
```
**How it works?**
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
<a name=sw></a>
### [sem_wait / Block](https://man7.org/linux/man-pages/man3/sem_timedwait.3.html)
lock a semaphore.
```c
#include <semaphore.h>
int sem_wait(sem_t *sem);
int sem_trywait(sem_t *sem);
int sem_timedwait(sem_t *restrict sem, const struct timespec *restrict abs_timeout);

Return:
  Sucess: 0 on success
  Error: -1, semaphore is left unchanged, errno is set to indicate the error.
```
**How it works?**
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
