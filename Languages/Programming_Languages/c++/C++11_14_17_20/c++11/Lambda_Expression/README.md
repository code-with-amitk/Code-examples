- [What is Lambda Function](#what)
  - [Example](#ex)
  - [Lambda vs Functor](#vs)
- [Syntax](#syn)
- Examples
  - [Empty capture list, parameter list, function body](#emp)
  - [Pass By Value using Capture list](#value)
    - [1. Passing 1 outside variable to lambda](#value1)
    - [2. Passing all outside variables to lambda](#valueall)
    - [3. Outside Variable cannot be modified in lambda](#notmod)
  - [Pass by Reference(&) RW](#ref) 

<a name=what></a>
## Lambda Expression(C++11)
- Function that does not have a name, can be defined inside other function. Returns value using function pointers. Lambda should be closed using Semicolon.
- *Why lambda?* For some logic/code to be used for only 1 time, function is not a good idea.  
- *Advantages*  
  - _1._ Can defined inside other function.   
  - _2._ Complete Logic of function can be written as argument to function.

<a name=ex></a>
### Example
```cpp
Example-1
  auto p2 = [ ] (int a, int b) -> int { return a+b; };
  cout << p2(2,3) << endl;            //O/P 5
```
<a name=vs></a>
### Lambda vs Functor
- *1.* Lambdas are more of writing compact/inline code Basically for 1 time only.
- *2.* Functors store state of object can be called again and again and provide added advantage over functions.
[Youtube](https://www.youtube.com/watch?v=uk0Ytomv0wY)    

<a name=syn></a>
## Syntax
```cpp
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

## Examples
<a name=emp></a>
### Empty capture list, parameter list, function body
```cpp
int main(){
  auto  p1  = [ ] () { } ;
  p1();                           //Calling lambda, Nothing is printed
```

<a name=value></a>
### Pass By Value using Capture list
- Passing outside variables into lambda using capture list. Pass by value variable are RO, cannot be modified lambda.
<a name=value1></a>
#### 1. Passing 1 outside variable to lambda
```cpp
  int i = 1;
  auto p =  [ i ]  (int a, int b)  ->  int {  return a + b + i;   };
  cout << p(2,3) << endl;            //6
```  
<a name=valueall></a>
#### 2. Passing all outside variables to lambda
```c++
  int i = 1, j = 2;
  auto p =  [ = ]  (int a, int b)  ->  int {  return a + b + i + j;   };
  cout << p(3,4) << endl;            //10
```  
<a name=notmod></a>
#### 3. Outside Variable cannot be modified in lambda
```c++
  int i = 1;
  auto p =  [ = ]  (int a, int b) -> int { i = 6;  return a + b + i;   };   //Compilation error: assignment of read-only variable ‘i’
  cout << p4(2,3) << endl;
```  

#### 1. Open /dev/mem
```c++
int main(){
  int fd;
  if((fd=[]()->int{return open("./hello.txt", O_RDWR);}()) != -1)
    cout<<fd;
}
```

<a name=ref></a>
### Pass by Reference(&) RW
- Passing outside variables into lambda. Variables passed can be modified inside lambda.
```cpp
  //Passing 1 outside variable inside lambda
  int i = 1;
  auto p = [ &i ] (int a, int b)  ->  int {         
    i = 5;  return a + b + i; 
  };
  cout << p(2,3) << endl;            //10


  //Passing all outside variables to lambda
  int i = 1, j = 2;
  auto p = [ & ] (int a, int b)  ->  int {
    return a + b + i + j; 
  };
  cout << p(3,4);    //10
```
