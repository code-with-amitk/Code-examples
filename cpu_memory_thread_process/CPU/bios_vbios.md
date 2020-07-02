## ROM/BIOS(Basic I/O System)
  - This is ROM chip located on all motherboard. 
  - When computer is turned on these are sequence of tasks performed by BIOS:
    1. Check the CMOS Setup.
    2. Load interrupt handlers and device drivers   
    3. Initialize registers and power management    
    4. Perform the power-on self-test (POST): Test computer hardware insuring hardware is properly functioning before starting process of loading Operating System.
    5. Display system settings    
    6. Determine which devices are bootable    
    7. Initiate the bootstrap sequence
    
## VBIOS(Video BIOS)
  - **What** 
    - (BIOS) of a graphics card or the integrated graphics controller in a computer.
    - provides a set of video-related functions that are used by programs to access the video hardware.
    
## Boot loader/Bootstrap loader
  - Loads Operating system.
  - Popular boot loaders: GRUB, LILO, Loadlin, SYSLINUX
