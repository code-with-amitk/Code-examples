## Compile time or Run time
- **Literal?**
  - Literals are the constant values assigned to variables or literals means fixed values that cannot be modified. Example
```c
  const int a=10;     //Integer literal whose value is fixed
  string a = "hello"; //String literal whose value is fixed
```  

||Stack(compile time)|Heap(runtime)|
|---|---|---|
|What|All data stored on the stack must have a known, fixed size|Data with an unknown size at compile time stored on the heap|
|Type of data stored|int,float,char,string literal|Which can change at run time. Eg: String|
|Which is Faster|Stack is faster wrt heap because for pushing data on stack, place is never required to be searched. Push always happens at top of stack|Slower Why? When we ask data at runtime from heap, memory allocator finds big empty spot & returns. This search takes time|
