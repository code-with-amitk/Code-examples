## Communication between soc(system on Chip)
### 1. I<sup>2</sup>C/I2C (Inter-Interconnected Circuit Bus)
- **What** 
  - For communication b/w 2 soc's or IC's. [2-wire Serial communication bus](/cpu_memory_thread_process/CPU/Communication/Serial_Parallel_Bus.md) for connecting 2 separate ICs/soc's.
  - Similar to nodes(ICs/SOCs) connected on LAN using switch/ethernet-cable.
  - **Disadv:** Low bandwidth(less data can be sent), short distance, slow protocol, Max speed: 400kbps(around).
  - **Adv:** Simple
```c
Similar to Switch
[Central        ]-------|-----------------|----------------|---SD_a(Data line)                 //Similar to LAN
[Microcontroller]------||----------------||---------------||---SC_l(Clock line)
                    IC-1/SOC-1      IC-2/SOC-2        IC-3/SOC-3                //Nodes=ICs or SOCs
                   sender/master    reciever/slave
```
- **Addressing** Every IC on I<sup>2</sup> bus will have unique Address(7 bit). I<sup>2</sup> has its own addressing scheme.
- **Packet format**
  - Before data, device address(for whom this data is meant to be) is sent on the bus.
```
  [Data][Device_address]----->
```
