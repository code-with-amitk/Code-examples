
## Terms
- **A. PCI(Peripheral Component Interconnect)?** A standard that describes how to connect the peripheral components/devices of a system together in a structured and controlled way.
- **B. PCI-Bridges?** These are used to connect more than 1 PCI bus to the system. Bridges joins the PCI buses.
- **C. PCI Bus Architecture?** Overall layout of a PCI system is a tree where each bus is connected to an upper-layer bus, up to bus 0 at the root of the tree.
```html
   -------CPU-----------
  |           Registers |
  | CU        ========  |
  | ALU       ========  |
  |                     |         PCI-Bridge---------PCI-Bus-0--------     //PCI-Domain-B(0001). //Can have upto 65535 domains
   ---------------------              |
            |                         |
    ----------------system-Bus--------|-
                                      |
                                   PCI-Bridge--------PCI-Bus-0----        //PCI-Domain-A(0000)
                                      |                 |
                                        -------------------------------------
                                        |                                   |
                               ---------Bus-2---                   -----------Bus-3-----------------
                               |0            31|                   |0       |                    31|
                              mouse                                     ---device7--------------
                                                                        | f0(4096)     f6        |
                                                                        |        0000:03:07.6.40 | 
                                                                        -------------------------- 
                                                                         //Domain:0,Bus:3,Device:7,Function:6,Register:40
                                                                         
> MAX BUSES can be 256 supported by any motherboard
This is for future, presently you will see max 20-30 devices on PCI Bus.
Huge Boards can have higher number of PCI buses

1 PCI Domain:     
256 Buses > 32 PCI devices/Bus > 8 functions/Device.        
Functions or PCI Configuration Space Registers: 256 bytes(PCI), 4096 bytes(PCIe)
1 PCI Device is represented by 1 Function = 4096 bytes
 
 MCFG Table Size=>  256(buses) x 32(Devices/Bus) x 8(functions/Device) x 4KB(Bytes/function) = 256MB
 mmap 256MB from MCFGTable-base address to process memory
```
![ImgURL](https://i.ibb.co/SK8BKzH/pci.png)


```
- *SYSFS File System* sysfs file system is automatically mounted at /sys by kernel contains information of PCI devices on system.
```
# ls -ltr /sys/devices/pci0000\:00\                     //PCI devices in domain 0000
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:0.0    
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:07.0
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:07.1
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:08.0
```    
- **[PCI Registers / PCI Configuration Space](PCIConfigSpace.md)**
  - **What** PCI Devices can be read/written/configured using PCI configuration space registers.

| | PCI | PCIe |
| --- | --- | --- |
| Register length | 256 bytes | 4096 bytes |


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
