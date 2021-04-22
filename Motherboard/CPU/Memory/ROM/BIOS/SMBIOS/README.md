## SMBIOS(System Management BIOS)
- **What** Data structures (and access methods) for reading management information produced by the BIOS.
- **Why** This eliminates the need for the operating system to probe hardware directly to discover what devices are present in the computer
- **SMBIOS Structure Type**

| Type | Description |
| --- | --- |
| 0 | BIOS Information |
| 1 | System Information |
| 2 | BaseBoard information |
| 9 | System slots |
| 16 | System memory array |
| 17 | Memory device |
| 32 | system boot information |

-  **BIOS vs SMBIOS**

| | BIOS | SMBIOS |
| --- | --- | --- |
| What | Firmware in ROM chip used for system bootup | DS for reading management information produced by BIOS |
