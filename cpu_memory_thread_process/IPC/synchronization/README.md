## Synchronization Techniques
- **Why?** When multiple threads need to modify a shared resource(eg: global variable) we should lock the resource to guarantee at most 1 thread can do modification, such that a thread-1 cannot interfere with other thread-2 and leads to unexpected behaviors. For Example: Thread-1 is in Critical section and thread-2 wants to enter inside
- **What?**
