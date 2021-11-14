- [Mutex](#mut)
- [Mutex Problems](#mp)
- [Mutex Types](#ty)
  - [a. try_lock](#mtl)
  - [b. Recursive mutex](#rec)
  - [c. timed_mutex_try_lock_for](#tmtlf)
  - [d. timed_mutex_try_lock_until](#tmtlu)
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
  
<a name=ty></a>
### Mutex Types
- `include<mutex>` has 4 classes: mutex, recursive_mutex, timed_mutex, recursive_timed_mutex for providing synchronization to threads.
```c
         Type	               |                 What	                        | Locking same mutex Mutliple time
-----------------------------|----------------------------------------------|----------------------------------
1. mutex (non_recursive)     | Normal mutex                                 | undefined behaviour
2.try_lock/NON_BLOCKING      | if mutex is acquired by any other            | no
                               thread it returns back immediately
                               ie does not block
3. Recurive Mutex            | Locking same mutex again                     | yes
4. timed_mutex_try_lock_for  | Unlike try_lock()(Which returns immediately) | no
                               this waits for specific timeout duration 
                               and returns if lock is not acquired during 
                               that time.
5. timed_mutex_try_lock_until| same as Timed_mutex_try_lock_for but waits   | no
                               for specific time from present
```
<a name=mtl></a>
#### A. Mutex Try lock
- try_lock() tries to lock the mutex, if mutex is acquired by any other thread it returns back immediately ie does not block.
```c
Return value:
  true: if the lock was acquired successfully
  false: otherwise 
- Parameters: None
- Undefined-Behaviour/Deadlock: if try_lock() is called again by same thread who owns the mutex.
```
**Code**
```cpp
#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>

std::mutex m;
void fun(){
  m.try_lock();
  std::cout<<std::this_thread::get_id()<<" in CriticalSection.\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(4*1000));
  m.unlock();
}

int main(){
  std::thread t1(fun);
  std::thread t2(fun);
  std::cout<<std::this_thread::get_id()<<" Doing other task.\n";
  t1.join();
  t2.join();
}

# g++ mutex.cpp -pthread
# ./a.out 
140309152466752 Doing other task.
140309124548352 in CriticalSection.
140309133002496 in CriticalSection.
```
<a name=rec></a>
#### b. Recursive Mutex
- **What?** RM can be locked multiple times by same thread(without deadlock), but in case of normal mutex locking already locked mutex results in undefined behavior.
- **Why?** In some recursive function resource lock is required again and again.        
- **How Implemented?** RM keeps count of how many times its locked hence same number of time unlock should be called.
- **How many time we can lock RM?** This is not defined, but if we reach that number: lock() will return system_error, try_lock() will return false
- **Code**
```cpp
//2 Threads locking mutex 5 times each
#include<iostream>
#include<thread>
#include<mutex>

std::recursive_mutex rm;
int var=0;

void recursion(int th, int k){
  if(k==5)
    return;

  rm.lock();
  std::cout<<"Thread:"<<th<<", var:"<<var<<"\n";
  k++; var++;
  recursion(th, k);
  rm.unlock();
}

int main(){
  std::thread t1(recursion,0,0);
  std::thread t2(recursion,1,0);
  t1.join();
  t2.join();
}
# g++ recursive_mutex.cpp -pthread
# ./a.out 
Thread:0, var:0
Thread:0, var:1
Thread:0, var:2
Thread:0, var:3
Thread:0, var:4
Thread:1, var:5
Thread:1, var:6
Thread:1, var:7
Thread:1, var:8
Thread:1, var:9
```
<a name=tmtlf></a>
#### c. Timed mutex Try lock for
- **What is TIMED MUTEX?** Unlike try_lock(){Which returns immediately} this waits for specific timeout duration and returns if lock is not acquired during that time.
- **TRY_LOCK_FOR()?** Waits until specified timeout duration has elapsed or lock is acquired.
- **Return:**
  - true: if lock is acquired within timeout duration
  - false: if lock cannot be acquired
- **Code**  
```cpp
//Thread-1 acquires the lock, Sleeps for 4 seconds  
//Thread-2 wait for 3 seconds, But lock was not released in 3 seconds, so thread-2 returns false
#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

std::timed_mutex tm;

void fun(int t){
  if(tm.try_lock_for(std::chrono::milliseconds(3*1000))){
    std::cout<<"Thread "<<t<<" in Critical Section\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(4*1000));
    tm.unlock();
  }else{
    std::cout<<"Thread "<<t<<" cannot get the lock\n";
  }
}

int main(){
  std::thread t1(fun,1);
  std::thread t2(fun,2);
  t1.join();
  t2.join();
}

# g++ timed_mutex.cpp -pthread
# ./a.out 
Thread 1 in Critical Section
Thread 2 cannot get the lock
```
<a name=tmtlu></a>
#### d. timed_mutex_try_lock_until
- **TIMED MUTEX?** Unlike try_lock(){Which returns immediately} this waits for specific timeout duration and returns if lock is not acquired during that time.
- **TRY_LOCK_UNTIL()?** Waits until specified timeout duration from now() or lock is acquired.
- Return:
  - true: if lock is acquired within timeout duration
  - false: if lock cannot be acquired
- **Code**
```cpp
//Thread-1 acquires the lock, Sleeps for 4 seconds
//Thread-2 did wait for 3 seconds from Present time, But lock was not released in 3 seconds, so thread-2 returns false

#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

std::timed_mutex tm;

void fun(int t){
  auto currTime = std::chrono::steady_clock::now();
  if(tm.try_lock_until(currTime + std::chrono::milliseconds(3*1000))){
    std::cout<<"Thread "<<t<<" in Critical Section\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(4*1000));
    tm.unlock();
  }else{
    std::cout<<"Thread "<<t<<" cannot get the lock\n";
  }
}

int main(){
  std::thread t1(fun,1);
  std::thread t2(fun,2);
  t1.join();
  t2.join();
}

# g++ timed_mutex_try_lock_until.cpp -pthread
# ./a.out 
Thread 1 in Critical Section
Thread 2 cannot get the lock 
```

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


