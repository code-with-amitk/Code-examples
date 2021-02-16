## A. GCC/G+++ Flags

### A1. Mostly Used options
| Option | Meaning |
| --- | --- |
| -c | Compile and Stop after assembly stage, **but do not link** (gcc -c test.c) |
| -D name | Predefine name as a macro, with definition 1 |
| -D name=definition | define name as definition |
| -E | Stop after the preprocessing stage; do not run the compiler proper.|
| -g | Produce debugging information in the operating system's native format |
| -L<dir> | Add directory dir to the list of directories to be searched for -l |
| -lLibrary | <ul><li>Search the library named library when linking</li></ul> <ul><li>Option is provided in LDLIBS += lpthread</li></ul> ||
| -o file | Place output in file file |
| -O Optimization Options | <ul><li>-O0: optimization level 0 (no optimization, same as omitting the -O argument)</li></ul> <ul<li>-O1: Optimize More. Compilation time increases.</li></ul> |
| -W Warning Options | <ul><li>-Wall: enables all the warnings about constructions</li></ul> <ul><li>-Wno-array-bounds: Warn about subscripts/indexes of arrays that are out of bounds(enabled by -Wall)</li></ul> <ul><li>-Wunused-but-set-variable: Warn when local variable is assigned but not used. (enabled by -Wall)</li></ul>|
| -S | Stop after compilation stage, do not assemble |

- What is Optimization?
  - Optimization Option. When we compile the program Compiler inherently optimizes the code at compilation phase(called "Code Optimization"). With these flags we can ask compiler to further optimize in addition to optimization provided by complier inherently.

### A2. Headers Related options
| Option | Meaning |
| --- | --- |
| -std=standard | gnu90=c++98 |
| --sysroot=dir | Use dir as the logical root directory for headers and libraries |
| -isystem dir | Add the directory dir to the list of directories to be searched for header files during preprocessing |

### A3. Other options
| Option | Meaning |
| --- | --- |
| -pie | Produce a dynamically linked position independent executable on targets that support it |
| -pipe | Use pipes rather than temporary files for communication between the various stages of compilation. |
| -pthread | Define additional macros required for using the POSIX threads library |
| -M | output a rule suitable for making the dependencies of the main source file |
| -MD | equivalent to -M. Instead of outputting the result of preprocessing, output a rule suitable for make describing the dependencies of the main source file |
| -march=cpu-type | Generate code that runs on cpu-type.  cpu-type are z900/arch5, z990/arch6, z9-109, z9-ec/arch7, z10/arch8, z196/arch9, zEC12, z13/arch11 |
| -msse | Use SSE register passing conventions for float and double arguments and return values |
| -mtune=cpu-type | Tune to this type of CPU. The list of cpu-type values is the same as for -march. |

### A4. `-f<ption>` options
| Option | Meaning |
| --- | --- |
| -fasynchronous-unwind-tables | Generate unwind table in DWARF format |
| -fexceptions | Enable exception handling, generate exta code for exception handling |
| -fno-working-directory | opposite of working-directory |
| -fomit-frame-pointer | Remove frame pointer from registers when not required |
| -fPIC | <ul><li>If supported, emit Position Independent Code, required for building shared object.</li></ul> <ul><li>This is not required while building static library.</li></ul>|
| -fstrict-aliasing | <ul><li>Compiler to use strictest aliasing rules when compiling code.</li></ul> <ul><li>Check **C++** OR **man g++** for aliasing</li></ul> |
| -funwind-tables | <ul><li>Similar to -fexceptions, but  generates any needed static data</li></ul> <ul><li>Normally not required to enable this option</li></ul> |
| -fworking-directory | <ul><li>Generate line markers in prepprocessor output, then compiler will know current working directory at the time of preprocessing.</li></ul> <ul><li>This option is implicitly enabled if debugging information is enabled</li></ul> |
| -fwrapv | Tell the compiler to wrap overflow of addition, subtraction, multiplication around twos-complement representation |

## [LD]LINKER OPTIONS

| Options | Meaning |


