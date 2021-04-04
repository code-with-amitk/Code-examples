## Things CPU does after getting interrupt
- CPU might be doing some task,
  - *a.* CPU saves Registers [CS, IP(Program Counter)](/Motherboard/CPU/Memory/CPU_Registers) on stack of currently executing function.
    - Saved IP points to the first instruction which will be loaded into the processor after the interrupt handler completes.
  - *b.* Saves local variables, intermidiate results(on registers(Accumulator), PSW) on stack.
  - *c.* Create [Stack](https://sites.google.com/site/amitinterviewpreparation/c-1) for interrupt routine.
  - *d.* Swaps new page in RAM ie changes [MMU, Page Table, TLB](https://sites.google.com/site/amitinterviewpreparation/c-1/memory-management/virtual-memory)
  - *e.* ACK interrupt controller
  - *f.* Jumps to [ISR(Interrupt service routine)](ISR) after looking from [IVT(Interrupt Vector Table)](IVT).
