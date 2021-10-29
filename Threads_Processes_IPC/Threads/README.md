- [Why Threads](#w)
  - [When single threaded is better than Multi-Threaded](#st)
- [Memory layout of Threads](#ml)
- [Terms: yeild](#t)
- [Problems with Threads / Problems in turning Single Threaded Code to Multithreaded](#p)
- [Synchronization needed to access shared resource](#sy)
- [POSIX Thread APIs](#ta)
- **[User Space, Kernel Space Threads](#usks)**
  - [User space threads](#us)
  - [Kernel space threads](#ks)
- [Scheduler Activation](#sa)
- [Upcall](#up)
- **[Code](#co)**

<a name=w></a>
## Why Threads
- _1._ To run Tasks in parallel & parallelly tasks can be completed faster wrt sequential. [Thread usecases](..)
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
<a name=st></a>
#### When single threaded is better than Multi-Threaded
- Consider web-server serving telephone directory assistance for an area with (1 million = 10<sup>6</sup>) people only.
- If each record(name, telephone number) is 64 characters, the entire database takes (64x10<sup>6</sup>bytes = 64MB) 
- 64MB can easily be kept in the server’s memory to provide fast lookup. Multithreaded will be an overhead.

<a name=ml></a>
## Memory Layout of Threads
Every Thread have its seperate stack on Process stack. This is true for both [user-space](#us) and [kernel-space](#ks) threads.
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

<a name=t></a>		
## Terms
### Yeild
Means thread gives up CPU voluntarily by itself.

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

<a name=usks></a>
## User Space, Kernel Space Threads
<img src=./userspace_kernelspace_threads.PNG width=500 />

<a name=us></a>
### User Space Threads
- Kernel is not aware about UST. Kernel see it as ordinary, single-threaded process.
- Each process will need its own **[Thread Table](#tt)**(to keep track of threads in process). 
- **Advantages**
  - *1.* [Context switch] between threads is done in user space, no call into kernel space or call trap().
  - *2.* UST can be implemented on OS which does not support threads
  - *3.* Each process can have its own customized Thread scheduling algos.
- **Disadvantages**
  - *1.* If any of thread [busy waits]() on kernel for IO or [system call]() Eg: blocking read() then whole process will block/sleep. All other threads will also block(even if other threads are in runnable state).
    - *Solutions:* 
      - *1.* Making blocking calls as non-blocking.
      - *2.* [Upcall](#up)

<a name=tt></a>
#### Thread Table
- When thread is moved to sleep or blocked state(ie it finished its execution for moment), it state information is stored in thread-table so that later thread can come back to running state.For example thread1 waiting for input from thread2.
- This is Similar to process table containing following entries:
```c
 Each thread’s program counter, stack pointer, registers, state etc
```
<a name=ks></a>
### Kernel space threds
- When a thread wants to create/destroy an existing thread, it makes a kernel call, which then does the creation or destruction by updating the kernel [thread table](#tt).
- kernel have thread-Table having same contents.
- **Advantages**
  - *1.* No Thread-Table in each process.
- **Disadvantages**
  - *1.* Every thread will need some Thread-Control-block and stack space in kernel, in case of large number of threads this will become problem.
  - *2.* Every thread will make [system calls](https://sites.google.com/site/amitinterviewpreparation/c-1/device-driver) in kernel and its cost is high.
  - *3.* Slower than user level threads.

<a name=sa></a>
## Scheduler Activation
- When scheduler activations are used, the kernel assigns a certain number of virtual processors(core) to each process. Now user space process can allocate each thread on specific core.
- Intially only 1 virtual processors(core) is given to process, but process can ask more if required. The kernel can also take back virtual processors(core) & assign them to high priority process.

<a name=up></a>
## Upcall
- _1._ Suppose a [User Space Thread](#us) thread is block on kernel IO and due to it whole process is blocked. 
- _2._ Kernel is aware the Thread-1 has blocked the process.
- *3.* Kernel notifies Run-Time system(scheduler) (ie does **upcall**) that Thread-1 of Process-x has blocked, event why thread is blocked by copying data on Scheduler-Process's stack. Run-Time system will marks thread as blocked, takes other runnable threads and starts them.
- *4.* Later when kernel finds blocking system call is completed, it again makes a **upcall** and run-time system can restart the blocked thread immediately or put it on the ready list to be run later.
- **Objections to upcalls?**
  - *1.* upcalls violates the layered system architecture. ie Layer-n offering services that layer(n + 1) but layer(n+1) cannot pass information to layer-n. Upcalls do not follow this fundamental principle.


<a name=co></a>
## [Code](Code)
- Creating Threads: POSIX, C++
- Joinable, Detachable Threads
- Threaded Bookmyshow
- Threadpool
