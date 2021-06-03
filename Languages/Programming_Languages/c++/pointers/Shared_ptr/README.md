## Shared_ptr
- **What?** Container of [raw pointer](..) with following characteristics:
  - Maintains reference count/ownership of its contained pointer. 
  - Once count reaches 0, allocated memory is deleted.
```c
shared_ptr<int> p   =   int* p          //We can think like this
```
- **[Examples Using shared pointer](Examples)**
- **[Copy Initialization not allowed on shared_ptr](Copy_Initialization)**
