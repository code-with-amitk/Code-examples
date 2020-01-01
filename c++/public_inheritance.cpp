/*
What is Inheritance? Creating new class(decendent/derived) from existing class(ansector/base).

*************Rules of Public Inheritance***************
1. All member variables(public,protected,pvt) of base are inherited inside derv class. See Memory layout of derv class object.

2. Inheriting Base member variables inside derv:
a. Public:
        - all public members of the base class are accessible as public members of the derived class
        - ie goes in public section
b. protected:
        - all protected members of the base class are accessible as protected members of the derived class
        - ie goes in protected section
        - Function present in protected section cannot be called using Object.
c. private:
        - private members of base class does not go into private section of derv class.
        - private members of the base are never accessible unless friended.
        How to access private data members inside derv? Using public function in base and calling same from derv.

3: Instance of derv class can invoke any public function of base class.

4: SAME-NAMED-FUNCTION_IN_BASE_AND_DERV(FUNCTION-OVERRIDING)
 - Base & derv can have same named function. But with derv Object, derv class function is called.
 - (function overriding) Same named function having different body inside derv class.
*******************************************************

*****Memory layout of Derv class object******
<-      stack   ->
| c=3 |b=2 | a=1 |
B obj
*********************************************
*/

#include<iostream>
using namespace std;

class A{
public:
        int a = 1;
        void f(int x){c=x;}
protected:
        int b = 2;
private:
        int c = 3;
};

class B : public A{
public:
        void f1(){
                cout<<"a="<<a<<endl;                    //2a
                f2();
                f(4);                                   //2d
        }
protected:
        void f2(){cout<<"b="<<b<<endl;}                 //2b
private:
        //void f3(){cout<<"c="<<c<<endl;}               //2c  error: ‘int A::c’ is private within this context
};

int main(){
        B obj;
        obj.f1();                       //Output: a=1
}

/*
Output:
# ./a.out
a=1
b=2
 */
