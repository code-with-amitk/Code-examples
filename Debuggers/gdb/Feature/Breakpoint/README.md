**What is breakpoint?** User-designated location in the program where the user wants to regain control if program execution ever reaches that location.

## How breakpoints are implemented internally?
- gdb implements it in 3 ways.
- **1. Hardware breakpoint**
  - Built in debugging features with some chips.
  - Dedicated register is provided into which the breakpoint address may be stored. 
```c
  if (PC_program_counter == value in a breakpoint registers)
    CPU raises an exception(SIGTRAP) and reports it to GDB.
```

- **2. Using Emulators**
  - Many emulators include circuitry that watches the address lines coming out from the processor, and force it to stop if the address matches a breakpoint’s address.

- **3. Software breakpoint**
```c
fun(){
1  ...
2  ...   //breakpoint
3  ...
}
```
- gdb will replace line=2 deliberately with illegal instruction (Eg: 1/0).
- This illegal instruction will cause [trap()](https://sites.google.com/site/amitinterviewpreparation/c-1/memory-management/virtual-memory)
- Kernel returns [SIGTRAP](https://sites.google.com/site/amitinterviewpreparation/signals) to process and debugger recieves it.
- **How continue is implemented?**
  - When user says to continue, gdb 
    - reinserts original instruction
    - does 1 step
    - reinsert illegal instruction for trap()
    - continue
