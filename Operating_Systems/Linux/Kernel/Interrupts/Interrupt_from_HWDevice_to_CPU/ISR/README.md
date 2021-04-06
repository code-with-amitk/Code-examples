## ISR(Interrupt Service Routine) / Interrupt Handler
- ISR is function/process that processes the interrupt. ie this process is executed when interrupt is received. Every device has seperate ISR.
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

### Divison of ISR
- ISR is divided into two parts:
  - **1. Top-half or First-Level Interrupt Handler (FLIH):** Executed immediately at occurance of interrupt. Example:
    - Acknowledging interrupt
    - Resetting hardware(if needed)
    - Recording any information ie only available at time of interrupt. 
  - **2. Bottom-half or Second-Level Interrupt Handlers (SLIH):** Non-critical processing is deferred for this.
