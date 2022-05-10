**Exception**
- [try, throw, catch](#t)
- **Examples**
  - [1. Divide by 0](#ex1)
  - [2. bad_alloc, vector index out_of_range Exception](#ex1)
  - [3. Exception in constructor](#e3)
  - **Throw Exception class**
    - [1. Empty exception class](#e3)
    - [2. Exception class having what()](#e4)
    - [3. Null Exception class](#e5)


## Exception
- Exception is Problem/error that arises when program is Running. Eg: Divide by Zero.
- Normally what will happen in this case is Segmentation Fault and abort. But we can place the same code inside try, catch and do something so that program does no coredumps.

<a name=t></a>
### try, throw, catch
- In case of problem instead of simply dying(coredumping), transfer control from one part of a program to another. This is build on 3 keywords:
  - *1. try block*: Block of code which throws exception. This is followed by one or more catch blocks
  - *2. throw keyword:* Instead of dying throw the exception
  - *3. catch:* This catches the thrown exception. This is piece of code that executes on thrown Exception.
- Code placed inside try/catch block is called protected code. We can have multiple catch block after try. Because Code can generate different kind of Exceptions in different conditions.
```cpp
try {
   // protected code
} catch( ExceptionName e1 ) {
   // catch block
} catch( ExceptionName e2 ) {
   // catch block
} catch( ExceptionName eN ) {
   // catch block
}
```

## Examples
<a name=ex1></a>
#### 1. Catching divide by 0
```cpp
////Coredump generated without try, catch/////
int main(){
  int c = 0;
  cout << 4/c;                        //Coredumps here
}

////Catching error(with try catch)/////
int main(){
  int c = 0;
  try {
    if(c == 0)
      throw 0;
    cout << 4/c;
  } catch (int x) {
    cout << "Exception: " << x;
  } catch (...) {
    cout << "All other exceptions";
  }
}
# ./a.out                       //No coredump happenened
Exception: 0
```

<a name=ex2></a>
#### 2. Catching bad_alloc, out_of_range Exception
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
#### 3. Exception in constructor
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

### Throw Exception class
Exception class is used to create our own exception types. **Why own exception types are needed?**
- *1.* We want to display custom message to user at time of exception.
- *2.* Perform some logging on Log server. Block security sensitive information from being dumped. An exception might contain sensitive information, we donot want to show this to user.

<a name=e3></a>
#### 1. Empty Exception class
- _a._ In try block we throw OBJECT of class type
- _b._ catch, catches the object and displays it
```cpp
class demo {};
int main() {
	try {
		throw demo();                   //a
	}
	catch (demo d) {                  //b
		cout << "Caught exception of demo class \n";
	}
}
```

<a name=e4></a>
#### 2. Exception class having what()
- Code throws Exception class(BadLength) when len<5.
```cpp
class BadLength {
    int a;
public:
    BadLength(int x):a(x){}
    int what(){
        return a;
    }
};
int main() {
    int len;
    cin >> len;
    try {
        if (len < 5)
            throw BadLength(len);             //1. Call constructor of class
        else
            cout << "Len is Fine"<<endl;
    } catch (BadLength b) {
        cout << "Too Short:" << b.what();
    }
}
```

<a name=e5></a>
#### 3. NULLException class
- *1.* Create a class called NULLException. This class will: Log message to Log server, print custom information with Exception message
- *2.*  Throw the custom class.
- *3.* Catch the custom class.
```cpp
////////////Example//////////////////
class NULLException { ... }
main ()
  try {
    throw NULLException;
  } catch (NULLException obj) {
    cout << obj.what ();
  } catch (...) {               //This will not be executed
  }

/////////////////Code////////////////
#include<iostream>
#include<cstring>
using namespace std;

class base {
protected:
  char* m_msg = nullptr;
private:
  void copyMsg (const char *test) { //Deep copy
    char *customMessage = "Amit ";                      //Added Custom Message
    if ( test != nullptr ) {
      delete [] m_msg;
      m_msg = nullptr;
    }
    size_t size = strlen (test);
    m_msg = new char [size+6];
    memset (m_msg, '\0', size);

    memcpy (m_msg, customMessage, 5);
    memcpy ((char*)m_msg+5, test, size);                      //3
  }

public:
  base (const char* m) : m_msg(nullptr) { //Default ctr doing deep copy
    copyMsg (m);
    cout << "Logged message on Log server\n";
  }
  base (const exception& obj) {         //copy ctr doing deep copy
    copyMsg (obj.what());
  }
  base& operator = (const base& obj) {    //Assigment operator deep copy
    if (this != &obj)
      copyMsg(obj.what());
  }
  virtual ~base() {                     //Destructor
    if ( nullptr != m_msg) {
      delete [] m_msg;
      m_msg = nullptr;
    }
  }
  virtual const char* what() const {
    return m_msg;
  }
};

class NULLException : public base {
public:
  explicit NULLException (const char *msg) : base (msg) {}
};

int main() {
  try {
    char *ptr = nullptr;

    if (ptr == nullptr)
      throw NULLException ("NULL Exception");

  } catch (const NULLException &obj ) {
    printf ("%s\n",__FILE__);                       //2
    cout << obj.what() <<"\n" ;                     //3
  } catch (...) {
    cout << "Catch ellipse block";                  //Will not executed
  }
}
/*Output
Logged message on Log server                  //1
filename.cpp                                  //2 
Amit Null Exception                           //3
```
