/*	mutex-example.c

Thread synchronization is defined as a mechanism which ensures that two or more concurrent processes or threads do not simultaneously execute some particular program segment known as a critical section.

With mutex: Thread-1 did not finished while Thread-2 enters Critical section

With mutex: Thread-2 is not allowed to enter until thread-1 did not finish.
*/

#include<stdio.h>
#include<pthread.h>

pthread_t tid1,tid2;  //Defined as int
int counter;
pthread_mutex_t lock;

void *fun(){
	pthread_mutex_lock(&lock);       //Thread-2 sleeps until Thread-1 unlocks the mutex
	unsigned long i = 0; 
    	counter += 1; 
    	printf("\n Thread-%d has started a job\n", counter); 
    	for (i = 0; i < (0xFFFFFFFF); i++) 	//Added to make processing large
        ; 
    	printf("\n Thread-%d has finished\n", counter); 
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
- if pthread_mutex_lock(), pthread_mutex_unlock() are removed.
 Thread-1 has started
 Thread-2 has started		//See thread-1 did not finished while thread-2 entered.
 Thread-2 has finished		
 Thread-2 has finished

- After adding pthread_mutex_lock() & pthread_mutex_unlock()
 Thread-1 has started a job
 Thread-1 has finished
 Thread-2 has started a job
 Thread-2 has finished
*/
