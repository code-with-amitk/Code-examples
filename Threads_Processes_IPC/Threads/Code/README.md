**[Details about Thread APIs](../)**
- [Creating Threads](#cre)
  - [POSIX](#cp)
  - [C++](#ct)
    - [1. Using Object of thread class](#m1)
      - [1. Create Thread. Not copy constructible, nor copy assignable](#m12)
      - [2. Thread object is MoveAssignable](#m13)
      - [3. Thread calling methods of class](#m14)
    - [2. Using Functor](#m2)
  - [Windows](#win)
  - [Rust](#ru)
    - [1. thread::spawn = OS Thread](#ts)
    - [2. tokio::spawn = Green Thread](#tos)
  - Python
    - [1. Threading Library](#p1)
  - Java
    - [1. Thread Class](#tc)
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
<a name=m1></a>
#### 1. Using Object of [thread class](https://www.cplusplus.com/reference/thread/thread/thread/)
- Thread class Object is: 
  - NOT CopyConstructible or CopyAssignable.
  - It is MoveConstructible and MoveAssignable.
- **thread header file**
```cpp
class thread {					//Header thread
  thread() noexcept;				//1. Default Ctr
  template <class Fn, class... Args>		//2. Initialization ctr
    explicit thread (Fn&& fn, Args&&... args);
  thread (const thread&) = delete;		//3. Copy ctr deleted
  thread (thread&& x) noexcept;			//4. Move ctr
  
  thread& operator=(const thread&) = delete;	//Assignment Operator deleted
};
```
<a name=m12></a>
**1. Create Thread. Not copy constructible, nor copy assignable**
```cpp
#include<thread>
void fun(int a){
  std::cout<<"Hello"<<a<<"\n";
}
int main() { 
  int a = 10;
  std::thread t1(fun, a);            //Creates Thread Object, which is entity that can start execution immediately after creation
  t1.join();
  
  /* Not copy construtible */
  //std::thread t2 = t1		     //error: use of deleted function ‘std::thread::thread(std::thread&)’
  
  /* Not copy assignable */
  //std::thread t2(fun,3);           //error: use of deleted function ‘std::thread& std::thread::operator=(const std::thread&)’
  //t1 = t2;
}
```
<a name=m13></a>
**2. Thread object is MoveAssignable**
```cpp
#include<thread>
#include<iostream>
#include<chrono>
void fun(int a){
    std::cout<<"Hello"<<a<<"\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
int main() {
  std::thread t1(fun, 10);
  std::thread t2 = std::move(t1);
  t2.join();
}
$ g++ test.cpp -lpthread
$ ./a.out
Hello10			//main() does not exit until thread exists
```
<a name=m14></a>
**3. Thread calling methods of class**
```cpp
#include<thread>
class A {
  void test(int a) {
    cout << a;
  }
public:
  void fun(int a) {
    thread t1(&A::test, this, a);
    t1.join();
  }
};
int main() {
  A obj;
  obj.fun(1);
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
<a name=ts></a>
#### 1. thread::spawn() = OS Thread
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

<a name=tos></a>
#### 2. tokio::spawn() = [asynchronous](/Threads_Processes_IPC/Terms/README.md#as) [Green Thread](/Threads_Processes_IPC/Threads#usks)
- [tokio](/Languages/Programming_Languages/Rust/Tokio/)::spawn is 1 level up from threads. 
- These are user level non-blocking threads(ie if thread blocks on any call, due to async it will return immediately) means now thread will also not block.
```rs
$ cat Cargo.toml
[package]
name = "tokio_spawn"
version = "0.1.0"
authors = ["amitk"]
edition = "2018"

[dependencies]
futures = { version = "0.3.*" }
tokio = {version = "0.2.*", features = ["full"] }

$ cat main.rs
use tokio::task;
fn fun_thread() {
    println!("thread-1");
}
#[tokio::main]
async fn main() {
    let join:JoinHandle<()> = task::spawn(async {		//spawn() returns `struct JoinHandle`
        fun_thread()
    });
    assert!(join.await.is_err());
}
$ cargo build
$ cargo run
thread-1
```

### Python
<a name=p1></a>
#### 1. Threading Library
**Thread.run():**
- This is inbuilt method of the Thread class of the threading module in Python.
- This method is used to represent a thread's activity. It calls the method expressed as the target argument in the Thread object along with the positional and keyword arguments taken from the args and kwargs arguments, respectively. This method can also be overridden in the subclass.
```py
import threading, zipfile

class AsyncZip(threading.Thread):
    def __init__(self, infile, outfile):              # Constructor
        threading.Thread.__init__(self)
        self.infile = infile
        self.outfile = outfile

    def run(self):
        f = zipfile.ZipFile(self.outfile, 'w', zipfile.ZIP_DEFLATED)
        f.write(self.infile)
        f.close()
        print('Finished background zip of:', self.infile)

background = AsyncZip('mydata.txt', 'myarchive.zip')
background.start()
print('The main program continues to run in foreground.')

background.join()    # Wait for the background task to finish
print('Main program waited until background was done.')
```

### Java
<a name=tc></a>
#### 1. Using Thread class
```java
class test implements Runnable {		//Class should implement Runnable Interface to create Thread
    test() {
        Thread cur = Thread.currentThread();

        Thread t = new Thread (this, "New thread"); //1. Created child thread
        t.start();                                  //2. Started child thread. if start() is not called, Child Thread will not start
        try {
            for (int i = 0; i < 6; ++i) {
                System.out.println ("Parent Thread");       //Parent process waits 1sec
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println ("Interrupted");
        }
        System.out.println ("exiting main thread");
    }
    public void run () {
        try {
            for (int i = 0; i < 3; ++i) {
                System.out.println ("Child Thread");        //Child Thread waits 2sec
                Thread.sleep(2000);
            }
        }
        catch (InterruptedException e) {
            System.out.println ("child interrupted");
        }
        System.out.println ("exiting child thread");
    }
    public static void main (String args[]) {
        new test();					//1. Calls constructor
    }
}
$ javac test.java
$ java test
$ java test
Parent Thread
Child Thread
Parent Thread
Child Thread
Parent Thread
Parent Thread
Child Thread
Parent Thread
Parent Thread
exiting child thread
exiting main thread
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

