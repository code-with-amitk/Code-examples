
## [I<sup>2</sup>C/I2C (Inter-Interconnected Circuit Bus)](https://www.youtube.com/watch?v=U5CDf4TNARE)
- **What** 
  - For communication between 2 soc's or IC's on 1 board using  [2-wire Serial communication bus](/cpu_memory_thread_process/CPU/Communication/Serial_Parallel_Bus.md). ICs on seperate boards cannot be connected using I<sup>2</sup>. Similar to nodes(ICs/SOCs) connected on 1 LAN using switch/ethernet-cable.
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

### Steps of Communicating with a Slave on I<sup>2</sup> Bus
- Slave can be voltage regulator and master can be tool.
```c
  Master/Tool                          Slave(address=43)
    -[00101001][W][Slave-address][1]--->
    <---------ACK----------------------
      ---Stop-bit----------------->
      <---------ACK-----------
```
- *1.* Get Slave address to which master want to send data. Eg slave_address=43.
- *2.* write slave address at off1 = Register_Aperature + offset1
- *3.* Enable I2C bus by setting 1 at off2 = Register_Aperature + offset2
- *4.* Write on I2C at off3 = Register_Aperature + offset3
- *5.* POOL for status
  - I2C Status
  - I2C Acknowledgement status
```c
  i2c_SetAddress (off1, slave_address>>1)          //2  =>  MMWrite(off1, 21)
  i2c_Enable (off2, 1)                       //3        =>  MMWrite(off2, 1)
  i2c_Write(off3, command=154)                 //4      =>  MMWrite(off3, 154)  
  i2c_pollTxStatus(){
    status = MMRead(offset4);
    ACK or NAK = MMRead(offset5);
  }
  
Physical to virtual memory is mapped at stat and write is done there.
```
