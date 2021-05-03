## Atomic Operation(Uninterrupted Operation)
  - Operation which guarantees is completed without intervention of CPU. ie result at end of AO is predictable and correct.
  - Example: Let's function is incrementing a global/static variable.
    - Thread-1 is executing the fun() fetched count value(say 2). At this point of execution, thread-1 is preempted and another thread-2 gets into same function.
    - Thread-2 does count=3.
    - Thread-1 comes back and has previous value (2), instead of writing(4), it ends up in writing (3). But value of count should be 4 due to affect of both the threads.
    - Such kind of bugs are quite difficult to recreate and locate.
  - Achieving Atomic Operation:    
    - a. Taking a volatile variable     
    - b. Using synchronization methods.
```c
count = 2;
fun(){
  count++;    
}//This statement can be decomposed into, atleast three operations:    
    a. Fetching count value    
    b. Incrementing count value    
    c. Storing the updated value
```    
