#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>

#include "threadpool.h"

#define THREAD 4
#define SIZE   8192
#define QUEUES 64

/*
 *  * Warning do not increase THREAD and QUEUES too much on 32-bit
 *   * platforms: because of each thread (and there will be THREAD *
 *    * QUEUES of them) will allocate its own stack (8 MB is the default on
 *     * Linux), you'll quickly run out of virtual space.
 *      */

threadpool_t *pool[QUEUES];
int tasks[SIZE] = {0}, left;
pthread_mutex_t lock;

int error;

void dummy_task(void *arg) {
    printf("Thread executing the dummay task\n");
    int *pi = (int *)arg;
    *pi += 1;

    if(*pi < QUEUES) {
        assert(threadpool_add(pool[*pi], &dummy_task, arg, 0) == 0);
    } else {
        pthread_mutex_lock(&lock);
        left--;
        pthread_mutex_unlock(&lock);
    }
}

int main(int argc, char **argv)
{
    	int i, copy = 1;
    	left = SIZE;

    	pthread_mutex_init(&lock, NULL);
    	for(i = 0; i < QUEUES; i++) {	//QUEUES=64. Creating 64 pools and 4 threads in each pool.
		printf("Pool[%d]:\n",i);
        	pool[i] = threadpool_create(THREAD, SIZE, 0);	//THREAD=4, SIZE=8192
        	assert(pool[i] != NULL);
    	}
	printf("\nCreated 64 Pools\n");
	printf("Step-1: %d threads created and information stored in (struct threadpool_t) using threadpool_create()\n",THREAD);
    	usleep(10);
printf("\n\
***********FUNCTION=> threadpool_create(int thread_count, queue_size)**************\n\
1. allocates threadpool_t structure memset to 0\n\
2. Does mutex_init(NULL); cond_init(NULL);\n\
3. Creates threads and notes thier IDs in thread varible\n\n\
pool = malloc(threadpool_t) and memset to 0\n\
pool->thread_count = malloc(pthread_t) * thread_count\n\
pool->queue = malloc(threadpool_task_t) * queue_size\n\
pthread_mutex_init(pool->lock, NULL)\n\
pthread_cond_init(pool->notify, NULL)\n\
for(i=0;i<thread_count;i++)\n\
        pthread_create(&pool->threads[i],NULL,callback_fun,address_of_pool)\n\
        pool->thread_count++;\n\
        pool->started++;\n\
return pool\n\
*************************************************\n");

    	for(i = 0; i < SIZE; i++) {//SIZE=8192
       // 	tasks[i] = 0;
        	assert(threadpool_add(pool[0], &dummy_task, &(tasks[i]), 0) == 0);
    	}

    while(copy > 0) {
        usleep(10);
        pthread_mutex_lock(&lock);
        copy = left;
        pthread_mutex_unlock(&lock);
    }

    for(i = 0; i < QUEUES; i++) {
        assert(threadpool_destroy(pool[i], 0) == 0);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}

