## Problems with Threads / Problems in turning Single Threaded Code to Multithreaded
### 1. Global variables are shared
  - ie Conflict of threads over use of Global variables.  [Code](./Code/Global_Variables_are_shared.md)
  - **Solutions:**
    - *a.* Prohibit global variables altogether.
    - *b.* Each thread its own private global variables. This will create new problem of accessing other thread's global variables.
    - *c.* Every thread allocates its own variables on heap & hence getting seperate copy. `struct* var = new new(struct var)`

### 2. Many library functions are not [Rentrant](/cpu_memory_thread_process/threads/Terms)

### 3. Signal Handling by Threads
- *a.* Signals like keyboard interrupt(Cntrl^C), are not thread specific. if 10 threads are there which thread should handle it?
- *b.* Singal handler code is global, Thread-1 changes the signal handler without telling Thread-2. Now thread-2 catches the signal.
- *c.* Thread-1, Thread-2 both want to catch the signal(Cntrl^C) and Thread-1 want to continue while Thread-2 want to terminate the process.

### 4. Stack Management
- **What?** When process stack overflows, kernel provides that process with more stack automatically. When it becomes unmanagable it hangs.
- **Thread Stacks** When process has multiple threads, Each thread will have its own stack.
  - When thread stack overflows, kernel is not aware(since its entity inside process), user space process need to take care of it.
