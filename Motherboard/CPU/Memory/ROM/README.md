## ROM / Read Only Memory
- Nonvolatile memory ie does not lose its contents when the power is switched off.
- ROM Stores: BIOS(program to start PC), other information

### Types of ROM
- **SPIROM?** AMD's SPIROM contains these: PSP bootloader, MP1, MP2, MPM, VBL, ABL, IFWI(Integrated Firmware Image). IFWI initializes Memory. HW can access GPU memory. Provides security. 
- **EEPROM(Electronically erasable programmable)?** These ROMs can be electrically erased/re-programmed, but possible only certain number of times.
- **GPU-ROM?** ROM on GPU.
```c
  Structure:    <VGA-VBIOS(maxSize=64kb)>         <x86-UEFI-GOP-Driver> <ARM-URFI-GOP-Driver>
               offset=0    |-PSP directory table   0x10000              0x20000
                           |-SOFTUSE chain
```  
