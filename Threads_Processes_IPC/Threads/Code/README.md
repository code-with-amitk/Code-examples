**[Details about Thread APIs](../)**
- [Creating Threads](#cre)
  - [POSIX](#cp)
  - [C++](#ct)
    - [1. Using Object of thread class](#m1)
    - [2. Using Functor](#m2)
  - [Windows](#win)
  - [Rust](#ru)
- [Joinable, Detachable Threads](#jd)
- [Condition Variables](#cond)
  - [pthread_cond_t](#pc)
    - [Simple Example](#c1)
    - [Ping Pong game](#pp)
  - [C++, std::condition_variable](#cppc)
    - [1. Ping Pong using std::condition_variable, unique_lock](#cpppp)
  - [C++ condition_variable_any](#cppcva) 

<a name=cre></a>
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
- **[thread class](https://www.cplusplus.com/reference/thread/thread/thread/):**
<a name=m1></a>
#### 1. Using Object of thread class
```cpp
#include<thread>
void fun(int a){
  std::cout<<"Hello"<<a<<"\n";
}
int main() { 
  int a = 10;
  std::thread t1(fun, a);            //Creates Thread Object, which is entity that can start execution any time.
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

<a name=win></a>
#### Windows
```c
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
using namespace std;
DWORD WINAPI worker(LPVOID param) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int* data = (int*)param;
	TCHAR buf[60];
	DWORD dwChar;
	StringCchPrintf(buf, 60, TEXT("val=%d"), *data);
	WriteConsole(hStdout, buf, 10, &dwChar, nullptr);
	return 0;
}

int _tmain() {
	DWORD thread_id[5];
	for (int i = 0; i < 5; ++i) {
		CreateThread(
			NULL,               //Default security attributes
			0,                  //Use default stack size
			worker,             //thread function
			(void*)i,           //argument to thread function
			0,                  //Default creation flag
			&thread_id[i]);     //Thread identifier returned
	}

}
```
<a name=ru></a>
### [Rust](/Languages/Programming_Languages/Rust)
- Use [move](/Languages/Programming_Languages/Rust/Functions) before closure if want closure to take ownership of the values it’s using rather than allowing Rust to infer that it should borrow the values
```rs
$ cargo new thread1

$ cat main.rs
use std::thread;
fn fun1() {
	println!("Thread-1");
}

fn main() {
	let handle1 = thread::spawn(fun1);                      //Thread-1
	let handle2 = thread::spawn(                           //Thread-2 created using closure       
		|| {
		    for i in 1..5 {
		    	println! ("Thread-2");
			thread::sleep (Duration::from_millis(1));
		    }
		}
	);
	handle1.join().unwrap();                           //Thread1, Thread2 are joinable. main will not exit without t1,t2
	handle2.join().unwrap();
}
$ cargo build
$ cargo run
```

<a name=jd></a>
## Joinable, Detachable Threads
### Joinable Thread
Thread1(Main Process) waits for thread2 before it terminates itself. Thread1(Main process) cannot terminate before thread2 terminates.
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

### Detachable Thread
Thread-1/Main does not wait for Thread-2 to finish. Thread-1/Main is free to terminate.
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
- Thread1 waits for condition to be true, which is signalled(ie made true) by other Thread.
- This is a synchronization primitive that can be used to block a thread, or multiple threads at the same time, until another thread modifies a shared variable (the condition), and this unblocks 1 or multiple threads.
<a name=pc></a>
### 1. pthread_cond_t
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
<a name=cppc></a>
### 2. C++ [std::condition_variable](https://en.cppreference.com/w/cpp/thread/condition_variable) only works with [`unique_lock<mutex>`]
- same thread-1 waiting on condition variable, thread-2 changes cond variable then thread-1 starts in critical section.
- **Seqeunce:**
  - **For thread publishing on condition_variable:**
    - _a._ acquire a std::mutex (typically via std::lock_guard)
    - _b._ perform the modification while the lock is held
    - _c._ execute notify_one() or notify_all()
  - **For thread waiting on condition_variable:**
    - _a._ acquire a `std::unique_lock<std::mutex>`, same mutex as used to protect the shared variable
    - _b._ execute wait, wait_for, or wait_until.
<a name=cpppp></a>
#### Ping Pong using std::condition_variable, unique_lock
- _1._ Create 2 threads ping(), pong(). Consider execution starts from pong()
- _2._ Control reaches pong()
  - Own the `Mutex mtx` by creating [unique_lock](/Threads_Processes_IPC/IPC/synchronization/Mutex)
  - `cv.wait(unique_lock, []{wait_condition});` Wait on condition variable until wait_condition becomes true. if wait_condition==false, Donot go in.
  - Here start is false hence Pong will not be printed.
- _4._ Control reaches ping().
  - _4a._ mtx is owned by unique_lock. 
  - _4b._ `cv.wait(unique_lock, []{wait_condition});` wait_condition==true. Hence go in. Print ping
  - _4c._ unlock unique_lock. notify_one() one of threads waiting on condition variable (start).
  - _4d._ if we have not printed 10 times, goto pong().
```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
mutex mtx;
condition_variable cv;
bool start = false;
int k = 0;

void ping() {								//4
	while(1) {
		unique_lock<mutex> ulock(mtx);				//4a
		cv.wait(ulock, []					//4b
			{	//Wait until this code block return true
				return !start;
			}
		);
		if (k++ > 10)						//4d
			return;
		start = true;						//4c
		cout << "Ping\n";
		ulock.unlock();
		cv.notify_one();
	}
}

void pong() {
	while(1) {
		unique_lock<mutex> ulock(mtx);				//2
		cv.wait(ulock, []					//3
			{	//Wait until this code block return true
				return start;
			}
		);
		if (k++ > 10)
			return;
		start = false;
		cout << "Pong\n";
		ulock.unlock();
		cv.notify_one();
	}
}

int main() {
	thread t1(ping);		//1
	thread t2(pong);
	t1.join();
	t2.join();
	return 0;
}
```
<a name=cppcva></a>
### C++ condition_variable_any
- unlike [condition_variable]() which works with only unique_lock, these can work with any (eg: shared_lock)
