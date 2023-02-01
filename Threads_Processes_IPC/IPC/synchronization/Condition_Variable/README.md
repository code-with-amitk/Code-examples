**Conditional Variable**
- **Code**
  - [1. Thread1 signalling Thread2 using pthread](#c1)
  - **2. Ping Pong game**
    - [A. pthread_cond_signal 2 threads](#c2)
    - [B. C++, std::condition_variable, unique_lock](#ppcv)
      - [Using 2 threads](#c3)
      - [Using 4 threads](#c4)
  - [C++ condition_variable_any](#cppcva) 

<a name=cv></a>
## Conditional Variable / Condition Variable / shared variable
- This block 1/multiple thread(s) until another thread modifies a shared variable (the condition), and notifies the condition_variable.
- **Advantages?**
  - Avoids [busy waiting](/Threads_Processes_IPC/Terms#busyw), which spinlock does. For instance, if you have a thread (or multiple threads) that can't continue onward until a queue is empty, the busy waiting approach would be to just doing something.
- **Similar to [Semaphores]**
  - CV and semaphores are similar, both signals the sleeping threads, but counting semaphore is used for n available things.

## Code
<a name=c1></a>
### 1. Thread1 signalling Thread2 using pthread
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
### Ping Pong game
<a name=c2></a>
#### A. Ping pong using pthread
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
<a name=ppcv></a>
#### B. Ping pong using [std::condition_variable](https://en.cppreference.com/w/cpp/thread/condition_variable), `unique_lock<mutex>`
- std::condition_variable only works with [unique_lock](/Threads_Processes_IPC/IPC/synchronization/Mutex)
- **Seqeunce:** Thread-1 waiting on condition variable, thread-2 changes cond variable then thread-1 starts in critical section.
  - **Thread-2 publishing on condition_variable:**
    - _a._ acquire a std::mutex (typically via std::lock_guard)
    - _b._ perform the modification while the lock is held
    - _c._ execute notify_one() or notify_all()
  - **Thread-1 waiting on condition_variable:**
    - _a._ acquire a `std::unique_lock<std::mutex>`, same mutex as used to protect the shared variable
    - _b._ execute wait, wait_for, or wait_until.
<a name=c3></a>
#### ping pong using 2 threads
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

void ping() {								//5. Control reaches ping()
	while(1) {
		unique_lock<mutex> ulock(mtx);				//5a. mtx is owned by unique_lock
		
		//5b. `cv.wait(unique_lock, []{wait_condition});` wait_condition==true.
		//Hence go in. Print ping
		cv.wait(ulock, []{ return (start==false;); } );		//if wait condition is true ie start==false, go in
		
		if (k++ > 10)						//5e. if we have not printed 10 times, goto pong()
			return;
		start = true;
		cout << "Ping\n";
		
		ulock.unlock();                                         //5c. unlock unique_lock.
		cv.notify_one();					//5d. notify_one() one of threads waiting on condition variable (start).
	}
}

void pong() {                                                            //2. Control reaches pong()
	while(1) {
		unique_lock<mutex> ulock(mtx);				//3. Own the `Mutex mtx` by creating unique_lock
		
		//4. `cv.wait(unique_lock, []{wait_condition});` 
		//Wait on condition variable until wait_condition becomes true. 
		//if wait_condition==false, Donot go in.
		//Here start is false hence Pong will not be printed
		
		cv.wait(ulock, []{ return (start==true;); } );		//if wait condition is true ie start==true, go in
		
		if (k++ > 10)
			return;
		start = false;
		cout << "Pong\n";
		ulock.unlock();
		cv.notify_one();
	}
}

int main() {
        //1. Create 2 threads ping(), pong(). Consider execution starts from pong()
	thread t1(ping);		
	thread t2(pong);
	
	t1.join();
	t2.join();
	return 0;
}
```

<a name=c4></a>
#### ping pong using 4 threads
```cpp
// Condition_Variable_PingPong.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
mutex mtx;
condition_variable cv;
bool start = false;
int k = 1;

void ping() {
	while(1) {
		unique_lock<mutex> ulock(mtx);
		cv.wait(ulock, []
			{	//Wait until this code block return true
				return !start;
			}
		);
		if (k++ > 10)
			return;
		start = true;
		cout << "Ping\n";
		ulock.unlock();
		cv.notify_all();
	}
}

void pong() {
	while(1) {
		unique_lock<mutex> ulock(mtx);
		cv.wait(ulock, []
			{	//Wait until this code block return true
				return start;
			}
		);
		if (k++ > 10)
			return;
		start = false;
		cout << "Pong\n";
		ulock.unlock();
		cv.notify_all();
	}
}

int main()
{
	thread t1(ping);
	thread t2(pong);
	thread t3(ping);
	thread t4(pong);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	std::this_thread::sleep_for(std::chrono::seconds(4));
	return 0;
}
$ ./a.out
Ping
Pong
Ping
Pong
Ping
Pong
Ping
Pong
Ping
Pong
```

<a name=cppcva></a>
### C++ condition_variable_any
- unlike [condition_variable]() which works with only unique_lock, these can work with any (eg: shared_lock)
