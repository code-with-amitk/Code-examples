## Interrupt?
- This is signal sent by IO device(Eg: keyboard) to Interrupt Controller(IC) when I/O device want CPU to do some task. 
- IC forwards Interrupt to CPU, CPU stops what it is doing and start doing requested task(based on priority). After completing the task resumes it again.
- Ex: User is watching a video(CPU using Video Memory), copying from network(CPU using NIC card). User presses key on keyboard, Interrupt is generated & sent to CPU.
- **INTERRUPT CONTROLLER?** Chip present on motherboard, which detects and forwards interrupt to CPU on address bus. Older computers might not have this, there devices need to talk with CPU directly.

< img src="interrupt.PNG" width=500 />
