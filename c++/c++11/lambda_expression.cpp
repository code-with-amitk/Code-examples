/*      lambda_expression.cpp

What? Function that does not have any name. This can be defined inside any other function and they return their value to function pointers.
URL: https://www.youtube.com/watch?v=uk0Ytomv0wY

*******SYNTAX*********
    function_pointer  = [ ] () mutable throw -> return_type { .....function body ......};

    Lambda should be closed using Semicolon.
    [ ]: Capture List
        captures local/Global variables defined outside lambda to be used inside lambda function.
        For changing Values of passed variables:
                a. Passed by value: Cannot be changed. This passes variables are Read-Only
                b. Passed as reference variable: Can be changed.
    (): Optional. Parameter list
        Function Parameters to be passed.

    mutable: Optional

    throw:Optional
        Exception Specification,    

    ->:Optional
        return type
************************

********COVERS**********
 A. Examples
 B. GENERIC LAMBDA(C++14):
    - Now lambda can be made Generic, for example auto can be used inside lambda. Earlier this use to give error.
************************
*/
#include<iostream>
using namespace std;

int main(){

        /*Ex1: empty capture list, parameter list, function body*/
        auto  p1  = [ ] () { } ;
        p1();                           //Calling lambda, Nothing is printed


        /*Ex2: empty capture list
               Parameters:2,3
               returns: int */
        auto p2 = [ ] (int a, int b) -> int { return a+b; };
        cout<<p2(2,3)<<endl;            //O/P 5


        /*Ex3:Compilation Error. Local variable(i) should be passed in capture list*/
        //auto p3 =  [ ]  (int a, int b)  ->  int {  return a + b + i;   };


        /*Ex4: capture-list: takes the variables defined outside lambda to be used inside lambda*/
        int i = 5;
        auto p4 =  [ i ]  (int a, int b)  ->  int {  return a + b + i;   };
        cout<<p4(3,4)<<endl;            //O/P 12 


        /*Ex5: = inside Capture-list?
         Tihs means local variables can be used inside lamba without defining inside capture list. 
         But values of i,j cannot be changed.*/
        int j = 6;
        auto p5  =  [=]  (int a, int b)  ->  int {  return a + b + i + j;   };
        cout<<p5(3,4)<<endl;                        //O/P 3+4+5+6=18


        /*Ex6: Reference variables can be changed*/
        auto p6  =  [ &i ]  (int a, int b)  ->  int {  i=5;  return a + b + i; };
        cout<<p6(3,4)<<endl;            //12


        /*Ex7: Except "j" everything else is captured as reference(ie can be changed).
               Just "j" cannot be changed*/
        auto p7  =  [ &, j ]  (int a, int b)  ->  int {  i=7;  return a + b + i; };


        /*Ex8: Except "i" nothing can be changed.
               Since It says capture everything as Value except "j"*/
        auto p8  =  [ =, &i ]  (int a, int b)  ->  int {  i=95;  return a + b + i; };


        /*GENERIC LAMBDA*/
        auto ptr = [](auto x, auto y){return x+y;};
        string a="Never", b="GiveUp";
        cout<<ptr(1,2)<<endl;                            //3
        cout<<ptr(a,b)<<endl;                            //NeverGiveUp
}
