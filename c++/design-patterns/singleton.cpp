/*
 	singleton.cpp	//Single Object

WHAT? Only single instance/object of class can be created. And provides Global point of access to it.

******HOW SINGLETON IS ACHIEVED?*********
1.  BLOCK ALL OBJECT CREATION METHODS
	1A. MAKE DEFAULT CTR PVT
	1B. MAKE COPY CTR PVT
	1C. MAKING ASSIGNMENT OPERATOR PVT
	
2. Use static variable to save Object address, since only 1 static variable exists/class.

3. Use Static Method to create Objects, static variables can be manipulated inside static methods.

4. Call static method from main(), to create Object.
**********************************************

***************Multi-threaded, Synchronization***************
Multithreaded: Below code is not thread-safe. if 2 threads run this code it will creates two objects for singleton.
Solution:
    1. Making fun() as synchronized (In Java)
            public static synchronized test fun(){        //Adding synchronized makes every thread to wait for its turn.    
            }
    2. Using Mutexes (In Linux)
    
Drawbacks of Synchronization: This is heavy/time consuming operation.
1. Do eagerly instance creation (instead of lazily done Below)
            public class test{
                    static test obj = new test(); //Since all threads have same DS. so there will be only 1 copy of obj.
                    test(){}
                    public:
                        static test fun(){  return obj;  }
            }
2. Check the variable before locking mutex//Double-Checking Locking
        class test{
                volatile test obj;
            public:
                static test fun(String n){
                        if(obj == NULL){        //Adding extra check for Object reduces overhead significantly.
                            pthread_mutex_lock(&var);
                                if(obj=NULL)
                                        obj = new test(n);
                            pthread_mutex_unlock(&var);
                        }
                        return obj;    
                }
        }
**************************************************************
*/

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
