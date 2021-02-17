## Copy Constructor
- **What** Same named member function of class for creating a new object as a copy of an existing object. Achieved using const L-value reference.
- **PARAMETERS**
  - 1st parameter is A&, const A&, volatile A&, or const volatile A&
  - Either there are no other parameters, or the rest of the parameters all have default values.

### When compiler does not provide copy ctr?
1. CC declared by user.
2. If class has virtual function. class A{ public: virtual f();}
3. If class has virtual base class class A:virtual B{}
4. Class has member which cannot be copied to other object(ie not copy construable) Eg: reference variable

### WHEN CC IS CALLED?
1. When compiler generates temporary object
2. When object is created using another object of same class.
3. When Object of class is passed to function as value.    
4. When object of class is returned by value.

### VALID DECLARATIONS OF CC 
```c++
    - A(const A &obj)      //Mostly used.
    - A (A &obj)      
    - A (volatile A &obj)
    - A (const volatile A &obj)
    - A (A &obj, int a=0)     //2nd Argument If passed must be default    
    - A(const A &obj, int a=10, float b=10.1)
```    
