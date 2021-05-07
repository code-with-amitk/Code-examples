## Scripting vs Complied Language
### 1. Scripting/Interpreter Language
- **What?** Takes 1 line at a time & executes that line.  Interpreter will terminate the program as soon it finds any error on any particular line.
- **Examples?** python, perl, tcl shell script, lua, javascript, vbscript
```c
  source-code        -------------
    *.py      -->   | Interpreter |    ->  O/P or exception
                    --------------
```

### 2. Compiled Language
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
