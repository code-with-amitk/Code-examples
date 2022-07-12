- [Mutex](#mut)
  - [How internally implemented?](#how)
- [Problems with Mutex](#mp)
- [Creating Mutex](#cr)
  - [1. C++](#cpp)
  - [2. pthread](#pt)
  - [3. Rust](#rs)
- [Mutex Types](Mutex_Types.md): try_lock, recursive_mutex, timed_mutex_try_lock_for, timed_mutex_try_lock_until
- **Code**
  - 2 Threads Executing same function
    - [pthread](#pt1)
    - [C++ thread](#ct)
- [Wrappers over Mutex](#wr)
  - [1. lock_guard](#lg)
  - [2. unique_lock](#ul)
  - [3. scoped_lock C++17]()

<a name=mut></a>
## Mutex / Mutual Exculsion / Locking mechanism / Block / Sleep
if 1 thread is in CS other cannot enter, Return value: None, Parameters: None
<a name=how></a>
#### How Mutex is internally implemented?
- Mutex is kernel maintained lock(a data structure) that we set before using a shared resource and release after using it. Mutex keeps track of who currently has exclusive access to the data.
- When the lock is set, no other thread can access the locked region of code. Mutex lock will only be released by the thread who locked it.
<a name=wake></a>
#### Wake up?
- When call to mutex.unlock() comes, signal is sent to scheduler. Scheduler checks all threads waiting on mutex.
- if 1000 threads are waiting, wakeup call to activate 1000 comes(also called **thundering herd**), but scheduler wakes up 1 thread(at its discretion) & 999 falls to sleep.

<a name=mp></a>
### Problems with Mutex
#### 1. Priority Inversion
  - Lower priority process is executing in Critical section, suddenly High-Priority process is scheduled, lower-priority process is preempted & thrown out of CS & higher priority process excecutes in CS. if 
  - if Higher priority thread/process is [Busy Waiting](/Threads_Processes_IPC/Terms) then lower priority process will never get CPU(ie never scheduled).
  - **Can PI happen on user-level threads?** No, there is no preemption in user level threads.
#### 2. Easy Deadlock 
if order of mutex locking/unlocking is not correct, that can led to easy dead-lock situation. See Dead-lock example.
#### 3. Thread holding mutex paniced
if thread-1 which holding the lock panics, whole process would panic.
#### 4. Mutex and data are seperate Entities
Thread-1,2 are accessing data using mutex, But thread-3 changed the data without mutex, this should not Happen.
  - _Solutions:_ 
    - [_1._ Making mutex and data as single entity as done in Rust](#rs)
    - _2._ All times keeping in mind that data should not handled outside mutex guards.
```c
std::mutex m;
int a = 5;
void test(int tid) {
    m.lock();
    a++;
    m.unlock();
}
int main() {
    std::thread t1(test,1);
    a += random_value;                      //But Thread-3=Main changed data without mutex.
    std::thread t2(test,2);                 //Thread-1,2 will access data using mutex.
    t1.join();                 
    t2.join();
    return 0;
}
$ ./a.out
Thread-1: 5
Thread-2: Random value
```

<a name=cr></a>
### Mutex Creation Code
<a name=cpp></a>
#### 1. C++
```c
//Note asynchronous nature of threads, Thread-2 starts earlier than thread-1.
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
std::mutex m;
int a = 5;
void test(int tid) {
    m.lock();
    a++;
    std::cout << "Thread: " << tid;
    std::cout << "a:" << a <<endl;
    m.unlock();
}

int main() {
    std::thread t1(test,1);     std::thread t2(test,2);
    t1.join();    t2.join();
    return 0;
}

///////Output without m.lock(), m.unlock()///////////
Thread: Thread: 1, a:7                 //Because Global variables are not thread safe.
2, a:6

///////Output with m.lock(), m.unlock()///////////
Thread: 2, a:6                        
Thread: 1, a:7
```
<a name=pt></a>
#### 2. pthread
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
<a name=rs></a>
#### 3. Rust
- In rust, Mutex is implemented as [Smart pointer](/Languages/Programming_Languages/Rust/Smart_Pointers), `Mutex<type>`.
- Mutex and data(data to be protected, shared data) are not seperate entities, ie we cannot access data without locking mutex. Rust will not allow
- We need to lock() the mutex to get the data.
```rs
use std::sync::Mutex;
fn main() {
    let m = Mutex::new(5);                   //1. Create mutex and associate a i32 data with it(whose initial value=5).
    {
        let mut num = m.lock().unwrap();     //2. Access to data inside Mutex is only allowed after lock() the mutex.
        *num = 6;                            //3. After acquiring lock, data inside mutex can be changed(treated as mutable reference).
    }                                        //4. Once mutex goes out of scope, data can be used without mutex.
    println!("m = {:?}", m);
}
```

<a name=wr></a>
## Wrappers over Mutex
- Wrapper means, these classes owns the mutex. To create object of any of these classes mutex has to be passed.

<a name=lg></a>
### 1. lock_guard
- [Good Video cppnuts](https://www.youtube.com/watch?v=ACoYnEzjEz4).
- We do mutex.lock() before going into CS and mutex.unlock() at exit.
- lock_guard owns the mutex, then this mutex is handled with lock_guard.
```cpp
mutex mtx;
lock_guard<mutex> lgLock(mtx);           //Mutex(mtx) is owned by lock_guard
```
#### Templated class lock_guard
- This is **Wrapper over Mutex** that provides a [RAII](/Languages/Programming_Languages/c++/OOPS_Principles), ie lock the mutex (mutex.lock()) no need to worry about unlocking (mutex.unlock()), when lock_guard object goes out of scope, mutex is automatically unlocked(destructor gets called).
- lock_guard provides mutex for duration of scoped block.
- We cannot copy lock_guard, because operator = is deleted. Hence its not copy or move assignable.
- **Why?** If someone locks the mutex and forgets to unlock, then whole process will block.
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
### 2. unique_lock
- This also owns the mutex, then this mutex is handled with unique_lock.
```cpp
mutex mtx;
unique_lock<mutex> ulock(mtx);           //Mutex(mtx) is owned by unique_lock
```
- This is similar to [lock_guard](#lg), but supports additional locking strategies(or types of unique_locks):
```cpp  
unique_lock<mutex> ulock(mtx);                    //Lock immdiately

unique_lock<mutex> ulock(mtx, defer_lock);        //deferred locking: Acquire the mutex but donot lock immediately.  

unique_lock<mutex> ulock(mtx);                   //time-constrained attempts at locking: try_lock_for(), try_lock_until()
mtx.try_lock_for(5 millisec);

//recursive locking
//unique_lock can be moved ie it is (MoveConstructible and MoveAssignable) but cannot be copied (not of CopyConstructible or CopyAssignable).
```
