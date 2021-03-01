## [PCI Registers / PCI Configuration Space]((https://wiki.osdev.org/PCI#PCI_Device_Structure)
- **What?**
  - [PCI Devices](../PCI_Device) can be read/written/configured using PCI configuration space registers(which are present on PCI devices only) and need to be mapped to System Memory so that Device Driver/BIOS can read them.

<img src=pci-header.PNG width=800 />
