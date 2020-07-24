# ROM(READ ONLY MEMORY)?
- **What** ROM is non-volatile memory whose data cannot be modified once manufacturer has written it.

# EEPROM(Erasable programmable ROM)
- **What** These can be electrically erased and re-programmed, but possible only certain number of times.

# BIOS(Basic I/O System)/ (Also called ROM BIOS)
- **What** 
  - This is firmware used to perform hardware initialization during the booting process (power-on startup)
  - This comes pre-installed on a PC's, and is 1st software to run when powered on.
  - *Unified Extensible Firmware Interface (UEFI)* is a successor of legacy BIOS, which aims to address its technical shortcomings.
- **Sequence of Steps** When computer is turned on these are sequence of tasks performed by BIOS:
  1. Check the CMOS Setup.
  2. Load interrupt handlers and device drivers   
  3. Initialize registers and power management    
  4. Perform the power-on self-test (POST): Test computer hardware insuring hardware is properly functioning before starting process of loading Operating System.
  5. Display system settings    
  6. Determine which devices are bootable    
  7. Initiate bootloader which loads operating system.
- **Where BIOS is stored**
  - **Originally** BIOS firmware was stored in a ROM chip on the PC motherboard.
  - **Present Day** BIOS contents are stored on flash memory so it can be rewritten without removing the chip from the motherboard.  
    
# VBIOS(Video BIOS)
- (BIOS) of a graphics card or the integrated graphics controller in a computer.
- provides a set of video-related functions that are used by programs to access the video hardware.

# SMBIOS(System Management BIOS)
- **What** Data structures (and access methods) for reading management information produced by the BIOS.
- **Why** This eliminates the need for the operating system to probe hardware directly to discover what devices are present in the computer
    
# C. Boot loader/Bootstrap loader
- Loads Operating system.
- Popular boot loaders: GRUB, LILO, Loadlin, SYSLINUX
