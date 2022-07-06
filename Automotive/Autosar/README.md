- [Classic Autosar](#ca)
- [Adaptive Autosar](#aa)
- [Code](#c)

<a name=ca></a>
## Classic Autosar (Automotive(Aut) Open(o) System(s) Architecture(ar))
- Present day vehicles has 100 ECUs, which communicate using CAN bus/Ethernet network using their own standards
- Autosar is worldwide partnership of manufactures and companies in automotive industry, to standardize interfaces between application & ECUs.

### Architecture
```c
                Application Layer
  -------------------------------------
  | Autosar Run Time Enviornment(RTE) |
  -------------------------------------
  | Services Layer                    |
  -------------------------------------
  | ECU Abstraction Layer             |
  -------------------------------------
  | Microcontroller Abstraction Layer | Drivers
  -------------------------------------
  |       Microcontroller (MCU)       |
  -------------------------------------
```

<a name=aa></a>
## Adaptive AUTOSAR
- [Classic Autosar](#ca) was doing good with 60-80 ECUs.
- But IoT coordinating with automotive, automated driving its felt Classic Autosar will not support these. Hence Adaptive Autosar.
- **Advantages of AA:** Scalable, Upgrade application inside OEM on the fly without restart

### Architecture
- 1 high-end central application server, ECUs connect via ethernet.

## Code
1. Download Simulink software from [matlab](https://matlab.mathworks.com/)
2. [Simulink](https://matlabacademy.mathworks.com/details/simulink-onramp/simulink) traning video
