# A. Peripheral/PCI Device
### 1. WHAT?
- Device used to put/get information into/from computer eg: I/O devices. Devices that is connected to PCI Bus.
- **PCI Device Examples?**
  - *Input* mouse, keyboard, webcam etc.
  - *Output* Monitor, printer, headphones etc
  - *I/O* Network cards, Bus controllers USB, PCMCIA, Sound cards, Graphics cards
  
- **PCI Device types**
  1. *End point device(Type 0)* That does not spawn another bus behind it. Example: VGA, LAN card
  2. *Bridge Device(Type-1)* Which can spawn another bus behind it.

### 2. PCI Device Representation  Bus:Device:Function
- Each PCI device is represented using: 
  - *Bus No* Bus on which PCI device is connected
  - *Device Number (5 bit)* Each device is given a number by vendor.
  - *Function number(3 bit)* Each device can have upto 8 functions.
  - 
- **Listing all PCI devices on system**
  - *lspci*
```
# lspci                                                   //Enumerates all PCI devices
Bus:Device.Function
  00:00.0          Host Bridge Intel corporation..
  00.07.0          ISA Bridge
  00.07.1          IDE Interface
  00.80.0          VGA Compatible Controller
```
  - *SYSFS File System* sysfs file system is automatically mounted at /sys by kernel contains information of PCI devices on system.
```
# ls -ltr /sys/devices/pci0000\:00\                     //PCI devices in domain 0000
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:0.0    
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:07.0
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:07.1
drwrx-xr-x. 6 root  root  0 Aug 7 02:41 0000:00:08.0
```    

### 3. [PCI Registers / PCI Configuration Space](PCIConfigSpace.md)
- **What**
  - PCI Devices can be read/written/configured using PCI configuration space registers.
  
| | PCI | PCIe |
| --- | --- | --- |
| Register length | 256 bytes | 4096 bytes |

![ImgURL](https://i.ibb.co/SK8BKzH/pci.png)

### 4. Communication b/w CPU & PCI Device
#### Method-1 MMIO(Memory Mapped IO)
- At system boot, kernel send/recv messages with each PCI-device & **MAPS PCI-device control registers(PCI Config Space registers)** are mapped into the address space of the processor, this address space is called MCFG-SPACE(256 MB). 
- When device driver accesses the PCI device, its memory and I/O regions have already been mapped into the processor’s address space. Details [PCIConfigSpace.md](PCIConfigSpace.md)

### Method-2 (Special I/O instructions)

# B. Peripheral Circuit Board(PCB)?
- **What** Boards of peripheral devices. PCB has 8 pins out of which 4 are for interrupts. Eg: dvr, printer, external modem, game console etc.  
- **Response PCI provides to CPU?** PCB provides only these 3 addresses to CPU: 
  - Configuration Registers (also called **config space**	{Section-C})
  - memory locations
  - I/O ports
