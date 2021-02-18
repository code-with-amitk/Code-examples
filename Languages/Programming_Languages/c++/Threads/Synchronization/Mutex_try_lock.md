## Mutex Try lock
- try_lock() tries to lock the mutex, if mutex is acquired by any other thread it returns back immediately ie does not block.
- Return value: 
```c
 true: if the lock was acquired successfully
 false: otherwise
``` 
- Parameters: None
- Undefined-Behaviour/Deadlock: if try_lock() is called again by same thread who owns the mutex.

### Code 
```c++
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
