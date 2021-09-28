- **Exception**
  - [What](#w)
  - [Example](#e)
- [try, throw, catch](#t)
- **Exception class**
  - [Null Exception class](#n)


<a name=w></a>
## Exception
- Exception is Problem/error that arises when program is Running. Eg: Divide by Zero.
- Normally what will happen in this case is Segmentation Fault and abort. But we can place the same code inside try, catch and do something so that program does no coredumps.

<a name=e></a>
### Example
```cpp
////Coredump generated without try, catch/////
int main(){
  int c=0;
  cout << 4/c;                        //Coredumps here
}

////Catching error(with try catch)/////
int main(){
  int c = 0;
  try {
    if(c == 0)
      throw 99;
    cout << 4/c;
  } catch (...){
    cout<<"Divide by 0 happened\n";
  }
}
# ./a.out                       //No coredump happenened
Divide by 0 happened
```

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

### Exception class
Exception class is used to create our own exception types. **Why own exception types are needed?**
- *1.* We want to display custom message to user at time of exception.
- *2.* Perform some logging on Log server
- *3.* Block security sensitive information from being dumped. An exception might contain sensitive information, we donot want to show this to user.

<a name=n></a>
#### NULLException class
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
