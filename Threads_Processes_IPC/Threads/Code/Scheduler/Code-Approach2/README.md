- [Code Structure](#cs)
  - [A. class Worker](#w)
  - [B. class Dispatcher](#d)

<a name=cs></a>
## Code Structure
- 10 threads are created.
- Every thread calls run() method. Access to run() is protected by mutex, condition variables.

<a name=w></a>
### A. Class Worker
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

<a name=d></a>
### B. Class Dispatcher
Contains vector of ThreadId's.
```cpp
class Dispatcher {
	static vector<thread*> threads;
};  
```
