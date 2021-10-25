- [Mutex](#mt)
- [Mutex internal Implementation](#in)
- [Mutex Problems](#mp)
- [Mutex Types](#ty)
- **Code**
  - 2 Threads Executing same function
    - [pthread](#pt1)
    - [C++ thread](#ct)

<a name=mt></a>
## Mutex / Mutual Exculsion / Locking mechanism
- if 1 thread is in other cannot enter.

<a name=in></a>
## Mutex internal Implementation
- This is kernel maintained lock that we set before using a shared resource and release after using it.
- When the lock is set, no other thread can access the locked region of code. Mutex lock will only be released by the thread who locked it.

<a name=mp></a>
### Mutex Problems
  - *1. Priority Inversion:*   Higher priority thread has to wait behind lower priority thread to get mutex lock & resource.
  - *2. Easy Deadlock:* if order of mutex locking/unlocking is not correct, that can led to easy dead-lock situation. See Dead-lock example.  
  
<a name=ty></a>
### Mutex Types
  - **a. Non-Recursive:** They cannot be locked more than once. Deadlock: if thread that has already locked the mutex tries to lock again, It will enter deadlock(waiting state).
  - **b. Recursive:** Allows thread holding lock to acquire the lock again. Helpful for recursive algorithms.
  - **c. Reader/Writer:** Multiple Readers can acquire Lock Simultaneously. If single reader is in, Writer access is blocked.  Writer is allowed only when all readers exits.
  - **d. Queuing:** FIFO is maintained for acquiring the mutex.     
  
## Code
### 2 Threads executing same function
<a name=ct></a>
#### C++ thread
Note asynchronous nature of threads, Thread-2 starts earlier than thread-1.
```
$ cat test.h
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

$ cat test.cpp
#include "test.h"
using namespace std;

int a = 5;
mutex m;

void test(int tid) {
    m.lock();
    a += 5;
    std::cout << "Thread: " << tid << ", a:" << a <<endl;
    m.unlock();
}

int main()
{
    vec.push_back(40);
    std::thread t1(test,1);
    std::thread t2(test,2);
    t1.join();
    t2.join();
    return 0;
}

///////Output without m.lock(), m.unlock()///////////
Thread: Thread: 1, a:15                 //Because Global variables are not thread safe.
2, a:15

///////Output with m.lock(), m.unlock()///////////
Thread: 2, a:10                         
Thread: 1, a:15
```

<a name=pt1></a>
#### pthread
```c
#include<pthread.h>

pthread_t tid1,tid2;  //Defined as int
int counter;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *fun(){
  pthread_mutex_lock(&lock);              //Thread-2 sleeps until Thread-1 unlocks the mutex
  printf("\n Thread-%d has started a job\n", pthread_self()); 
  for (unsigned long i = 0; i < (0xFFFFFFFF); i++) 	//Added to make processing large
    printf("\n Thread-%d has finished\n", pthread_self());
  pthread_mutex_unlock(&lock); 
  return NULL;	
}

int main(){
    pthread_create(&tid1,NULL,&fun,NULL);   
    pthread_create(&tid2,NULL,&fun,NULL);
    pthread_join(tid1, NULL);    
    pthread_join(tid2, NULL);
}
/*
Output:
- Without mutex_lock
 Thread--1997539584 has started a job
 Thread--2005932288 has started a job			//SEE BOTH THREADS ARE IN CS
 Thread--2005932288 has finished
 Thread--1997539584 has finished
 
- With pthread_mutex_lock()
 Thread-1438967552 has started a job
 Thread-1438967552 has finished
 Thread-1430574848 has started a job
 Thread-1430574848 has finished
*/
```

