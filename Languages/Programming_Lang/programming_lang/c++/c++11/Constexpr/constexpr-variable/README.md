### Comparison

- **const vs constexpr**

||const|constexpr|
|---|---|---|
|What?|(As per definition)Whose value remains same through out the program|variable whose value is derived at compile-time & initialized|

- **Example**
```c++
#include<iostream>
using namespace std;
int main(){

 ///////////PROBLMATIC CODE////////////
 int a;
 cin>>a;
 const int b = a;   //Problem: How b is const if its value can be changed at runtime?
 
 /////////SOLUTION: constexpr//////////
 //constexpr int c = a;  //error: uninitialized const ‘c’ [-fpermissive
 //constexpr int c;      // error: uninitialized const ‘c’ [-fpermissive]
 constexpr int c = 1;
}
```
