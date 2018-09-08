/*Detachable Thread:
 * 	Thread1 does not wait for thread2 to finish.
 * 	Thread1 is free to terminate.
 */
#include<pthread.h>
#include<stdio.h>
void *thread1 (){
	printf("\nThread1 created Detachable");
}

void main() {
	int ret;
	pthread_attr_t attr;
	ret = pthread_attr_init (&attr);
	ret = pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	pthread_t tid;
	pthread_create (&tid, &attr, thread1, NULL);	//thread1 is Detachable
	printf ("\n Inside Main thread\n");
}
