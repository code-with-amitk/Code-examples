- [PCI system Architecture](#ar)
- [How CPU discover PCI Device](#h)

<a name=ar></a>
### PCI system Architecture
- [PCI Devices](Terms/PCI_Device) can be plugged on PCI slots present on mother board and connected to CPU using PCI-Buses, buses are connected using [PCI-Bridges](Terms/PCI_Bridge).
- Layout of a PCI system is a tree where each bus is connected to an upper-layer bus, up to bus 0 at the root of the tree.
```c
   -------CPU-----------
  |           Registers |
  | CU        ========  |
  | ALU       ========  |
  |                     |         PCI-Bridge--------------------PCI-Bus-0--------     //PCI-Domain-B(0001)
   ---------------------              |
            |                         |
    ----------------system-Bus--------|---
                                      |
                                   PCI-Bridge--------------PCI-Bus-0--------            //PCI-Domain-A(0000)
                                      |                       |
                                                -------------------------------------
                                                |                                   |
                                       ---------Bus-2---                   -----------Bus-3-----------------
                                       |0            31|                   |0       |                    31|
                                     mouse                                     ---device7--------------
                                                                              | f0(4096)     f6        |
                                                                              |        0000:03:07.6.40 | //Domain:0,Bus:3,Device:7,Function:6,Register:40
                                                                              --------------------------
                                                                        
1 PCI Domain:     //Can have 65535 domains(or PCI Segment Groups)
=> 256 Buses
=> 32 PCI devices/Bus
=> 8 functions/Device.        //This is config address space mapped to system Memory at MMCFG-Space
=> Config Space Register/function
 - 256 (PCI)
 - 4096 (PCIe)
 
 MCFG Table Size=>  256(buses) x 32(Devices/Bus) x 8(functions/Device) x 4KB(Bytes/function) = 256MB
 mmap 256MB from MCFGTable-base address to process memory
 4096bytes Config Space per function
``` 

<a name=h></a>
# How CPU Discovers PCI Device?
- **MMIO(Memory Mapped IO)?** At system boot, kernel send/recv messages with each PCI-device & maps its [PCI Config Space](Terms/PCI_Config_Space) to the address space of the processor, this address space is called MCFG-SPACE(256 MB).
- When device driver accesses the PCI device, its memory and I/O regions have already been mapped into the processor’s address space.

<a name=pcs></a>
## PCI Config Space
- Every [PCI Device](Terms/PCI_Device) have PCI configuration space registers which are read/written after mapping to System Memory so that Device Driver/BIOS can read them.
- PCI Config space of System has PCI-devices(GPU,CPU,APU) which are connected to system. if we want to RW we need to map PCIConfigSpace then find particular device.

<a name=loc></a>
### Locating PCI Config Space
> RDP-PTR > RDSP-struct{xsdt-struct-address} > XSDT-struct{64bit-mcfg-struct-address} > MCFG-struct{contains MCFG_BaseAddress} > Store Mapping to PCIConfig Space



**Steps**
  - *1.* Search `RSDP Structure` in Physical Memory 
    - Start searching string **RSD PTR** from address `0xe0000=917504` till 1 MB. **RDP PTR** is 1st element of RSDP Structure. RSDP structure may not be page aligned ie it may not fall on 4096 bytes(page size=4k) start address. It may be inside page as well.
    - Once `RDP PTR` string is located, Read `36 bytes` this is RDSP Structure.
    - Read `uint64 xsdtAddress` and go to xsdt-table
  - *2.* Parsing `PointerToOtherSDT[] or Description Headers` array present at end of XSDT table to find `MCFGTable` base address.
    - `PointerToOtherSDT` is array of uint64_t ie 64 bit length physical Addresses.
    - 2nd field Length of ACPISDTHeader is complete length ie ACPISDTHeader + Description headers.
    - Read ACPISDTHeader > Read 2nd field Length.
    - Number of Description Headers n = (TotalLength(2nd field) - ACPISDTHeaderLength(36 bytes) )/ 8
    - Allocate array of storing Description headers `uint64_t PointerToOtherSDT[n]`. These are physical addresses.
    - `mmap()` each Physical address to virtual space, if (1st 4 bytes == MCFG) this is MCFGTable.
      - Read `ACPISDTHeader + 8` then Array of PCI-Domains is present.
  - *3. Parsing PCI Domains*
      - Read *Domain0 Base Address* at offset 44 from start. This is starting of PCI Config Space.
      - Read *StartPCIBusNo* at offset 45 from start. This is starting bus number present in this PCI Domain.
      - Read *EndPCIBusNo* at offset 46 from start. This is end Bus number in this PCI domain.
        - Example: Ubuntu20.17 has StartPCIBusNo=0, EndPCIBusNo=63. This means only 63 buses.
      - Store PCI Space mapping all buses(default=256).
```c
  struct PCIInfo{
    uint64_t mappedAddress;       //Virtual address of mapped region
    uint64_t mappedAddressSize;   //size of mapped region
    uint8_t *MMBase;              //char* to Mapped Virtual address
  };
  vector<PCIInfo> vec_PCIInfo;
  
  //0x100000 = 1 MB = 1048576 = 32 x 8 x 4096 //Memory Space needed by 1 Bus
  
  for ( int i = StartPCIBusNo; i <= EndPCIBusNo; ++i) {
    PCIInfo test;
    mmap ( "Domain0 Base Address" + i * 0x100000, 0x100000, &test.mappedAddress, &test.mappedAddressSize, "/dev/mem fd");
    test.MMBase = (char*) test.mappedAddress;
    vec_PCIInfo [i] = test;
  }
```
- **Overall Steps**
> RDP-PTR -> RDSP-struct{xsdt-struct-address} -> XSDT-struct{64bit-mcfg-struct-address} -> MCFG-struct{contains MCFG_BaseAddress} -> Store Mapping to PCIConfig Space -> 


### B. Structures Tables in System Memory

|Table|Why|
|---|---|
|1. [RDSP(Root System Description Pointer)/ACPI Structure (36 bytes)](https://wiki.osdev.org/RSDP)|<ul><li>To reach PCI Config Space of CPU and find PCI devices</li></ul> <ul><li>RSDP Table->XSDT Table->MCFG Table (contains MCFGBase)->PCI Config Space starts from MCFGBase</li></ul>|
|2. [SDT(System Description Table)](https://wiki.osdev.org/XSDT)|<ul><li>Generic XSDT Table.(Described Below)</li></ul><ul><li>sizeof(ACPISDTHeader) = 36 bytes</li></ul>|
|3. [MCFG Table (60bytes)](https://wiki.osdev.org/PCI_Express)|<ul><li>Contains `unsigned long long MCFGBase` which is Start Address of PCI Config Space|

### C. Table Descriptions
- **SDT(System Description Table)**
  - There are many kinds of SDT. All the SDT may be split into two parts. 
    - **1. header** which is common to all the SDT 
    - **2. Data** which is different for each table.
  - Types of SDT:
    - **1. SRAT/System Resource Affinity Table (SRAT)**
    - [Many other](https://wiki.osdev.org/XSDT)
    - **2. XSDT/Extended System Descriptor Table(Size=92 bytes)**
      - Validating XSDT: sum all the bytes in the table and compare the result to 0.
```c
bool doChecksum(ACPISDTHeader *tableHeader){    //Validating xsdt
    unsigned char sum = 0;
    for (int i = 0; i < tableHeader->Length; i++){
        sum += ((char *) tableHeader)[i];
    }
    return sum == 0;
}
```
