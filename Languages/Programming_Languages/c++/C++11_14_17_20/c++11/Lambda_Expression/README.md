- [Lambda usecase, advantages](#uc)
- [Syntax](#syn)
- [Lambda vs Functor](#vs)
- Examples
  - [Empty capture list, parameter list, function body](#emp)
  - [Pass By Value(RO) using Capture list, outside var cannot modified](#value)
  - [Pass by Reference(&) RW, can modify outside variables](#ref) 
  - [Pass by ref and val in capture list](#refval)


<a name=uc></a>
## Lambda Expression(C++11) / Anonymous Function
Function does not have a name, defined inside other function
- **Usecases?**
  - _1._ For some logic/code to be used for only 1 time, function is not a good idea.
  - _2._ If some logic/function need to be called again and again, then function call is not good(stack creation/destroy). Store in variable(pointer).
- **Advantages**
  - _1._ Can defined inside other function.   
  - _2._ Complete Logic of function can be written as argument to function.
```cpp
  auto p2 = [ ] (int a, int b) -> int { return a+b; };
  cout << p2(2,3) << endl;            //O/P 5
```
**Syntax**
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
  return type is Optional.  //if return type is not specified its Deduced Automatically
``` 

<a name=vs></a>
**Lambda vs Functor**
  - *1.* Lambdas are more of writing compact/inline code Basically for 1 time only.
  - *2.* Functors store state of object can be called again and again and provide added advantage over functions.
[Youtube](https://www.youtube.com/watch?v=uk0Ytomv0wY)    

## Examples
<a name=emp></a>
### Empty capture list, parameter list, function body
```cpp
int main(){
  auto  p1  = [ ] () { } ;
  p1();                           //Calling lambda, Nothing is printed
```

<a name=value></a>
### Pass By Value
Passing outside variables into lambda using capture list. Pass by value variable are RO, cannot be modified lambda.
```cpp
  //1. Passing 1 outside variable to lambda
  int i = 1;
  auto p =  [ i ]  (int a, int b)  ->  int {
    return a + b + i;   
  };
  cout << p(2,3) << endl;            //6

  //2. Passing all outside variables to lambda
  int i = 1, j = 2;
  auto p =  [ = ]  (int a, int b)  ->  int {
    return a + b + i + j;   
  };
  cout << p(3,4) << endl;            //10

  //3. Outside Variable cannot be modified in lambda
  int i = 1;
  auto p =  [ = ]  (int a, int b) -> int {
    i = 6;                        //Compilation error: assignment of read-only variable ‘i’
    return a + b + i;   
  };   
  cout << p4(2,3) << endl;
```  

<a name=ref></a>
### Pass by Reference(&) RW
Passing outside variables into lambda. Variables passed can be modified inside lambda.
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

<a name=refval></a>
### Pass by ref and val in capture list
Capture by reference all except 1
  - Except "j" everything else is captured as reference(ie can be changed). Just "j" cannot be changed
```cpp
  auto p7  =  [ &, j ]  (int a, int b)  ->  int {
    i=7;
    return a + b + i; 
  };
```  
Capture by Value all except 1
  - Except "i" nothing can be changed.
```cpp
  auto p8  =  [ =, &i ]  (int a, int b)  ->  int {  i=95;  return a + b + i; };
```

#### 1. Open /dev/mem
```c++
int main(){
  int fd;
  if((fd=[]()->int{return open("./hello.txt", O_RDWR);}()) != -1)
    cout<<fd;
}
```


