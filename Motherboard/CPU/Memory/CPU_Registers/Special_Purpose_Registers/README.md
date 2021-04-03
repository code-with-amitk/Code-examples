## Special Purpose Registers
- Values stored in them have a specific meaning depending on the register.
  - RBP(base pointer) : points to the base of the current stack frame
  - RSP(Stack Pointer): points to the top of the current stack frame. 
> note rbp always has a higher value than %rsp because the stack starts at a high memory address
