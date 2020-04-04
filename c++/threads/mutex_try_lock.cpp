/*      mutex_try_lock.cpp

try_lock() tries to lock the mutex, if mutex is acquired by any other thread it returns back immediately ie does not block.

Return value: 
 true: if the lock was acquired successfully
 false: otherwise

Parameters: None

Undefined-Behaviour/Deadlock:
 - if try_lock() is called again by same thread who owns the mutex.
*/

#include <chrono>
#include <mutex>
#include <thread>
#include <iostream> // std::cout

mutex m;
void fun(){
        m.try_lock();
        cout<<"\nThread:"<<this_thread::get_id()<<" in CriticalSection.\n";
        this_thread::sleep_for(std::chrono::milliseconds(4*1000));
        m.unlock();
}
void fun1(){
        fun();
        cout<<"Thread:"<<this_thread::get_id()<<" done task after mutex"<<endl;
}

void fun2(){
        fun();
        cout<<"Thread:"<<this_thread::get_id()<<" done task after mutex"<<endl;
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

Thread:
Thread:139854360147712 in CriticalSection.
139854368540416 in CriticalSection.
*/
