## Hardware Interrupt reaching CPU
  - User is watching a movie and presses key on keyboard(hardware device).
  - Hardware device/Periheral generates H/W Interrupt sends to [Interrupt Controller-8952 on IR0-IR7 lines](/Motherboard/8952_PIC). IC decides priority of Interrupt and forwards to CPU on [INTR(Interrupt) PIN](/Motherboard/CPU/Microprocessors/8086).
  - CPU stops what it is doing and does the [following](Things_CPU_does_after_getting_Interrupt.md).
  - Finds [ISR(Interrupt Service Routine/Interrupt Handler)](ISR.md) from [IVT(Interrupt Vector Table)](IVT), executes ISR. After completing the ISR resumes the task what it was doing.

<img src="./interrupt.jpg" width=1000 />
