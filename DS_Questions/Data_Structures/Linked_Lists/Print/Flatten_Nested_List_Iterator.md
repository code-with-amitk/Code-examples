**Flatten Nested List Iterator**

### [341. Flatten Nested List Iterator](https://leetcode.com/problems/flatten-nested-list-iterator/description/)
- You are given a nested list of integers nestedList. 
- Each element is either an integer or a list whose elements may also be integers or other lists. Example
```c
  [[1,1],2,[1,1]]
```
- There is a `class NestedIterator` in which following functions(isInteger(), getInteger(), getList()) are already defined
- **Your Task:** Implement following functions(constructor, next(), hasNext()) of same class.
```c
class NestedIterator {
public:
  /////////////// Already defined Functions /////////////////
  // Return true if this node holds a single integer, rather than a nested list.  
  bool isInteger() const {
    if (present node is 1 integer)
      return true;
    else
      return false;
  }
  
 // if present node holds int return it, else result is undefined
 int getInteger() const {
   if (present node is 1 integer)
     return int_value;
   else
     //Undefined
 }
  
  // if present node holds list return it, else result is undefined
  const vector<NestedInteger> &getList() const {
     if (present node holds list)
       return list
     else
       //Undefined
  }
  
  /* You need to code these Functions 
     with help of above provided functions
  */
  NestedIterator(vector<NestedInteger> &nestedList) {
    // Store nested list locally
  }
  
  int next() {                                    
    // Returns the next integer in the nested list.
  }
  
  boolean hasNext() {                             
    if (present node is integer || any integer is present ahead in list)
      return true;
    else
      return false;
  }
};
```
- **Then class will be tested with the following code:**
```c
int main() {
  vector<NestedInteger> nestedList = {{1,1},2,{1,1}};
  NestedIterator obj(nestedList);
  vector<NestedInteger> res;
  auto it = res.hasNext();
  while (it != res.end()) {
    res.push_back (iterator.next());
    it = res.hasNext();
  }
  return res;   //If res matches the expected flattened list, then your code will be judged as correct.
}
```
**Examples**
```c
Example 1:
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Input: nestedList = [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
```

### Approach-1. stack
### Logic
- _1._ Use stack to store the nested List nodes.
- _2._ Store 1st item on top of stack means, start filling from back to 1st.
#### Code
**CPP**
```cpp
class NestedIterator {
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Fill last element 1st
        for(int i = nestedList.size() - 1; i >= 0; --i)
            st.push(nestedList[i]);
    }
    
    int next() {
        // if this node holds Integer
        // return it
        auto result = st.top().getInteger();
        st.pop();
        return result;
    }
    
    bool hasNext() {
        // until stack is not empty
        while(!st.empty()) {
            NestedInteger top = st.top();

            if (top.isInteger()) {
                // if node is 1 integer not nestedList, return true
                return true;
            } else {
                st.pop();
                // This node holds a Nested list
                // DFS to elements in list
                vector<NestedInteger>& next = top.getList();
                for(int i = next.size() - 1; i >= 0; --i)
                    st.push(next[i]);
            }
        }//while
        return false;
    }
};
```
