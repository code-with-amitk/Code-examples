**1st See (What_is_Peripheral-Device_PCB.md)**

## A. PCI Config Space/Config Registers/Config Header (PCI = 256 bytes, PCIe = 4096 byte)
- **What** 
	- Registers present on PCI devices having device information, these are used by CPU for device intialization/configuration.
	- These are mapped to Memory location(PHYSICAL MEMORY) & read/written using configuration RW cycles.
  - Every PCI manufacturer assigns values to these RO registers(vendor-id, device-id, class). Driver uses these to look for device.
- **Listing Config Space Registers**
	- *lspci -x*
```
# lspci -x										//Lists PCI configuration space for each device
.........
00:07.0	ISA Bridge: Intel Corporation 823171AB/EB/MB PIIX4 ISA (rev 01)
00: 86 80 10 81 07 00 00 02 01 00 01 06 00 00 80 00
10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20: 00 00 00 00 00 00 00 00 00 00 00 00 14 14 00 00
30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
.........
```
- **Config Register Structure**
	- offset0: VendorID, offset1: DeviceID, offset10: classID, offset16to39: BAR0-BAR5, offset44: subvendorID
		- vendor-id,device-id(mandatory): assigned by the vendor.		
	- *BAR(Base Address Register) {56 bytes}* Tells CPU how much space this PCI device requires for I/O and PCI memory.
		- *Types of PCI BARs*
  		- *1. Register holding base address of PCI Memory space* : Indicate on which address space this Device register will be present
  		- *2. Register holding base address of PCI I/O space* : Indicate on which address space this Device register will be present    

## A2. Reading from Config Space Register
> Consider Reading from Bus=3, Device=2, Function=5, Register=40 {3:2:5:40} = 0x80031540

### 1. PCI(256 bytes)

|1000 0000|Bus-number=03|Device(5bit)=00010 Function(3bit)=010|RegisterAddress(8 bit)=40| 
| --- | --- | --- | --- | 

- Above table creates address = 0x80031540
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
- 1MB(1048576) PCI Space/Bus
	- 1048576/32 Devices = 32KB(32768) space/Device
	- 32768/8 Functions = 4KB(4096) Space/Function
```
|																					|									|
|==4kb(fun0)==|==4kb(fun1)==|==4kb(fun8)==|									|
|<---Device0(32KB) PCI Config Space------>|<-----Device1--->|
MCFGBase
```
		
|BaseAddressOfMCFG_BaseAddress(8 byte)=0x80000000|BusNumber=03|Device(5bit)=00010 Function(3bit)=101|RegisterAddress(12bit)=40 |
| --- | --- | --- | --- |

- Above table creates address = 0x80031540		

![ImgURL](https://i.ibb.co/LSnZW04/mmcfg-space.png)


# B. How to Know MCFG_BaseAddress
- [Using RDSP Structure](RDSP.md)
