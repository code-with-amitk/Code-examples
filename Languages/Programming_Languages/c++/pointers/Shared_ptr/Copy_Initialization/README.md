### Copy Initialization not allowed on shared_ptr
- **Copy Initialization?** When we initialise with `=`, we invoke copy-initialisation.
```c++
int main() {
  shared_ptr <int> a = new int;                 //Copy Initialization
}  
# g++ test.cpp
  conversion from 'int*' to non-scalar type 'std::shared_ptr' requested
```
- **Why CI not allowed?** Because shared_ptr constructor is explicit and a explicit construtor is not copy-assignable.
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
