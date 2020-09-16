## NULLException class
- **How it works**
  - *1.* Create a class called NULLException. This class will:
    - Log message to Log server
    - Print custom information with Exception message
  - *2.*  Throw the custom class.
  - *3.* Catch the custom class.
```c++
class NULLException { ... }
main ()
  try {
    throw NULLException;
  } catch (NULLException obj) {
    cout << obj.what ();
  } catch (...) {               //This will not be executed
  }
```
  
### Code  
```c++
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
  base() :  m_msg(nullptr) {}
  base (const char* m) : m_msg(nullptr) {
    copyMsg (m);
    cout << "Logged message on Log server\n";                 //1
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
