## Terms
- **Atomic Operation(Uninterrupted Operation)**
  - Operation which guarantees is completed without intervention of CPU. ie result at end of AO is predictable and correct.
  - Example: Let's function is incrementing a global/static variable.
    - Thread-1 is executing the fun() fetched count value(say 2). At this point of execution, thread-1 is preempted and another thread-2 gets into same function.
    - Thread-2 does count=3.
    - Thread-1 comes back and has previous value (2), instead of writing(4), it ends up in writing (3). But value of count should be 4 due to affect of both the threads.
    - Such kind of bugs are quite difficult to recreate and locate.
  - Achieving Atomic Operation:    
    - a. Taking a volatile variable     
    - b. Using synchronization methods.
```c
count = 2;
fun(){
  count++;    
}//This statement can be decomposed into, atleast three operations:    
    a. Fetching count value    
    b. Incrementing count value    
    c. Storing the updated value
```
- **Bound Waiting:** Process-2 waits outside critical section while process-1 is executing inside.
- **CPU Bound:** Process spends most of time with CPU executing instructions. From Source: Program doing lot of calculations Eg: finding all possible permutations of a string.
- **Deadlock**
  - 2 or more threads waits on resources which is/are held by each other. None of thread releases the resource and in turn waits for other to release. 
```c
Example-1
  Thread-1 acquires mutex-a. 
  Thread-2 acquires mutex-b. 
  Thread-1 wants to acquire mutex-b, thread-2 mutex-a
- Example-2:    
  Thread-1 acquires mutex a, b.    
  Thread-2 acquires mutex b,a
  
//Code for creating Deadlock
#include<pthread.h>
pthread_mutex_t     a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t     b = PTHREAD_MUTEX_INITIALIZER;
main(){
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1, NULL);     //Wait until thread-1 to terminate
    pthread_join(tid2, NULL);    ////Wait until thread-2 to terminate
}
void *thread-1(void *a){
    while(1){
        pthread_mutex_lock(&a); 
        pthread_mutex_lock(&b);
        pthread_mutex_unlock(&b);
        pthread_mutex_unlock(&a);
    }
}

void *thread-2(void *a){
    while(1){
        pthread_mutex_lock(&b); 
        pthread_mutex_lock(&a);
        pthread_mutex_unlock(&a);
        pthread_mutex_unlock(&b);
    }
}
```
- **IO Bound?** Process spends most of time in IO. From source: Program doing lot of File RW operations.
```c
Q: Find whether a process is IO Bound or CPU Bound?
 top command has %cpu column(Total CPU time used by process from when its started). CPU bound will have high %cpu.
 while (i<100){    ++i;                //Its %cpu = 100
    if(i==98)
        i=0;
 }
 ```
- **Critical Section(requires Mutual Exclusion):** 
  - Piece of code where 2 processes/threads are not allowed to execute concurrently. 
  - Ex: shared data structures, peripheral device, or network connection. CS should be accessed using synchronization. Eg: semaphore
- **[Deadlock](Deadlock)**
- **Pareto Principle** 90% of CPU cycles are spent in 10% of code. Means we have to focus & parallelly implement this 10% of code
- **Race Condition?** 2 or more threads/processes are accessing/writing same shared resource(file, global variables etc) then at end result is unpredictable or wrong.
- **[Reentrant](Reentrant)**


