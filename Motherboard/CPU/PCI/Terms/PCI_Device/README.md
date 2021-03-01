## Peripheral/PCI Device
- **What?** 
  - Any I/O device that plugs directly into a PCI slot on a computer’s motherboard.
  - Each PCI Device is represented using **4096bytes Function**.
  - Each Function present at (Segment>Bus>Device>Function) has {Header 64bytes}+{Memory Area 4032bytes}
- **Examples of PCI devices?** Modem, Network card, Sound card, Video card, Wireless adapter, GPU, bridges etc
- **PCI Device types**
  1. *End point device(Type 0)* That does not spawn another bus behind it. Example: VGA, LAN card
  2. *Bridge Device(Type-1)* Which can spawn another bus behind it.
- **Locating PCI Device:** PCI device can be reached at Bus:Device:Function
```c
# lspci                       //Lists all devices
Bus:Device.Function
  03:00:0          VGA Controller(GPU)
  ..
# lspci -x										//Lists PCI configuration space for each device
.........
00:07.0	ISA Bridge: Intel Corporation 823171AB/EB/MB PIIX4 ISA (rev 01)
00: 86 80 10 81 07 00 00 02 01 00 01 06 00 00 80 00
10: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
20: 00 00 00 00 00 00 00 00 00 00 00 00 14 14 00 00
30: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
.........
# lspci | wc - l
100
# lspci | grep bridge | wc - l      //Lots of Bridges
67
```
