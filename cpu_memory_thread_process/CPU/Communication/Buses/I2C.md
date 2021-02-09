
## [I<sup>2</sup>C/I2C (Inter-Interconnected Circuit Bus)](https://www.youtube.com/watch?v=U5CDf4TNARE)
- **What** 
  - Developed by Philips, For communication between 2 soc's or IC's on 1 board using  [2-wire Serial communication bus](/cpu_memory_thread_process/CPU/Communication/Serial_Parallel_Bus.md). ICs on seperate boards cannot be connected using I<sup>2</sup>. Similar to nodes(ICs/SOCs) connected on 1 LAN using switch/ethernet-cable.
  - I2C supports multiple master, but usually 1 master is present
  - **Components which can be connected** sensors, clocks, EEPROM
  - **Disadv:** Low bandwidth(less data can be sent), short distance, slow protocol, Max speed: 400kbps(around).
  - **Adv:** Simple
```c
Similar to Switch
[Central        ]-------|-----------------|----------------|---SD_a(Data line)                 //Similar to LAN
[Microcontroller]------||----------------||---------------||---SC_l(Clock line)
                    IC-1/SOC-1      IC-2/SOC-2        IC-3/SOC-3                //Nodes=ICs or SOCs
                   sender/master    reciever/slave
```
- **Addressing** Every IC on I<sup>2</sup> bus will have unique Addresses(7 bit). I<sup>2</sup> has its own addressing scheme. 1 device can have multiple addresses.
- **Packet format**
```c  
        <-------header--------------->
  [data][R/W][Slave-Address][Start-Bit]
R: Master reading, Slave should write
W: Master writing, slave should read.  
```
- **Flow**
```c
  Master                                Slave
    -[00101001][W][Slave-address][1]--->
    <---------ACK----------------------
      ---Stop-bit----------------->
      <---------ACK-----------
```
