- [L Value](#lv)
- [L Value Reference / Reference Variable](#lr)
  - **Rules**
    - [1. Reference member variable can only be initialized using Initializer list](#r1)
- [R Value](#rv)
- [R Value Reference](#rr)
- [XVALUE/EXPIRING VALUE](#xv)
- [PRVALUE/PURE R VALUE](#pr)

<a name=lv></a>
### L VALUE(C++98)
Value that have memory address. LHS of assignment operator. 
Types of L values: a. Modifyable l-values: Lvalues without const.    b. Non-Modifyable lvalues: Lvalues with const  
```cpp
            int a = 5;        //a is L value
```

<a name=lr></a>
### L VALUE REFERENCE(C++11) / Reference Variable
Variable pointing to L-value(also called reference variable). Represented by &.
```cpp
            int a = 5;        //a is L value
            int &b = a;     //b is L-value reference, Since it points to L-value 
```
<a name=r1></a>
#### 1. Reference member variable can only be initialized using Initializer list
```c
class A {
    int &a;                //Reference member variable in class
public:
    A(int &x) { a=x; }
    void fun(){cout<<a;}
};

int main() {
    int b = 4;
    A obj(b);
    obj.fun();
}
$ ./a.out
Complier Error             //To resolve. A(int &x):a(x){}   
```

<a name=rv></a>
### R VALUE/TEMPORARY ITEM(C++98)
- Does not have memory address. RHS of assignment operator. Eg: literals(eg: 5), temporary computation state(x+y). Values cannot be assigned to R values.
- Function always returns a temporary or r-value stored in rax Register.    (github: move-ctr/function_returns_rvalue.cpp)
```c
            int a = 5;        //5 is R value
            int x =y+z;    //y+z is R value
```            
    
<a name=rr></a>    
### R VALUE REFERENCE(C++11) 
Variable pointing to temporary objects. Reference of r value. Represented by double ampersand (&&)
```c
            int &&c = 5;    //c is r-value reference  
```
**Example**
```
void f(int &a){                         //Function collecting lvalue ref
        cout<<a;
}
void f(int &&rval){                     //Function collecting rvalue ref
        cout<<rval;
}

/*error: call of overloaded ‘f(int)’ is ambiguous
void f(int b){
        cout<<"b="<<b;
}*/

int main(){
        int b = 5;              //b:l value, 5:r value
        f(b);                   //calls f(&a). b is lvalue              
        
        int &lr = b;            //lr: l value reference
        f(lr);                  //calls f(&a). lr is lvalue ref

        int &&rr = 10;          //rr: r value reference
        f(10);                  //calls f(&&a). 10 is rvalue
        f(rr);                  //calls f(&a). Because rval reference are be collected in Lvalue reference
}
```

<a name=xv></a>
### XVALUE/EXPIRING VALUE
(b+c) is called xvalue/temporary value which is ready to expire    
```c
a = b+c;  
```

<a name=pr></a>
### PRVALUE/PURE R VALUE 
Literal value is called pure R value.
```c
a =42; 
```

