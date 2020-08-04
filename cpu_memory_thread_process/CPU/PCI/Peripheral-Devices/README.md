```
-----PCI-Bus-n---|
                 |
------------PCI Device------------------------------------------------------
| PCI Config Space OR                                                       |
| Configuration Registers <===================256 bytes===================> |
|                                                                           |
|                                                                           |
----------------------------------------------------------------------------

 - **Remember PCI Domain** Each domain can have upto 
  - **256 PCI buses** 
	  - Each bus can connect **32 PCI devices**.
			- Each device can have **8 functions**.
				- For Each Function have **256 bytes(PCI) or 4096 bytes(PCIe)** config space.
```

## Contents
- **What_is-Peripheral-Device.md**
  - Device Number
  - Function Number
  - Types of PCI Devices
    - Bridge
    - Endpoint
  - Registers in PCI Devices
    - Type-0
    - Type-1
- **PCB-PCIConfigSpace.md**
  - PCB?
  - PCI Config Space?
    - BAR(Base address register)
  - PCI Device addresses
- 
