/*      recursive_mutex.cpp

Rules:
1. RM can be locked multiple times by same thread, but we know in case of normal mutex locking already locked mutex results in undefined behavior.
2. RM keeps count of how many times its locked hence same number of time unlock should be called.
3. How many time we can lock RM?
        - This is not defined
        - But if we reach that number 
                -> lock() will return system_error
                -> try_lock() will return false


*******How program works?*********
- 2 threads are created. thread1, thread2
- Thread1 locks mutex 10 times prints var(0-9)
        - Thread1 unlocks the mutex 10 times
- Thread2 locks mutex 10 times prints var(10-19)
        - Thread2 unlocks the mutex 10 times
*/
#include<iostream>
#include<thread>
#include<mutex>

std::recursive_mutex rm;
int var=0;

void recursion(int th, int k){
        if(k==10)
                return;

        rm.lock();
        std::cout<<"Thread:"<<th<<", var="<<var<<"\n";
        k++;
        var++;
        recursion(th, k);
        rm.unlock();
}

int main(){
        std::thread t1(recursion,0,0);
        std::thread t2(recursion,1,0);
        t1.join();
        t2.join();
}
/*
# g++ recursive_mutex.cpp -pthread
# ./a.out 
Thread:0, var=0
Thread:0, var=1
Thread:0, var=2
Thread:0, var=3
Thread:0, var=4
Thread:0, var=5
Thread:0, var=6
Thread:0, var=7
Thread:0, var=8
Thread:0, var=9
Thread:1, var=10
Thread:1, var=11
Thread:1, var=12
Thread:1, var=13
Thread:1, var=14
Thread:1, var=15
Thread:1, var=16
Thread:1, var=17
Thread:1, var=18
Thread:1, var=19
*/
