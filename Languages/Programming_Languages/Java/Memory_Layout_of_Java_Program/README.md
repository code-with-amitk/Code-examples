## Memory Layout of Java Program
- Since program runs inside JVM, we will also see How JVM looks on memory.
```java
                                 |---   Stack   Area      -----|  |----    PC(program counter Registers ---|
    [ Method Area ] [ Heap area] <--Thread-1----><-Thread-2---->  <Register-Thread-1><Register-Thread-2> [Native-Method-Stack]
                                  Stack-Frames LVA,OS,FD 
```

- _Method Area_ Heap memory created by JVM at startup and all threads share this. JVM stores following information here: FQDN of a type (ex: String), Type's modifiers, Type's direct superclass name, Structured list of the fully qualified names of super interfaces.
- _Heap Area:_ This is created on JVM startup. Only 1 heap exists for each running JVM process. By default, the maximum heap size is set to 64 MB.
  - What is stored on Heap area:    a. Instance of objects allocated using new keyword.     b. Arrays
- Understanding Heap Area
```java
    <---------------------        Young Space            ------------------->    <---------  Old Space   --------->
    | Eden Space | S0(Survivor-0) | S1(Survivor-1) | Keep Area |
    Minor GC                                                                        Major GC 
```                                        
- _Nursery/Young Space/Young Generation_
  - Nursery is divided into - Eden space, 2 survivor spaces.
  - Eden space: Stores newly created objects.
  - Survivor Spaces: When Eden becomes full, Minor garbage collector(Minor GC) is run and objects present from long are moved to Survivor spaces, ensuring 1 survivor space is always empty. Objects that survived many cycles of GC, are moved to old generation memory space.
  - Keep Area: Contains the most recently allocated objects in the nursery and is not garbage collected until the next young generation. 
- Old Space/Old Generation
  - Garbage collection is performed in Old generation memory when it’s full called Major GC and usually takes longer time

- _Stack Area🇦🇬 This is created when Thread is created. Stack memory is allocated per thread. It contains references to heap objects. 
  - Stack-Frame: This is a data structure that contains the thread's data. Only one frame (the frame for executing method) is active at any point in a given thread of control. This frame is called the current frame. Contains:
    - Local Variable Array (LVA), Operand Stack (OS), and Frame Data (FD). 
- PC-Registers: Each thread has a Program Counter (PC) register associated with it. PC register stores the return address or a native pointer. It also contains the address of the JVM instructions currently being executed.
- Native Method Stack/C stack: This stack is for native code written in a language other than Java
