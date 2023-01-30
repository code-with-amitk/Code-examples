**Print FooBar Alternately**
- [Approach-1. Taking a shared boolen variable](#a1)
  - [Logic](#l)
  - Code
    - [CPP. condition_variable](#cpp)

### [1115. Print FooBar Alternately](https://leetcode.com/problems/print-foobar-alternately/description/)
- Suppose you are given the following code:
```c
class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
```
- The same instance of FooBar will be passed to two different threads:
  - thread A will call foo(), while
  - thread B will call bar().
- Modify the given program to output "foobar" n times.
```c
Example 1:
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.

Example 2:
Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
```

<a name=a1></a>
### Approach-1. Taking a shared boolen variable
#### Logic
- _1._ Take a shared variable, make it to true.
- _2._ if variable=true print foo, Inside foo() change variable to false.
- _3._ Use condition variable to synchronize

### Code
<a name=cpp></a>
#### CPP. condition_variable
```cpp

class FooBar {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    bool bCondition;
public:
    FooBar(int n) {
        this->n = n;
        bCondition = true;
    }
    void foo(function<void()> printFoo) {   

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(mtx);
            //Wait on condition variable to become true
            cv.wait(ul, [this]() { return bCondition==true;});

        	printFoo();

            bCondition = false;
            ul.unlock();
            cv.notify_all();
        }

    }
    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(mtx);
            //Wait on condition variable to become true
            cv.wait(ul, [this]() { return bCondition==false;});

        	printBar();
            
            bCondition = true;
            ul.unlock();
            cv.notify_all();
        }
    }
};
/*
int main() {
    thread t1(foo);
    thread t2(bar);
}
*/
```
