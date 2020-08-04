## A. Peripheral Devices
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

## C. PCI DEVICE ADDRESSES
- Device on PCI Bus can be represented by using 2 byte address with either of these:
  - a. (B:D) = (Bus-number(1byte) : device+function-number(1byte))    OR
  - b. (B:D:F) = (1-byte:Bus-number  : device : function)    OR
  - c. (DO:B:D:F) = (Domain(16 bit) : Bus-number(8 bit)  : device(5 bit) : function(5 bit) )   
- Commands to see PCI devices:
```
        # lspci                     //lists of devices are being used
        # tree /sys/bus/pci/devices/
            0000:00:14.0 -> ../../../devices/pci0000:00/0000:00:14.0
        #$ tree /sys/bus/pci/devices/0000:00:10.0
            |-- class
            |-- config        //allows raw PCI information to be read from device.
            |-- detach_state
            |-- device
            |-- irq        //current IRQ assigned to this PCI device
            |-- power
            |`-- state
            |-- resource    //shows the current memory resources allocated by this device
            |-- subsystem_device
            |-- subsystem_vendor
            `-- vendor
        # cat /proc/bus/pci/devices| cut -f1
```

## D. How PCI Device is detected
- Every PCB has BIOS, NVRAM, or PROM. CPU can access device's address space by reading and writing registers in the PCI controller.
- At system boot, the firmware (Linux kernel) performs configuration transactions with every PCI peripheral & allocate a safe place its address region.
- When device driver accesses the PCI device, its memory and I/O regions have already been mapped into the processor’s address space.
