## Types of Interrupts

||Hardware|Software|
|---|---|---|
|What|Caused by signal from H/W|Interrupt that originates in software(process in user mode), CPU need to switch to kernel mode|
|Examples|Key press on keyboard, mouse movement, timers|System calls: open(), socket()|

- **Making software Interrupt?**
```asm
  mov rax,4    ;Store system-call number in rax register
  mov rbx,arg1    ;Store arguments of system-call in rbx,rcx,rdx,rsi,rdp registers
  mov rcx,arg2
  int 0x80        ;Call S/W Interrupt. Just call int function with Interrupt number.    //As int is called Control Reaches IVT, Interrupt Vector table
```        
