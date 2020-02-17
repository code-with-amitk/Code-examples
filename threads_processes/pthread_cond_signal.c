/*      pthread_cond_signal.c
  
a. 2 threads are created. fun1(), fun2()
b. Both threads are joinable by main()
c. Thread1 waits for condition to be true;
*/
#include<stdio.h>
#include<pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *fun1()
{
        pthread_mutex_lock(&mutex);
        printf("Thread-1 Waiting for condition\n\n");
        pthread_cond_wait(&cond, &mutex);

        printf("Thread-1 recieved condition ok, processes the data\n");
        pthread_mutex_unlock(&mutex);
}

void *fun2()
{
        printf("Thread-2 processing data\n");
        sleep(2);
        printf("Thread-2 Signalled the condition\n");
        pthread_cond_signal(&cond);
}

void main(){
    pthread_t tid1,tid2;
    pthread_create(&tid1, NULL, fun1, NULL);
    pthread_create(&tid2, NULL, fun2, NULL);

    pthread_join(&tid1, NULL);
    pthread_join(&tid2, NULL);
}
/*
# ./a.out 
Thread-1 Waiting for condition

Thread-2 processing data
Thread-2 Signalled the condition
Thread-1 recieved condition ok, processes the data
*/
