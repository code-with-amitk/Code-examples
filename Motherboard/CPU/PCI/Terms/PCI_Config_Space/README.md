## PCI Registers / PCI Configuration Space
- **What?** [PCI Devices](../PCI_Device) can be read/written/configured using PCI configuration space registers(which are present on PCI devices only) and need to be mapped to System Memory so that Device Driver/BIOS can read them.

| | PCI | PCIe |
| --- | --- | --- |
| Register length | 256 bytes | 4096 bytes |
