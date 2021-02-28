## Types of Interrupts
- **1. Hardware, Software Interrupt**

||Hardware|Software|
|---|---|---|
|What|Caused by signal from H/W|Interrupt that originates in software(process in user mode), CPU need to switch to kernel mode|
|Examples|Key press on keyboard, mouse movement, timers|System calls: open(), socket()|

- *Making software Interrupt?*
```asm
  mov rax,4    ;Store system-call number in rax register
  mov rbx,arg1    ;Store arguments of system-call in rbx,rcx,rdx,rsi,rdp registers
  mov rcx,arg2
  int 0x80        ;Call S/W Interrupt. Just call int function with Interrupt number.    //As int is called Control Reaches IVT, Interrupt Vector table
```        

- **2. Vectored & Non Vectored**
  - *a. Vectored?* The interrupts which have fixed address location ie ISR to be executed on occurence of Interrupt.
  - *b. Non Vectored?* The interrupts which does not have fixed address location for ISR to be executed at occurence

- **3. Maskable & Non Maskable Interrupts**
  - *a. Maskable?* Interrupts which can be ignored by CPU.
  - *b. Non Maskable?* Interrupts which cannot be ignored by CPU.

## Source of Interrupt
- **1. Hardware / IO Devices:** 8259(PIC) sends interrupt signal on NMI or INTR inupt pins of 8086.
- **2. Software / Special Intruction in Software:** int(interrupt instruction) in program. See above.
- **3. Software / Condition produced in program:** some condition produced in the program by the execution of an instruction. Eg: Divide by 0.  
