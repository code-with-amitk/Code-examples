## Example-1
- **APIs**
```c
sem_init(): Initializes the semaphore to 1.
sem_wait(): 
        if(semaphore == 1)
                Then only I will enter Critical Section
        else
                I will Wait outside
        Enter & Does semaphore to 0

sem_post(): does semaphore=1
```

### Code
```c
-> See in output without semaphore both threads enters critical section at same time.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;
pthread_t t1,t2;

void *fun(void* arg) {
    sem_wait(&s);

    printf("\nThread-%d Inside Critical section..\n",pthread_self());
    sleep(4);
    printf("\nThread-%d Exiting...\n",pthread_self());

    sem_post(&s);
}

int main() {
    sem_init(&s, 0, 1);

    pthread_create(&t1,NULL,fun,NULL);
    sleep(2);

    pthread_create(&t2,NULL,fun,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    sem_destroy(&s);
    return 0;
}

Output without sem_wait() and sem_post()
Thread--986036480 Inside Critical section..
Thread--994429184 Inside Critical section..     //SEE BOTH THREADS ARE IN CS
Thread--986036480 Exiting...
Thread--994429184 Exiting...

Output with sem_wait() and sem_post()
Thread-530441984 Inside Critical section..
Thread-530441984 Exiting...
Thread-522049280 Inside Critical section..
Thread-522049280 Exiting...
```
