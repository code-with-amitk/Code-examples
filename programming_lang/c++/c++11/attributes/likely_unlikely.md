## `[[likely]](C++20) [[unlikely]](C++20)` Branch prediction macros
  - Can be applied to labels or statements.
  - **`[[likely]]`**
    - When applied to statement, tells that path of execution to this statement is more likely to be hit and complier should optimize for same.
  - **`[[unlikely]]`**
    - When applied to statement, tells that path of execution to this statement is less likely to be hit and complier should optimize for same.    
    
### C Implementation
  - These are defined as follows in linux kernel code.
```
http://lxr.linux.no/linux+v3.6.5/include/linux/compiler.h
#define likely(x)      __builtin_expect(!!(x), 1) 
#define unlikely(x)    __builtin_expect(!!(x), 0) 
```
  - Example:
    - Here, if condition is marked likely. 
    - Compiler will optimize the program considering if is very likely to be hit.
    - If prediction is correct, it means there is zero cycle of jump instruction
    - but if prediction is wrong, then it will take several cycles, because processor needs to flush it’s pipeline
```
const char *home_dir ; 

home_dir = getenv("HOME"); 
if (likely(home_dir))  
    printf("home directory: %s\n", home_dir); 
else
    perror("getenv"); 
```
