**[Details about Thread APIs](../)**
- Creating Threads
  - [POSIX](#cp)
  - [C++](#ct)
    - [1. Using Object of thread class](#m1)
    - [2. Using Functor](#m2)
- [Joinable, Detachable Threads](#jd)


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

<a name=jd></a>
## Joinable, Detachable Threads
**Joinable Thread:** Thread1(Main Process) waits for thread2 before it terminates itself. Thread1(Main process) cannot terminate before thread2 terminates.
```c
#include<pthread.h>
void *thread2() {
  sleep(4);	//Even on sleep Main thread does not terminate
  printf("\nThread2 Created");
}

void main() {			//THREAD1 = MAIN PROCESS
  pthread_t tid;

  //pthread_create (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
  pthread_create (&tid, NULL, thread2, NULL);

  pthread_join(tid, NULL);
	
  printf("\nThread-1/Main terminates after Thread-2\n");
}
# gcc test.c -lpthread
# ./a.out
 Thread2 Created
 Thread-1/Main terminate2 after Thread-2
```

**Detachable Thread:** Thread-1/Main does not wait for Thread-2 to finish. Thread-1/Main is free to terminate.
```c
#include<pthread.h>
void *thread1 (){
  printf("\nThread1 created Detachable");
}

void main() {
  int ret;
  pthread_attr_t attr;
  ret = pthread_attr_init (&attr);		//Get thread attributes
  
  ret = pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);	//Set Detahable attributes
  
  pthread_t tid;
  pthread_create (&tid, &attr, thread1, NULL);	//Thread-1/Main is Detachable
  printf ("\n Inside Main thread\n");
}
# gcc test.c -lpthread
# ./a.out
  Inside main thread
```
