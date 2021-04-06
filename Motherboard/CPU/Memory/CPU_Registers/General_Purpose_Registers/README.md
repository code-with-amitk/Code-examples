## General Purpose Registers
- **Usage?** Used for logical, arithmetic, address calculations, Temporary storage.

### Types
> RAX, RBX, RCX, RDX, RDI, RSI, RSP, RBP, R8 through R15. 

- **RAX(64 bit)accumulator** can be read as EAX(32 bit), AX(16 bit), AH(8 bit), AL(8 bit). Each register is divided into 16bit, 8bits parts.
  - **Usages:**
    - *a.* Stores intermidiate sum,subtract,divide within the function
    - *b.* Store return values of function. Larger return types like structs are returned using the stack.
- RBX: Memory pointer, base register
- RSP(stack pointer): points to head of stack
- RBP(base pointer): points to base of stack
- AVX(Advanced Vector Extensions): 64 byte Registor present in Intel and AMD.
- **EDI/RDI, RSI, RDX, RCX, R8, R9:** Stores 1st 6 arguments to function. If there are more than 6 parameters, then the program’s stack is used to pass in additional parameters to the function.
  - RDI = 1st argument
  - RSI = 2nd argument. Also used for String instructions
  - RDX = 3rd argument. Also used for Divide & Multiply
  - RCX = 4th argument. Also used for loop counter
  - R8 = 5th argument
  - R9 = 6th argument

#### Volative, Non Volatile Registers
- **Non-Volatile Registers: (rdi,rsi,rdx,rcx)** Means they store function arguments & must be preserved.
- **Volatile Registers: (rax, rdx, rcx)** Means these store intermidiate calculation and must be preserved.
