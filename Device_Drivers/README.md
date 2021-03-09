## Device Driver
- **What?** Computer program that communicates with device attached to computer. These vary from OS to OS.
```c
                           <-------user space----------------->                     <--kernel space->
LINUX DEVICE DRIVER      Application [open/read/write/close] <>     Device-File     <> Device-Driver     <>     Physical-Device(Terminal, Speakers, HD, keyboard, Tape, Memory)
WINDOWS DEVICE DRIVER    Application > Window's OS >Driver-1(Filter Driver) > Driver-2(Filter Driver) > Driver-3(Function Driver) > Physical Device
 ```
- **Types Of Device Drivers?**

||Character|Block|Network|
|---|---|---|---|
|Read/Write|1 Character at a time|Blocks(512 bytes or more)|Byte Stream|
|Speed|Fast|Slow|Depends on N/W|
|Example|Keyboard,printers|Disk Drivers|NIC|
 
 
