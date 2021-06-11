## Semaphore
- **What?** A integer whose [atomicity](/Threads_Processes_IPC) is maintained by kernel.
```c
  if (variable==1)
    //Entrance allowed into Critical section 
  if (variable==0)
    //Entrace blocked. Wait
```
- **How?** 
  - As in mutex only, 1 thread enters Critical section, But Thread-1 will signal Thread-2 once he's done.
  - See [Code: Thread1 Signalling Thread2 to enter Critical Section, when Thread1 is done](Types_of_Semaphores/Binary/Code/Thread1_Signalling_Thread2/C++_code.md)
```c
  Thread-1()      Critical_Section()      Thread-2()
      ---execute---->                     waiting
                   Thread-1 Done
                   
  signal Thread-2 ------------------------->
  waiting
                      <--------execute--------                  
```
- **[Types of Semaphores](Types_of_Semaphores):** Binary, Counting
