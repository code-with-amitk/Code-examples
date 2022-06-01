**Implement Queue using Stacks**
- [Approach, 2 stacks](#a)
  - Code
    - [CPP](#cpp)
  - [Complexity](#co) 


### [Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
- Implement a queue using only 2 stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
- Implement the MyQueue class:
```c
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
```

<a name=a></a>
### Approach, 2 Stacks
- _1._ Take 2 stacks(s1, s2). s1 represents queue, while s2 represents temporary stack.
- _2._ Insert=1. if s1 is empty insert directly. 
```c
Insert:1   1
          s1 s2
```
- _3._ Insert=2. if s1 is not empty, Pop all elements from s1, push on s2. Then insert 2
```c
Insert:2
          1
          s1 s2
          
          2   1
          s1 s2
          
          1
          2
          s1 s2    //Pop all elements from s2 and place back on s1.
```
- _4._ Insert=3
```c
Insert:3
           1
           2
          s1 s2
          
              2
              1  
          s1 s2

              2
           3  1
          s1 s2

           1
           2
           3
          s1 s2

```

#### Code
<a name=cpp></a>
**CPP**
```cpp
class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s1.size() == 0)
            s1.push(x);
        else{
            //Remove elements from s1 push to s2
            while (s1.empty() != 1){
                s2.push(s1.top());
                s1.pop();
            }
            
            //Push element on s1
            s1.push(x);
            
            //Place all elements back on s1
            while(s2.empty() != 1){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        if (s1.empty())
            return 0;
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        if (s1.empty())
            return 0;        
        return s1.top();
    }
    
    bool empty() {
        return s1.empty() == 1 ? true : false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

#### Complexity
- **Time:** 
  - Push: O(n). n elements on stack
  - Pop: O(1)
- **Space:** O(n). O(n/2) for stack1, O(n/2) for stack2
