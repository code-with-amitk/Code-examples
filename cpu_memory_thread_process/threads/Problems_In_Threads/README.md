## Problems with Threads / Problems in turning Single Threaded Code to Multithreaded
### 1. Global variables are shared
  - ie Conflict of threads over use of Global variables.  [Code](./Code/Global_Variables_are_shared.md)
  - **Solutions:**
    - *a.* Prohibit global variables altogether.
    - *b.* Each thread its own private global variables. This will create new problem of accessing other thread's global variables.
    - *c.* Every thread allocates its own variables on heap & hence getting seperate copy. `struct* var = new new(struct var)`

