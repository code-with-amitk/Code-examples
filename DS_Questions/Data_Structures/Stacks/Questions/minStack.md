**Min Stack**
- [Approach-1, O(logn). Using multiset, multimap](#a1)

### 155. Min Stack
- Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
- Implement the MinStack class:
```c
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
```
Example 1:
```c
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output: [null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

<a name=a1></a>
### Approach-1. O(logn). Using multiset, multimap
#### Logic
- _1._ Take stack, multiset, multimap(implemented using balanced BT).
  - `multiset<int>` will always store value in ascending order.
- _2._ push(), pop(), top() are achieved in O(1) time using stack.
```
  pop().
    - Erase elements from stack, multimap<int, multiset<int>::iterator>, multiset<int>
```
- _3._ getMin() 
```c
  On each push, pop. Insert element into multiset, multimap<element, multiset::iterator> //O(logn)
  getMin()
    - search element in multimap. <key=element, value=iterator to multiset>  //O(logn)
    - goto iterator in multiset and return element    //O(logn)
```
#### Code
```cpp
class MinStack {
    stack<int> st;
    multiset<int> s;
    multimap<int, multiset<int>::iterator> um;
public:
    MinStack() { }
    
    void push(int val) {
        st.push(val);
        auto it = s.insert(val);
        um.insert({val, it});
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        auto it = um.find(val);
        s.erase(it->second);
        um.erase(it);
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *s.begin();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
