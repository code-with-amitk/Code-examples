## Communication between soc(system on Chip)
### 1. I<sup>2</sup>C/I2C (Inter-Interconnected Circuit Bus)
- **What** 
  - For communication b/w 2 soc's or IC's. 2-wire Serial communication bus for connecting 2 separate ICs/soc's.
  - Similar to nodes(ICs/SOCs) connected on LAN using switch/ethernet-cable.
  - **Disadv:** Low bandwidth(less data can be sent), short distance, slow protocol, Max speed: 400kbps(around).
  - **Adv:** Simple
```c
  Similar to Switch
[Central        ]-------|-----------------|----------------|---SD_a(serial Data)                 //Similar to LAN
[Microcontroller]------||----------------||---------------||---SC_l(serial clock)
                    IC-1/SOC-1      IC-2/SOC-2        IC-3/SOC-3
```
- **How it works**
  - Every IC on I<sup>2</sup> bus will have unique Address. I<sup>2</sup> has its own addressing scheme.
