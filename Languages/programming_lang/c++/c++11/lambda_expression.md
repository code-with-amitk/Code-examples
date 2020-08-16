# Lambda Expression(C++11)
- **What** 
  - Function that does not have any name. 
  - These can be defined inside any other function and they return their value to function pointers.
  - Lambda should be closed using Semicolon
- **Advantages**
  1. Can defined inside other function.
  2. For some logic/code to be used for only 1 time, function is not a good idea.  
  3. Complete Logic of function can be written as argument to function.
```  
    vector<int> v {4, 1};  
    count(v.begin(), v.end(), [] (int a) { return (a >= 5); });
```
- **Syntax:**     function_pointer  = [ ] () mutable throw -> return_type { .....function body ......};
  - `[   ]` called Capture List
    - captures local/Global variables defined outside lambda to be used inside lambda function.
    - Changing Values of passed variables:
      - Passed by value `[=]` are RO: These cannot be changed.
      - Passed as reference `[&]`: Can be changed.
  - `()` called Parameter list which is Optional
    - Function Parameters to be passed.
  - `mutable` keyword is Optional
  - `throw` keyword is Optional
  - `->` is return type which is Optional.

[Youtube](https://www.youtube.com/watch?v=uk0Ytomv0wY)    

## 1. Empty capture list, parameter list, function body
```
#include<iostream>
using namespace std;
int main(){
  auto  p1  = [ ] () { } ;
  p1();                           //Calling lambda, Nothing is printed
```  

## 2. Filled Parameter List
```  
  auto p2 = [ ] (int a, int b) -> int { return a+b; };
  cout << p2(2,3) << endl;            //O/P 5
```

## 3. CAPTURE LIST EXAMPLES
### 3A. Compilation Error. Local variable(i) should be passed in capture list
```  
  auto p3 =  [ ]  (int a, int b)  ->  int {  return a + b + i;   };
  //Compilation error
```

### 3B. PASS BY VALUE `[ = ]`
#### 1. Passing 1 outside variable inside lambda
- Outside variable i can be used inside lambda.
```
  int i = 5;
  auto p4 =  [ i ]  (int a, int b)  ->  int {  return a + b + i;   };
  cout << p4(3,4) << endl;            //O/P 12 
```  

#### 2. Using all outside variables inside lambda `[ = ]`
- This means all local variables can be used inside lamba without defining inside capture list.
- But values of i,j cannot be changed.
```
  int i = 5, j = 6;
  auto p4 =  [ = ]  (int a, int b)  ->  int {  return a + b + i + j;   };
  cout << p4(3,4) << endl;            //O/P 18 
```  

#### 3. Pass by value variable are RO, cannot be modified lambda
```
  int i = 5;
  auto p4 =  [ = ]  (int a, int b) -> int { i = 6;  return a + b + i;   };
  cout << p4(3,4) << endl;
  
  Compilation error: assignment of read-only variable ‘i’
```  

### 3C. PASS BY REFERENCE `[ & ]` RW
#### 1. Passing 1 outside variable inside lambda
- Passing outside variable using refrence & to lambda. This variable can be changed inside lambda.
```  
  int i = 2;
  auto p6 = [ &i ] (int a, int b)  ->  int { i = 5;  return a + b + i; };
  cout << p6(3,4) << endl;            //3+4+5 = 12
```

#### 2. Using all outside variables inside lambda `[ & ]`
```  
  int i = 2, j = 3;
  auto p6 = [ & ] (int a, int b)  ->  int { return a + b + i + j; };
  cout << p6(4,5);    //14
```
  
### 3D. Using both `[=]` and `[&]`
#### 1. Capture by reference all except 1
- Except "j" everything else is captured as reference(ie can be changed). Just "j" cannot be changed
```  
  auto p7  =  [ &, j ]  (int a, int b)  ->  int {
    i=7;
    return a + b + i; 
  };
```  

#### 2. Capture by Value all except 1
- Except "i" nothing can be changed.
```  
  auto p8  =  [ =, &i ]  (int a, int b)  ->  int {  i=95;  return a + b + i; };
```

### 3E. Lambda capture initializers
- Allows lambda captures initialized with arbitrary expressions.
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

## THIS INSIDE CAPTURE LIST 
### LAMBDA CAPTURE FOR `*THIS` (C++17)
- This is CALL-VALUE-COPY of the current object.
- call-by-value means you cannot change any of object's values.
```
class A{
  int  a = 3;       
public:
  void f(){
    int l;
    auto ptr = [l, *this]{

      //a = 3;                              //Compilation error: Changing value of RO Object is not allowed

      int k = a + l;    //This is OK
    };
  }
};
```

### Other `this` examples
#### Using `this` with Reference inside capture list
```
  int i = 2;
  auto p6 = [ &, this ] (int a)  ->  int { return a + i; };     //OK, equivalent to [&]
  cout << p6(4);    //6

   [&, this, i]{};                                              // OK, equivalent to [&, i]
```

#### Using `this` with Value inside capture list
```
  [=, *this]{};   // since c++17: OK: captures the enclosing function by copy
                  // until C++17: Error: invalid syntax
                    
  [=, this] {};   // since C++20: OK, same as [=]
                  // until C++20: Error: this when = is the default
```

#### Repeated `this` inside capture list
```
  [this, *this] {};   // Error: "this" repeated (C++17)
```

## BY-COPY, BY-REFERENCE CAPTURE of Parameter Pack (C++20)
```
auto f = []<typename ...Ts>(Ts&& ...ts) {
   return foo(std::forward<Ts>(ts)...);
};
```

### Real world examples
#### 1. Open /dev/mem
```
int main(){
  int fd;
  if((fd=[]()->int{return open("./hello.txt", O_RDWR);}()) != -1)
    cout<<fd;
}
```
