- **Operand and Mnemonic**
 ```c
  mnemonic(Instruction-name)/opcode        operand(parameters)        ;Comment        
           mov                             rax, 1
```
- **Home Area / Home Space?** 
  - This is uninitialized space between allocation of arguments on stack and rbp. 
  - *Usage?* 
    - *a.* Storage of 7th,8th,9th ... function arguments since [RDI/EDI, RSI, RDX, RCX, R8, R9](/Motherboard/CPU/Memory/CPU_Registers/General_Purpose_Registers) only stores 1st 6 arguments.
    - *b.* Storage of transient values.
     - Eg: Temporary storage of return value of function, before stack unwinding ret value is copied to rax.
