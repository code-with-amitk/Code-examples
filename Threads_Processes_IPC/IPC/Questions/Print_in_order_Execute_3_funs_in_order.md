**Print in Order**
- [Approach-1. 1 Mutex. Not work](#a1)
- [Approach-2. 1 shared variable accessed by all threads](#a2)
  - **Code**
    - CPP
      - [1. condition_variable](#cv)

### [Print in Order](https://leetcode.com/problems/print-in-order/description/)
- Suppose we have a class:
```c
public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
```
- The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().
- We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.
```c
Example 1:
Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.

Example 2:
Input: nums = [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
```

<a name=a1></a>
### Approach-1, 1 mutex
#### Logic
- _1._ Lock mutex before entering into functions
- _2._ Take 2 bools to decide on order of function execution
- **When this approach works?**
```c
main () {
  thread t1 (first);    //t1 reaches first(), lock mutex. a=true. unlock
  thread t2 (second);   //t2 finds mutex lock, waits.                   . acquires lock. b=true
  thread t3 (third);
}
```
- **When approach not work?**
```c
main () {
  thread t1 (first);
  thread t3 (third);
  thread t2 (second);
}
```
**Code**
```c
class Foo {
    bool a,b;
    mutex m;
public:
    Foo() {
        a = false;
        b = false;
    }

    void first(function<void()> printFirst) {
        m.lock();
        printFirst();
        a = true;
        m.unlock();
    }

    void second(function<void()> printSecond) {
        m.lock();
        if (a==false) {
            m.unlock();
            return;
        }
        printSecond();
        b =true;
        m.unlock();
    }

    void third(function<void()> printThird) {
        m.lock();
        if (a==false || b==false) {
            m.unlock();
            return;        
        }
        printThird();
        m.unlock();
    }
};
```


<a name=a2></a>
## Approach-2, 1 shared variable accessed by all threads
### Code
#### CPP
<a name=cv></a>
##### 1. condition_variable
- _Logic:_
  - _1._ Take a variable count, initialize to 1
  - _2._ second() waits for variable to become=2, third() waits for variable to become=3
  - _3._ Change count=2 in first(), count=3 in second().
  - _4._ Use [condition_variable & unique_lock](/Threads_Processes_IPC/IPC/synchronization/Condition_Variable) to check count at entry of function.
```cpp
class Foo {
    mutex mtx;
    condition_variable cv;
    int count;
public:
    Foo() {
        count=1;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> ul(mtx);
        
        printFirst();
        count = 2;
        
        ul.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> ul(mtx);
        
        // wait on condition to become true count==2
        cv.wait(ul, [this]() { return count == 2;});
        
        printSecond();
        count = 3;
        ul.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> ul(mtx);
        
        // wait on condition to become true count==3
        cv.wait(ul, [this]() { return count == 3;});

        ul.unlock();
        printThird();
    }
};
```
