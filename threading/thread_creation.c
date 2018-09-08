#include<pthread.h>
#include<stdio.h>

void *fun(){
    printf("Thread Created\n");
}

void main(){
	pthread_t tid;     //typedef int pthread_t; //sysdeps/pthread/bits/pthread.h

	//pthread_create (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg)
	//NULL Attributes
	pthread_create(&tid, NULL, fun, NULL);

	pthread_join(tid, NULL);
}
