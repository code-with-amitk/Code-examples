## Things CPU does after getting interrupt
- CPU might be doing some task,
  - *a.* CPU saves Registers, [CS, IP(Program Counter)](/Motherboard/CPU/Memory/CPU_Registers) on stack.
  - *b.* Create [Stack](https://sites.google.com/site/amitinterviewpreparation/c-1) for interrupt routine.
  - *c.* Swaps new page in RAM ie changes [MMU, Page Table, TLB](https://sites.google.com/site/amitinterviewpreparation/c-1/memory-management/virtual-memory)
  - *d.* ACK interrupt controller
  - *e.* Jumps to [ISR(Interrupt service routine)](ISR) after looking from [IVT(Interrupt Vector Table)](IVT).
