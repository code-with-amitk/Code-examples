- **Throw Exception class**
  - [1. Empty exception class](#e3)
  - [2. Exception class having what()](#e4)
  - [3. Null Exception class](#e5)


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
