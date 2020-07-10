## GCC OPTIONS

| Option | Meaning |
| --- | --- |
| -g | Produce debugging information in the operating system's native format |
| -c | Compile or Assemble the source files, **but do not link** (gcc -c test.c) |
| -o file | Place output in file file |
| -std=standard | gnu90=c++98 |
| --sysroot=dir | Use dir as the logical root directory for headers and libraries |
| -isystem dir | Add the directory dir to the list of directories to be searched for header files during preprocessing |
| -D name | Predefine name as a macro, with definition 1 |
| -D name=definition | define name as definition |
| -O Optimization Options | <ul><li>-O0: optimization level 0 (no optimization, same as omitting the -O argument)</li></ul> <ul<li>-O1: Optimize More. Compilation time increases.</li></ul> |
| -W Warning Options | <ul><li>-Wall:   enables all the warnings about constructions</li></ul> |

- What is Optimization?
  - Optimization Option. When we compile the program Compiler inherently optimizes the code at compilation phase(called "Code Optimization"). With these flags we can ask compiler to further optimize in addition to optimization provided by complier inherently.
