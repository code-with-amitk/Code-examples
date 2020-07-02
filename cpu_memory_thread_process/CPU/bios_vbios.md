## ROM/BIOS(Basic I/O System)
  - This is ROM chip located on all motherboard. 
  - When computer is turned on these are sequence of tasks performed by BIOS:
    a. Check the CMOS Setup.
    b. Load interrupt handlers and device drivers   
    c. Initialize registers and power management    
    d. Perform the power-on self-test (POST): Test computer hardware insuring hardware is properly functioning before starting process of loading Operating System.
    e. Display system settings    
    f. Determine which devices are bootable    
    g. Initiate the bootstrap sequence
    
## Boot loader/Bootstrap loader
  - Loads Operating system.
  - Popular boot loaders: GRUB, LILO, Loadlin, SYSLINUX
