## Destructor
- **WHAT?** 
  - ~classname() that is called when lifetime of an object ends. 
  - Dtr frees resources that object may have acquired during its lifetime.
- **WHEN DTR IS CALLED?**  whenever an object's lifetime ends, which includes
  - program termination with exit()
  - thread exit.
  - end of scope
  - delete called for objects with dynamic storage duration
  - stack unwinding, for objects with automatic storage duration 
- **PARAMETERS?** None
- **RETURN TYPE?** None
- **Can dtr be overloaded?** No bcoz they cannot be called using objects.
- **Conditions under which implicit dctr not provided:**
  1. If explicitly declared destructor present in class.   
  2. [In C++11]Default destructor deleted. ~A() = delete; 
