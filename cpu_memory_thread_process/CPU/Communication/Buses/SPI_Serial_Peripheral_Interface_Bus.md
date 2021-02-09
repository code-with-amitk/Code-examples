## SPI(Serial Peripheral Interface) Bus
- Provides half(communication in 1 direction at a time) or full duplex(Communication in both directions at same time), synchronous(Devices are time syncd), [serial communication bus](/cpu_memory_thread_process/CPU/Communication/Serial_Parallel_Bus.md) with external devices.
- Similar to [I<sup>2</sup>C](/cpu_memory_thread_process/CPU/Communication/Buses/I2C.md) master/slave concept is present. multiple masters can be present.
- Communication clock is called SCK.
- **Data** Order of data is programmable ie MSB 1st or LSB 1st. Data can be 8 or 16 bit. Data can be transferred to SPI Device from Memory(ie using DMA) directly.
- **SPI Pins**
  - *1. MISO(Master In/Slave Out) Pin:* Master receiveing and slave sending data.
  - *2. MOSI(Master Out/Slave In) Pin*
  - *3. SCK(Serial clock):* Output for SPI masters, input for SPI slaves
  - *4. NSS(Slave select):* optional pin to select slave device, Helps master to communicate directly with particular slave aoviding contention on SPI Bus.
```c
  |   board-n   |           |   board-m   |
  | IC-1  IC-2  |           | IC-3  IC-4  |
            /\                  /\
            |-------------------|
```
