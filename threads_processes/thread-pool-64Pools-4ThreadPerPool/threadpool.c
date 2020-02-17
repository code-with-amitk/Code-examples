/**
 *  * @file threadpool.c
 *   * @brief Threadpool implementation file
 *    */

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "threadpool.h"

typedef enum {
    immediate_shutdown = 1,
    graceful_shutdown  = 2
} threadpool_shutdown_t;

/**
 struct threadpool_task:	brief the work struct
 var: function Pointer to the function that will perform the task.
 var: argument Argument to be passed to the function.
**/
typedef struct {
    void (*function)(void *);
    void *argument;
} threadpool_task_t;

/*
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;
#if __WORDSIZE == 64
    unsigned int __nusers;
#endif
    int __kind;
#if __WORDSIZE == 64
    int __spins;
    __pthread_list_t __list;
# define __PTHREAD_MUTEX_HAVE_PREV      1
#else
    unsigned int __nusers;
    __extension__ union
    {
      int __spins;
      __pthread_slist_t __list;
    };
#endif
  } __data;
  char __size[__SIZEOF_PTHREAD_MUTEX_T];
  long int __align;
} pthread_mutex_t;
 */

/*
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[__SIZEOF_PTHREAD_COND_T];
  __extension__ long long int __align;
} pthread_cond_t;
*/

/**
 struct threadpool: The threadpool struct
 @var notify       Condition variable to notify worker threads.
 @var threads      Array containing worker threads ID.
 @var thread_count Number of threads
 @var queue        Array containing the task queue.
 @var queue_size   Size of the task queue.
 @var head         Index of the first element.
 @var tail         Index of the next element.
 @var count        Number of pending tasks
 @var shutdown     Flag indicating if the pool is shutting down
 @var started      Number of started threads
*/
struct threadpool_t {
  pthread_mutex_t lock;		//Shown above
  pthread_cond_t notify;	//struct shown above
  pthread_t *threads;	//typedef int pthread_t; //sysdeps/pthread/bits/pthread.h
  threadpool_task_t *queue;	//struct defined above
  int thread_count;
  int queue_size;
  int head;
  int tail;
  int count;
  int shutdown;
  int started;
};

/**
 void *threadpool_thread(void *threadpool)
  @brief the worker thread
  @param threadpool the pool which own the thread
*/
static void *threadpool_thread(void *threadpool);

int threadpool_free(threadpool_t *pool);

threadpool_t *threadpool_create(int thread_count, int queue_size, int flags)
{
    threadpool_t *pool;
    int i;
    (void) flags;

    if(thread_count <= 0 || thread_count > MAX_THREADS || queue_size <= 0 || queue_size > MAX_QUEUE) {
        return NULL;
    }

    if((pool = (threadpool_t *)malloc(sizeof(threadpool_t))) == NULL) {
	printf("malloc threadpool_t failed");
        goto err;
    }

    /* Initialize */
    pool->thread_count = 0;
    pool->queue_size = queue_size;
    pool->head = pool->tail = pool->count = 0;
    pool->shutdown = pool->started = 0;

    /* Allocate thread and task queue */
    pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
    pool->queue = (threadpool_task_t *)malloc(sizeof(threadpool_task_t) * queue_size);

    /* Initialize mutex and conditional variable first */
    if((pthread_mutex_init(&(pool->lock), NULL) != 0) ||
       (pthread_cond_init(&(pool->notify), NULL) != 0) ||
       (pool->threads == NULL) ||
       (pool->queue == NULL)) {
        goto err;
    }

    /* Start worker threads */
    for(i = 0; i < thread_count; i++) {
        if(pthread_create(&(pool->threads[i]), NULL, threadpool_thread, (void*)pool) != 0) {
            threadpool_destroy(pool, 0);
            return NULL;
        }
        pool->thread_count++;
        pool->started++;
	printf("Thread-%d tid=%d created in pool=%d stored in pool->thread[%d]\n",i,pool->threads[i],pool, i);
    }

    return pool;

 err:
    if(pool) {
        threadpool_free(pool);
    }
    return NULL;
}

