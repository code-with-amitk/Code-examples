## Peripheral Devices
- **What** Device used to put/get information into/from computer. ie IO devices
- **TYPES OF PD** 
  - a. Input: Sends instructions to computer. Eg: mouse, keyboard, webcam etc.
  - b. Output: Provides output from the computer. Eg: Monitor, printer, headphones etc
  - c. IO: Device performing both input and output functions.Eg: data storage device(hard disk, USB, memory card etc)
  
  
## B. PERIPHERAL CIRCUIT BOARD(PCB)?
- **What** Boards of peripheral devices. PCB has 8 pins out of which 4 are for interrupts. Eg: dvr, printer, external modem, game console etc.  
- **PCB ADDRESS** Each PCI device has its own 265 byte configuration registers.
- **Response PCI provides to CPU?** PCB provides only these 3 addresses to CPU: 
  - memory locations
  - I/O ports
  - configuration registers. 
  
### B1. CONFIGURATION REGISTERS
- PCI registers are always little endian.
- Every PCI manufacturer assigns values to these RO registers(vendor-id, device-id, class). Driver uses these to look for device.
```
 |vendor-id(2byte) | Device ID(2) | Command Reg(2) | Status Reg(2) | class code(3) | CacheLine(1)| LatencyTimer(1)| HeaderType(1)| BIST(1)|
 |BaseAddress0(4bytes) | BaseAddress1(4) | BaseAddress2(4) | BaseAddress3(4) | 
 |BaseAddress4(4bytes) | BaseAddress5(4) | Card Bus CIS Pointer(4) | SubSystem Vendor ID(2) | SubSystem Device ID(2) | 
 |Expansion ROM Base Address(4 bytes) | Reserved(8) | IRQLine(1) | IRQPin(1) | Min_Gnt(1) | Max_Gnt(1) |
``` 
- vendor-id(2 bytes mandatory): Identifies hardware manufacturer.
- device-id(2 bytes mandatory): vendor-id + device-id together are called signature
- class(2 bytes): 1st byte=Group
- subSystem Vendor ID,SubSystem Device ID(2 byte): For further identification of a device
- Required Registers: vendorID, DeviceID, Command Reg, Status Reg, Revision ID, Header Type, Reserved.      //All other are optional.
