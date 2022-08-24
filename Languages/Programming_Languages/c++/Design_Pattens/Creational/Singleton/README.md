**Singleton/Single Object**
- [How to achieve Singleton](#how)
- [Can't task of Singleton is done by Global variable?](#c)
- **Code**
  - [1. Lazy Initialization](#laz)
  - [2. Eagerly Initialization](#eag)
- **[Multithreaded](#mul)**
- [Singleton vs Static](#vs)

## Singleton DP / Single Object
Only 1 object of class can be created. And provides Global point of access to it.

<a name=how></a>
### How Singleton is Achieved?
- *1.* Block all Object creation methods. Make these private:
  - default ctr
  - copy ctr
  - Assignment operator
- *2.* Static variable to save Object address, since only 1 static variable exists/class.
- *3.* Static Method to create Objects, static variables can be manipulated inside static methods.
- *4.* Call static method from main(), to create Object.

<a name=c></a>
#### Can't task of Singleton is done by Global variable?
- Ans- No, Global needs to be created at start of program & exist till end, But singleton creates object when its required.
- [Code](Code)
- [if 2 threads run this code it will creates two objects for singleton.How to solve?](MultiThreaded_Singleton)

## Code
<a name=laz></a>
### Lazy Initialization
Object creation is delayed until user requests it.
#### C++98
```cpp
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
A *A::ptr = nullptr;
int main(){
//      A obj1;         //Error:error: ‘A::A()’ is private within this context
        A *p1 = A::fun();			//4
        cout<<p1<<endl;

        A *p2 = A::fun();
        cout<<p2<<endl;
}
# ./a.out
0x1ec5e70
```
#### C++11
```cpp
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

<a name=eag></a>
### Eagerly Initialization
Object is created beforehand.
```cpp
public class Singleton {
	private static Singleton uniqueInstance = new Singleton();
	private Singleton() {}
	public static Singleton getInstance() {
		return uniqueInstance;
	}
}
```

<a name=mul></a>
## Multithreaded
- **Problem?** [Lazy Initialization](#laz) is not thread-safe. if 2 threads run this code it will creates two objects for singleton.
  - *Solution*
    - *1.* Making fun() as synchronized (In Java)
```java
  public static synchronized test fun(){        //Adding synchronized makes every thread to wait for its turn.    
  }
```
  - *2.* Using Mutexes (In Linux)
    
- **Drawbacks of Synchronization:** This is heavy/time consuming operation.
  - *1. Do eagerly instance creation (instead of lazily)*
```java
            public class test{
                    static test obj = new test(); //Since all threads have same DS. so there will be only 1 copy of obj.
                    test(){}
                    public:
                        static test fun(){  return obj;  }
            }
```
  - *2. Check the variable before locking mutex//Double-Checking Locking*
```java
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
```

<a name=vs></a>
### Singleton vs Static class

||Static class|Singleton class|
|---|---|---|
|Level|It cannot be top-level class|it can be top level class|
|Interface|it cannot implement interface||
|Members|All Members of static class need to be static|Not mandate for singleton|
|Object|Stored on Stack|Stored on Heap|
