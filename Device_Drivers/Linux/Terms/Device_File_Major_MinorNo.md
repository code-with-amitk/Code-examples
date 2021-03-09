## Device File / Major No / Minor No
- **What?** File used for communication b/w user space & kernel space. File is located in /dev directory. 
- **Writing/Reading Device Files?**  
  - To write to hard disk = Write to File
  - Read from Keyboard = Read from File
```c
#  cd /dev 
# ls -l     //Devices attached to your PC
  crw--w---- 1 root  tty    4, 0    tty0      //Character Device.    4-Major No    0-Minor No
  brw-rw----. 1 root disk   8, 1    sda1      //Block device.        8-Major No    1-Minor No
```
- **MAJOR NO:** Represents the device driver
- **MINOR NO:** Represents the device file
```c
    user-appl-1 ----- [Dev File 1] Minor No    -----|
    user-appl-2 ----- [Dev File 2] Minor No    -----|-  Major No  [Device Driver]
    user-appl-3 ----- [Dev File 3] Minor No    -----|
```
- **CREATING DF?** mknod command creates a (Device File or Named pipe). 
```c
# mknod   /dev/<file-name>  c 125 1        //Create a character device file having Major-no(125) & Minor-no(1)
```
