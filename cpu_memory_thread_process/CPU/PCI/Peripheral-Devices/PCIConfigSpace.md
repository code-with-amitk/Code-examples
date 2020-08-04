**1st See (What_is_Peripheral-Device_PCB.md)**

# A. PCI Config Space (PCI = 256 bytes, PCIe = 4096 byte)
> Also called Configuration Register/PCI Config Header 
- **What** 
	- Registers present on PCI devices having device information, this is mapped to Memory location(maybe virtual).

- **How to access Config Space** OS provides APIs to access config space to device drivers.
- **About**
  - Every PCI manufacturer assigns values to these RO registers(vendor-id, device-id, class). Driver uses these to look for device.
  - 1st 64 bytes of configuration space are standardized; the remainder are available for vendor-defined purposes
```
  <====256 byte Configuration Register====>
  <---64 bytes----><------208 bytes------>
    standard        vendor defined
```

## A1. Feilds of Config Register
```
 |vendor-id(2byte) | Device ID(2) | Command Reg(2) | Status Reg(2) | class code(3) | CacheLine(1)| LatencyTimer(1)| HeaderType(1)| BIST(1)|
 |BaseAddress0(4bytes) | BaseAddress1(4) | BaseAddress2(4) | BaseAddress3(4) | 
 |BaseAddress4(4bytes) | BaseAddress5(4) | Card Bus CIS Pointer(4) | SubSystem Vendor ID(2) | SubSystem Device ID(2) | 
 |Expansion ROM Base Address(4 bytes) | Reserved(8) | IRQLine(1) | IRQPin(1) | Min_Gnt(1) | Max_Gnt(1) |
```

|field->|vendor-id|Device-id|command-register|status-register|..|HeaderType-register|CacheLine-register|BaseAddressRegister|
| --- | --- | --- | --- | --- | --- | ---- | --- | --- |
|size(bytes)|2|2|2|2| |1|1|56|

- PCI ID/Signature: These 2 field identify the device.
  - vendor-id(mandatory): assigned by the vendor.
  - device-id(mandatory):
- Status register: Report which features are supported  
- Header Type: different layouts of remaining 48 bytes
  - Type-0: For endpoints
  - Type-1: For Root Complex, switches, and bridges
- Cache Line register: Must be programmed before the device can do memory-write-and-invalidate transaction
- BAR: See below
- subSystem Vendor ID,SubSystem Device ID(2 byte): For further identification of a device
- Required Registers: vendorID, DeviceID, Command Reg, Status Reg, Revision ID, Header Type, Reserved.      //All other are optional.

### BAR(Base Address Register) {56 bytes}
- **What** 
  - Different PCI devices have different requirements for PCI I/O and Memory.
  - This will tell CPU how much space this PCI device requires for I/O and PCI memory.
- **Types of PCI BARs**
  - *1. Register holding base address of PCI Memory space* 
    - Indicate on which address space this Device register will be present
  - *2. Register holding base address of PCI I/O space* 
    - Indicate on which address space this Device register will be present    

|content->|base-address-of-memory-space|...|0|
| --- | --- | --- | --- |
|index->|31 |...|0|

|content->|base-address-of-I/O-space|...|1|
| --- | --- | --- | --- |
|index->|31 |...|0|


## A2. Reading from PCI(256 bytes) Config Space Registers
> Note this is only for PCI or for 1st 256 bytes of PCIe
- **Message format for reading PCI address space**
	- Register Address(8 bit) 2<sup>8</sup> = 256 bytes

|Bits->|31 ... 24| 23 ... 16 | 15 ... 8 | 7 .. 0 |
| --- | --- | --- | --- | --- |
| | 1000 0000 | Bus number | Device(5bit) Function(3bit) | Register-Address| 

- For Example, we want to read from PCI-Bus=3, PCI-Device=2, Function=5, Register=40		{3:2:5:40}

|Bits->|31 ... 24| 23 ... 16 | 15 ... 8| 7 .. 0 |
| --- | --- | --- | --- | --- |
| 1000=8 0000=0 | Bus number = 03 | Device(0010) Function(101) = 10101 = 15 | 40 | 
| 80 | 03 | 15 | 40 | 

![ImgURL](https://i.ibb.co/xzwy2hY/PCI-READ.png)
```
//Read from PCI-Bus=3, PCI-Device=2, Function=5, Register=40

																Index-Register [0xCF8]		Data-Register[0xCFC]
			-----------write 80031540------------>|							|
	<-------------Read information--------------------------|
```

## A3. Reading from PCIe(4096 bytes) Config Space Registers
- **MMCFG(Memory Mapped Config)** 
 - This is new mechanism for reading beyond 256 bytes, because 256 bytes(PCI), PCIe provides 4096 bytes address space.
- For 1 PCI Domain
  - 256 PCI buses
  - 32 PCI devices/Bus
  - 8 functions/Device
  - 4096 bytes config space/Function
	  - Total = 256 x 32 x 8 x 4096 = 256 MB. Means 1 MB for each bus.
- **MMCFG Space**
  - This is 256 MB space reserved at start of MMIO-Low for addressing 4k registers in PCIe.
  - Every Bus is assigned 1 MB Space.

![ImgURL](https://i.ibb.co/LSnZW04/mmcfg-space.png)

- **Message format for reading PCIe address space**
	- Register Address(12 bit) 2<sup>12</sup> = 4096 bytes
	
|Bits->|31 ... 24| 23 ... 16 | 15 ... 8| 12 .. 0 |
| --- | --- | --- | --- | --- |
| | Base-Address-of-MMCFG-Space | Bus number | Device(5bit) Function(3bit) | Register-Address| 

- For Example, we want to read from PCI-Bus=3, PCI-Device=2, Function=5, Register=40		{3:2:5:40}

|Bits->|31 ... 24| 23 ... 16 | 15 ... 8| 12 .. 0 |
| --- | --- | --- | --- | --- |
| if 2G=0x8000-0000 | Bus number = 03 | Device(0010) Function(101) = 10101 = 15 | 040 | 
| 0x8 | 03 | 15 | 40 | 

	- Any access to MMCFG-Space is treated as config transaction.
	- Now system will use this 256 MB for access PCI config space on PCIe.
		- Lowest 1 MB is used by PCI-Bus-0.
		- Next 1 MB is used by PCI-Bus-1.

# B. How to Know Exact starting address of MMCFG-Space
- ACPI-Table

# C. Commands to see PCI devices:
```
        # lspci                     //lists of devices are being used
        # tree /sys/bus/pci/devices/
            0000:00:14.0 -> ../../../devices/pci0000:00/0000:00:14.0
        #$ tree /sys/bus/pci/devices/0000:00:10.0
            |-- class
            |-- config        //allows raw PCI information to be read from device.
            |-- detach_state
            |-- device
            |-- irq        //current IRQ assigned to this PCI device
            |-- power
            |`-- state
            |-- resource    //shows the current memory resources allocated by this device
            |-- subsystem_device
            |-- subsystem_vendor
            `-- vendor
        # cat /proc/bus/pci/devices| cut -f1
```
