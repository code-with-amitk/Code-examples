- [What is Mutex](#mut)
- [Mutex Problems](#mp)
- [Mutex Types: try_lock, recursive_mutex, timed_mutex_try_lock_for, timed_mutex_try_lock_until](Mutex_Types.md)
- **Code**
  - 2 Threads Executing same function
    - [pthread](#pt1)
    - [C++ thread](#ct)
- [lock_guard](#lg)
- [unique_lock](#ul)
- [scoped_lock C++17]()

<a name=mut></a>
## Mutex / Mutual Exculsion / Locking mechanism / Block / Sleep
- if 1 thread is in CS other cannot enter, Return value: None, Parameters: None
- **How Mutex is internally implemented?**
  - Mutex is kernel maintained lock(a data structure) that we set before using a shared resource and release after using it. Mutex keeps track of who currently has exclusive access to the data.
  - When the lock is set, no other thread can access the locked region of code. Mutex lock will only be released by the thread who locked it.
#### Code
**C++**
```c
//Note asynchronous nature of threads, Thread-2 starts earlier than thread-1.
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
int a = 5;
mutex m;
void test(int tid) {
    cout << this_thread::get_id() << " Waiting..\n";
    m.lock();
    a += 5;
    std::cout << "Thread: " << tid << ", a:" << a <<endl;
    m.unlock();
}

int main() {
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
**pthread**
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

<a name=mp></a>
### Mutex Problems
- **1. Priority Inversion:** Higher priority thread/process has to [Busy Wait](/Threads_Processes_IPC/Terms) outside critical section, because lower priority thread has locked mutex and is in Critical section.
- **2. Easy Deadlock:** if order of mutex locking/unlocking is not correct, that can led to easy dead-lock situation. See Dead-lock example.
- **3. Thread holding mutex paniced:** if thread-1 which holding the lock panics, whole process would panic.
  


<a name=lg></a>
## lock_guard
- [Good Video cppnuts](https://www.youtube.com/watch?v=ACoYnEzjEz4)
- We do mutex.lock() before going into CS and mutex.unlock() at exit
### Templated class lock_guard
- **what is lock_guard?**
  - This is mutex wrapper that provides a [RAII](/Languages/Programming_Languages/c++/OOPS_Principles), ie lock the mutex (mutex.lock()) no need to worry about unlocking (mutex.unlock()), when lock_guard object goes out of scope, mutex is automatically unlocked.
  - lock_guard provides mutex for duration of scoped block.
  - We cannot copy lock_guard, because operator = is deleted. Hence its not copy or move assignable.
- **Why?** If someone locks the mutex and forgets to unlock, then whole process will block.
- **How it works**
  - This is used to lock the mutex at object creation, But we donot need to unlock the mutex at exit from thread function (or when lock_guard object goes out of scope).
  - When lock guard object goes out of scope, destructor is called and mutex is unlocked.
```cpp
template<typename T>
class lock_guard {
public:
  lock_guard(T a):mutex(a){
    a.lock();
  }
  ~lock_guard(){
    a.unlock();
  }
  operator=[deleted]           //Cannot copy lock_guard
};
```
**Code Example**
```c
#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;

void fun(const char* name, int loop){
    lock_guard<mutex> lgLock(m);                //1. Create object of lock_guard and mutex is locked. Same as m.lock()
    for (int i=0;i<loop; ++i){
        cout << name << ": " << i << endl;
    }
}                                               //2. No need to do m.unlock(). This will done in destructor of lock_guard object

int main(){
    thread t1(fun, "T1", 3);
    thread t2(fun, "T2", 3);
    t1.join();
    t2.join();
    return 0;
}
$ g++ test.cpp -lpthread
$ ./a.out
T1: 0
T1: 1
T1: 2
T2: 0
T2: 1
T2: 2
```

<a name=ul></a>
## unique_lock
- This is similar to [lock_guard](#lg), but has additional features. Features:
  - deferred locking
  - time-constrained attempts at locking
  - recursive locking
  - transfer of lock ownership
  - Use with condition variables.
- unique_lock can be moved ie it is (MoveConstructible and MoveAssignable) but cannot be copied (not of CopyConstructible or CopyAssignable).
```cpp
class unique_lock{
mutex m;
public:
  unique_lock(mutex m):a(m){}
  ~unique_lock();
  operator=     //unlocks (i.e., releases ownership of) the mutex, if owned, and acquires ownership of another
  try_lock()
  try_lock_for()
  try_lock_until()
  unlock()
}
```


