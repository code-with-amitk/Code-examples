# Lambda Expression(C++11)
- **What**
  - Function that does not have any name. 
  - Can be defined inside any other function and they return their value to function pointers.
  - Lambda should be closed using Semicolon
- **Why?** For some logic/code to be used for only 1 time, function is not a good idea.  
- **Advantages**
  1. Can defined inside other function.
  2. Complete Logic of function can be written as argument to function.
- Example:
```c++
    vector<int> v {4, 1};  
    count(v.begin(), v.end(), [] (int a) { return (a >= 5); });
```
- **Syntax**
```c++
  function_pointer  = [ ] () mutable throw -> return_type { .....function body ......};
  
  [   ] called Capture List
    - captures local/Global variables defined outside lambda to be used inside lambda function.
    - Changing Values of passed variables:
      - Passed by value `[=]` are RO: These cannot be changed.
      - Passed as reference `[&]`: Can be changed.
  () called Parameter list which is Optional
    - Function Parameters to be passed.
  mutable keyword is Optional
  throw keyword is Optional
  -> is return type which is Optional.
``` 

[Youtube](https://www.youtube.com/watch?v=uk0Ytomv0wY)    

## 1. Empty capture list, parameter list, function body
```c++
#include<iostream>
using namespace std;
int main(){
  auto  p1  = [ ] () { } ;
  p1();                           //Calling lambda, Nothing is printed
```  

## 2. Filled Parameter List
```c++  
  auto p2 = [ ] (int a, int b) -> int { return a+b; };
  cout << p2(2,3) << endl;            //O/P 5
```

### 3. CAPTURE LIST EXAMPLES
#### 3A. Compilation Error. Local variable(i) should be passed in capture list
```c++
  auto p3 =  [ ]  (int a, int b)  ->  int {  return a + b + i;   };
  //Compilation error
```


### Real world examples
#### 1. Open /dev/mem
```c++
int main(){
  int fd;
  if((fd=[]()->int{return open("./hello.txt", O_RDWR);}()) != -1)
    cout<<fd;
}
```