int threadpool_add(threadpool_t *pool, void (*function)(void *), void *argument, int flags)
{
    int err = 0;
    int next;
    (void) flags;

    if(pool == NULL || function == NULL) {
        return threadpool_invalid;
    }

    printf("Working on Pool=%d\n",pool);
    if(pthread_mutex_lock(&(pool->lock)) != 0) {
        return threadpool_lock_failure;
    }
    printf("Locked Mutex pool->lock\n");

    next = (pool->tail + 1) % pool->queue_size;
	
    do {
        /* Are we full ? */
        if(pool->count == pool->queue_size) {
            err = threadpool_queue_full;
            break;
        }

        /* Are we shutting down ? */
        if(pool->shutdown) {
            err = threadpool_shutdown;
            break;
        }

        /* Add task to queue */
        pool->queue[pool->tail].function = function;
        pool->queue[pool->tail].argument = argument;
        pool->tail = next;
        pool->count += 1;
	printf("Adding Task [void dummy_task()] to Pool's queue\n");
	
        /* pthread_cond_broadcast */
        if(pthread_cond_signal(&(pool->notify)) != 0) {
            err = threadpool_lock_failure;
            break;
        }
    } while(0);

    if(pthread_mutex_unlock(&pool->lock) != 0) {
        err = threadpool_lock_failure;
    }

    return err;
}

int threadpool_destroy(threadpool_t *pool, int flags)
{
    int i, err = 0;

    if(pool == NULL) {
        return threadpool_invalid;
    }

    if(pthread_mutex_lock(&(pool->lock)) != 0) {
        return threadpool_lock_failure;
    }

    do {
        /* Already shutting down */
        if(pool->shutdown) {
            err = threadpool_shutdown;
            break;
        }

        pool->shutdown = (flags & threadpool_graceful) ?
            graceful_shutdown : immediate_shutdown;

        /* Wake up all worker threads */
        if((pthread_cond_broadcast(&(pool->notify)) != 0) ||
           (pthread_mutex_unlock(&(pool->lock)) != 0)) {
            err = threadpool_lock_failure;
            break;
        }

        /* Join all worker thread */
        for(i = 0; i < pool->thread_count; i++) {
            if(pthread_join(pool->threads[i], NULL) != 0) {
                err = threadpool_thread_failure;
            }
        }
    } while(0);

    /* Only if everything went well do we deallocate the pool */
    if(!err) {
        threadpool_free(pool);
    }
    return err;
}

int threadpool_free(threadpool_t *pool)
{
    if(pool == NULL || pool->started > 0) {
        return -1;
    }

    /* Did we manage to allocate ? */
    if(pool->threads) {
        free(pool->threads);
        free(pool->queue);
 
        /* Because we allocate pool->threads after initializing the
 *            mutex and condition variable, we're sure they're
 *                       initialized. Let's lock the mutex just in case. */
        pthread_mutex_lock(&(pool->lock));
        pthread_mutex_destroy(&(pool->lock));
        pthread_cond_destroy(&(pool->notify));
    }
    free(pool);    
    return 0;
}


static void *threadpool_thread(void *threadpool)
{
    threadpool_t *pool = (threadpool_t *)threadpool;
    threadpool_task_t task;

    printf("Inside thread Function callback fun()\n");
    for(;;) {
        /* Lock must be taken to wait on conditional variable */
        pthread_mutex_lock(&(pool->lock));

        /* Wait on condition variable, check for spurious wakeups.
 *            When returning from pthread_cond_wait(), we own the lock. */
        while((pool->count == 0) && (!pool->shutdown)) {
            pthread_cond_wait(&(pool->notify), &(pool->lock));
        }

        if((pool->shutdown == immediate_shutdown) ||
           ((pool->shutdown == graceful_shutdown) &&
            (pool->count == 0))) {
            break;
        }
        /* Grab our task */
        task.function = pool->queue[pool->head].function;
        task.argument = pool->queue[pool->head].argument;
        pool->head = (pool->head + 1) % pool->queue_size;
        pool->count -= 1;
        /* Unlock */
        pthread_mutex_unlock(&(pool->lock));
	
	printf("pthread_cond_wait brokn Grabbed task from queue. going a head to task function dummy_task()\n");
        /* Get to work */
        (*(task.function))(task.argument);
    }

    pool->started--;

    pthread_mutex_unlock(&(pool->lock));
    pthread_exit(NULL);
    return(NULL);
}

