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
                                       |1            32|     |1         32|
                                     mouse                  keyboard

In 1 PCI Domain:
   - Upto 256 PCI buses
   - Each Bus can connect upto 32 devices
   - 1 Peripheral device can have 8 functions.
``` 

## Contents
  - Peripherals
  - PCIAndPCI_Bus
