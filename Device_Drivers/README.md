## Device Driver
- **What?** Computer program that communicates with device attached to computer. These vary from OS to OS.
  - *LINUX Device Driver*
```c
  <----------------------user space----------------->        <--kernel space->
  Application [open/read/write/close]  <>  Device-File   <>   Device-Driver     <>     Physical-Device(Terminal, Speakers, HD, keyboard, Tape, Memory)
```
<img src=device-driver.jpg width=700 />

  - *Window's Device Driver*
```c
  Application > Window's OS >Driver-1(Filter Driver) > Driver-2(Filter Driver) > Driver-3(Function Driver) > Physical Device
```
