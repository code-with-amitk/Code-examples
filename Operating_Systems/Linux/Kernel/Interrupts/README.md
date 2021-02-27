## Interrupt?
- This is signal sent by IO device(Eg: keyboard) to Interrupt Controller(IC) when I/O device want CPU to do some task. 
  - Ex: User is watching a video(CPU using Video Memory), copying from network(CPU using NIC card). User presses key on keyboard, Interrupt is generated & sent to CPU.
- IC forwards Interrupt to CPU, CPU stops what it is doing and start doing requested task(based on priority). After completing the task resumes it again.
  - **INTERRUPT CONTROLLER?** Chip present on motherboard, which detects and forwards interrupt to CPU on address bus. Older computers might not have this, there devices need to talk with CPU directly.

<img src="./interrupt.PNG" width=500 />

- Total: 256 types of Interrupts(0-255). Examples: 0: Pointer Divide Error    1: Pointer single Step    2: Pointer Non-maskable    3: Pointer I-Byte NIT Instruction    4: Pointer Overflow    5-31: Reserved for future use
- All reported Interrupts are shown in [/proc/interrupts and /proc/stat](Interrupts_Information.md).
