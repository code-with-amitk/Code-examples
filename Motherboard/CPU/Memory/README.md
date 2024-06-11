- [Virtual, Physical Memory](#vpmemory)
- [Memory Types](#mt)
  - **[1. CPU Registers](#m1)**
    - [1a. General Purpose Registers](#gp)
    - [1a. Segment Registers](#sr)
    - [1c. Special Purpose: IP, PSW](#sp)
    - [1d. XMM Registers](#xmm)
    - [1e. RFLAGS Register](#rf)
  - **[2. CPU Cache](#cc)**
  - **[3. ROM](ROM)**

<a name=vpmemory></a>
# [Virtual, Physical Memory HTML](https://code-with-amitk.github.io/Motherboard/Memory/virtual_and_physical.html)

<a name=mt></a>
# Memory Types
Program only runs when its in RAM.
```c
CPU-Registers  L1-Cache/   L2-Cache/   L3-Cache/    Physical_Memory/  Hard_Disk/Secondary_Memory  Tertiary_Memory/
                SRAM         SRAM        DRAM        RAM/Main Memory    SSD                        remote_storge
    <------------------[Speed, Cost increases]   [Size Decreases]-----------------------------
```
<img src=Memory_types.jpg width=600/>

<a name=m1></a>
## 1. CPU Registers
Register store values on CPU. Hardware registers are outside CPU.

<img src="x86-32_64 Registers.jpg" width=600 />

<a name=gp></a>
### 1a. General Purpose Registers
Used for logical, arithmetic, address calculations, Temporary storage.
- **Types:** RAX, RBX, RCX, RDX, RDI, RSI, RSP, RBP, R8 through R15. 

**RAX(64 bit)accumulator** can be read as EAX(32 bit), AX(16 bit), AH(8 bit), AL(8 bit). Each register is divided into 16bit, 8bits parts.
  - **Usages:**
    - *a.* Stores intermidiate sum,subtract,divide within the function
    - *b.* {Return value} rax stored return value of function. Larger return types like structs are returned using the stack.
    - *c.* {Division Operation} rax = quotient, rdx = reminder
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

<a name=sr></a>
### 1b. Segment Registers(16 bit)
- Holds segment addresses. Segment register initialization and management is normally handled by the operating system.
- **Types**
  - *CS/CODE SEGMENT:* Contains address of the code segment of the currently executing instruction
  - *DS/DATA SEGMENT:*  Contains address of that data segment which belongs to Current Program.
  - *STACK SEGMENT/SS:* stores memory address inside stack that CPU is using at this point of time.
  - *ES/EXTRA SEGMENT:* a spare segment that may be used for specifying a location in memory
  - *FS, GS:*    They are both additional segments with no specific job or specialty

<a name=sp></a>
### 1c. Special Purpose
#### IP(Instruction Pointer) / PC(Program Counter)    RIP/EIP
Holds offset address of the next machine instruction to be executed in the current code segment. IP can neither read from nor written directly by user.

#### Program Status Word / PSW (16 bit)
Tells about status of Processor. 
- **Usage?** Contains bits which stores status or result of operations.
  - *Example:* Bits of PSW tells sign of previous operation. Eg: previous operation produced -ve,+ve or 0 result.
- **Bits** 7(unused), 9(used): 3(control flags), 6(status flags)
  - *Control Flags:* Set/Reset by programmer
```c
  a. DF(Direction Flag): Controls direction of operation of string operation. (DF=0 Ascending order DF=1 Descending order)
  b. IF(Interrupt Flag): controls the interrupt operation in 8086µP. (IF=0 Disable interrupt IF=1 Enable interrupt) 
  c. TF(Trap Flag): Controls the operation of the microprocessor. (TF=0 Normal operation TF=1 Single Step operation)  
```
  - *Status flags:* Set/reset depending on the results of some arithmetic or logical operations.
```c
  d. CF (Carry Flag): is set (CF=1) if there is a carry out of the MSB position resulting from an addition operation or subtraction.
  e. AF (Auxiliary Carry Flag) AF is set if there is a carry out of bit 3 resulting from an addition operation.
  f. SF (Sign Flag) set to 1 when result is negative. When result is positive it is set to 0.
  g. ZF (Zero Flag) is set (ZF=1) when result of an arithmetic or logical operation is zero. For non-zero result this flag is reset (ZF=0).
  h. PF (Parity Flag) this flag is set to 1 when there is even number of one bits in result, and to 0 when there is odd number of one bits.
  i. OF (Overflow Flag) set to 1 when there is a signed overflow. For example, when you multiply FFH by 11H (result is not one byte)
```

<a name=xmm></a>
### 1d. XMM Registers
These support: 
  - 64-bit and 32-bit floating-point operations and 
  - Single Instruction Multiple Data (SIMD) instructions.
    - The SIMD instructions allow a single instruction to be applied simultaneously to multiple data items. This results in significant performance increase.

<a name=rf></a>
### 1e. RFLAGS Register (64 Bits)
There are 64 bits in this register each bit representing:
  - status of results of logical and arithmetic operations.
  - System control bits(used by OS)
```c
Bit     Name            Symbol      Use
0     Carry Flag          CF      Status
1     Reserved                      1
2     Parity Flag         PF      Status
3     Reserved                      0
4  Auxiliary Carry Flag   AF      Status
5     Reserved                      0
6     Zero Flag           ZF      Status
7   Sign Flag             SF      Status
8   Trap Flag             TF      System
9   Interrupt Enable Flag IF      System
10  Direction Flag        DF      Control
11  Overflow Flag         OF      Status
12  I/O Privilege Level Bit 0   IOPL System
13 I/O Privilege Level Bit 1    IOPL System
14 Nested Task           NT       System
15    Reserved                      0
16    Resume Flag        RF       System
17  Virtual 8086 Mode    VM       System
18  Alignment Check      AC       System
19  Virtual Interrupt Flag VIF    System
20  Virtual Interrupt Pending VIP System
21  ID Flag             ID        System
22 - 31 Reserved 0
```

<a name=cc></a>
## 2. CPU Cache
Most frequently used data(from RAM) is kept by CPU into cache.
- **Types of CPU Cache**
```
Type    |   Where                  |               What                |   Size    |   Access Delay
--------|--------------------------|-----------------------------------|-----------|------------------
  L1    | Always inside CPU        | Holds decoded instructions of CPU | 16KB Each | None
  L2    | Have x MB of memory data |                                   |           |1-2 clock cycles
```
### Cache Lines/Cache Block
CPU Cache content which is copied from RAM to cache. Data is transferred from RAM to CPU cache and is stored as cache line.
```c
Cache line 0 = 0 to 64 bytes
Cache line 1 = 65 to 127 bytes
so on
4095
```
- **Cache Hit?** When the CPU want to RW data from RAM, it first checks for a data in cache. if data is found its cache hit else its cache miss
- **Cache Miss?** CPU goes to RAM to read the data. After data is read from RAM, entry is Cache is updated.
- **Number of Cache lines?** Typically 4096 with each holding 64 bytes of data.

- *5.* [Physical Memory / RAM / Main Memory:](RAM) Volatile(looses content at power off)
- *6.* Virtual Memory / Hard Disk / Secondary Memory: Non volatile
