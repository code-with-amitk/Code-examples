## ISR(Interrupt Service Routine)
- Every device has seperate ISR.
- ISR is function/process that processes the interrupt.

## IVT(Interrupt Vector Table)
- Contains ISR(Interrupt service routine)/Handler/Address to which CPU jumps at occurrence of  interrupt. 
- All devices are identified at boot time and respective ISRs are filled in IVT.
- Interrupt number is used as index in IVT.  CPU goes to IVT's index, gets Program counter and starts Interrupt service procedure. Once CPU starts ISP, Device Acks Interrupt controller
```c
            | 0x420932 ISR of Int0 |      |     |     |
Interrupt No>       0                 1       2     3
```
