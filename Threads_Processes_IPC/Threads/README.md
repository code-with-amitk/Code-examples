- [Why Threads](#w)
- [Memory layout of Threads](#ml)
- [Joinable, Detachable Threads](#jd)
- [Problems with Threads / Problems in turning Single Threaded Code to Multithreaded](#p)
- [Synchronization needed to access shared resource](#sy)
- [POSIX Thread APIs](#ta)

<a name=w></a>
## Why Threads
- _1._ To run Tasks in parallel & parallelly tasks can be completed faster wrt sequential.
```c
//Very Imp Example to understand (Tanenbaum). Do not Delete
Example-1: Suppose multiprogrammed system has degree of 6 (i.e 6 programs in memory at the same time).
           Assume that each process spends 40% of its time in I/O wait. What is CPU utilization?     
Ans: For 1 process. if Total time=1min, 0.4 min is IO Wait.
     For 6 processes. .04^6 is IO Wait.
     1 - 0.4^6 = 1 - 0.004096 = 0.995904 CPU Utilization

Example-2: Suppose there are 2 jobs(j1,j2), each needing (20 minutes of CPU time), 50% of IO Wait time starts simultaneously.
           How long will it take to complete if they run sequentially? How long if they run parallel.
Ans:
A. Sequential: 80 min.  | j1 IO Wait(20 min) | j1 CPU Time(20 min) | j2 IO Wait(20 min) | j2 CPU Time(20 min) |.
  CPU Utilization = 1 - 0.5^2  (Each job uses CPU for 0.5 times (20min IO, 20min CPU)). = 0.375.
  Each job gets CPU for 0.375 minutes from 1 minute (this includes IO wait time as well).
B. Parallel: 53.33 min (Actual)
 0.375  --> 1		           //0.375 CPU got in 1 min
 20     --> 20/0.375 = 53.33       //For getting 20 min CPU.
     60 min (Theoritical)
Once j1 goes to IO Wait, j2 also starts executing & enters IO wait.     
     | j1 IO Wait(20 min) | j1 CPU Time(20 min) |
     | j2 IO Wait(20 min) | ------------------- | j2 CPU Time(20 min) |
     
```

<a name=ml></a>
## Memory Layout of Threads
Threads have seperate stacks on Process stack
#### Thread1 executing fun1(), Thread2 executing fun2()
```c
<--------------Process Memory layout--------------------------->
[           Stack             ][ ptr-to-heap ][Data Segment][Code Segment]
 [Thread1 fun1] [Thread2 fun2]
```			
#### Memory layout of 2 threads executing same function
```c
<--------------Process Memory layout--------------------------->
[       Stack   fun()          ][ ptr-to-heap ][Data Segment][Code Segment]
 Thread1, Thread2 accesses fun()
```			
			
<a name=jd></a>
## Joinable, Detachable Threads
**Joinable Thread:** Thread1(Main Process) waits for thread2 before it terminates itself. Thread1(Main process) cannot terminate before thread2 terminates.
```c
#include<pthread.h>
void *thread2() {
  sleep(4);	//Even on sleep Main thread does not terminate
  printf("\nThread2 Created");
}

void main() {			//THREAD1 = MAIN PROCESS
  pthread_t tid;

  //pthread_create (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
  pthread_create (&tid, NULL, thread2, NULL);

  pthread_join(tid, NULL);
	
  printf("\nThread-1/Main terminates after Thread-2\n");
}
# gcc test.c -lpthread
# ./a.out
 Thread2 Created
 Thread-1/Main terminate2 after Thread-2
```

**Detachable Thread:** Thread-1/Main does not wait for Thread-2 to finish. Thread-1/Main is free to terminate.
```c
#include<pthread.h>
void *thread1 (){
  printf("\nThread1 created Detachable");
}

void main() {
  int ret;
  pthread_attr_t attr;
  ret = pthread_attr_init (&attr);		//Get thread attributes
  
  ret = pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);	//Set Detahable attributes
  
  pthread_t tid;
  pthread_create (&tid, &attr, thread1, NULL);	//Thread-1/Main is Detachable
  printf ("\n Inside Main thread\n");
}
# gcc test.c -lpthread
# ./a.out
  Inside main thread
```

<a name=p></a>
## Problems with Threads / Problems in turning Single Threaded Code to Multithreaded
#### 1. Global variables are shared
Threads will Conflict over use of Global variables.
- **Solutions:**
  - _a._ Use ATOMIC variables.
  - *b.* Prohibit global variables altogether.
  - *c.* Each thread its own private global variables. This will create new problem of accessing other thread's global variables.
  - *d.* Every thread allocates its own variables on heap & hence getting seperate copy. `struct* var = new new(struct var)`
#### 2. Many library functions are not [Rentrant](/Threads_Processes_IPC/Threads/Terms/)
#### 3. Signal Handling by Threads
- *a.* Signals like keyboard interrupt(Cntrl^C), are not thread specific. if 10 threads are there which thread should handle it?
- *b.* Singal handler code is global, Thread-1 changes the signal handler without telling Thread-2. Now thread-2 catches the signal.
- *c.* Thread-1, Thread-2 both want to catch the signal(Cntrl^C) and Thread-1 want to continue while Thread-2 want to terminate the process.
#### 4. Stack Management
- When process stack overflows, kernel provides that process with more stack automatically. When it becomes unmanagable it hangs.
- **Thread Stacks** When process has multiple threads, Each thread will have its own stack.
  - When thread stack overflows, kernel is not aware(since its entity inside process), user space process need to take care of it.

<a name=sy></a>
### Synchronization needed to access shared resource
- if same function is executed by 2/more threads and resources are not thread safe, output is unpredictable.
- Also note asynchronous nature of threads, Thread-2 starts earlier than thread-1.
  - [2 Threads Executing same function](/Threads_Processes_IPC/IPC/synchronization/Mutex)

<a name=ta></a>
### POSIX Thread APIs
## Thread APIs
```c
int pthread_create(pthread_tid *tid, pthread_attr_t *attr, void *(*func)(void *), void *arg)

int pthread_equal(pthread_t, pthread_t): Returns 0 if ThreadIds are not equal else 1

int pthread_join(pthread_t tid, void **status): Waiting on (Thread tid) to terminated. Similar to process waitpid.

pthread_t pthread_self(void): Thread can get its own thread ID using this API

int pthread_detach(pthread_t tid): To create a detachable Thread

pthread_cancel(pthread_t tid)    //Thread1 can terminate thread2

int pthread_mutexattr_init(pthread_mutexattr_t *attr): Initialize mutex attributes

int pthread_yield(void): Causes the calling thread to give up CPU(ie terminate himself) voluntarily so that other threads can take CPU.

pthread_exit();    //This will exit calling Thread
```
