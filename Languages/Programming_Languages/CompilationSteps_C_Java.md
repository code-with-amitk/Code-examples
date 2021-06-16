### Compiled Language
- **What?** A executable is created after being checked/converted at various stages. [Complilations Steps]()
- **Examples?**
  - C/C++
```c
source-code                     Intermediate-file       assembly-code            001010101
  a.c      -> | Pre-processor |  - a.i ->  | Compiler |  - a.s ->   | Assembler | - a.o ->   | Linker (ld) | -> a.out -> | Loader |  -> |RAM|
```
  - Java
```c
source-code                              bytecode         ---------------- JVM(resides on RAM)--------------------            
 a.java    -->    | Compiler(javac) |    -a.class ->     | class-loader   bytecode-verifier    Execution-Engine  | 
                                                         ---------------------------------------------------------
```
