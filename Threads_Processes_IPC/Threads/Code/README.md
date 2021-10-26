**[Details about Thread APIs](../)**
- Creating Threads
  - [POSIX](#cp)
  - [C++](#ct)
    - [1. Using Object of thread class](#m1)
    - [2. Using Functor](#m2)


## Creating Threads
<a name=cp></a>
### POSIX
```c
#include<pthread.h>
#include<iostream>
using namespace std;
#define NUM_OF_THREADS 5

void* worker (void* arg) {
    cout << "Thread: " << *((int*)arg) << " Created" << endl;
}

int main() {
    pthread_t thread_id[NUM_OF_THREADS];
    int thread_args[NUM_OF_THREADS], ret;

    for (int i=0;i<NUM_OF_THREADS;++i){
        thread_args[i] = i;
        ret = pthread_create(&thread_id[i], 0, worker, (void*)&thread_args[i]);
    }

    for (int i=0;i<NUM_OF_THREADS;++i)
        pthread_join (thread_id[i], 0);
    return 0;
}

$ g++ test.cpp -lpthread
$ ./a.out
Thread: 0 Created
Thread: 1 Created
Thread: 2 Created
Thread: 4 Created
Thread: 3 Created
```
<a name=ct></a>
### C++
<a name=m1></a>
#### 1. Using Object of thread class
```cpp
#include<thread>
void fun(int a){
  std::cout<<"Hello"<<a<<"\n";
}
int main() { 
  int a = 10;
  std::thread t1(fun, a);
  t1.join();
}
```

<a name=m2></a>
#### 2. Using Functor
```cpp
void fun(int tid) {
    m.lock();
    a += 5;
    std::cout << "Thread: " << tid << ", a:" << a <<endl;
    m.unlock();
}
int main()
{
    
    for (int i = 0; i < 5; ++i) {
        vecThreads.emplace_back(
            [&]() {                             //Functor to create Threads
                fun(i); 
            }
        );
    }
    for (auto& t : vecThreads)
        t.join();
    return 0;
}
```
