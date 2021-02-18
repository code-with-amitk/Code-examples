## Empty capture list, parameter list, function body
```c++
#include<iostream>
using namespace std;
int main(){
  auto  p1  = [ ] () { } ;
  p1();                           //Calling lambda, Nothing is printed
```  
