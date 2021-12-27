**Pointers**
- **Raw/Normal**
- **Smart**
  - [Code](#smartcode)
  - **Types of Smart Pointers**
    - [Unique ptr vs Shared ptr](#vs)
    - _1. UNIQUE Pointer_
      - [Characteristics](#ch)
      - [Allocating unique pointer using make_unique?](#make)
    - _2. SHARED Pointer shared_ptr_ 
      - [Characteristics](#sch)
      - [Copy Initialization not allowed on shared_ptr](#cint)
      - [Code](#spcode)
    - _3. WEAK POINTER weak_ptr_

## Raw/Normal pointer 
As defined in C. Eg: 
```c
int *p = new int();         //p is raw pointer.
```

<a name=sp></a>
## Smart Pointer
This is a data structure that not only act like a pointer but has additional metadata, which does automatic deletion of allocated memory when no one using it.
- In code, this is User-defined class where Allocation is done in constructor, deletion inside destructor. Bcoz Destructors are automatically executed when Object goes out of scope.
- These are useful when Programmer may allocate memory using new() & later might forget to use delete(). 

<a name=smartcode></a>
**Code:** class maintains a local pointer, memory is allocated and assigned to pointer. Overloaded functions are defined for `*, ->`
```cpp
template <class T>		
class A{                    //This class is Smart pointer
  //int *a;
  T *a;
public:
//A(int *r):a(r){
  A(T *r):a(r){ cout << "Allocated\n"; }
  ~A(){
    delete a;
    cout << "Freed\n";
  }
//int &operator *(){	//& returns a only, does not create new copy
  T &operator *(){
    return *a;
  }
};

int main(){
  //Automatic template type deduction => Provided in C++17
  A <int> obj(new int());	//obj is my pointer now. I can carry all pointer operations
  *obj = 10;
  cout<<*obj<<"\n";

  A <float> obj1(new float());
}

# g++ smart_pointers
Allocated
10
Allocated 

Freed
Freed
```

## Types of Smart Pointers
<a name=vs></a>
### Unique Ptr vs Shared Ptr //Both are [smart pointers](#sp)

|| Unique Pointer | Shared Pointer |
|---|---|---|
|What|Only 1 pointer to an object|Multiple pointers to the same resource|
|Copy Constructible|No, any attempt to make a copy of a unique_ptr will cause a compile-time error|Yes|
|Move Constructible|Yes,can be moved using the new move semantics||

<a name=up></a>
#### Unique ptr
- _1. Not Copy Constructible_ There can be only one unique_ptr to any resource, any attempt to make a copy of a unique_ptr will cause a compile-time error.
```c
unique_ptr<T> ptr(new T);       // Okay
unique_ptr<T> cptr = ptr;       // Error: Can't copy unique_ptr
```
- _2. Are Move Constructible:_ unique_ptr can be moved using the new move semantics
```c
unique_ptr<T> ptr(new T);             // Okay
unique_ptr<T> cptr = std::move(ptr);  // Okay, resource now stored in cptr
```

<a name=shp></a>
#### Shared Pointer
Allows for multiple pointers to point at a given resource.
```c
shared_ptr<T> ptr(new T);       // Okay
shared_ptr<T> cptr = ptr;       // Okay.  Are Copy Constructible
```
- Internally, shared_ptr uses [reference counting](https://en.wikipedia.org/wiki/Reference_counting) to track how many pointers refer to a resource, Once all references goes away resource is deleted. So we need to be careful not to introduce any reference cycles.


### 1. Unique Pointer //In C++11
[What is UP](#vs)
<a name=ch></a>
#### Characteristics of UP
  - copy is not allowed(copy ctr, assignment operator are deleted)
  - std::move(transferring ownership) is allowed. Original pointer cannnot be accessed. ptr.reset(): Deletes the memory
<a name=make></a>
#### `make_unique<T>()`?
  - *a.* Avoid use of new operator
  - *b.* Provides exception safety, as new and delete internally handled by compiler. 
  - Function defined in `<memory>` header for creating a unique pointer. Memory is allocated to 0.
```cpp
#include <memory>
int main(){
        unique_ptr<int> p(new int(5));          //Create UP, Allocate int, provide value=5
        cout<<*p;                               //5

        //unique_ptr<int> p1 = p;               //error: use of deleted function. copy of UP is not allowed

        unique_ptr<int> p2 = std::move(p);      //Moving ownership
        cout<<*p2;                              //5
        //cout<<*p;                             //Segmentation Fault

        p2.reset();

        unique_ptr<int> p1 = make_unique<int>();  //Create UP using make_unique()
        cout<<*p1<<endl;                          //0
}
```

### 2. Shared Pointer
[What is SP](#vs)
```cpp
shared_ptr<int> p   =   int* p          //We can think like this
```
<a name=sch></a>
#### Characteristics of shared pointer
Maintains reference count/ownership of its contained pointer. Once count reaches 0, allocated memory is deleted.

<a name=cint></a>
#### Copy Initialization not allowed on shared_ptr
*Copy Initialization?* When we initialise with `=`, we invoke copy-initialisation.
```c++
int main() {
  shared_ptr<int> a = new int;                 //Copy Initialization
}  
# g++ test.cpp
  conversion from 'int*' to non-scalar type 'std::shared_ptr' requested
```
*Why CI not allowed?* Because shared_ptr constructor is explicit and a explicit construtor is not copy-assignable.
```cpp
//shared_ptr<int> a = new int; is equivalent to:
int* b = new int;
shared_ptr<int> a = b;

//.....
shared_ptr<int> a = b;
//.....
shared_ptr<int> a1 = b;     //second ptr holding b... fails concept of shared_ptr
```
*Solution*
```cpp
shared_ptr<int> a = make_shared<int>();
```

<a name=spcode></a>
#### Code
```cpp
int main(){
  shared_ptr<int> ptr (new int(5));          //Allocated int, made shared_ptr point to it
  shared_ptr <int> ptr1 = ptr;               //ptr,ptr1 now points to same memory

  cout << *ptr;                             //Ouput:5
  cout<<*ptr1;                              //Output:5

  ptr.reset();                               //Deleting ptr
  cout << *ptr1;                             //5 But ptr1 still points to memory

  ptr1.reset();                               //Deleting ptr1
  //cout<<*ptr;                              //Segmentation Fault
}
```
