## Globals are shared
```c++
#include<thread>
using namespace std;

int a;

void fun1(){
  //cout<<"Thread-1: "<<this_thread::get_id()<<"\n";
  a = 1;    cout<<"a_fun1 = "<<a<<"\n";
}

void fun2(){
  //cout<<"Thread-2: "<<this_thread::get_id()<<"\n";
  a = 2;    cout<<"a_fun2 = "<<a<<"\n";
}

int main(){
  thread t1(fun1);
  thread t2(fun2);
  t1.join();
  t2.join();
  cout<<"a_main = "<<::a;
}

# ./a.out
a_fun1 = 1
a_fun1 = 2
a_main = 2        //See both threads affecting global variable
```
