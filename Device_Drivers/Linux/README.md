- [Device Drivers](#dd)
- [How userspace application talks to Physical Device](#how)
- [Terms](#t)
  - [Device File, Major, Minor number](#df)
  - [ioctl](#ioctl)

## Device Driver
- Computer program that communicates with device attached to PC using [device file](#df). These vary from OS to OS.
- **Types of DD**
```c
	         |        Character	 |          Block	     |    Network
-----------------|-----------------------|---------------------------|------------      
Read/Write       | 1 Character at a time | Blocks(512 bytes or more) | Byte Stream
Speed	         |         Fast          |        Slow	             | Depends on N/W
Example	         | Keyboard,printers	 |         Disk Drivers      |	NIC
```

<a name=how></a>
## How userspace application talks to Physical Device
- **Parts of IO Device:** Controller(embedded chip on device which accepts commands from OS), device itself
- Device driver talks to device controller using register present on the controller. 
  - Example: Disk controller have registers for specifying the disk address, memory address, sector count, and direction (read or write).
```c
Physical Devices: Terminal, Speakers, HD, keyboard, Tapes, Memory

<---------------------user space---------------->     <kernel space>      <----Physical Device---->
Application[open/read/write/close] <> Device-File  <>  Device-Driver  <>  Controller--ActualDevice
                                                                          (registers)
```
<img src=device-driver.jpg width=1000 />

- **Terms**
  - [Device File, Major, Minor Number](Terms/Device_File_Major_MinorNo.md)
  - [IOCTL](Terms/IOCTL.md)

<a name=t></a>
## Terms
<a name=df></a>
### Device File / Major No / Minor No
File used for communication b/w user space & kernel space. File is located in /dev directory.
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

<a name=ioctl></a>
### IOCTL((sockfd, command, data_arguments)
- It is command to do any of following operations on file descriptor:
  - Make sockfd non-blocking
  - Pass messages to device driver. Example
```c
  User Application                   User Space                  Device Driver{Kernel Space}
fd = open("/dev/pkp", 0);             Device File                 struct file_operations fops{
char msg[100];                       mknod 125 0 /dev/pkp            .read = device_read,;
ioctl(fd, IOCTL_GET_MSG, msg);                                        .write=device_write,
                                                                      .ioctl=device_ioctl
                                                                   }
                                                                  device_ioctl(....){
                                                                   switch(ioctl_num){
                                                                    case IOCTL_GET_MSG:--
                                                                    case IOCTL_SET_MSG:--
                                                                  }
```


