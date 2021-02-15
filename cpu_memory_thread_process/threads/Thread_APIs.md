## Thread APIs
```c
int pthread_create(pthread_tid *tid, pthread_attr_t *attr, void *(*func)(void *), void *arg)

int pthread_equal(pthread_t, pthread_t): Returns 0 if ThreadIds are not equal else 1

int pthread_join(pthread_t tid, void **status): Waiting on (Thread tid) to terminated. Similar to process waitpid.

pthread_t pthread_self(void): Thread can get its own thread ID using this API

int pthread_detach(pthread_t tid): To create a detachable Thread

pthread_cancel(pthread_t tid)    //Thread1 can terminate thread2

int pthread_mutexattr_init(pthread_mutexattr_t *attr): Initialize mutex attributes

int pthread_yield(void): Causes the calling thread to give up CPU(ie terminate himself) voluntarily so that other threads can take CPU.

pthread_exit();    //This will exit calling Thread
```
