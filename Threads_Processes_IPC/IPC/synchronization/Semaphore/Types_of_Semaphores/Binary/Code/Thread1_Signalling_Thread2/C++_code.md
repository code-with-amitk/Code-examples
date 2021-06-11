## Thread1 Signalling Thread2 to enter Critical Section, when Thread1 is done
- _1._ Two Threads created.
- _2._ Thread1 goes into Critical Section, does processing
- _3._ Thread1 informs Thread2, that Thread1 is out of Critical Section
- _4._ Thread2 enters Critical Section

[sem_wait(), sem_post()](../../../../APIs)
```c++
#include<iostream>
#include<thread>
#include<unistd.h>
#include<semaphore.h>

sem_t sem;

void CriticalSection() {
  std::cout<<"Critical section\n\n";
  sleep(1);
}

void thread1(int a){
  for(;;) {
    std::cout<<"Thread1 inside ";
    CriticalSection();                //2
    sem_post (&sem);                  //3
  }
}
void thread2(int a){
  for (;;) {
    sem_wait(&sem);
    std::cout<<"Thread2 inside ";
    CriticalSection();                  //4
  }
}

int main(){
  std::thread t1(thread1, 5);            //1
  std::thread t2(thread2, 5);
  t1.join();
  t2.join();
}

# .a/out
Thread1 inside Critical section

Thread2 inside Critical section

Thread1 inside Critical section

Thread2 inside Critical section
```
