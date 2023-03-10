**Pointers**
- _1._ Raw/Normal
- [_2._ Smart Pointers](#sp)
  - [2a. Unique ptr](#up)
  - [2b. Shared ptr (Reference Counted. Multiple Owners Allowed)](#shp)
    - [How shared_ptr is implemented internally?](#hsp)
- _3. WEAK POINTER weak_ptr_


## Raw/Normal pointer 
As defined in C.
```c
int *p = new int();         //p is raw pointer.
```

<a name=sp></a>
## Smart Pointer
- Automatically deletes the allocated memory when goes out of scope.
- **How?**
  - Allocate memory in ctr
  - Delete memory in dtr. Bcoz Destructors are automatically executed when Object goes out of scope.
- **Why?**
  - Programmer may allocate memory using new() & later might forget to use delete().
```cpp
template <class T>		
class A{                    //This class is Smart pointer
  T *a;         //int *a;
public:
  A(T *r):a(r){ cout << "Allocated\n"; }              //A(int *r):a(r)
  ~A(){
    delete a;
    cout << "Freed\n";
  }
  T &operator *(){        //int &operator *()    //& returns a only, does not create new copy
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

### Types of Smart Pointers
#### Unique Ptr vs Shared Ptr //Both are [smart pointers](#sp)

|| Unique Pointer | Shared Pointer |
|---|---|---|
|What|Only 1 Owner of memory, ie only 1 pointer to an object|Multiple owners of a resource|
|Copy Constructible|No, any attempt to make a copy of a unique_ptr will cause a compile-time error. copy ctr, assignment operator are deleted|Yes|
|Move Constructible|Yes,can be moved using the new move semantics||

<a name=up></a>
#### 1. Unique ptr
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
- Code
```cpp
#include <memory>
int main(){
        unique_ptr<int> p(new int(5));          //Unique Pointer for int
        cout<<*p;                               //5
        //unique_ptr<int> p1 = p;               //error: use of deleted function. copy of UP is not allowed
        unique_ptr<int> p2 = std::move(p);      //Moving ownership
        cout<<*p2;                              //5
        //cout<<*p;                             //Segmentation Fault
        p2.reset();
/*
make_unique<T>()
 - Avoid use of new operator
 - Provides exception safety, as new and delete internally handled by compiler. 
 - Function defined in `<memory>` header for creating a unique pointer. Memory is allocated to 0.
*/
        unique_ptr<int> p1 = make_unique<int>();  //Create UP using make_unique()
        cout<<*p1<<endl;                          //0
        
//////UP for char array////////
    std::unique_ptr<PWSTR[]>    m_pwstrPath;    //PWSTR: pointer to wide str
    m_pwstrPath = (PWSTR*) new TCHAR[260]();    //Allocate char array of 260 chars and Initialize to ()
}
```

<a name=shp></a>
#### 2. Shared Pointer
- Multiple owners for a resource. ie Multiple pointers can point to same resource.
- Owner count is maintained using **reference counting**. When noone is referencing the memory, it's deleted automatically.
```c
shared_ptr<int> p   =   int* p          //We can think like this

shared_ptr<T> ptr(new T);       // Okay
shared_ptr<T> cptr = ptr;       // Okay.  Are Copy Constructible
```
- *1. Copy Initialization not allowed?* When we initialise with `=`, we invoke copy-initialisation. 
  - *Why CI not allowed?* Because shared_ptr constructor is explicit and a explicit construtor is not copy-assignable 
```c++
int main() {
  int* b = new int;
  shared_ptr<int> a = b;     //Copy Initialization. conversion from 'int*' to non-scalar type 'std::shared_ptr' requested
  ..
  shared_ptr<int> a1 = b;   //second ptr holding b... fails concept of shared_ptr
}
```
- Code
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

<a name=hsp></a>
##### How shared_ptr is implemented internally?
- shared_ptr maintains 2 things.
```c
  int reference_count;
  T* data;                  //and a pointer to the object being shared
```
- Creation of shared_ptr: reference_count=1
- On every new shared_ptr creation: reference_count++
- Deletion/Reset: reference_count--
```c
template<typename T>
class shared_ptr {
    struct ControlBlock {   //stores a pointer to the object being shared (T* ptr_) and a reference count (int ref_count_).
        T* ptr_;
        int ref_count_;
    };    
    ControlBlock* data_;
public:
    shared_ptr(T* ptr) {
        data_ = new ControlBlock;
        data_->ptr_ = ptr;
        data_->ref_count_ = 1;
    }
    
    shared_ptr(const shared_ptr& other) {
        data_ = other.data_;
        data_->ref_count_++;
    }
    
    ~shared_ptr() {
        if (--data_->ref_count_ == 0) {
            delete data_->ptr_;
            delete data_;
        }
    }    
};
```
