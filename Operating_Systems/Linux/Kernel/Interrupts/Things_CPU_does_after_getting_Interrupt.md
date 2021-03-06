## Things CPU does after getting interrupt
- CPU might be doing some task,
  - *a.* it saves present going task(eg: Save Registers, [CS, IP](https://sites.google.com/site/amitinterviewpreparation/c-1/assembly-language))
  - *b.* Create [Stack](https://sites.google.com/site/amitinterviewpreparation/c-1) for interrupt routine(may involve setting [MMU, Page Table, TLB](https://sites.google.com/site/amitinterviewpreparation/c-1/memory-management/virtual-memory))
  - *c.* ACK interrupt controller
  - *d.* Jumps to [ISR(Interrupt service routine)](ISR_Interrupt_Service_Routine.md) after looking from [IVT(Interrupt Vector Table)](IVT_Interrupt_Vector_Table.md).
