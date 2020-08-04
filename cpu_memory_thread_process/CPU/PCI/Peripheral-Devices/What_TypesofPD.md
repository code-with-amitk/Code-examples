## A. Peripheral Devices
- **What** Device used to put/get information into/from computer. ie IO devices
- **TYPES OF PD** 
  - a. Input: Sends instructions to computer. Eg: mouse, keyboard, webcam etc.
  - b. Output: Provides output from the computer. Eg: Monitor, printer, headphones etc
  - c. IO: Device performing both input and output functions.Eg: data storage device(hard disk, USB, memory card etc)
  
## B. How PCI Device is detected
- Every PCB has BIOS, NVRAM, or PROM. CPU can access device's address space by reading and writing registers in the PCI controller.
- At system boot, the firmware (Linux kernel) performs configuration transactions with every PCI peripheral & allocate a safe place its address region.
- When device driver accesses the PCI device, its memory and I/O regions have already been mapped into the processor’s address space.
