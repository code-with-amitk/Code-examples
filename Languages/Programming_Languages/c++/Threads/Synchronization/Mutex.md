## Normal Mutex
- This is NORMAL/BLOCKING/SLEEPING mutex ie caller gets blocked/sleeps if some other thread has locked the mutex.
- Task after critical section remains blocked until mutex is acquired.
- Return value: None
- Parameters: None

### Code
```c++
#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

std::mutex m;
void fun(){
  std::cout<<std::this_thread::get_id()<<" Waiting..\n";
  m.lock();
  std::cout<<std::this_thread::get_id()<<" in fun()\n";
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  m.unlock();
}

int main(){
  std::thread t1(fun);
  std::thread t2(fun);

  t1.join();
  t2.join();
}

# g++ mutex.cpp -pthread;  ./a.out

139985246684928 Waiting..
139985246684928 in fun()
139985255139072 Waiting..
139985255139072 in fun()
```
