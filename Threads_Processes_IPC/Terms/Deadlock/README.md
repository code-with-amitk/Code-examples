## Deadlock
- 2 or more threads waits on resources which is/are held by each other. None of thread releases the resource and in turn waits for other to release. 
- Example-1:
  - Thread-1 acquires mutex-a. 
  - Thread-2 acquires mutex-b. 
  - Thread-1 wants to acquire mutex-b, thread-2 mutex-a
- Example-2:    
  - Thread-1 acquires mutex a, b.    
  - Thread-2 acquires mutex b,a
```c
#include<pthread.h>
pthread_mutex_t     a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t     b = PTHREAD_MUTEX_INITIALIZER;
main(){
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1, NULL);     //Wait until thread-1 to terminate
    pthread_join(tid2, NULL);    ////Wait until thread-2 to terminate
}

void *thread-1(void *a){
    while(1){
        pthread_mutex_lock(&a); 
        pthread_mutex_lock(&b);
        pthread_mutex_unlock(&b);
        pthread_mutex_unlock(&a);
    }
}

void *thread-2(void *a){
    while(1){
        pthread_mutex_lock(&b); 
        pthread_mutex_lock(&a);
        pthread_mutex_unlock(&a);
        pthread_mutex_unlock(&b);
    }
}
```
