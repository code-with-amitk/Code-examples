/*
 	singleton.cpp	//Single Object

WHAT? Only single instance/object of class can be created. And provides Global point of access to it.

HOW SINGLETON IS ACHIEVED?

**********1.  BLOCK ALL OBJECT CREATION METHODS************

*****1A. MAKE DEFAULT CTR PVT:********
- Object should not be created from direct calls of constructor.

	///////////COMPILER PROVIDED DEFAULT CTR///////////
	class A{
        	int a=1;
	public:
        	void disp(){ cout<<a<<"\n";}
	};
	int main(){
        	A obj1; obj1.disp();    //1
        	A obj2; obj2.disp();    //1
	}
	
	////////USER DEFINED DEFAULT CTR/////////////
        class A{
                int a;
        public:
                A(){}
        };
        main(){
                A obj1();
                A obj2();      //Two objects are created
        }
	

*******1B. MAKE COPY CTR PVT:**********
CCtr is used to copy an exiting object to create new object.

        ///////////COMPLIER PROVIDED COPY CTR///////////
	class A{
        	int a=1;
	public:
        	void disp(){ cout<<a<<"\n"; }
	};
	int main(){
        	A obj1; obj1.disp();    //1
        	A obj2(obj1);  obj2.disp();    //1
	}
	
	//////////USER CREATED COPY CTR///////////////
        class A{    
            int a;
        public:
	    A(int b):a(b){}
	    A(const A &k)
                this->a = k.a;
            }
        };
        int main(){
            A obj1(1)
            A obj2(obj1);                  //Two objects created. obj2 is copy of obj1
        }       
        
*********1C. MAKING ASSIGNMENT OPERATOR PVT************
Assignment Operator is used if object is already existent, new object is given new value from other object.

        ///////////COMPLIER PROVIDED ASSIGNMENT OPERATOR///////////
	class A{
        	int a=1;
	public:
        	void disp(){ cout<<a<<"\n"; }
	};
	int main(){
        	A obj1; obj1.disp();    //1
        	A obj2 = obj1;  obj2.disp();    //1
	}
	
	///////////USER CREATED ASSIGNMENT OPERATOR///////////
	class A{
        	int a=1;
	public:
        	void operator = (A &k){
                	this->a = k.a;
        	}
        	void disp(){ cout<<a<<"\n"; }
	};
	int main(){
        	A obj1; obj1.disp();    	//1
        	A obj2 = obj1;  obj2.disp();    //1
	}
**********************************************

2. Use static variable to save Object address, since only 1 static variable exists/class.

3. Use Static Method to create Objects, static variables can be manipulated inside static methods.

4. Call static method from main(), to create Object.

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

class A{
        A(){}					//1A
        A(A &){}				//1B
        void operator = (const A&){}		//1C
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
0x1ec5e70
*/
