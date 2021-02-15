## Thread synchronization 
- This is defined as a mechanism which ensures that two or more concurrent processes or threads do not simultaneously execute some CS known as a critical section.
- With mutex: Thread-1 did not finished while Thread-2 enters Critical section
- With mutex: Thread-2 is not allowed to enter until thread-1 did not finish.

### C Code	
```c
#include<stdio.h>
#include<pthread.h>

pthread_t tid1,tid2;  //Defined as int
int counter;
pthread_mutex_t lock;

void *fun(){
  pthread_mutex_lock(&lock);       //Thread-2 sleeps until Thread-1 unlocks the mutex

  printf("\n Thread-%d has started a job\n", pthread_self()); 
  for (unsigned long i = 0; i < (0xFFFFFFFF); i++) 	//Added to make processing large
    printf("\n Thread-%d has finished\n", pthread_self()); 
	
  pthread_mutex_unlock(&lock); 
  return NULL;	
}

int main(){
    pthread_create(&tid1,NULL,&fun,NULL);   
    pthread_create(&tid2,NULL,&fun,NULL);
    pthread_join(tid1, NULL);    
    pthread_join(tid2, NULL);
}
/*
Output:
- Without mutex_lock
 Thread--1997539584 has started a job
 Thread--2005932288 has started a job			//SEE BOTH THREADS ARE IN CS
 Thread--2005932288 has finished
 Thread--1997539584 has finished
 
- With pthread_mutex_lock()
 Thread-1438967552 has started a job
 Thread-1438967552 has finished
 Thread-1430574848 has started a job
 Thread-1430574848 has finished
*/
```
