# Lambda Expression(C++11)
- **What** 
  - Function that does not have any name. 
  - These can be defined inside any other function and they return their value to function pointers.
  - Lambda should be closed using Semicolon
- **Syntax**

***function_pointer  = [ ] () mutable throw -> return_type { .....function body ......};***

- `[   ]` called Capture List
  - captures local/Global variables defined outside lambda to be used inside lambda function.
  - For changing Values of passed variables:
    a. Passed by value: Cannot be changed. This passes variables are Read-Only
    b. Passed as reference variable: Can be changed.
- `()` called Parameter list which is Optional
  - Function Parameters to be passed.
- `mutable` keyword is Optional
- `throw` keyword is Optional
- `->` is return type which is Optional.

[Youtube](https://www.youtube.com/watch?v=uk0Ytomv0wY)    

## Examples
### 1. Empty capture list, parameter list, function body
```
#include<iostream>
using namespace std;
int main(){
  auto  p1  = [ ] () { } ;
  p1();                           //Calling lambda, Nothing is printed
```  

### 2. Filled Parameter List
```  
  auto p2 = [ ] (int a, int b) -> int { return a+b; };
  cout << p2(2,3) << endl;            //O/P 5
```

### 3. Capture List Examples.
#### 3a. Compilation Error. Local variable(i) should be passed in capture list
```  
  auto p3 =  [ ]  (int a, int b)  ->  int {  return a + b + i;   };
```

#### 3b. Pass by value(Not Changable) in capture-list. 
> Passing variable defined outside lambda cannot be modified in lambda.
```
  int i = 5;
  auto p4 =  [ i ]  (int a, int b)  ->  int {  return a + b + i;   };
  cout << p4(3,4) << endl;            //O/P 12 
```  

#### 3c. = inside Capture-list
- This means local variables can be used inside lamba without defining inside capture list.
- But values of i,j cannot be changed.
```  
  int i = 5, j = 6;
  auto p5  =  [=]  (int a, int b)  ->  int {  return a + b + i + j;   };
  cout << p5(3,4) << endl;                        //O/P 3+4+5+6=18
```  

#### 3d. Passing Reference(Changable) inside capture list
> Passing outside variable using refrence & to lambda. This variable can be changed inside lambda.
```  
  int i = 2;
  auto p6 = [ &i ] (int a, int b)  ->  int {  
    i = 5;
    return a + b + i; 
  };
  cout << p6(3,4) << endl;            //3+4+5 = 12
```

#### 3e. Passing both Reference and Value inside capture list
> Except "j" everything else is captured as reference(ie can be changed). Just "j" cannot be changed
```  
  auto p7  =  [ &, j ]  (int a, int b)  ->  int {
    i=7;
    return a + b + i; 
  };
```  

#### 3f. Except "i" nothing can be changed.
> Since It says capture everything as Value except "j"
```  
  auto p8  =  [ =, &i ]  (int a, int b)  ->  int {  i=95;  return a + b + i; };
```

#### 3g. Lambda capture initializers
Allows lambda captures initialized with arbitrary expressions.
```
  auto f = [x = test(2)] { return x; };           //20  
```  
          
## GENERIC LAMBDA(C++14)
- Now lambda can be made Generic, for example auto can be used inside lambda. Earlier this use to give error.
```
  auto ptr = [](auto x, auto y){ return x+y; };
  string a = "Never", b = "GiveUp";
  cout<<ptr(1,2)<<endl;                            //3
  cout<<ptr(a,b)<<endl;                            //NeverGiveUp   
```
