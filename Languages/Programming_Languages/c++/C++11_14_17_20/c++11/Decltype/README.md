## Decltype
- **What?** Inspects the type of an entity/expression.
- **Why use decltype?** When declaring types that are difficult or impossible to declare using standard notation, like lambda-related types or types that depend on template parameters.        
- **SYNTAX?**
```c++
        decltype ( expression )         //Since C++11
        decltype ( type )               //Since C++11
``

A. DECLTYPE: [C++11]
   A1. Declaring variable using decltype
   A2. LAMBDA FUNCTION:
       - return type of function is int
       - decltype(f) is int
   A3. TEMPLATES:
       - return type depends on template parameters
       - return type can be deduced since C++14

B. DECLTYPE(AUTO): [C++14]
Similar to auto, it deduces return types while keeping their references
and cv-qualifiers(const, volatile), while auto will not.       
*/

### Code
        
```
#include<iostream>
#include<string>
using namespace std;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u)
{
    return t+u;
}

int main(){

        /******A. DECLTYPE********/
        //A1
        int a;
        decltype(a) b = 10;
        cout<<b<<endl;          //10


        //A2.LAMBDA
        auto f = [](int a, int b)->int {return a*b;};
        decltype(f) c = f;
        cout<<c<<endl;          //1


        //C.TEMPLATE
        decltype(add(1.2,1.3)) d = 3.4;         //float d = 3.4
        string s1 = "never", s2 = "give";
        decltype(add(s1,s2)) s = "Think";       //string s = "Think"
        cout<<d<<endl;          //3.4
        cout<<s<<endl;          //Think
        /*************************/


        /****B. decltype(auto)*****/
        const int x = 0;
        auto x1 = x;            //Problem: x1 is int, should be 'const int'
        decltype(auto) x2 = x;  //Solved: x2 is const int

        int y = 0;
        int& y1 = y;
        auto y2 = y1;           //Problem: y2 is int
        decltype(auto) y3 = y1; //Solved:  y3 is int&   

        int&& z = 0;
        auto z1 = move(z);              //Problem: z1 is int
        decltype(auto) z2 = move(z);    //Solved: z2 is int&&   
}

/*****B. decltype(auto)*******/
auto fun(const int& i) {
        return i;                       //Problem:Return type is `int`
}

decltype(auto) fun(const int &i){
        return i;                       //Solved: Return type is `const int&`
}
```
