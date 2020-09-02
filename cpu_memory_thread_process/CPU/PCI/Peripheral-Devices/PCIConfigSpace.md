**1st See (What_is_Peripheral-Device_PCB.md)**

## A. [PCI Config Space/Config Registers/Config Header](https://wiki.osdev.org/PCI#PCI_Device_Structure)
> (PCI = 256 bytes, PCIe = 4096 byte)
- **What** 
	- Registers present on PCI devices having device information, these are used by CPU for device intialization/configuration.
	- These are mapped to Memory location(PHYSICAL MEMORY) & read/written using configuration RW cycles.
	- Every PCI manufacturer assigns values to these RO registers(vendor-id, device-id, class). Driver uses these to look for device.
	- Listing Config Space Registers **lspci -x**
	- Bus>Device>Function(4096 bytes) will have Header and memory area.
		- **Bus>Device>Function Header(64 bytes)**

|Header-type|For|
|---|---|
|0|Standard Header(all other)|
|1|PCI-to-PCI Bridge|
|2|PCI-to-Card-Bus Bridge|

![ImgURL](https://i.ibb.co/nCN4X92/pci-header.png)

#### BAR(Base Address Register)
- **What** This PCI device is using some memory, BAR will hold the memory addresses used by this device, or offsets for port addresses. 
- **Types of BARS**

![ImgURL](https://i.ibb.co/7n2BqDJ/bar-pci.png)

|Type|Located in|Identified by|Feilds|Retrieving Base address of BAR|
|---|---|---|---|---|
|1.Memory Space BAR|Physical Memory|LSB is 0|<ul><li>Type=0(base register is 32bit), Type=2(Base regiser is 64bit), Type=1(not used)</li></ul><ul><li>Prefetchable means base address region does not have read side effects</li></ul>|<ul><li>For 16bit:(BAR[x] & 0xFFF0)</li></ul><ul><li>For 32 bit(BAR[x] & 0xFFF0)</li></ul><ul><li>For 64 bit((BAR[x] & 0xFFFFFFF0) + ((BAR[x+1] & 0xFFFFFFFF) << 32))|
|2.I/O Space BAR||LSB is 1||(BAR[x] & 0xFFFFFFFC)|



## B. Reading from Config Space Register
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
