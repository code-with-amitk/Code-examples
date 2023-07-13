**[Details about Thread APIs](../)**
- Creating Threads
  - [POSIX](POSIX)
  - [C++](C++)
    - _1._ Using Object of thread class
      - _1._ Create Thread. Not copy constructible, nor copy assignable
      - _2._ Thread object is MoveAssignable
      - _3._ Thread calling methods of class
    - _2._ Using Functor
  - [Windows](Windows)
  - [Rust](Rust)
    - _1._ thread::spawn = OS Thread
    - _2._ tokio::spawn = Green Thread
  - [Python](Python)
  - [Java](Java)
- [Joinable, Detachable Threads](#jd)


<a name=jd></a>
### Joinable, Detachable Threads
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

