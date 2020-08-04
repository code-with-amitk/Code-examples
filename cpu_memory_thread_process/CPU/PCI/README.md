```
   -------CPU-----------
  |           Registers |
  | CU        ========  |
  | ALU       ========  |
  |                     |         PCI-Bridge-------------PCI-Bus-0--------     //PCI-Domain-B
   ---------------------              |
            |                         |
    ----------------system-Bus--------|---
                                      |
                                   PCI-Bridge--------PCI-Bus-0--------     //PCI-Domain-A
                                      |                 |
                                                -----PCI-Bus-1------
                                                |                  |
                                       -----PCi-Bus-2---      --PCI-Bus-3-         
                                       |0            31|     |0         31|
                                     mouse                  device0

In 1 PCI Domain:
   - Upto 256 PCI buses
   - Each Bus can connect upto 32 devices
   - 1 Peripheral device can have 8 functions.
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
