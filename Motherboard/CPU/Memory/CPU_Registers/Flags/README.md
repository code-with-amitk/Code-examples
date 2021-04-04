## RFLAGS Register (64 Bits)
- **What?** There are 64 bits in this register each bit representing:
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
