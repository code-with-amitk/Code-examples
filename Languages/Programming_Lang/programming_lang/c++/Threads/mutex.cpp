/*      mutex.cpp
        
 This is NORMAL/BLOCKING/SLEEPING mutex.
 This means caller gets blocked/sleeps if some other thread has locked the mutex.
 Task after critical section remains blocked until mutex is acquired.

 Return value: None
 Parameters: None
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

mutex m;
void fun(){
        m.lock();
        cout<<"\nThread:"<<this_thread::get_id()<<" in CriticalSection.";
        cout<<"\nThread:"<<this_thread::get_id()<<" done task after mutex\n";
        this_thread::sleep_for(std::chrono::milliseconds(1000));  
        m.unlock();
}

int main(){
        thread t1(fun);
        thread t2(fun);

        t1.join();
        t2.join();
}
/*
# g++ mutex.cpp -pthread
# ./a.out

Thread:139716691150592 in CriticalSection.
Thread:139716691150592 done task after mutex

Thread:139716682757888 in CriticalSection.
Thread:139716682757888 done task after mutex
*/
