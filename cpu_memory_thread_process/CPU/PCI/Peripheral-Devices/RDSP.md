## A. Structures Tables in System Memory

|Table|Why|
|---|---|
|1. [RDSP(Root System Description Pointer)/ACPI Structure (36 bytes)](https://wiki.osdev.org/RSDP)|<ul><li>To reach PCI Config Space of CPU and find PCI devices</li></ul> <ul><li>RSDP Table->XSDT Table->MCFG Table (contains MCFGBase)->PCI Config Space starts from MCFGBase</li></ul>|
|2. [SDT(System Description Table)](https://wiki.osdev.org/XSDT)|<ul><li>Generic XSDT Table.(Described Below)</li></ul>|
|3. [MCFG Table (60bytes)](https://wiki.osdev.org/PCI_Express)|<ul><li>Contains `unsigned long long MCFGBase` which is Start Address of PCI Config Space|

![ImgURL](https://i.ibb.co/QNVLK4z/mcfg-xsdt-rdsp.png)

## B. Locating MCFGTable using RDSP struct
- **Steps**
  - Seach `RSDP Structure` in Physical Memory 
    - Start searching string **RDP PTR** from address `0xe0000=917504` till 1 MB. **RDP PTR** is 1st element of RSDP Structure.
    - Once `RDP PTR` string is located, Read `36 bytes` this is RDSP Structure.
    - Read `uint64 xsdtAddress` and go to xsdt-table
  - Read `128 bytes` from each 8 Byte-Physical_Addresses present at end of `XSDT Table`.
    - if content at this 60 byte starts with `MCFG`, This is MCFG table.
    - Read **MCFG_BaseAddress** at offset 44 from start.
    - Read **StartPCIBusNo** at offset 45 from start.
    - Read **EndPCIBusNo** at offset 46 from start.
  - Store PCI Space mapping of 256 buses locally. struct{unint64 mappedAddress, uint64 mappedRegion, char `*MMBase`};
    - Iterate in for loop read contents from MCFGBase and store in structure.
      - mappedAddress = Physical Address of PCI Config Space
      - mappedRegion = Sizeof memory area to accessed using mappedAddress
- **Overall Steps**
> RDP-PTR -> RDSP-struct{xsdt-struct-address} -> XSDT-struct{64bit-mcfg-struct-address} -> MCFG-struct{contains MCFG_BaseAddress} -> Store Mapping to PCIConfig Space -> 

## C. Table Descriptions
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
