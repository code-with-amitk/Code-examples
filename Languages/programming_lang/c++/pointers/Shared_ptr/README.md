### shared_ptr
#### What
- Container of raw pointer with following characteristics:
  - Maintains reference count ownership of its contained pointer. 
  - Once count reaches 0, allocated memory is deleted.
- **Equivalent** We can think `shared_ptr<int> p   =   int* p`

#### Copy Initialization not supported
- **Copy Initialization?** 
  - When we initialise with `=`, we invoke copy-initialisation.
  - C++ does not allow copy-initialisation of a shared_ptr from a raw pointer.
```c++
int main() {
  shared_ptr <int> a = new int;                 //Copy Initialization
}  
# g++ test.cpp
  conversion from 'int*' to non-scalar type 'std::shared_ptr' requested
```
- **Why CI not allowed?**
  - *1.* Because shared_ptr constructor is explicit and a explicit construtor is not copy-assignable.
```c++
//shared_ptr <int> a = new int; is equivalent to:
int* b = new int;
shared_ptr<int> a = b;

//.....
shared_ptr<int> a = b;
//.....
shared_ptr<int> a1 = b;     //second ptr holding b... fails concept of shared_ptr
```
- **Solution**
```c++
shared_ptr<int> a = make_shared<int>();
```
