### Task          
- Create threads using thread class is introduced in c++11.
- Example:
  - Find sum of all even numbers between 1 to 9999999999  Task-1
  - Find sum of all odd numbers between 1 to 9999999999.  Task-2
- With 1 thread running parallely with main, time gets reduced to half[Amazing]
### Code
```c++
#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;

using ull = unsigned long long; //size=8.       2pow(64)
ull e = 9999999999;
ull s=0;
ull evensum, oddsum;

void evenSum(ull start, ull end){               //Task1
  for(int i=start;i<end; i++){
    if((i&1) == 0)
      evensum += i;
  }
}

void oddSum(ull start, ull end){                //Task2
  for(int i=start;i<end; i++){
    if((i&1) == 0)
      evensum += i;
  }
}

#ifdef NOTHREADS
int main(){
  auto startTime = high_resolution_clock::now();
  oddSum(s, e);
  evenSum(s, e);
  auto endTime = high_resolution_clock::now();
  auto diff = duration_cast<milliseconds>(endTime - startTime);
  cout<<diff.count()/1000<<" seconds";                    //6 seconds
}
#endif

#define THREADS
#ifdef THREADS
int main(){                             //Task1 by main process
  auto startTime = high_resolution_clock::now();
  thread t1(oddSum,s,e);          //Task2 by Thread(t1)           
  t1.join();
  auto endTime = high_resolution_clock::now();
  auto diff = duration_cast<milliseconds>(endTime - startTime);
  cout<<diff.count()/1000<<" seconds";                    //3 seconds
}
#endif

# g++ create-thread.cpp -pthread
```
