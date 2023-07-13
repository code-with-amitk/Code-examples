**Create Threads**
- [1. Using Object of thread class](#m1)
  - [1. Create Thread. Not copy constructible, nor copy assignable](#m12)
  - [2. Thread object is MoveAssignable](#m13)
  - [3. Thread calling methods of class](#m14)
- [2. Using Functor](#m2)


### Create Threads
<a name=m1></a>
#### 1. Using Object of [thread class](https://www.cplusplus.com/reference/thread/thread/thread/)
- Thread class Object is: 
  - NOT CopyConstructible or CopyAssignable.
  - It is MoveConstructible and MoveAssignable.
- **thread header file**
```cpp
class thread {					//Header thread
  thread() noexcept;				//1. Default Ctr
  template <class Fn, class... Args>		//2. Initialization ctr
    explicit thread (Fn&& fn, Args&&... args);
  thread (const thread&) = delete;		//3. Copy ctr deleted
  thread (thread&& x) noexcept;			//4. Move ctr
  
  thread& operator=(const thread&) = delete;	//Assignment Operator deleted
};
```
<a name=m12></a>
**1. Create Thread. Not copy constructible, nor copy assignable**
```cpp
#include<thread>
#include<iostream>
void fun(int a){
  std::cout<<"Hello"<<a<<"\n";
}
int main() { 
  int a = 10;
  std::thread t1(fun, a);            //Creates Thread Object, which is entity that can start execution immediately after creation
  t1.join();
  
  /* Not copy construtible */
  //std::thread t2 = t1		     //error: use of deleted function ‘std::thread::thread(std::thread&)’
  
  /* Not copy assignable */
  //std::thread t2(fun,3);           //error: use of deleted function ‘std::thread& std::thread::operator=(const std::thread&)’
  //t1 = t2;
}
$ g++ test.cpp -lpthread
```
<a name=m13></a>
**2. Thread object is MoveAssignable**
```cpp
#include<thread>
#include<iostream>
#include<chrono>
void fun(int a){
    std::cout<<"Hello"<<a<<"\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
int main() {
  std::thread t1(fun, 10);
  std::thread t2 = std::move(t1);
  t2.join();
}
$ g++ test.cpp -lpthread
$ ./a.out
Hello10			//main() does not exit until thread exists
```
<a name=m14></a>
**3. Thread calling methods of class**
```cpp
#include<thread>
class A {
  void test(int a) {
    cout << a;
  }
public:
  void fun(int a) {
    thread t1(&A::test, this, a);        //if we start thread on static function, then this will not be passed
    t1.join();
  }
};
int main() {
  A obj;
  obj.fun(1);
}
```

<a name=m2></a>
#### 2. Using [Functor](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Polymorphism/Static_CompileTime/Operator_Overloading/Functor/)
```cpp
#include<thread>
#include<iostream>
#include<mutex>
#include<vector>
std::mutex m;

void fun(int tid) {
    int a;
    m.lock();
    a += 5;
    std::cout << "Thread: " << tid << ", a:" << a << std::endl;
    m.unlock();
}

int main() {
    std::vector<std::thread> vecThreads;
    for (int i = 0; i < 5; ++i) {
        vecThreads.emplace_back(
            [&]() {                             //Functor to create Threads
                fun(i);
            }
        );
    }
    for (auto& t : vecThreads)
        t.join();
    return 0;
}
```
