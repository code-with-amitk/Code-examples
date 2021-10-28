- [Atomic Operations](#at)
  - [Atomic Variables](#av)
- [Bound Waiting](#bw)
- [Busy Waiting](busyw)

## Terms
<a name=at></a>
### Atomic Operation(Uninterrupted Operation)
- The end result of AO is predictable and correct. Example:
```cpp
a = 0;
void fun () {     //2 Threads executing this function
  a += 12;
}

/////////Problem without Atomic////////
- Thread-1 enters fun() does a=12, At this point of execution, thread-1 is preempted and another thread-2 gets into same function.
- Thread-2 does a=12
- Thread-1 comes back and has previous value (12), instead of writing(14), it ends up in writing (12). But value should be 24.
  
/////Solution(Make operation a+=12 atomic):////////
a. Take a as volatile
b. Use synchronization methods.
```

<a name=av></a>
#### Atomic Variables
- Atomic types provide are used for shared-memory communication between threads. Atomic variables are safe to share between threads.
- ie values at end in these variables in not vague/unpredictable after n threads finished operating.
- [C++ Atomic](/Languages/Programming_Languages/c++/Threads/)

<a name=bw></a>
### Bound Waiting
Process-2 waits outside critical section while process-1 is executing inside.

<a name=busyw></a>
### Busy Waiting
- Let's suppose UserSpace program wants to read IO device. It invokes [Device Driver using device file](/Device_Drivers/Linux).
- [Device driver writes to Device Controller's register](/Device_Drivers/Linux/how) for reading memory address & device driver sits in loop, continuously polling the device to see if it is done 
- When IO is completed data(if any) is returned to driver. Device driver returns control to user space process. User space process was said to be in busy waiting.

<a name=cb></a>
### CPU Bound 
Process spends most of time with CPU executing instructions. From Source: Program doing lot of calculations Eg: finding all possible permutations of a string.
<a name=dl></a>
### Deadlock
2 or more threads waits on resources which is/are held by each other. None of thread releases the resource and in turn waits for other to release. 
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
<a name=io></a>
### IO Bound 
Process spends most of time in IO. From source: Program doing lot of File RW operations.
```c
Q: Find whether a process is IO Bound or CPU Bound?
 top command has %cpu column(Total CPU time used by process from when its started). CPU bound will have high %cpu.
 while (i<100){    ++i;                //Its %cpu = 100
    if(i==98)
        i=0;
 }
 ```
 <a name=cs></a>
### Critical Section(requires Mutual Exclusion)
  - Piece of code where 2 processes/threads are not allowed to execute concurrently. 
  - Ex: shared data structures, peripheral device, or network connection. CS should be accessed using synchronization. Eg: semaphore
- **Pareto Principle** 90% of CPU cycles are spent in 10% of code. Means we have to focus & parallelly implement this 10% of code
- **Race Condition?** 2 or more threads/processes are accessing/writing same shared resource(file, global variables etc) then at end result is unpredictable or wrong.
- **Reentrant**
  - Making second call same function while a previous call has not yet finished.
  - *Example:*
    - Suppose 2 threads can excute same function `fun()`.
    - Thread-1 executing is on line-11(writing to some big memory area `*ptr=bb`) of `fun()` & CPU decides to context switch. State of memory `*ptr` will be inconsistent and control is given to thread-2.
    - Thread-2 starts executing and writes to `*ptr=bbaaaa` and again context switch is done to thread-1.
    - Thread-1 comes back, expects `*ptr=bb` and starts writing `*ptr=bbbbb` and done.
    - Thread-2 reads `*ptr` thinking output as `bbaaaa` But `*ptr` is in inconsistent state.
  - **Solution:** mutex(But it eliminates parallelism)
```c
  fun(){            
      ...
11:    writing_to_big_memory (*ptr)
      ...
  }
  
int main(){  
  thread t1(fun);
  thread t2(fun);
  t1.join();
  t2.join();
}  
```
