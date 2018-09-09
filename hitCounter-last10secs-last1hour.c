/*Logic
 * We maintain only last 1 hour hit count using array of 3600 integer elements.
 * Every element inside array = hit count for particular second
 * Mutex is not needed here since, Thread1 writes and Thread2 only reads
 *
 * Thread1: Writer Thread
 * 	- This generates (random Number = hit count) every 1 second
 * 	- Fills hit count into an global array of 3600 elements
 *
 * Thread2: Reader Thread
 * 	- On Every 10 seconds: Calculates last 10 seconds Hit counts
 * 	- On Every 30 seconds: Calculates last 1 hour count.
 */
#include<stdio.h>
#include<pthread.h>

int hitCount[3600]={0}, counter=0;
pthread_mutex_t mutex;
long int timer_seconds;

void *thread1_writer(){
	printf("Inside Writer Thread1\n");
	int var;
	//Generates random hit Count at every 1 second
	srand(time(NULL));
	while(1) {


		//pthread_mutex_lock(&mutex);
		if (counter==3600) counter=0;
		var = rand()%1000;
		hitCount[counter] = var;
		printf("Hit Count this second. hitCount[%d]=%d timer=%d\n",counter,var,timer_seconds);
		timer_seconds++;
		counter++;
		//pthread_mutex_unlock(&mutex);
		sleep(1);
	}
}

void *thread2_reader(){
	int i,counter_h;
	int temp;
	//After Every 10 seconds => Reads hit count of last 10 seconds
	while(1) {
		if ((timer_seconds%10 == 0)&&(timer_seconds/10!=0)) {
			temp = 0;
			printf("\nInside Reader Thread2 10 Seconds Counter");
		//	pthread_mutex_lock(&mutex);
			counter_h = counter;
			printf("\tCounter=%d\n",counter);
			for (i=(counter_h-10);i<counter_h;i++){
	//			printf("hitCount[%d]=%d\n",i,hitCount[i]);
				temp += hitCount[i];
			}
		//	pthread_mutex_unlock(&mutex);
			printf("Hit Count in Last 10 seconds = %d\n\n",temp);
//			sleep(2);
		}

		//After Every 30 seconds => Reads hit count of last 1 hour
		if((timer_seconds%30 == 0)&&(timer_seconds/30!=0)) {
			temp = 0;
			printf("\nInside Reader Thread2 1 Hour Counter");
			for (i=0;i<3600;i++){
				temp += hitCount[i];
			}
			printf("Hit Count in Last 1 Hour = %d\n\n",temp);
		}
			sleep(2);
	}
}

void main() {
	pthread_t tid1, tid2;
	pthread_create (&tid1, NULL, thread1_writer, NULL);
	pthread_create (&tid2, NULL, thread2_reader, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}
