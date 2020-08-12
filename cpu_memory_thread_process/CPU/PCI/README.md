```
   -------CPU-----------
  |           Registers |
  | CU        ========  |
  | ALU       ========  |
  |                     |         PCI-Bridge--------------------PCI-Bus-0--------     //PCI-Domain-B(0001)
   ---------------------              |
            |                         |
    ----------------system-Bus--------|---
                                      |
                                   PCI-Bridge--------------PCI-Bus-0--------            //PCI-Domain-A(0000)
                                      |                       |
                                                -------------------------------------
                                                |                                   |
                                       ---------Bus-2---                   -----------Bus-3-----------------
                                       |0            31|                   |0       |                    31|
                                     mouse                                     ---device7--------------
                                                                              | f0(4096)     f6        |
                                                                              |        0000:03:07.6.40 | //Domain:0,Bus:3,Device:7,Function:6,Register:40
                                                                              --------------------------
                                                                        
1 PCI Domain:     //Can have 65535 domains
=> 256 Buses
=> 32 PCI devices/Bus
=> 8 functions/Device.        //This is config address space mapped to system Memory at MMCFG-Space
=> Config Space Register/function
 - 256 (PCI)
 - 4096 (PCIe)
 
 MCFG Table Size=>  256(buses) x 32(Devices/Bus) x 8(functions/Device) x 4KB(size/function) = 256MB
 mmap 256MB from MCFGTable-base address to process memory
``` 
## Contents
  - **Peripheral-Devices.md**
    - Peripheral Devices?
    - PCB & configuration registers
    - PCI Device Addresses
    - How PCI devices are detected
  - **PCI_PCIBus_PCIDomain.md**
    - PCI?
    - PCI Bridges
    - PCI Domain
