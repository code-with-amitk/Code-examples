## A. Peripheral/PCI Device
#### 1. WHAT
  - Device used to put/get information into/from computer. ie IO devices
  - Device that is connected to PCI Bus.
  - Each PCI device have a associated **Device Number (5 bit) feild**, (0-31).
    - Device numbers are assigned at hardware level. 
  
#### 2. TYPES OF DEVICES

| | What | Example |
| --- | --- | --- |
| End-Point Device(Type-0) | does not spawn another bus behind it | VGA, LAN card |
| Bridge Device(Type-1) | Which can spawn another bus behind it | |

#### 3. FUNCTION NUMBER
- Each device can have multiple functions with in it.
- Function numbers can be `0-7` hence 3 bit field.

#### 4. REGISTERS / [PCI Configuration Space](PCIConfigSpace.md)
##### What 
- PCI Devices exposes these registers using which CPU can initialize/configure the device called Config Registers.
  
| | PCI | PCIe |
| --- | --- | --- |
| Register length | 256 bytes | 4096 bytes |

![ImgURL](https://i.ibb.co/SK8BKzH/pci.png)

#### 5.Examples OF PD** 
- a. Input: Sends instructions to computer. Eg: mouse, keyboard, webcam etc.
- b. Output: Provides output from the computer. Eg: Monitor, printer, headphones etc
- c. IO: Device performing both input and output functions.Eg: data storage device(hard disk, USB, memory card etc)
  
## B. Communication b/w CPU & PCI Device
### Method-1 MMIO(Memory Mapped IO)
- At system boot, kernel send/recv messages with each PCI-device & **MAPS PCI-device control registers(PCI Config Space registers)** are mapped into the address space of the processor, this address space is called MCFG-SPACE(256 MB). 
- When device driver accesses the PCI device, its memory and I/O regions have already been mapped into the processor’s address space. Details [PCIConfigSpace.md](PCIConfigSpace.md)

### Method-2 (Special I/O instructions)

## C. Peripheral Circuit Board(PCB)?
- **What** Boards of peripheral devices. PCB has 8 pins out of which 4 are for interrupts. Eg: dvr, printer, external modem, game console etc.  
- **Response PCI provides to CPU?** PCB provides only these 3 addresses to CPU: 
  - Configuration Registers (also called **config space**	{Section-C})
  - memory locations
  - I/O ports
