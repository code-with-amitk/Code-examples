- **1st See (What_is_Peripheral-Device_PCB.md)**
- **Book: ACPI_6_3_final_Jan30.pdf Section: 5.5.2.4.3 PCI Device BAR Target Protocols**
- ** [PCI-SIG](https://pcisig.com/specifications?field_technology_value%5B%5D=express&speclib=bar)

## [A. PCI Config Space/Config Registers/Config Header](https://wiki.osdev.org/PCI#PCI_Device_Structure)
> (Bus>Device>Function Size on PCI=256 bytes, PCIe=4096 byte)
- **What** 
	- These are Registers present on PCI devices having PCI device information, these are used by CPU for PCI device intialization/configuration.
	- These registers need to be mapped to System memory so that it can be accessed using Driver.
	- Listing Config Space Registers **lspci -x**
- **Each Bus>Device>Function(4k bytes) has {Header 64bytes}+{Memory Area 4032bytes}**
	- 1 Device = 8x4096 = 32K bytes of space.
	- **Bus>Device>Function Header(64 bytes)**

![ImgURL](https://i.ibb.co/Tt0N7Tq/pci-header.png)

### BAR(Base Address Register)
- **What** 
	- BARs contains base address of an I/O or Memory mapped region of this PCI device where its control registers lie.
	- Ownership of the I/O & Memory regions associated with BARs is given to a device driver associated with PCI device.
	- PCI BAR Target operation regions may only be declared in the scope of PCI devices that have a PCI Header Type of 0.
	- Device can have upto six 32bit BARs. Two 32bit BARs can be combined to create 64Bit BAR.
- **BAR Types**
```c
1. Memory Space BAR
|16byte Aligned Base Address(28 bits)|Prefechable(1 bit)|Type(2 bit)|0(1 bit)|
LSB: Always 0
Type:
	|-0: Base register is 32bit
	|-2: Base regiser is 64bit
	|-1: Not used
Prefechable: Base address region does not have read side effects
When you want to retrieve the actual base address of a BAR, be sure to mask the lower bits.

2. I/O Bar Space
|4byte Aligned Base Address(30bits)|Reserved(1 bit)|1(1 bit)|
LSB: Always 1

```
- **6 BARs**

||offset|Purpose|
|---|---|---|
|BAR0(MEM_BASE/MMIO Register)|0x10||
|BAR1(IO_BASE/VRAM Aperature)|0x14|area of prefetchable memory that maps to the card’s VRAM.|
|BAR2(REG_BASE_LO)|0x18||
|BAR3(REG_BASE_HI)|0x1C||
|BAR4(IO_BASE_WS)|0x20||
|BAR5(REG_BASE)|0x24||

- **Reading BAR Register**




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
