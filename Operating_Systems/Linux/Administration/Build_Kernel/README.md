## Build kernel from source
- *1.* Download source tar.gz from [kernel.org](https://www.kernel.org/). wget
- *2.* Install dependent packages.
  - fakeroot: tool to make fakeroot env
  - build-essential: installing c,c++,gcc,g++
  - ncurses-dev: text based terminal
  - xz-utils: compression, decompression
  - bc: basic calculator. Mathematical scriting language
  - flex: Fast lexical analyzer generator. lexical analyzer to convert characters to tokens
  - libelf-dev: elf file manager
  - bison: gnu convertor for converting grammer description to C program.
```c
# apt install fakeroot build-essential ncurses-dec xz-utils libssl-dev bc flex libelf-dev bison -y
```
- *3.* Copy existing kernel boot config file to source code folder
```c
# vim /boot/config-$(uname -r)                  //Huge file, 10000+ lines
CONFIG_CC_IS_GCC = y                                            //take gcc
CONFIG_VERSION_SIGNATURE = "Ubuntu 5.4.0-26.30-generic 5.4.30"  //Kernel version
CONFIG_IRQ_DOMAIN = y                                           //IRQ enable

# cp /boot/config-$(uname -r) .config
```
- *4.* Make changes to config file copied in step-3. Configure firmware, file system, network, memory settings. This will present a ncurses menu.
```c
# make menuconfig
xqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
x General setup ->                                     x 
x[x] 64-bit kernel                                     x
x  [*] DMA memory allocation support                   x
x  [*] Enable MPS Table                                x
x[x] Power management and ACPI options                 x
x  ....                                                x
x  [*] Networking Support                              x  
xqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq  
- *5. Build*
```c
# make
```
- *6.* Make modules and install modules.
```c
# make modules_install
```
- *7.(OPTIONAL STEP)* Update bootloader. "make install does this step automatically, but we can also do".
  - *7a.* Update initramfs.
```c
# update-initramfs -c -k <kernel-version>
```
  - *7b.* Update grub bootloader
```c
# update-grub  
```
- *8.* Install kernel
```c
# make install
```
- *9.* Reboot and verify kernel version
```c
# uname -mrs
```
