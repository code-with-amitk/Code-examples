## FEATURES OF JAVA
- Platform Independent: Unlike many other programming languages including C and C++, when Java is compiled, it is not compiled into platform specific machine, rather into platform independent byte code. This byte code is distributed over the web and interpreted by virtual Machine (JVM) on whichever platform it is being run. ie byte-code can be generated on MAC & run on linux/Windows.
- Secured: a. Java always runs on JRE which has almost 0 interaction with OS hence secure.    b. No pointers(hence no SEG faults)    c. Runtime exception handling.        //Secure wrt C,C++
- Robust: Code is made robust as Java introduces, Memory management & mishandled exceptions.
- Architecture Neutral: Compiler generates bytecode which has nothing to do with computer architecture.
- Portable: bytecode can be carried to any platform, no implementation depend features.
- Multi-threaded
- Distributed: We can create distributed application in Java using RMI, EJB.
- Automatic Garbage Collection: Looking at heap memory, finding what objects are in use & what not. Deleting the un-used Objects.
- Speed: Memory is allocated on Eden space and its not guaranteed that it will be allocated contiguously. Non-contiguous memory is slower wrt to contiguous.        //Java is slow wrt C,C++
