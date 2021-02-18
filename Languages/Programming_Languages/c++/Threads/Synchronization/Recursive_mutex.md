## Recursive Mutex
- **What?** RM can be locked multiple times by same thread(without deadlock), but in case of normal mutex locking already locked mutex results in undefined behavior.
- **Why?** In some recursive function resource lock is required again and again.        
- **How Implemented?** RM keeps count of how many times its locked hence same number of time unlock should be called.
- **How many time we can lock RM?** This is not defined, but if we reach that number
```c
                -> lock() will return system_error
                -> try_lock() will return false
```        


### Code
- 2 Threads locking mutex 5 times each
```c++
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
