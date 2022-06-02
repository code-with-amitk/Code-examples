**Exception**
- [try, throw, catch](#t)
- **Examples**
  - [1. Catching Divide by 0](#e1)
  - [2. bad_alloc, vector index out_of_range Exception](#e2)
  - [3. Catch exception from constructor in main](#e3)
  - [Throw Exception class](Exception_class)


## Exception
- Exception is the problem state into which program enters that's not normal. Now exception floats into callstack until handler is found for it.
- **Examples of exception:**
  - Divide by Zero.
  - Accessing out of bound array index.    //Segmentation Fault and abort.
- But we can place the same code inside try, catch and do something so that program does no coredumps.

<a name=t></a>
### try, throw, catch
- In case of problem instead of simply dying(coredumping), transfer control from one part of a program to another. This is build on 3 keywords:
  - *1. try block*: This need to be protected
  - *2. throw keyword:* Instead of dying, throw exception that should be handled in some other part of code
  - *3. catch:* This catches the thrown exception. This is piece of code that executes on thrown Exception.

<a name=e1></a>
#### Example-1: Catching Divide by 0
**Program generating coredump**
```cpp
int main(){
  int c = 0;
  cout << 4/c;                        //Coredumps here
}
```
**1a. Catching exception with throw**
```cpp
include<iostream>
#include <stdexcept>
using namespace std;
class A {
public:
    float fun(int a) {
        if (a <= 0)
            throw runtime_error("Divide by 0");               //Throw exception so that can be handled in some other code
        return 1/b;
    }
};

int main() {
    try {                             //Protected Code
        A obj;
        obj.fun(0);
    }
    catch (runtime_error& e) {
        cout << "runtime error:" << e.what();
    } catch (...) {
        cout << "Exception";
    }
}
$ a.out
runtime error:Divide by 0
```

<a name=e2></a>
#### Example-2. Catching bad_alloc, out_of_range Exception
```cpp
#include<new>			//bad_alloc
class A {
public:
	static int fun (long long A, long long B) {
		if(A < 0)
			throw std::invalid_argument("A is negative");
		vector<int> v(A, 0);                  //Initialize vector
		if(B == 0) throw 0;
		return A/B + A - B*v.at(B);
	}
};
int main() {
        try {
            cout << Server::compute(A,B) << endl;
        } 
        catch (std::bad_alloc& error) {
            cout << "Bad Alloc" << endl;           		//if A is passed huge ie greater than 50 million.
        }
        catch (exception& error) {
            cout << "Exception: " << error.what() << endl;      //A=2, B=10. Because v[2] and trying access v[10]
        }
        catch (...) {
            cout << "Other Exception" << endl;
	}
}	
```

<a name=e3></a>
#### Example-3. Exception in constructor
```cpp
class base {
  char* ptr;
public:
  base() {
      ptr = nullptr;
      ptr = new char[10];
      if (ptr == nullptr) 
        throw std::bad_alloc();        //Exception thrown from constructor
  }
  ~base(){
    std::cout<<"base dtr\n";
  }
};
int main() {
    try {
        base b;
    }
    catch (std::bad_alloc& b) {
        std::cout << "Bad alloc" << b.what();
    }
    catch(...){
        std::cout << "Exception happened";
    }    
}
```
