## Accessing GPU Registers
- Presently, AMD/Nvidia exposes all GPU registers as Device connected to PCIe bus.
- This means GPU Register contents are stored in [PCI-Config-Space.md](PCIConfigSpace.md) of a particular PCI Device, that means if that device is mapped properly to [MMCFG-SPACE](PCIConfigSpace.md) then GPU registers can be accessed. 
