## ROM 
- **What?** Non-volatile memory used to boot up the system. When computer starts its reads BIOS(program to start PC) from ROM and other information, loads on RAM and starts executing.
- Old ROM cannot be erased/flashed/reprogrammed.
- **SPIROM?** AMD's SPIROM contains these: PSP bootloader, MP1, MP2, MPM, VBL, ABL, IFWI(Integrated Firmware Image). IFWI initializes Memory. HW can access GPU memory. Provides security. 
- **EEPROM(Electronically erasable programmable)?** These ROMs can be electrically erased/re-programmed, but possible only certain number of times.
- **GPU-ROM?** ROM on GPU.
```c
  Structure:    <VGA-VBIOS(maxSize=64kb)>         <x86-UEFI-GOP-Driver> <ARM-URFI-GOP-Driver>
               offset=0    |-PSP directory table   0x10000              0x20000
                           |-SOFTUSE chain
```                                
