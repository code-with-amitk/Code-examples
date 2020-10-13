- **1st See (What_is_Peripheral-Device_PCB.md)**
- **Book: ACPI_6_3_final_Jan30.pdf Section: 5.5.2.4.3 PCI Device BAR Target Protocols**
- ** [PCI-SIG](https://pcisig.com/specifications?field_technology_value%5B%5D=express&speclib=bar)

## [A. PCI Config Space/Config Registers/Config Header](https://wiki.osdev.org/PCI#PCI_Device_Structure)
> (Bus>Device>Function Size on PCI=256 bytes, PCIe=4096 byte)
### What
  - These are Registers/Memory present on PCI device having PCI device information, these are used by device driver to interact with PCI device.
  - These registers/memory need to be mapped to System memory so that it can be accessed using Driver or BIOS.
  - Listing Config Space Registers **lspci -x**
  - **Each Segment>Bus>Device>Function(4096 bytes) has {Header 64bytes}+{Memory Area 4032bytes}**
    - 1 Device = 8x4096 = 32K bytes of space.
    - **Bus>Device>Function Header(64 bytes)**

![ImgURL](https://i.ibb.co/Tt0N7Tq/pci-header.png)

### BAR(Base Address Register)
#### What
  - BARs contains base address of an I/O or Memory mapped region of this PCI device where its control registers lie.
  - Ownership of the I/O & Memory regions associated with BARs is given to a device driver associated with PCI device.
  - PCI BAR Target operation regions may only be declared in the scope of PCI devices that have a PCI Header Type of 0.
  - Device can have upto six 32bit BARs. Two 32bit BARs can be combined to create 64Bit BAR.
#### BAR Types
  - **1. Memory Space BAR**
```c
|16byte Aligned Base Address(28 bits)|Prefechable(1 bit)|Type(2 bit)|0(1 bit)|   //LSB: Always 0
Type:
  |-0: 32bit decoder.	//Means This PCI device can access addresses from 0-4GB. 2^32 = 4GB. BIOS will mmap this device's Memory(after header) to MMIO_LOW.
  |-2: 64bit decoder.	//This PCI device can access addresses from 0-16ExaBytes. BIOS can allocate space from MMIO_LOW or MMIO_HIGH. In this case next BAR is ganged together.
  |-1: Not used
Prefechable: Base address region does not have read side effects
```

  - **2. I/O Bar Space**
```c  
|4byte Aligned Base Address(30bits)|Reserved(1 bit)|1(1 bit)|		//LSB: Always 1
```
#### 6 BAR Registers

|BAR No|offset|Purpose|
|---|---|---|
|0|0x10|Frame Buffer/Video Memory 64Bit = <BAR0 on left 32 bits><BAR1 on right 32 Bits>|
|1|0x14|Combined with BAR0 makes frame buffer|
|2|0x18|Doorbell or REG_BASE_LO|
|3|0x1C|Doorbell or REG_BASE_HI|
|4|0x20|IO Base|
|5|0x24|Memory Mapped Register Space or Register Base Address or GPU Register Access|

#### Reading BAR Registers
> How BIOS discover what's sizeof MMIO Range is needed by PCI Device(Eg:GPU). Sizeof MMIO Range means memory needed to map this device configuration space.
- **1. (BAR0 << 32) + BAR1 Video Frame Buffer**
```c
    BIOS						BAR0(c000_000c)
       ----Read BAR5 in uint32_t--->
       <---read(bn, dn, offset=0x10, &dword=c000_000c)---
 uint64 aperatureStartAddress = c000_000c & ffff_fff0 = 0000_0000_c000_0000

    if (BAR0 & 0x04){   //Check if 64 bit
       ----Read BAR1 in uint32_t--->                      BAR1(0000_0000)
       <---read(bn, dn, offset=0x14, &dword)---
       //Left shift BAR1 read by 32
       dword << 32 = 0000_0000_0000_0000
       aperatureStartAddress = aperatureStartAddress + dword
       aperatureStartAddress = 0000_0000_c000_0000
    }
```

- **2. BAR5 = Memory Mapped Register Space //This is Where GPU Registers are present**
```c
    BIOS						BAR5(d0a0_0000)
       ----Read BAR5 in uint32_t--->
       <---read(bn, dn, offset=0x24, &dword)---
 uint64 registerBaseAddress = d0a0_0000 & 0xffff_fff0;	      //0000_0000_d0a0_0000

    if (BAR5 & 0x04){       //Check if 64 bit
       //does not go inside
    }
```

- **3. IO Base Address = BAR1 or BAR4 & 0000_fffe)**
```c
    Program						BAR1(000a_0000)
    uint16_t wread
       ----Read BAR1 in uint16_t--->
       <---read(bn, dn, offset, &word)---
     if (word == 0)                                     BAR4(0000_3001)
       ----Read BAR4 in uint16_t--->
       <---read(bn, dn, offset, &word)---
     uint32_t ioBase = wread & 0000_fffe = 0000_3000
    }
```

- **4. Reading/Writing GPU Registers**
```c
   -> Read/Write on 
   //Map 1MB from start of registerBaseAddress to virtual Memory
   void* mmap(=0, length=131072(1MB), prot=READ|WRITE, flags=SHARED, fd='/dev/mem', offset=registerBaseAddress=d0a0_0000)
   logical_address = 0x7fff19239100
   
How we know 1MB is to be mapped?
   Program                          BAR1
           -----write ffff_ffff--->
	   <---Read BAR back------
    fff0_0000
    Last 20 bits are zeros. 2^20=1MB
           ---Restore value to BAR--->
	   
   //Reading dword(32 bytes) from offset=16 in GPU Register
   > readdword offset=16
   if (logical_address and offset < 1MB) {
     char *p = logical_address=0x7fff19239100 + offset=16;
   if (p != 0)
     cout << *((uint32 *)p);

   //Writing dword=4 at offset=16 in GPU Register
   > regwrite offset=16 value=4
   if (logical_address and offset < 1MB) {
     char *p = logical_address=0x7fff19239100 + offset16;
   if (p != 0)
     *((uint32 *)ptr) = (uint32)val=4;
```

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
