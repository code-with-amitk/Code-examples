## Voltage Controller/Regulator/VRM(Vol Reg Module)
- Component steps down the voltage from input(ie system power rails 12,5,3,3V) and outputs regulated/cutted voltage(1.2V) to IC(CPU,GPU)
- **How to communicate with VR**
  - VR is connected on [I<sup>2</sup>C](/cpu_memory_thread_process/CPU/Communication/Buses/I2C.md) bus.
  - If tool want to read/write to VR, I<sup>2</sup>C read/write mechanism should be used.

<img src="https://i.ibb.co/VMHLZdg/voltage-regulator.png" width="600" />

- **Flow**
  - *1.* On system startup, VR is enabled 1st then CPU.
  - *2.* VD sends VDD_plane_strap signal to CPU to know hoe many lines/planes CPU supports.
  - *3.* Response from CPU is recieved on input pins.

- **Domains/Channels/Lines**
  - Each VR have 2 channels or domains or lines.
