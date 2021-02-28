## Interrupt?
- **What?** Interrupt is sort of signal sent to CPU, to perform some high priority than currently what CPU is doing. 
- [Type and Sources of Interrupts](Types_And_Sources_of_Interrupts.md).
- **Example of Hardware Interrupt:**  
  - User is watching a movie and presses key on keyboard(hardware device). Hardware device generates H/W Interrupt sends to [Interrupt Controller(IC) 8952](). IC sends to CPU on [INTR(Interrupt) PIN].
  - CPU stops what it is doing and [Saves state](Things_CPU_does_after_getting_Interrupt.md).
  - Finds [ISR(Interrupt Service Routine/Interrupt Handler)](ISR_Interrupt_Service_Routine.md) from [IVT(Interrupt Vector Table)](IVT_Interrupt_Vector_Table.md), executes ISR. After completing the ISR resumes the task what it was doing.

<img src="./interrupt.PNG" width=500 />

- **Interrupt Numbers?** 256 types of Interrupts(0-255). Examples: 0: Pointer Divide Error    1: Pointer single Step    2: Pointer Non-maskable    3: Pointer I-Byte NIT Instruction    4: Pointer Overflow    5-31: Reserved for future use
- All reported Interrupts are shown in [/proc/interrupts and /proc/stat](Interrupts_Information.md).
