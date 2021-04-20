## Code
- Lazy Initialization
- Eagerly Initialization
```c++
#include<iostream>
using namespace std;

//////////////////////////////LAZY INITIALIZATION START///////////////////////////////////
/****C++11 CLASS*****/
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
/*****C++11 CLASS*****/
/****C++98 CLASS*******
class A{
        A(){}
        A(A &){}
        void operator = (const A&){}
        static A *ptr;
public:
        static A *fun(){
                if(ptr == NULL)
                        ptr = new A();
                return ptr;
        }
};
*****C++98 CLASS*****/

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
0x1ec5e70
*/
//////////////////////////////LAZY INITIALIZATION END///////////////////////////////////

//////////////////////////////EAGERLY INITIALIZATION START/////////////////////////////////
public class Singleton {
	private static Singleton uniqueInstance = new Singleton();
	private Singleton() {}
	public static Singleton getInstance() {
		return uniqueInstance;
	}
}
//////////////////////////////EAGERLY INITIALIZATION END///////////////////////////////////
```
