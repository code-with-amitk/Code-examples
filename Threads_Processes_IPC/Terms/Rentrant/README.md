### Reentrant
- **What?** Making second call same function while a previous call has not yet finished.
- *Example:*
  - Suppose 2 threads can excute same function `fun()`.
  - Thread-1 executing is on line-11(writing to some big memory area `*ptr=bb`) of `fun()` & CPU decides to context switch. State of memory `*ptr` will be inconsistent and control is given to thread-2.
  - Thread-2 starts executing and writes to `*ptr=bbaaaa` and again context switch is done to thread-1.
  - Thread-1 comes back, expects `*ptr=bb` and starts writing `*ptr=bbbbb` and done.
  - Thread-2 reads `*ptr` thinking output as `bbaaaa` But `*ptr` is in inconsistent state.
- **Solution:** mutex(But it eliminates parallelism)
```c
  fun(){            
      ...
11:    writing_to_big_memory (*ptr)
      ...
  }
  
int main(){  
  thread t1(fun);
  thread t2(fun);
  t1.join();
  t2.join();
}  
```
