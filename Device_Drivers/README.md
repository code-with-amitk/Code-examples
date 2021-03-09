### Device Driver
- **What?** Computer program that communicates with device attached to PC using [device file](Terms/Device_File_Major_MinorNo.md). These vary from OS to OS.
  - *LINUX Device Driver*
```c
  <----------------------user space----------------->        <--kernel space->
  Application [open/read/write/close]  <>  Device-File   <>   Device-Driver     <>     Physical-Device(Terminal, Speakers, HD, keyboard, Tape, Memory)
```
<img src=device-driver.jpg width=1000 />

- **Terms**
  - [Device File, Major, Minor Number](Terms/Device_File_Major_MinorNo.md)
  - [IOCTL](Terms/IOCTL.md)
