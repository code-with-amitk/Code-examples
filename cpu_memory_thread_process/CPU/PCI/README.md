```
   -------CPU-----------
  |           Registers |
  | CU        ========  |
  | ALU       ========  |
  |                     |         PCI-Bridge-----------------------PCI-Bus-0--------     //PCI-Domain-B
   ---------------------              |
            |                         |
    ----------------system-Bus--------|---
                                      |
                                   PCI-Bridge---------------------PCI-Bus-0--------     //PCI-Domain-A
                                      |                       |
                                                ------------PCI-Bus-1----------------
                                                |                                   |
                                       -----PCi-Bus-2---                   ------PCI-Bus-3--------
                                       |0            31|                   |0                   31|
                                     mouse                           -----device0-----------
                                                                     | f0(4096) .. f7(4096) |
                                                                     ------------------------
                                                                        
1 PCI Domain:
=> 256 Buses
=> 32 PCI devices/Bus
=> 8 functions/Device.        //This is config address space mapped to system Memory at MMCFG-Space
=> Config Space Register/function
 - 256 (PCI)
 - 4096 (PCIe)
``` 
## Contents
  - **Peripheral-Devices.md**
    - Peripheral Devices?
    - PCB & configuration registers
    - PCI Device Addresses
    - How PCI devices are detected
  - **PCIAndPCI_Bus.md**
    - PCI?
    - PCI Bridges
    - PCI Domain
