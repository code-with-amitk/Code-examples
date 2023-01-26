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
  NestedIterator(List<NestedInteger> nestedList) {
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
- Your code will be tested with the following pseudocode:
```c
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res
If res matches the expected flattened list, then your code will be judged as correct.
```c
Example 1:
Input: nestedList = [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
```
