## [PCI Registers / PCI Configuration Space](https://wiki.osdev.org/PCI#PCI_Device_Structure)
- **What?**
  - [PCI Devices](../PCI_Device) can be read/written/configured using PCI configuration space registers(which are present on PCI devices only) and need to be mapped to System Memory so that Device Driver/BIOS can read them.
- **[Locating PCI Config Space](Locating_PCI_Config_Space.md):** RDP-PTR > RDSP-struct{xsdt-struct-address} > XSDT-struct{64bit-mcfg-struct-address} > MCFG-struct{contains MCFG_BaseAddress} > Store Mapping to PCIConfig Spac
- [BARS](./BARs)
- [Capabilites](./Capabilites)

<img src=pci-header.PNG width=1200 />

## Reading from Config Space Register
> Consider Reading from Bus=3, Device=2, Function=5, Register=40 {3:2:5:40} = 0x80031540

- **1. PCI(256 bytes)**

|1000 0000|Bus-number=03|Device(5bit)=00010 Function(3bit)=010|RegisterAddress(8 bit)=40| 
| --- | --- | --- | --- | 

- Above table creates address = 0x80031540
- Write 80031540 to 0xCF8{CONFIG_ADDRESS} and read information from 0xCFC{CONFIG_DATA}

- **2. PCIe(4096 bytes)**
  - **MCFG(Memory Mapped Config)** New mechanism for reading 4096 bytes address space.
  - *MCFG-Base* This is the starting address of MCFG Space & is required for constructing message for reading PCIe address space.  
  - For 1 PCI Domain.          Total 65535 domain are possible, But most systems have domain=0.
    - 256 PCI buses
    - 32 PCI devices/Bus
    - 8 functions/Device
    - 4096 bytes config space/Function
	    - Total = 256 x 32 x 8 x 4096 = 256 MB. Means 1 MB for each bus.
  - 1MB(1048576) PCI Space/Bus
	  - 1048576/32 Devices = 32KB(32768) space/Device
	  - 32768/8 Functions = 4KB(4096) Space/Function
