**Pointers**
- [Raw](#raw)
- [Smart](#smart)
  - [Code](#code)
  - **Types of Smart Pointers**
    - _1. UNIQUE Pointer_
      - [Characteristics](#ch)
      - [Why to use make_unique?](#make)
      - [Code](ucode)
    - _2. SHARED Pointer_ 
      - [Characteristics](#sch)
      - [Copy Initialization not allowed on shared_ptr](#cint)
      - [Code](#spcode)

<a name=raw></a>
## Raw/Normal pointer 
- as defined in C. Eg: 
```c
int *p = new int();         //p is raw pointer.
```

<a name=smart></a>
## Smart Pointer
- User-defined class that manages automatic deletion of dynamic memory. Allocation is done in constructor, deletion inside destructor. Bcoz Destructors are automatically executed 
when Object goes out of scope.
- These are useful when Programmer may allocate memory using new() & later might forget to use delete(). 

<a name=code></a>
- **Code**
  - class maintains a local pointer, memory is allocated and assigned to pointer.
  - Overloaded functions are defined for *, ->
```cpp
template <class T>		
class smart_pointer{
//	int *a;
	T *a;
public:
//	smart_pointer(int *r):a(r){
	smart_pointer(T *r):a(r){
		cout<<"Allocated memory\n";
	}
	~smart_pointer(){
		cout<<"\nDestructor called, Allocated memory freed\n";
		delete a;
	}
//	int &operator *(){	//& returns a only, does not create new copy
	T &operator *(){
		return *a;
	}
};

int main(){
	//Automatic template type deduction => Provided in C++17
	smart_pointer <int> obj(new int());	//obj is my pointer now. I can carry all pointer operations
	*obj = 10;
	cout<<*obj<<"\n";

	smart_pointer <float> obj1(new float());
}

# g++ smart_pointers
Allocated memory
10
Allocated memory

Destructor called, Allocated memory freed
Destructor called, Allocated memory freed
```

### 1. Unique Pointer //In C++11
<a name=ch></a>
#### Characteristics of UP
  - copy is not allowed(copy ctr, assignment operator are deleted)
  - std::move(transferring ownership) is allowed. Original pointer cannnot be accessed
  - ptr.reset(): Deletes the memory
<a name=makep></a>
#### Why to use `make_unique<T>()`?
  - *a.* Avoid use of new operator
  - *b.* Provides exception safety, as new and delete internally handled by compiler. 
  - Function defined in `<memory>` header for creating a unique pointer. Memory is allocated to 0.
<a name=ucode></a>
#### Code
```cpp
#include <memory>
int main(){
        /*Creating UP, Allocate *int, provide value=5*/ 
        unique_ptr<int> p(new int(5));
        cout<<*p;                               //5

        /*C1. copy of UP is not allowed*/
        //unique_ptr<int> p1 = p;               //error: use of deleted function

        /*C2. Moving ownership*/
        unique_ptr<int> p2 = std::move(p);
        cout<<*p2;                              //5
        //cout<<*p;                             //Segmentation Fault

        /*C3. reset() function*/
        p2.reset();

        /*B. Creating unique_ptr using make_unique()*/
        unique_ptr<int> p1 = make_unique<int>();
        cout<<*p1<<endl;                       //0
}
```

### 2. Shared Pointer
```c
shared_ptr<int> p   =   int* p          //We can think like this
```
<a name=sch></a>
#### Characteristics of shared pointer
  - Maintains reference count/ownership of its contained pointer. 
  - Once count reaches 0, allocated memory is deleted.

<a name=cint></a>
#### Copy Initialization not allowed on shared_ptr
*Copy Initialization?* 
- When we initialise with `=`, we invoke copy-initialisation.
```c++
int main() {
  shared_ptr <int> a = new int;                 //Copy Initialization
}  
# g++ test.cpp
  conversion from 'int*' to non-scalar type 'std::shared_ptr' requested
```
*Why CI not allowed?* 
- Because shared_ptr constructor is explicit and a explicit construtor is not copy-assignable.
```cpp
//shared_ptr <int> a = new int; is equivalent to:
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
- Pointing shared_ptr to int
  - _1._ ptr is pointer to integer having value=5
  - _2._ ptr,ptr1 now points to same memory.
```cpp
int main(){
  shared_ptr <int> ptr (new int(5));         //1
  shared_ptr <int> ptr1 = ptr;               //2

  cout << *ptr;                             //Ouput:5
  cout<<*ptr1;                              //Output:5

  ptr.reset();                               //Deleting ptr
  cout << *ptr1;                             //5   But ptr1 still points to memory

  ptr1.reset();                               //Deleting ptr1
  //cout<<*ptr;                              //Segmentation Fault
}
```
