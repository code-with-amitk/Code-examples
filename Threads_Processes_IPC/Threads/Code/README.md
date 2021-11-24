**[Details about Thread APIs](../)**
- [Creating Threads](#cre)
  - [POSIX](#cp)
  - [C++](#ct)
    - [1. Using Object of thread class](#m1)
    - [2. Using Functor](#m2)
  - [Windows](#win)
  - [Rust](#ru)
- [Joinable, Detachable Threads](#jd)


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

