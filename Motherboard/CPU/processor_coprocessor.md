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


