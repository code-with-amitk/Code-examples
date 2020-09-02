### A. PCI(Peripheral Component Interconnect)
- A standard that describes how to connect the peripheral components/devices of a system together in a structured and controlled way.
  
### B. PCI-Bridges
- These are used to connect more than 1 PCI bus to the system. Bridges joins the PCI buses.

### C. PCI Bus Architecture
- Overall layout of a PCI system is a tree where each bus is connected to an upper-layer bus, up to bus 0 at the root of the tree.
```c++
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
1 PCI Domain:     
256 Buses > 32 PCI devices/Bus > 8 functions/Device.        
Functions or PCI Configuration Space Registers: 256 bytes(PCI), 4096 bytes(PCIe)
1 Device = 8*4096 = 32K bytes.
 
 MCFG Table Size=>  256(buses) x 32(Devices/Bus) x 8(functions/Device) x 4KB(Bytes/function) = 256MB
 mmap 256MB from MCFGTable-base address to process memory
```
![ImgURL](https://i.ibb.co/SK8BKzH/pci.png)

### D. Peripheral/PCI Device
- **What?** Device used to put/get information into/from computer eg: I/O devices. Devices that is connected to PCI Bus.
- **PCI Device Examples?**  *Input*:Mouse,keyboard,webcam  *Output*: Monitor,printer,headphones *I/O*: Network cards, Bus controllers USB, PCMCIA, Sound cards, Graphics cards
- **PCI Device types**
  1. *End point device(Type 0)* That does not spawn another bus behind it. Example: VGA, LAN card
  2. *Bridge Device(Type-1)* Which can spawn another bus behind it.
- **PCI Device Representation  Bus:Device:Function**
  - Each PCI device is represented using: 
    - *Bus No* Bus on which PCI device is connected
    - *Device Number (5 bit)* Each device is given a number by vendor.
    - *Function number(3 bit)* Each device can have upto 8 functions.
- **Listing all PCI devices on system**
```c
# lspci                    //Enumerates all PCI devices
Bus:Device.Function
  00:00.0          Host Bridge Intel corporation..
  00.07.0          ISA Bridge
  00.07.1          IDE Interface
  00.80.0          VGA Compatible Controller
# lspci -x										//Lists PCI configuration space for each device
.........
00:07.0	ISA Bridge: Intel Corporation 823171AB/EB/MB PIIX4 ISA (rev 01)
00: 86 80 10 81 07 00 00 02 01 00 01 06 00 00 80 00
10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20: 00 00 00 00 00 00 00 00 00 00 00 00 14 14 00 00
30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
.........

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
