## Probing
- **What?** Finding which Interrupt line Hardware Device is going to use?
- **How?** Device driver tells the Hardware device to generate interrupts and watches the IRQ line and finds which line device is using.
```c
unsigned long probe_irq_on(void);
This function returns a bit maskof unassigned interrupts.
The driver must preserve the returned bit mask, and pass it to probe_irq_off later.
```
- **Other Method?** The interrupt handler can be installed either at driver initialization or when the device is first opened. Installing isr at device initialization causes interrupt line to be occupied even device is not used.
