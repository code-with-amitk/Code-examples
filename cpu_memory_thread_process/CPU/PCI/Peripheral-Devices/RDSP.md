## RDSP(Root System Description Pointer)
- **Why** 
  - From RSDP-Table we can reach PCI Config space of CPU and find PCI devices.RDSP structure contains address of XDST-Table(Extended RSDT table) or RDST-Table.

**What is ACPI?**
- See cpu_memory_thread_process/CPU/ACPI

## 1. RDSP Structures
#### A. struct RDSP          //ACPI Version 1.0

| Type-> | char | uint8 | char | uint8 | uint32 |
| --- | --- | --- | --- | --- | --- |
| Feild -> | signature`[8]` | checksum | OEMID`[16]` | Revision | RsdtAddress |

#### B. struct RSDP       //ACPI Version 2.0

| Type-> | struct RDSPDescriptor | uint32 | uint64 | uint8 | uint8 |
| --- | --- | --- | --- | --- | --- |
| Feild -> | firstPart | Length | XsdtAddress | ExtendedChecksum | reserved`[3]` |

#### C. [struct RSDP**36 bytes**      //ACPI Version 3.0](https://uefi.org/sites/default/files/resources/ACPI_6_3_final_Jan30.pdf)

| Type-> | char | uint8 | char | uint8 | uint32 | uint32 | uint64 | uint8 | uint8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Feild -> | signature`[8]`="RDP PTR\0" | checksum | OEMID`[16]` | Revision | RsdtAddress | length | xsdtAddress | extendedchecksum | reserved`[3]` |
| Description|RDP PTR\0| |Identifies OEM| |4 byte Physical Address of RSDT table|table length including header|8byte Physical address of xsdt table| | |

##### C1. XSDT/Extended System Descriptor Table(Size=92 bytes)

| Type-> | char | uint32 | uint8 | char | char | uint32 | char | uint32 | 8xNumberOfPhysicalAddresses |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Feild -> | signature`[4]`|length|revision|OEMID`[6]`|oemTableId`[8]`|revision|creatorId`[4]`|creatorRevision|Array-of-8Byte-Physical_Addresses-to-Description-Headers|

##### C2. MCFG Table

|Feild ->|signature`[4]`="MCFG"|length|revision|checksum|OEMID|OEMID-Rev|CreatorID|CreatorRev|Reseverd|List-of-Configuration-Space-Registers|
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

- **Configuration-Space-Registers**
  - This is list of Memory mapped configuration base address location structures.
  - Contains entry to each PCI Segment group present on system.


## 2. Locating RDSP
- **Steps**
  - Read `XSDTAddress` from `RSDP Structure` in Physical Memory 
    - Start searching string **RDP PTR** from address `0xe0000=917504` till 1 MB. **RDP PTR** is 1st element of RSDP Structure.
    - Once `RDP PTR` string is located, Read `36 bytes` this is RDSP Structure.
    - Read `uint64 xsdtAddress` and go to xsdt-table
  - Read `128 bytes` from each 8 Byte-Physical_Addresses present at end of `XSDT Table`.
    - if content at this 128 byte starts with `MCFG`, This is MCFG table.
- **Overall Steps**
> RDP-PTR -> RDSP-struct{xsdt-struct-address} -> XSDT-struct{64bit-mcfg-struct-address} -> MCFG-struct{Configuration-Space-Addresses-List} -> 
  


  
