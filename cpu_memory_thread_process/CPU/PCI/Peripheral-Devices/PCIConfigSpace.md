**1st See (What_is_Peripheral-Device_PCB.md)**

# PCI Config Space/Config Registers/Config Header (PCI = 256 bytes, PCIe = 4096 byte)
- **What** 
	- Registers present on PCI devices having device information, these are used by CPU for device intialization/configuration.
	- These are mapped to Memory location(PHYSICAL MEMORY) & read/written using configuration RW cycles.
  - Every PCI manufacturer assigns values to these RO registers(vendor-id, device-id, class). Driver uses these to look for device.

## A1. Config Register Structure

|vendorId|DeviceId|..|HeaderType|BAR0|BAR1|BAR2|BAR3|BAR4|BAR5|
| --- | --- | --- | --- | --- | --- | ---- | --- | --- | --- |

- vendor-id,device-id(mandatory): assigned by the vendor.
- **BAR(Base Address Register) {56 bytes}** Tells CPU how much space this PCI device requires for I/O and PCI memory.
	- *Types of PCI BARs*
  	- *1. Register holding base address of PCI Memory space* : Indicate on which address space this Device register will be present
  	- *2. Register holding base address of PCI I/O space* : Indicate on which address space this Device register will be present    

## A2. Reading from Config Space Registers
### 1. PCI(256 bytes)
- Constructing Address(32 bytes) to read from PCI-Bus=3, PCI-Device=2, Function=5, Register=40 {3:2:5:40} = x80031540

| 1000 0000 |Bus-number=03|Device(5bit)=00010 Function(3bit)=010|RegisterAddress(8 bit)=40| 
| --- | --- | --- | --- | 

- Write 80031540 to 0xCF8{CONFIG_ADDRESS} and read information from 0xCFC{CONFIG_DATA}

### 2. PCIe(4096 bytes)
- **MCFG(Memory Mapped Config)** New mechanism for reading 4096 bytes address space.
- *MCFG-Base* This is the starting address of MCFG Space & is required for constructing message for reading PCIe address space.  
- For 1 PCI Domain.          Total 65535 domain are possible, But most systems have domain=0.
  - 256 PCI buses
  - 32 PCI devices/Bus
  - 8 functions/Device
  - 4096 bytes config space/Function
	  - Total = 256 x 32 x 8 x 4096 = 256 MB. Means 1 MB for each bus.

![ImgURL](https://i.ibb.co/LSnZW04/mmcfg-space.png)

- Constructing Address(32 bytes) to read from PCI-Bus=3, PCI-Device=2, Function=5, Register=40 {3:2:5:40} = 0x8031540
	
|BaseAddressOfMCFG_BaseAddress(8 byte)=0x80000000|BusNumber=03|Device(5bit)=00010 Function(3bit)=101|RegisterAddress(12bit)=40 |
| --- | --- | --- | --- |


# B. How to Know MCFG_BaseAddress
- [Using RDSP Structure](RDSP.md)
