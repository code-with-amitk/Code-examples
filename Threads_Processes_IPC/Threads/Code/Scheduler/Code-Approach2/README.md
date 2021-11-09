- [Code Structure](#cs)
  - [1. Driver](#dr)
  - [2. Dispatcher](#d)
  - [3. Worker](#w)


<a name=cs></a>
## Code Structure
```
        MAIN
  1. Initialize Dispatcher
  
                                       DISPATCHER
                                     2. init() //Create 10 threads, store in vector<>  t1, t2, .. t9
				               //Threads will run Worker::run()
   3. Create Task Object
   4. Add Task to Dispatcher queue
                                     5. AddRequest()

   Module         |     Work
------------------|-----------------
1. main (Driver)  | - Add Task to Dispatcher Queue      Dispatcher::AddRequest()

2. Dispatcher     | - Create 10 threads initially       Dispatcher::init()
```
<a name=dr></a>
### 1. main(Driver)
<a name=d></a>
```c
main () {
	Dispatcher::init();                            //1. Call dispatcher init() function.
	while (signal_caught == 0 && i < 50) {	       //3. Until Cntrl^C caught or finished 50 tasks
		Task* t = new Task();                  //4. Create new task & add to Dispatcher
		Dispatcher::AddRequest(t);
	}
}
```

### 1. Dispatcher
- dispatcher maintains worker queue, to whose 1st worker task is assigned.
#### init()
```c
static queue<Worker*> queueWorkers;
vector<thread*> threads;
init() {				//2. Dispatcher creates 10 threads and store thread* in vector.
  for (int i = 0; i < 10; ++i) {
    thread* t = new thread(&Worker::run, i);	//Each thread will execute Worker class's run() method
    threads.push_back(t);
  }
}
```
#### AddRequest()
```c
AddRequest(Task* t) {
	if (worker queue is not empty) {
		queueWorkers.front()->GiveTask(t);        //5. Give task to Worker=Thread
	}
}
```

<a name=w></a>
### 3. Worker
Worker holds pointer to task to be performed.
```cpp
class Worker {
	Task* task;
public:
	GiveTask(Task* t){				//6. Worker is provided the task and set to ready state
		this->task = t;
		ready = true;
	}
};  
```


### B. Class Dispatcher
