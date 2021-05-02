## Compilation Steps

<img src="Compilation-Steps.jpg" width=1000 />

```c
# cat test.c
#include<stdio.h>
int main(){
  printf("Hello");
}
```
### 1. `CPP` PRE-PROCESSOR `(*.c → *.i)`
  - Converts source-code `*.c` to Intermidiate files `*.i`.
  - **Functions:** Remove comments from code. Expands include statements, macros. Expands anything else with `#`
  - **-E Flag** Stop after the preprocessing stage; do not run the compiler proper.
```c  
  # gcc -E test.c > m
  # cat m
typedef unsigned char __u_char;
...
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
...
int main(){
 printf("Hello");
}
```    
  
### 2. [`CCL` Compiler `(*.i → *.o)`](compiler.md)
  - Generates Object files. Only when told compiler generates asm files. Converts Intermediate files to object files.
  - Compiler is only bothered about ***function declaration***, it does not check definition.
  - Linking definition to function is task of ***Linker***. Linker gives `undefined reference` error if it cannot find definition inside `*.obj` OR  `*.so`  OR  `*.a`
  - **Functions** Lexical Analysis, parsing, Semantic Analysis, Verify code syntax
  - **-S Flag** Stop after the stage of compilation proper; do not assemble
```c
  # gcc -S test.c
  
  # cat test.s
  .file "test.c"
  .text
  .section  .rodata
.LC0:
  .string "Hello"
  .text
  .globl  main
  .type main, @function  
```      
   
### 3. `[AS]` Assembler `(*.s → *.o)`
  - Takes `*.s` as input and outputs [Object files](Object_File) `*.o`.
  - **-c Flag** Stop after assembly stage not to run into linker.
```c
  # gcc -c test.c
  # cat test.o
 ^?ELF^B^A^A^@^@^@^@^@^@^@^@^@^A^@>^@^A^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^P^C^@^@^@^@^@^@^@^@^@^@@^@^@^@^@^@@^@^N^@^M^@ó^O^^
 úUH<89>åH<8d>=^@^@^@^@¸^@^@^@^@è^@^@^@^@¸^@^@^@^@]ÃHello^@^@GCC: (Ubuntu 9.3.0-10ubuntu2) ....
```
   
### 4. `[LD]` Linker `(*.o → *[.exe])`
  - lets you are working on project having 10 modules, each having seperate `*.c` file. All c files create object files and at end you want 1 EXE file. Linker does it. Also Links code from library
  - **Steps for building executable**
    - ***Symbol resolution*** Obj files define and reference symbols. The purpose of symbol resolution is to associate each symbol reference with exactly one symbol definition.
    - ***Relocation*** Compilers and assemblers generate code and data sections that start at addr 0. The linker relocates these sections by associating a mem location with each symbol definition, and then modifying all of the references to those symbols so that they point to this mem location.
```c
# $ld -o hello-world [sys obj files and args] /tmp/test1.o /tmp/test2.o
```
