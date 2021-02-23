## Voltage Controller/Regulator/VRM(Vol Reg Module)
- Component steps down the voltage from input(ie system power rails 12,5,3,3V) and outputs regulated/cutted voltage(1.2V) to IC(CPU,GPU)
- **How to communicate with VR**
  - VR is connected on [I<sup>2</sup>C](/cpu_memory_thread_process/CPU/Communication/Buses/I2C.md) bus.
  - If tool want to read/write to VR, I<sup>2</sup>C read/write mechanism should be used.

<img src="https://i.ibb.co/VMHLZdg/voltage-regulator.png" width="600" />

## SVI(Serial VID Interface) Controller/Regulator
-  Allows dynamic adjustment of the Core and Northbridge output voltages independently and in combination from 0.500V to 1.55V
