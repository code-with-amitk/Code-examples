## C++11 Code
```c++
#include<iostream>
using namespace std;

class A{
    A(){}					//1A
    A(A &)=delete;				//1B
    void operator = (const A&)=delete;	//1C
	  ~A()=delete;
    static A *ptr;				//2
public:
        static A *fun(){			//3
                if(ptr == NULL)
                        ptr = new A();
                return ptr;
        }
};

A *A::ptr = nullptr;

int main(){
//      A obj1;         //Error:error: ‘A::A()’ is private within this context
        A *p1 = A::fun();			//4
        cout<<p1<<endl;

        A *p2 = A::fun();
        cout<<p2<<endl;
}
/*      Output:
0x1ec5e70
*/
```
