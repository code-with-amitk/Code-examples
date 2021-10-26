**[Details about Thread APIs](../)**
- Creating Threads
  - [POSIX](#cp)
  - [C++](#ct)
    - [1. Using Object of thread class](#m1)
    - [2. Using Functor](#m2)
- [Joinable, Detachable Threads](#jd)
- [Condition Variables](#cond)
  - [Simple Example](#c1)
  - [Ping Pong game](#pp)

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
<a name=cond></a>
## Condition Variables
Thread1 waits for condition to be true, which is signalled(ie made true) by other Thread
<a name=c1></a>
#### Simple Example
```c
#include<stdio.h>
#include<pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *fun1(void* arg) {
        //pthread_mutex_lock(&mutex);
	cout << "Thread1 waiting on condition\n";
        pthread_cond_wait(&cond, &mutex);               //pthread_cond_wait() might provide unexepected result without mutex
	cout << "Condition satisfied\n";
        //pthread_mutex_unlock(&mutex);
}
void *fun2(void* arg) {
        sleep(1);
	cout << "Thread2 signalled the condition\n";
        pthread_cond_signal(&cond);
}
int main(){
    pthread_t tid1,tid2;
    pthread_create(&tid1, 0, fun1, 0);
    pthread_create(&tid2, 0, fun2, 0);

    pthread_join(tid1, 0);
    pthread_join(tid2, 0);
}
$ ./a.out
Thread1 waiting on condition
Thread2 signalled the condition
Condition satisfied
```
<a name=pp></a>
#### Ping Pong game
```c
#include<stdio.h>
#include<pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

pthread_cond_t cond_ping = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_pong = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int j=0;

void *pong(void* arg) {
    while (j<10) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond_pong, &mutex);
        ++j;
        cout << "Pong" <<",j:"<< j <<"\n";
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond_ping);
    }
}
void *ping(void* arg) {
    while( j <10) {
        sleep(1);
        pthread_cond_signal(&cond_pong);
        pthread_mutex_lock(&mutex);
        ++j;
        cout << "Ping" <<",j:"<< j <<"\n";
        pthread_cond_wait(&cond_ping, &mutex);
        pthread_mutex_unlock(&mutex);
    }
}
int main(){
    pthread_t tid1,tid2;
    pthread_create(&tid1, 0, ping, 0);
    pthread_create(&tid2, 0, pong, 0);

    pthread_join(tid1, 0);
    pthread_join(tid2, 0);
}
$ ./a.out
Ping,j:1
Pong,j:2
Ping,j:3
Pong,j:4
Ping,j:5
Pong,j:6
Ping,j:7
Pong,j:8
Ping,j:9
Pong,j:10
```
