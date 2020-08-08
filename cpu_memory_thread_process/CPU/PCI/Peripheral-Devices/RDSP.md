## RDSP(Root System Description Pointer)

**What is ACPI?**
- See cpu_memory_thread_process/CPU/ACPI

### struct RDSPDescriptor          //ACPI Version 1.0

| Type-> | char | uint8 | char | uint8 | uint32 |
| --- | --- | --- | --- | --- | --- |
| Feild -> | signature`[8]` | checksum | OEMID`[16]` | Revision | RsdtAddress |

### struct RSDPDescriptor20       //ACPI Version 2.0

| Type-> | struct RDSPDescriptor | uint32 | uint64 | uint8 | uint8 |
| --- | --- | --- | --- | --- |
| Feild -> | firstPart | Length | XsdtAddress | ExtendedChecksum | reserved`[3]` |
