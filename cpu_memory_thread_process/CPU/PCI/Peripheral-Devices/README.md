```
-----PCI-Bus-n---|
                 |
------------PCI Device------------------------------------------------------
| PCI Config Space OR                                                       |
| Configuration Registers <===================256 bytes===================> |
|                                                                           |
|                                                                           |
----------------------------------------------------------------------------

Upto 65535 PCI Domain.
1 PCI Domain:
=> 256 Buses
=> 32 PCI devices/Bus
=> 8 functions/Device
=> Config Space Register/function
 - 256 (PCI)
 - 4096 (PCIe)
```

## Contents
- **What_is-Peripheral-Device_PCB.md**
  - Device Number
  - Function Number
  - Types of PCI Devices
    - Bridge
    - Endpoint
  - Registers in PCI Devices
    - Type-0
    - Type-1
  - PCB?    
- **PCB-PCIConfigSpace.md**
  - PCI Config Space?
    - BAR(Base address register)
  - PCI Device addresses
- 
