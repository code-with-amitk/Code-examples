## Program Status Word / PSW (16 bit)
- **What?** Tells about status of Processor. 
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
