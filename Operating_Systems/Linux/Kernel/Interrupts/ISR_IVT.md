## ISR(Interrupt Service Routine) / Interrupt Handler
- ISR is function/process that processes the interrupt. Every device has seperate ISR.
- Registering ISR.
```c
int request_irq(unsigned int irq,		                      //1
	irqreturn_t (*handler)(int, void *, struct pt_regs *),    //2
	unsigned long flags,                                     //3
	const char *dev_name,	                                 //4
	void *dev_id);                                           //5
            
1. irq=3(Interrupt no): Interrupt number to which this handler should be registered.
2. Interrupts Handler: Implemented as Function pointer, when interrupt happens code jumps to that location
3. Flags:
  SA_INTERRUPT: “fast” interrupt handler: Fast Interrupt executed with interrupts disabled on the current processor
  SA_SHIRQ: shared interrupt
  SA_SAMPLE_RANDOM: generated interrupts can contribute to the entropy pool used by /dev/random and /dev/urandom
4. owner of interrupt  
5. For shared Interrupt line. if interrupt is not shared. dev_id=NULL. But it a good idea anyway to use this item
  to point to the device structure
```

## IVT(Interrupt Vector Table)
- Contains ISR(Interrupt service routine)/Handler/Address to which CPU jumps at occurrence of interrupt. present in 1st 1K of physical memory
- All devices are identified at boot time and respective ISRs are filled in IVT.
- Interrupt number is used as index in IVT.  CPU goes to IVT's index, gets Program counter and starts Interrupt service procedure. Once CPU starts ISP, Device Acks Interrupt controller
```c
            | 0x420932 ISR of Int0 |      |     |     |
Interrupt No>       0                 1       2     3

    CPU                    Hardware_Device
       <- Interrupt3=signal-
 Find & runs ISR3 for Intr3
    isr3(){..}
```
