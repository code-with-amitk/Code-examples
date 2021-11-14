- [Mutex Types](#ty)
  - [a. try_lock](#mtl)
  - [b. Recursive mutex](#rec)
  - [c. timed_mutex_try_lock_for](#tmtlf)
  - [d. timed_mutex_try_lock_until](#tmtlu)

<a name=ty></a>
## Mutex Types
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
