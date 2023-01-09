**Min Stack**
- [Approach-1, O(logn). Using multiset, multimap](#a1)
- [Approach-2. O(1). 2 stacks](#a2)
- [Approach-3. O(1). 1 stack](#a3)
  - Code
    - [CPP](#cpp)
    - [C](#c)

### [155. Min Stack](https://leetcode.com/problems/min-stack/description/)
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

<a name=a2></a>
### Approach-2. O(1). 2 Stacks
#### Logic
- _1._ Take 2nd stack, in which we insert min values only.
#### Code
```cpp
class MinStack {
    stack<int> s1, s2;
public:
    MinStack() { }
    
    void push(int val) {
        s1.push(val);
        // Insert on s2 stack only when s2 is empty or
        // incoming value <= s2.top()
        if (s2.empty() || val <= s2.top())
            s2.push(val);
    }
    
    void pop() {
        // if s1 and s2 have same values remove from both
        if (s2.top() == s1.top())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
```

<a name=a3></a>
### Approach-3. O(1). 1 stack
#### Logic
- _1._ Store pair = {value, minimum value} inside the stack.
- _2._ Whenever getMin() is called return 2nd value from pair.
#### Code
<a name=cp></a>
**CPP**
```cpp
class MinStack {
        //number, minInStack
    stack<pair<int, int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty())
            st.push({val, val});
        else {
            auto it = st.top();
            if (val <= it.second)
                st.push({val, val});
            else 
                st.push({val, it.second});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
```
<a name=c></a>
**C**
```c
typedef struct {
    int value;
    int min;
} MinStack;
int top = -1;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack)*30000);
    memset(obj, 0, sizeof(MinStack)*30000);
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (top==-1){
        ++top;
        obj[top].value = val;    
        obj[top].min = val;
    }
    else {
        int minValue = minStackTop(obj);
        ++top;
        if (minValue <= val)
            obj[top].min = minValue;
        else
            obj[top].min = val;
        obj[top].value = val;
    }
}

void minStackPop(MinStack* obj) {
    obj[top].min = 0;
    obj[top].value = 0;
    top--;
}

int minStackTop(MinStack* obj) {
  return obj[top].value;
}

int minStackGetMin(MinStack* obj) {
    return obj[top].min;
}

void minStackFree(MinStack* obj) {
    free(obj);
    obj = NULL;
}
```
