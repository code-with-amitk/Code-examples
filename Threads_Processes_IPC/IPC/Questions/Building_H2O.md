**Building H2O**
- [Approach-1. 2 variables](#a1)
  - Code
    - [CPP, condition_variable](#cpp)



### [1117. Building H2O](https://leetcode.com/problems/building-h2o/description/)
- There are two kinds of threads: oxygen and hydrogen. Your goal is to group these threads to form water molecules.
- There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be given releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass the barrier in groups of three, and they must immediately bond with each other to form a water molecule. You must guarantee that all the threads from one molecule bond before any other threads from the next molecule do.
- In other words:
  - If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.
  - If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.
- Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.
```c
Example 1:
Input: water = "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.

Example 2:
Input: water = "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
```

### Code
<a name=cpp></a>
#### CPP. condition_variable
```cpp
class H2O {
    mutex m;
    condition_variable cv;
    int o, h;
public:
    H2O() {
        o = 1;
        h = 2;
    }
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this]() { return h>0;});
         
        releaseHydrogen();    // releaseHydrogen() outputs "H".
        
        h -= 1;
        if (h==0 && o==0){
            h=2;
            o=1;
        }
        ul.unlock();
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this]() { return o>0;});
         
        releaseOxygen();    // releaseOxygen() outputs "O".
        
        o -= 1;
        if (h==0 && o==0){
            h=2;
            o=1;
        }
        ul.unlock();
        cv.notify_one();
    }
};
```
