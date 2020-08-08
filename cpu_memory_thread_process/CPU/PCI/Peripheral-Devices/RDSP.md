## RDSP(Root System Description Pointer)

**What is ACPI?**
- See cpu_memory_thread_process/CPU/ACPI

## RDSP Structures
### A. struct RDSPDescriptor          //ACPI Version 1.0

| Type-> | char | uint8 | char | uint8 | uint32 |
| --- | --- | --- | --- | --- | --- |
| Feild -> | signature`[8]` | checksum | OEMID`[16]` | Revision | RsdtAddress |

### B. struct RSDPDescriptor20       //ACPI Version 2.0

| Type-> | struct RDSPDescriptor | uint32 | uint64 | uint8 | uint8 |
| --- | --- | --- | --- | --- | --- |
| Feild -> | firstPart | Length | XsdtAddress | ExtendedChecksum | reserved`[3]` |

## Locating RDSP
- RDSP is located at 0xE0000(917504) & length = 1 MB

  
