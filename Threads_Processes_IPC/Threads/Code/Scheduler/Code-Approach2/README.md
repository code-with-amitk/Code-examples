- [Code Structure](#cs)
  - [1. Dispatcher](#d)
  - [2. Worker](#w)


<a name=cs></a>
## Code Structure
```
   Module         |     Work
------------------|-----------------
1. Dispatcher     | - Create 10 threads initially       Dispatcher::init()
                   
2. main (Driver)  | - Add Task to Dispatcher Queue      Dispatcher::AddRequest()
```
<a name=d></a>
### 1. Dispatcher
```c
for (int i = 0; i < 10; ++i) {				//1. Dispatcher creates 10 threads
	thread* t = new thread(&Worker::run, i);	//Each thread will execute run() method
	threads.push_back(t);
}

while (signal_caught == 0 && i < 50) {			//2. Until Cntrl^C caught or served 50 requests
```
- Every thread calls run() method. Access to run() is protected by mutex, condition variables.
- Contains vector of ThreadId's.
```cpp
class Dispatcher {
	static vector<thread*> threads;
};  
```

<a name=w></a>
### 2. Worker
Contains mutex, condition variables, run() method.
```cpp
class Worker {
	condition_variable cv;
	mutex mtx;
	bool running;
	bool ready;
	unique_lock<mutex> ulock;
	AbstractRequest* request;
};  
```


### B. Class Dispatcher
