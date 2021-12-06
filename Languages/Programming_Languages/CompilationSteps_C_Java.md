### Compilation Steps
- A executable is created after being checked/converted at various stages.
- **C/C++**
```c
source-code(*.cpp) --|   
                    \/
             |Pre-processor| Intermediate file(a.i) 
                                                |
                                               \/ 
                                          |Compiler| -> Assembly code(a.s) 
                                                                      |
                                                                     \/
                                                                 |Assembler| -> Binary(a.o) 01010
                                                                                   |
                                                                                  \/
                                                                                |Linker (ld)| -a.out-> |Loader| -> |RAM|
```
**Java**
```c
source-code                              bytecode         ---------------- JVM(resides on RAM)--------------------            
 a.java    -->    | Compiler(javac) |    -a.class ->     | class-loader   bytecode-verifier    Execution-Engine  | 
                                                         ---------------------------------------------------------
```
