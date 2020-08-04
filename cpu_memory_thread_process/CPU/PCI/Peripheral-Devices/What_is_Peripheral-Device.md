## A. Peripheral/PCI Device
### 1. WHAT
  - Device used to put/get information into/from computer. ie IO devices
  - Device that is connected to PCI Bus.
  - Each PCI device have a associated **Device Number (5 bit) feild**, (0-31).
    - Device numbers are assigned at hardware level. 
  
### 2. TYPES OF DEVICES

| | What | Example |
| --- | --- | --- |
| End-Point Device(Type-0) | does not spawn another bus behind it | VGA, LAN card |
| Bridge Device(Type-1) | Which can spawn another bus behind it | |

### 3. FUNCTION NUMBER
- Each device can have multiple functions with in it.
- Function numbers can be `0-7` hence 3 bit field.

### 4. REGISTERS
#### What 
- PCI Devices exposes some registers using which software can configure the device called Config Registers.
  
| | PCI | PCIe |
| --- | --- | --- |
| Register length | 256 bytes | 4096 bytes |

### 5.Examples OF PD** 
- a. Input: Sends instructions to computer. Eg: mouse, keyboard, webcam etc.
- b. Output: Provides output from the computer. Eg: Monitor, printer, headphones etc
- c. IO: Device performing both input and output functions.Eg: data storage device(hard disk, USB, memory card etc)
  
## B. How PCI Device is detected
- Every PCB has BIOS, NVRAM, or PROM. CPU can access device's address space by reading and writing registers in the PCI controller.
- At system boot, the firmware (Linux kernel) performs configuration transactions with every PCI peripheral & allocate a safe place its address region.
- When device driver accesses the PCI device, its memory and I/O regions have already been mapped into the processor’s address space.
