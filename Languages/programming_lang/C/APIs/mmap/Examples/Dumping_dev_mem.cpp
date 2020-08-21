## Reading from /dev/mem
- **What is /dev/mem**
  - This is a character device file that is an image of the main/Phsical memory of the computer.
  - ie when we read */dev/mem* we are reading/writing to System's main Memory!!
  - But many linux distributions have stopped providing /dev/mem due to security concerns.
- **Why reading from System memory**
  - System's startup(BIOS), PCI Configuration Space(ACPI,XSDT,MCFG tables) are stored on physical memory.
  - if process want to read PCI config space it should read /dev/mem.

### Code
- Tasks
  - Maps (131072 bytes) starting at (offset=917504) from "/dev/mem" to memory `*ptr`
  - Dump and print contents of `ptr`

```c++
code
```
