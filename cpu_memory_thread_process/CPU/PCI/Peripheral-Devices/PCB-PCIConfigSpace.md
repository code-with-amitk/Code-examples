# A. Peripheral Circuit Board(PCB)?
- **What** Boards of peripheral devices. PCB has 8 pins out of which 4 are for interrupts. Eg: dvr, printer, external modem, game console etc.  
- **Response PCI provides to CPU?** PCB provides only these 3 addresses to CPU: 
  - Configuration Registers (also called **config space**	{Section-C})
  - memory locations
  - I/O ports
 
 # B. PCI Device Addresses
 - **Remember PCI Domain** PCI specifications allowed creation of PCI domains. Each domain can have upto 
	- **256 PCI buses** 
		- Each bus can connect **32 PCI devices**.
			- Each device can have **8 functions**.
				- For Each Function have **256 bytes(PCI) or 4096 bytes(PCIe)** config space.
- **PCI Bus size** 8 bit. 2<sup>8</sup> = 256     or 12 bit for 4096.
- Device on PCI Bus can be represented by using 2 byte address with either of these:
  - a. (B:D) = (Bus-number(1byte) : device+function-number(1byte))    OR
  - b. (B:D:F) = (1-byte:Bus-number  : device : function)    OR
  - c. (DO:B:D:F) = (Domain(16 bit) : Bus-number(8 bit)  : device(5 bit) : function(5 bit) )   
- Commands to see PCI devices:
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
 
# C. PCI Config Space/Configuration Register/PCI Config Header (PCI = 256 bytes, PCIe = 4096 byte)
- **What** Registers present on PCI devices having device information, this is mapped to Memory location(maybe virtual).
- **How to access Config Space** OS provides APIs to access config space to device drivers.
  - 5 bit = Device No.    3 bit = Function no
- **About**
  - Every PCI manufacturer assigns values to these RO registers(vendor-id, device-id, class). Driver uses these to look for device.
  - 1st 64 bytes of configuration space are standardized; the remainder are available for vendor-defined purposes
```
  <====256 byte Configuration Register====>
  <---64 bytes----><------208 bytes------>
    standard        vendor defined
```

### Feilds of Config Register
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


## C1. Steps of Reading from PCI(256 bytes) Address Space
> Note this is only for PCI or for 1st 256 bytes of PCIe
- Message format for reading PCI address space

|Bits->|31 ... 24| 23 ... 16 | 15 ... 8| 7 .. 0 |
| --- | --- | --- | --- | --- |
| | 1000 0000 | Bus number | Device(5bit) Function(3bit) | Register-Address| 

- For Example, we want to read from PCI-Bus=3, PCI-Device=2, Function=5, Register=40		{3:2:5:40}

|Bits->|31 ... 24| 23 ... 16 | 15 ... 8| 7 .. 0 |
| --- | --- | --- | --- | --- |
| 1000=8 0000=0 | Bus number = 03 | Device(0010) Function(101) = 10101 = 15 | 40 | 
| 80 | 03 | 15 | 40 | 

```
//Read from PCI-Bus=3, PCI-Device=2, Function=5, Register=40

																Index-Register [0xCF8]		Data-Register[0xCFC]
			-----------write 80031540------------>|							|
	<-------------Read information--------------------------|
```

## C2. Steps of Reading from PCIe(4096 bytes) Address Space
- **MMCFG(Memory Mapped Config)** This is new mechanism for reading beyond 256 bytes, because 256 bytes was for PCI, PCIe provides 4096 bytes address space.
- **Remember** For PCIe
	- **256 PCI buses** 
		- Each bus can connect **32 PCI devices**.
			- Each device can have **8 functions**.
				- For Each Function have **4096 bytes(PCI)** config space.
	- Total = 256 x 32 x 8 x 4096 = 256 MB. Means 1 MB for each bus.
- Remember the diagram of system memory(4GB), BIOS will take 256 MB as MMCFG Space just below MMIO-Low memory.
	- Any access to MMCFG-Space is treated as config transaction.
	- Now system will use this 256 MB for access PCI config space on PCIe.
		- Lowest 1 MB is used by PCI-Bus-0.
		- Next 1 MB is used by PCI-Bus-1.
```	
														  					  	<---MMIO-Low-->
	|			|	 		|SMMTSeg|	(MMCFG-Space)256MB	|							|
	0		 1 MB						2G	 						      						  4G
```
	
