- **Contents**
  - A. GCC/G++ Compiler options
  - B. LD linker options

## A. [GCC/G++]COMPILER OPTIONS

| Option | Meaning |
| --- | --- |
| -g | Produce debugging information in the operating system's native format |
| -c | Compile and Stop after assembly stage, **but do not link** (gcc -c test.c) |
| -o file | Place output in file file |
| -std=standard | gnu90=c++98 |
| --sysroot=dir | Use dir as the logical root directory for headers and libraries |
| -isystem dir | Add the directory dir to the list of directories to be searched for header files during preprocessing |
| -D name | Predefine name as a macro, with definition 1 |
| -D name=definition | define name as definition |
| -O Optimization Options | <ul><li>-O0: optimization level 0 (no optimization, same as omitting the -O argument)</li></ul> <ul<li>-O1: Optimize More. Compilation time increases.</li></ul> |
| -W Warning Options | <ul><li>-Wall:   enables all the warnings about constructions</li></ul> |
| -E | Stop after the preprocessing stage; do not run the compiler proper.|
| -S | Stop after compilation stage, do not assemble |
| -pie | Produce a dynamically linked position independent executable on targets that support it |
| -Ldir | Add directory dir to the list of directories to be searched for -l |
| -lLibrary | Search the library named library when linking |
| -M | output a rule suitable for making the dependencies of the main source file |
| -MD | equivalent to -M. Instead of outputting the result of preprocessing, output a rule suitable for make describing the dependencies of the main source file |
| -march=cpu-type | Generate code that runs on cpu-type.  cpu-type are z900/arch5, z990/arch6, z9-109, z9-ec/arch7, z10/arch8, z196/arch9, zEC12, z13/arch11 |
| -mtune=cpu-type | Tune to this type of CPU. The list of cpu-type values is the same as for -march. |
| -msse | Use SSE register passing conventions for float and double arguments and return values |
| -fPIC | If supported, emit position independent code, suitable for dynamic linking. Position-independent code requires special support, and therefore works only on        certain machines. |
| -fworking-directory | Generate line markers in prepprocessor output, so that compiler know the current working directory at the time of preprocessing. This option is implicitly enabled if debugging information is enabled |
| -fno-working-directory | opposite of working-directory |
| -fwrapv | Tell the compiler to wrap overflow of addition, subtraction, multiplication around twos-complement representation |
| -pipe | Use pipes rather than temporary files for communication between the various stages of compilation. |


- What is Optimization?
  - Optimization Option. When we compile the program Compiler inherently optimizes the code at compilation phase(called "Code Optimization"). With these flags we can ask compiler to further optimize in addition to optimization provided by complier inherently.

## [LD]LINKER OPTIONS

| Options | Meaning |

