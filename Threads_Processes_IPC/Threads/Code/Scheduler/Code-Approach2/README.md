- [Code Structure](#cs)
  - [1. Driver](#dr)
  - [2. Dispatcher](#d)
  - [3. Worker](#w)


<a name=cs></a>
## Code Structure
```
Datastructure Dispatcher have:
1. Two Queues
worker_object{task*=t, condition_variable}                  task_object
  /\         worker_object                                   /\         task_object
   |           /\                                             |         /\
| *worker-1 | *worker-2 | *worker-3 | *worker-4 |           | *task-1 | *task-2 |        
WORKER_QUEUE                                                TASK_QUEUE

2. Two vectors
|Worker-1*|Worker-2*|Worker-3*|                 |thread-1*|thread-2*|thread-3*|
vector<Worker*> vecAllWorkers                    vector<thread*> vecAllThreads

    main()
1. Initialize Dispatcher
                       |            DISPATCHER
                       |-------->   2. init() 
		                     for (int i=0;i<10;++i) {
		                       2a. Worker* w = new Worker; //Create 10 Worker Objects
				                          |----------------> WORKER Object {
						                               bool running = true;
						    			       bool ready   = false;
									       mutex mtx;
									       unique_lock<mutex> ulock(mtx);
									      }
                                            vecAllWorkers.push_back(w);  //Push in vector
				     
				        2b. thread* t = new thread(&Worker::run, w);  //Create 10 threads and push in vector
				            vecAllThreads.push_back(t);
                                       }
while (i < 50)					       
 3. Create 50 Task Objects
 4. Add Tasks to Dispatcher queue 
                         |-->     5. AddRequest(Task* t)
			       	          if worker_queue is not Empty
			                     worker_queue_mutex.lock();      //For acccessing worker Queue
					   //6. Get front element of worker Queue And provide task to it.
					     worker* w1 = queue.front()  
					     w1->giveTask(t);
					     
					    //7. if n threads is waiting on this worker's conditional variable.
					      Release one of them.
					      condition_variable cv;
					      w->getConditionalVariable(cv)
					      cv->notify_one();
					 
					    //8. Remove worker from Queue
					       queue.pop();
					      mutex.unlock();
					      
                                          if worker_queue is Empty          //9. Push task on task_queue
					    worker_queue_mutex.unlock();
					    task_queue_mutex.lock();
   9. sleep main thread 5 sec
   10. Stop Dispatcher
		|---------------->    11. stop()
		                          for (i=0;i<vec_workers.size();++i)
					    vec_workers[i].stop();
					    
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
