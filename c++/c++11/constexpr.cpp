/*      constexpr.cpp

WHAT IS CONST?
- CONST VARIABLE: Whose value remains same through out the program.
- CONST FUNCTION: 
 
A. CONSTEXPR VARIABLE: variable whose value is derived at compile-time & its initialized. 
    - Should be compile time constant. 
    - Should be initialized at declaration.

 B. CONSTEXPR FUNCTION:
    B1. it return value should be computable at compile time only.
    B2. RULES:
        - constexpr function or constructor is implicitly inline.
        - constexpr function accepts and returns only literal-types.
        - constexpr functions cannot be virtual
        - A constructor can't be defined as constexpr when the enclosing class has any virtual base classes.
        - The body can be defined as = default or = delete.
        - The body can contain no goto statements or try blocks.
        - constexpr function return value can be collected in const variable.
*/

#include<iostream>
using namespace std;

/*********B1************/
/*Problem: return depends on runtime
constexpr float fun(float a)
{
        int b;
        cin>>b;                 //error: uninitialized variable ‘b’ in ‘constexpr’ function
        return a+b; 
};*/

//Solution: nothing depends on runtime
constexpr float fun(float a)
{
        int b=10;
        return a+b;
};
/***********************/


int main(){

        /******** A. CONSTEXPR VARIABLE*******
          - Should be compile time constant. 
          - Should be initialized at declaration.        
        */
         ///////////PROBLMATIC CODE////////////
        int a;
        cin>>a;
        const int b = a;   //Problem: How b is const if its value can be changed at runtime?
        //////////////////////////////////////
 
        /////////SOLUTION: constexpr//////////
        //constexpr int c = a;  //error: uninitialized const ‘c’ [-fpermissive
        //constexpr int c;      // error: uninitialized const ‘c’ [-fpermissive]
        constexpr int c = 1;
        /***************************************/

        const float d = fun(2);
}
