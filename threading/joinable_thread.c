/* Joinable Thread:
 * 	Thread1 waits for thread2 before termination.
 * 	Thread1 cannot terminate before thread2.
 */
#include<pthread.h>
#include<stdio.h>

void *thread2() {
	sleep(4);	//Even on sleep Main thread does not terminate
	printf("\nThread2 Created");
}

void main() {
	pthread_t tid;

	//pthread_create (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
	pthread_create (&tid, NULL, thread2, NULL);

	pthread_join(tid, NULL);
	
	printf("\nMain Thread terminated after Thread1\n");
}
