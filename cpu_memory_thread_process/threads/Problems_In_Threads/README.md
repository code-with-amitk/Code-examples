## Problems with Threads / Problems in turning Single Threaded Code to Multithreaded
### 1. Global variables are shared 
  - ie conflict of threads over use of Global variables.
  - **Solutions:**
    - *a.* Prohibit global variables altogether.
    - *b.* Each thread its own private global variables. This will create new problem of accessing other thread's global variables.
    - *c.* Every thread allocates its own variables on heap & hence getting seperate copy. `struct* var = new new(struct var)`
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
