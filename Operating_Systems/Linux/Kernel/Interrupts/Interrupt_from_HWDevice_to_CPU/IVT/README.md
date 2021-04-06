## IVT(Interrupt Vector Table) / (IDT) Interrupt Descriptor Table
- Contains ISR(Interrupt service routine)/Handler/Address to which CPU jumps at occurrence of interrupt. Present in 1st 1K of physical memory.
- Starting address of IVT is stored in dedicated register (IDTR). 
- **How its created?** IDT is created when the system initially boots and reflects the specific system configuration.
- IVT is filled using [Probing](Probing_Hardware_Device.md).
- Interrupt number is used as index in IVT. CPU goes to IVT's index, gets [Instruction Pointer/Program counter](https://sites.google.com/site/amitinterviewpreparation/c-1/assembly-language) and starts Interrupt service procedure. Once CPU starts ISP, Device Acks Interrupt controller
```c
            | 0x420932 ISR of Int0 |      |     |     |
Interrupt No>       0                 1       2     3

    CPU                    Hardware_Device
       <- Interrupt3=signal-
 Find & runs ISR3 for Intr3
    isr3(){..}
```
