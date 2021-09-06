- [Serial, Parallel Bus](#sp)
- **Buses**
  - [I2C vs SMBus(System Management Bus) vs PMBus(Power Management Bus)](#vs)
  - **1. I<sup>2</sup>C**
    - [Packet format, Communication](#pf)
    - [Steps on Tool for I2C Comm](#st)
  - **[2. SMBus](#sb)**
  - **[3. PMBus v(1.3)](#pm)**
  - **[4. SPIBus](#spi)**
  - **[5. CAN](#can)**
    - [CAN Messages](#cmsg)
    - [Standard vs Extended CAN](#vs)

<a name=sp></a>
## Serial Bus
- There are 2 lines. data_line, clock_line.
  - Data_line: Data is sent serially over this line.
  - Clock_line: Clock signal is sent here by sender, all recievers start reading data over data line(sd_a). clock signal is again sent all recievers stop reading data.
- if some noise is there data will be corrupted.
```c
Example sending data(00001111) over the bus
Sent as digital signal
               ----------
              | 1 1 1 1 |
              |         |
  ---------------------------
    | 0 0 0 0 |
    |         |
    -----------

  ------|-------------|-------------|----- Data_line    (sd_a)
  -----||------------||------------||------- Clock_line (sd_c)
    sender/master  reciever1      reciever2
```
- **Problem-1: Slow Slave:** some slave is slow and cannot consume data at rate produced by master.
  - **Solution: Clock Streaching** Slave will pull the clock signal(sd_c) down when master tries to reset clock signal. Pulling down means setting. This way master will know slave is slow and master will slow down data sending over data line.

# Buses
<a name=vs></a>
#### I2C vs SMBus vs PMBus
```c
             |                    I2C | SMBus(System Management Bus) | PMBus(Power Management Bus)
-------------|------------------------|------------------------------|----------------------------------
Developed by | Philips(1982)          |         Intel(1995)          |      Intel
    Wire     |      2                 |               2              |        2
  Latest Rev |                        |     SMBus 3.1(2018)          |      PMBus 1.3
  What       |    Oldest              |       Superset of I2C        |  Superset of SMBus. Defines domain specific commands
Max Speed    | 100kbit/s to 3.4MBit/s |     100Khz                   |version1.2(400KHz), version1.3(1MHz)
MaxBlockSize |                        |         32 Bytes             | 255 Bytes
Compared to  |    Physical Layer      |       Phy+DL+N/W             |  Phy+DL+N/W+Transport Layer
OSI Layer
  Addresses   |7 bit(1 device can have|                              |     same as I2C
                 multiple addresses)
Components to |                       |     sensors, clocks, EEPROM   |
connect
Principle     | Slaves,Master.        |       Same as I2C            |
                Multimaster supported.
Disadv        |Low bandwidth(less data can be sent), short distance, slow, Max speed:400kbps(around)|||
Adv           | Simple
```

<a name=i2c></a>
## 1. [I<sup>2</sup>C/I2C (Inter-Interconnected Circuit Bus)](https://www.i2c-bus.org/specification/)
- For communication between 2 soc's or IC's on 1 board using  2-wire Serial communication bus, ICs on seperate boards can also be connected using I2C.
- This is similar to nodes(ICs/SOCs) connected on 1 LAN using switch/ethernet-cable.
- **Rules** Bus master device initiates a bus transfer between & provides the clock signals. Slave device can receive data provided by the master or it can provide data to the master.
 
<a name=pf></a>
### Packet format, Communication
```c  
        <---------header--------------->
  data  R/W | Slave-Address | Start-Bit
R: Master reading, Slave should write
W: Master writing, slave should read.  

//////////////Master communicating with slave////////////////////
1. Master: Master sends address byte: (7 bit slave address)+RW bit.
  if (SCL=high) {
    Pulls SDA to low ie send low on SDA. 
  }

2. Slave:ok this is my address. 
    if(SCL=high){ 
      Pulls SDA to low. 
      send low on SDA on 9th clock Signal
      }  //called Acknowledgement
      
3. All other devices remains silent.
4. Slave waits to data to be RW using its Shift_Registers.
  - Slave can be voltage regulator and master can be tool.
```

<a name=st></a>
### Steps on Tool for I2C Comm
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

<a name=sb></a>
## 2. [SMBus(System Management Bus) http://smbus.org/specs/](http://smbus.org/specs/)
- VDD may be 3 to 5 volts +/- 10% and there may be SMBus devices powered directly by the bus VDD
- SMBCLK and SMBDAT lines are bi-directional. When the bus is free, both lines are high
- **Placing 0 or 1 on Bus**
  - *Placing 0* A device that wants to place a ‘zero’ on the bus must drive the bus line to the defined logic low voltage level. 
  - *Placing 1* Device should release the bus line letting it be pulled high by the bus pull-up circuitry(pull-up resistor or current source).

<img src="SMBus.JPG" width=500 />

<a name=pm></a>
## 3. PMBus(Power Management Bus) v(1.3) 
Latest standard having AVS(Adaptive Voltage Scaling) Bus
- This is dedicated bus to control processor voltages statically and dynamically. AVS is closed loop real time feedback from Devices to Voltage Regulator to update the voltage requested from the power supply. Adv: Intelligent power consumption savings.
- AVS [Frames](https://pmbus.org/Assets/PDFS/Public/20130912PMBus_1-3_DPF.pdf)
```c
 Write Frame (32 bit)
 Read Frame (32 bit)
```
### AVSBus Commands
```c
– Target Rail Voltage
– Target Rail Vout Transition Rate (Rising and Falling)
– Rail Current (read only)
– Rail Temperature (read only)
– Reset Rail Voltage to Default Value (write only)
– Power Mode (Full Power, Maximum Efficiency)
– AVSBus Status (VGood, OCW, UVW, OTW, OPW)
– AVSBus Version
```

<a name=spi></a>
## 4. SPI(Serial Peripheral Interface) Bus
Provides half(communication in 1 direction at a time) or full duplex(Communication in both directions at same time), synchronous(Devices are time syncd), serial communication bus with external devices.
- Similar to I<sup>2</sup>Cmaster/slave concept is present. multiple masters can be present. Communication clock is called SCK.
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

<a name=can></a>
## 5. CAN / Controller Area Network
**What is CAN?** 
- Developed by Robert Bosch GmbH(1986) to send messages in automobile nodes.
- All electronic devices in car(such as active suspension, gear and lighting control, central locking, and ABS) are connected to dashboard using CAN Bus.
- Broadcast communication bus defined by the ISO 11898 standards, all nodes recieve packet, its upto node to recieve/discard the pkt.

**Why CAN not I2C?**
- Vehicular Env has high noise, CAN can handle better than any other protocol.
- The automobile has a large number of systems
- Long range communication with high speed.
- Reliable wrt I2C.

**How I2C does not fit for automotive?**
- communication in short-distance Only.
- True multi-master.

CAN Controller Examples
```c
Intel 82526 CAN controller
Philips 82C200
```

<a name=cmsg></a>
### CAN Messages
> max payload = 94 bit
There are 4 kinds of messages:
```c
///////1. Data Frame////////
     Arbitration Field    
|Identifier(11bit) + RTR(1 bit) | Data (0-8 bytes) | CRC (15 bit checksum) | ACK bit |
 AF: Decides priority of message

///////2. Remote Frame/////
- No data field is present, 
- its used by reciever to initiate data transfer. If, say, node A transmits a Remote Frame with the Arbitration Field=234 to node B, then node B responds with Data Frame with the Arbitration Field=234

///////3. Error Frame//////
When node detects a fault it sends Error Frame, transmitter will retransmit the message.

//////4. Overload Frame////
When node is occupied, it sends OF to inform transmitter I'm busy.
```

<a name=vs></a>
### Standard vs Extended CAN
```c
                     Standard(2.0A) |  Extended(2.0B)
------------------|-----------------|------------------
Arbitration Field | 11 bits         |    29 bits
```
<a name=ac></a>
### How Collision is avoided / Bus Arbitration
The transmitting nodes monitor the bus before sending. If it detects signal, it quits the arbitration process and become a receiver instead. 
