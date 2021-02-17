## std::thread
- **Creating** `thread t1(fun,args)`. Created thread by creating object of thread class and passing function-name to it.

### Code
```c++
#include<iostream>
#include<thread>

void fun(int a){
  std::cout<<"Hello"<<a<<"\n";
}

int main(){                          
  
  int a = 10;
  std::thread t1(fun, a);          //1
  t1.join();
  
}
# g++ create-thread.cpp -pthread
```
