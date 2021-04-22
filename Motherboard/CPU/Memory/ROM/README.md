## ROM / Read Only Memory
- **What?** Nonvolatile memory ie does not lose its contents when the power is switched off. Can be electrically erased.
- **ROM Stores?** [BIOS](BIOS), other information
- **ROM Chip?** ROM is present on ROM Chip on motherboard. Motherboard can have 1 or more ROM chips.

### Types of ROM
#### 1. SPIROM
  - AMD's SPIROM contains these: PSP bootloader, MP1, MP2, MPM, VBL, ABL, IFWI(Integrated Firmware Image). IFWI initializes Memory. HW can access GPU memory. Provides security. 
#### 2. EEPROM(Electronically erasable programmable)
  - These ROMs can be electrically erased/re-programmed, but possible only certain number of times.
#### 3. GPU-ROM
  - ROM on GPU.
```c
  Structure:    <VGA-VBIOS(maxSize=64kb)>         <x86-UEFI-GOP-Driver> <ARM-URFI-GOP-Driver>
               offset=0    |-PSP directory table   0x10000              0x20000
                           |-SOFTUSE chain
```  
