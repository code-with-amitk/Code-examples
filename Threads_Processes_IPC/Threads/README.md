- Situtations
  - **1. Child Thread Dies**
    - [C++. Whole Process Dies](#s1c)
    - [Java. Whole Process DOES NOT Die](#s1j)
    - [Rust. Other threads keep running](#s1r)
- [Why threads, When single threaded is better than Multi-Threaded](Why_Threads.md)
- [Memory layout of Threads](#ml)
- [Terms: yeild](#t)
- [Problems with Threads / Problems in turning Single Threaded Code to Multithreaded](#p)
- [Synchronization needed to access shared resource](#sy)
- [POSIX Thread APIs](#ta)
- [User Space/Green Threads, Kernel Space/OS Threads](https://code-with-amitk.github.io/Threads_Processes_IPC/)
- [Scheduler Activation](#sa)
- [Upcall](#up)
- **[Code](#co)**



## Situations
### 1. Child Thread Dies
<a name=s1c></a>
#### 1a. {CPP} When child thread dies, Whole Process Dies
Because thread is created on process stack, have common CS, HS, DS.
```c
#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
void fun() {                    //2. Child Thread starts execution
    int a = 1/0;                //3. Dies. Divide by 0 exception
    cout << "Child thread";
}
int main() {
    thread t1(fun);            //1. Created child thread. It starts execution immediately
    sleep(5);
    cout << "main thread";    //4. Main process also Dies
    t1.join();
    return 0;
}
$ g++ test.cpp -lpthread
$ ./a.out
Floating point exception (core dumped)
```
<a name=s1j></a>
#### 1b. {Java} When child thread dies, Main Process DOES NOT Die
```java
class test implements Runnable {                     //Implement runnable interface if want thread to be created.
    test() {
        Thread t = new Thread (this, "New thread"); //2. Created child thread
        t.start();                                  //3. Started child thread. if start() is not called, Thread will not start
        try {
            for (int i = 0; i < 3; ++i) {
                System.out.println ("Parent Thread");    //5. But parent executes properly
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println ("Interrupted");
        }
        System.out.println ("exiting main thread");
    }
    public void run () {                              //4. Child Execution starts and it Dies
      int k = 1/0;
    }
    public static void main (String args[]) {
        new test();                                   //1. Constructor called
    }
}
$ javac test.java
$ java test
Exception in thread "New thread" Parent Thread
java.lang.ArithmeticException: / by zero
        at test.run(test.java:16)
        at java.base/java.lang.Thread.run(Thread.java:829)
Parent Thread
Parent Thread
exiting main thread
```

<a name=ml></a>
## Memory Layout of Threads
Every Thread have its seperate stack inside Process stack. This is true for both [user-space](#us) and [kernel-space](#ks) threads.
#### Thread1 executing fun1(), Thread2 executing fun2()
```c
<-----------------------Process Memory layout------------------------------------>
 <--------Process Stack--------------> 
 |<Thread1 stack>|<Thread2 stack>|
[|fun1           |fun2           |    ][ ptr-to-heap ][Data Segment][Code Segment]

```			
#### Memory layout of 2 threads executing same function
```c
<-----------------------------Process Memory layout--------------------------->
<-------Process Stack--------------> 
[ fun()                             ][ ptr-to-heap ][Data Segment][Code Segment]
 Thread1
 Thread2 accesses fun()
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

<a name=tt></a>
### Thread Table
- When thread is moved to sleep or blocked state(ie it finished its execution for moment), it state information is stored in thread-table so that later thread can come back to running state.For example thread1 waiting for input from thread2.
- This is Similar to process table containing following entries:
```c
 Each thread’s program counter, stack pointer, registers, state etc
```

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
