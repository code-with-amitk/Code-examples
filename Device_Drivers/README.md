## Device Driver
- **What?** Computer program that communicates with device attached to computer. These vary from OS to OS.
  - *LINUX Device Driver*
```c
  <----------------------user space----------------->        <--kernel space->
  Application [open/read/write/close]  <>  Device-File   <>   Device-Driver     <>     Physical-Device(Terminal, Speakers, HD, keyboard, Tape, Memory)
  
User Application                     User Space                  Device Driver{Kernel Space}
fd = open("/dev/pkp", 0);           Device File                 struct file_operations fops{
char msg[100];                      mknod 125 0 /dev/pkp         .read = device_read, .write=device_write, .ioctl=device_ioctl
ioctl(fd, IOCTL_GET_MSG, msg);                                  }
                                                                device_ioctl(....){
                                                                  switch(ioctl_num){
                                                                     case IOCTL_GET_MSG:----------
                                                                     case IOCTL_SET_MSG:----------
                                                                   }
 ```
  - *Window's Device Driver*
```c
  Application > Window's OS >Driver-1(Filter Driver) > Driver-2(Filter Driver) > Driver-3(Function Driver) > Physical Device
```
- **Types Of Device Drivers?**

||Character|Block|Network|
|---|---|---|---|
|Read/Write|1 Character at a time|Blocks(512 bytes or more)|Byte Stream|
|Speed|Fast|Slow|Depends on N/W|
|Example|Keyboard,printers|Disk Drivers|NIC|
 
 
