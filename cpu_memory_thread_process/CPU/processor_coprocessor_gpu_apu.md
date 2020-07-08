# 1. CPU/Processor
### TERMS
- **flip-flop**
	- a circuit that has two stable states(0 or 1) – a bistable multivibrator. This stores a single bit (binary digit) of data; one of its two states represents a "one" and the other represents a "zero". It is the basic storage element in sequential logic.
- ***Synchronous circuit***
	- A digital circuit in which the changes in the state of memory elements are synchronized by a clock signal. Data is stored in memory devices called flip-flops or latches.
- ***Clock gating***
	-  technique used in synchronous circuits for reducing dynamic power dissipation, by removing the clock signal when the circuit is not in use. Now Clock flip-flops do not have to switch states. Switching states consumes power. switching power consumption goes to zero, and only leakage currents are present.
- ***AMD Powertune***
	- Dynamic frequency scaling techniques built into some AMD's GPU/APU.
	- This allow the clock speed of the processor to be dynamically changed making low power consumption, low noise, low overheating.
- ***GPU Clocks (unit 10KHz)***
	1. VCLK, DCLK: UVD(See wiki) Internal clocks
	2. SCLK: GPU Engine clock
	3. MCLK: GPU Memory clock
- ***GPU voltages***
	1. VDDC: (mV) This is GPU core voltage.
	2. VDDCI: (mV) This is IO Bus voltage between GPU & Memory comes from PCI-express slot.
	3. MVDD: Memory voltage
- ***I2C Bus***
	- This is a bus protocol developed by philips for connnecting devices
- ***SMBus(System Management Bus)***		
	- This based on the I2C protocol. The I2C bus connects one or more master chips and one or more slave chips.

# 2. COPROCESSOR
- **What**
	- computer processor used to supplement the functions of the primary processor/CPU/mircoprocessor.
	- coprocessor shares same memory, IO devices, bus control, clocks as with CPU.
	- coprocessor has its own instruction set, which would be added to CPU
	- coprocessor can have upto ***60 cores*** in 1 package.
- **Usage**
	- Offloads processor-intensive tasks from the main processor and hence can accelerate system performance
- **Operations performed by the coprocessor**
	- floating point arithmetic, graphics, signal processing, string processing, cryptography or I/O interfacing with peripheral devices.	
- **Examples**
	- 8087 was 1st math coprocessor developed by intel.
	- GPU(Graphics Processing Units)
	
	
# 3. GPU(Graphics Processing Unit)
### What is GPU
	- This is specialized electronic circuit created for manipulating images rapidly. ie Specialized in Graphics & Image processing.
	- GPUs are used in mobile phones, personal computers, workstations, and game consoles.
	- They work on ***parallel computing***.
	- **Companies** In 2018 AMD/ATI(33%) & Nvidia(66%) captured 100% of GPU market.	
### GPU Usages
	- Create high resolution images, videos
	- In machine training, deep learning neural networks, GPUs can be 250 times faster than CPUs.
	- Complex mathematical calculations.
	- financial simulations and risk modeling
### CPU vs GPU

|  | CPU | GPU |
| --- | --- | --- |
| Cores | 4 | Nvidia's GeForce:4000, AMD's Radeon: 2500, Intel's HD 500: 1100 |
| works on | | Parallelism |
| Tasks | varied: open spreadsheets, DB queries | To computation intensive tasks only |

### GPU Architecture

### GPU Series
#### Desktop GPUs

| Year | Model | CodeName | transistor & Die size |
| --- | --- | --- | --- |
| July 2019 | Radeon RX 5700 XT, 50th Anniversary Edition | Navi 10 XTX | 251 mm |
| Jan 2020 | Radeon RX 5600 | Navi 10 XLE | 251 mm |
| Dec 2019 | Radeon RX 5500 XT | Navi 14 XTX | 158 mm |


# 4. APU(AMD Accelerated Processing Unit)/Formely Fusion
- **What** This is 64-bit CPU from AMD designed to act as CPU+GPU on single die. These are general purpose processors.
## APUs

### Desktop APUs

| Year | Name |
| --- | --- |
| 2011 | Lynx |
| 2012 | Virgo |
| 2013 | Richland, Kabini |
| 2013 | Kaveri |
| 2016 | Carrizo |
| 2016 | Bristol |
| 2018 | Raven Ridge |
| 2019 | Picasso |

### Mobile APUs

| Year | Name |
| --- | --- |
| 2011 | Sabine |
| 2012 | Comal:Trinity |
| 2013 | Richland |
| 2013 | Kaveri |
| 2015 | Carrizo |
| 2016 | Bristol Ridge |
| 2018 | Raven Ridge |
| 2019 | Picasso |
| 2020 | Dali |
| 2020 | Renior |
