
## [I<sup>2</sup>C/I2C (Inter-Interconnected Circuit Bus)](https://www.i2c-bus.org/specification/)
- **What** 
  - For communication between 2 soc's or IC's on 1 board using  [2-wire Serial communication bus](../../Serial_Parallel_Bus.md), ICs on seperate boards can also be connected using I<sup>2</sup>C.
  - This is similar to nodes(ICs/SOCs) connected on 1 LAN using switch/ethernet-cable.
- **Rules**
  - Bus master device initiates a bus transfer between it and a single bus slave and provides the clock signals.
  - A bus slave device can receive data provided by the master or it can provide data to the master.
 

- **Packet format**
```c  
        <-------header--------------->
  [data][R/W][Slave-Address][Start-Bit]
R: Master reading, Slave should write
W: Master writing, slave should read.  
```

### Master communicating with slave
- *1.* Master if(SCL=high){ Pulls SDA to low. send low on SDA. }
- *2.* Master sends address byte(consists of 7 bit slave address)+RW bit.
- *3.* Slave . ok this is my address. if(SCL=high){ Pulls SDA to low. send low on SDA on 9th clock Signal}  //called Acknowledgement
- *4.* All other devices remains silent.
- *5.* Slave waits to data to be RW using its Shift_Registers.
- Slave can be voltage regulator and master can be tool.

**Steps on Tool**
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
