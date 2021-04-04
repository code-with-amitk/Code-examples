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

- **4. Precise & Imprecise Interrupts**
  - *a. Precise?* This interrupt that leaves the machine in a well-defined state. 4 properties of precise interrupts:
    - *1.* The [PC (Program Counter)](/Motherboard/CPU/Memory/CPU_Registers/User_Accessible_Registers/) is saved in a known place and PC is made to point to new ISR.
    - *2.* All instructions before the one pointed to by the PC have completed.
    - *3.* No instruction beyond the one pointed to by the PC has finished.
    - *4.* The execution state of the instruction pointed to by the PC is known.
  - *b. Imprecise?* Interrupts have completed in parts.
    - *Disadvantages of Imprecise Interrupts:*
      - *1.* The code for handling imprecise is exceedingly complex.
      - *2.* Huge stacks are created contaning information of all states.
      - *3.* Slow system, saving a large amount of information to memory on every interrupt makes interrupts slow and recovery even worse.

<img src=precise_imprecise_interrupts.JPG width=500 />
