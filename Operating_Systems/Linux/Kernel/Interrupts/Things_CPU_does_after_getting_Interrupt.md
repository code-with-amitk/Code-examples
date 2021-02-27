## Things CPU does after getting interrupt
- CPU might be doing some task,
  - *a.* it saves present going task(eg: Save Registers, CS,IP)
  - *b.* Create stack for interrupt routine(may involve setting, MMU, Page Table, TLB)
  - *c.* ACK interrupt controller
  - *d.* Jumps to ISR(Interrupt service routine). ISR is function/process that processes the interrupt.
