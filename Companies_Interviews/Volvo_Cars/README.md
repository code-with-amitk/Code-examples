- [Volvo cars Architecture](#ar)
- **April, 2022**
  - [R1. Online Assesement](#r1)
  - [R2. OOD](#r2)

<a name=ar></a>
### Architecture
**Present Day: Based on ECU(Electric control Unit)**
  - Around 100+ ECU, which talk to each other/dashboard.
  - These are sort of firmware(Hardware+ complied software) maybe from different vendors.
  - Used to control behaviour of components(Eg: parking camera)
```c
    -| |--------------Volvo car------------
    |
    |   ecu-vendor-1-------------|---|--------ecu-vendor-3
    |                            |
    |        ecu-vendorn---------|
    |
    -| |-----------------------------------| |-
```
**Future: Core computer**
- Car will have high end CPU/GPU 2 boxes which communicate over other components over ethernet.
- Does not rely on supplier provided ECUs for behaviour we want.
- Work load is distributed between these core_computers using distributed framework.
```c
    -| |--------------Volvo car------------
    |
    |   ecu-1---LAN(ethernet cable)------core_computer-1
    |                     |
    |        ecu-n--------|     core_computer_2
    |
    -| |-----------------------------------| |-
```
Volvo cars will launch its own OS.

### April,2022
<a name=r1></a>
**R1. Online Assesement**

<a name=r2></a>
**R2. OOD**
- Write a perception function
