- [Memory layout of Threads](#ml)
- [Joinable, Detachable Threads](#jd)
- [Problems with Threads / Problems in turning Single Threaded Code to Multithreaded](#p)
- [Synchronization needed to access shared resource](#sy)

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
if same function is executed by 2/more threads and resources are not thread safe, output is unpredictable. [2 Threads Executing same function](/Threads_Processes_IPC/IPC/synchronization/Mutex)
