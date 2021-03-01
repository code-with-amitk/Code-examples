

### Communication b/w CPU & PCI Device
#### Method-1 MMIO(Memory Mapped IO)
- At system boot, kernel send/recv messages with each PCI-device & **MAPS PCI-device control registers(PCI Config Space registers)** are mapped into the address space of the processor, this address space is called MCFG-SPACE(256 MB). 
- When device driver accesses the PCI device, its memory and I/O regions have already been mapped into the processor’s address space. Details [PCIConfigSpace.md](PCIConfigSpace.md)
#### Method-2 (Special I/O instructions)

### B. Peripheral Circuit Board(PCB)?
- **What** Boards of peripheral devices. PCB has 8 pins out of which 4 are for interrupts. Eg: dvr, printer, external modem, game console etc.  
- **Response PCI provides to CPU?** PCB provides only these 3 addresses to CPU: 
  - Configuration Registers (also called **config space**	{Section-C})
  - memory locations
  - I/O ports
