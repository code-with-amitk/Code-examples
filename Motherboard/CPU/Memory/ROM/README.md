## ROM / Read Only Memory
- **What?** Nonvolatile memory ie does not lose its contents when the power is switched off. Can be electrically erased.
- **ROM Stores?** [BIOS](BIOS), PSP Bootloader, MP1, MP2, MPM, VBL, ABL, IFWI(Integrated Firmware Image).
- **SPIROM / SPI-ROM / [Serial Peripheral Interface](/Motherboard/CPU/Communication/Buses/SPI_Serial_Peripheral_Interface_Bus.md) ROM** ROM and SPIROM both are same. ROM access over [SPI Bus](/Motherboard/CPU/Communication/Buses/SPI_Serial_Peripheral_Interface_Bus.md) is called SPIROM.
- **ROM Chip?** ROM is present on ROM Chip on motherboard. Motherboard can have 1 or more ROM chips.

### Types of ROM
#### 1. EEPROM(Electronically erasable programmable)
  - These ROMs can be electrically erased/re-programmed, but possible only certain number of times.
#### 2. GPU-ROM
  - ROM on GPU.
```c
  Structure:    <VGA-VBIOS(maxSize=64kb)>         <x86-UEFI-GOP-Driver> <ARM-URFI-GOP-Driver>
               offset=0    |-PSP directory table   0x10000              0x20000
                           |-SOFTUSE chain
```  
