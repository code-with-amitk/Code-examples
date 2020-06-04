## COPROCESSOR
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
	
## CPU/Processor
- **Terms**
	- ***flip-flop***
		- a circuit that has two stable states(0 or 1) – a bistable multivibrator. This stores a single bit (binary digit) of data; one of its two states represents a "one" and the other represents a "zero".
		- It is the basic storage element in sequential logic.
	- ***Synchronous circuit***
		- A digital circuit in which the changes in the state of memory elements are synchronized by a clock signal. Data is stored in memory devices called flip-flops or latches.
	- ***Clock gating***
		-  technique used in synchronous circuits for reducing dynamic power dissipation, by removing the clock signal when the circuit is not in use. Now Clock flip-flops do not have to switch states. Switching states consumes power. switching power consumption goes to zero, and only leakage currents are present.
	
## GPU(Graphics Processing Unit)
- **What**
	- This is specialized electronic circuit created for manipulating images rapidly. ie Specialized in Graphics & Image processing.
	- GPUs are used in mobile phones, personal computers, workstations, and game consoles.
	- They work on ***parallel computing***.
- **Usages**
	- Create high resolution images, videos
	- In machine training, deep learning neural networks, GPUs can be 250 times faster than CPUs.
	- Complex mathematical calculations.
	- financial simulations and risk modeling
- **Companies**
	- In 2018 AMD/ATI(33%) & Nvidia(66%) captured 100% of GPU market.	
- **CPU vs GPU**

|  | CPU | GPU |
| --- | --- | --- |
| Cores | 4 | Nvidia's GeForce:4000, AMD's Radeon: 2500, Intel's HD 500: 1100 |
| works on | | Parallelism |
| Tasks | varied: open spreadsheets, DB queries | To computation intensive tasks only |
	
- **General Terms**
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
	- ***SMU(System Management Unit)***
		- This is firmware provided by AMD
		- The SMU is designed to prevent unauthorized code execution. 

### GPU Architecture

## APU(AMD Accelerated Processing Unit)/Formely Fusion
- **What**
	- This is 64-bit CPU from AMD designed to act as CPU+GPU on single die. These are general purpose processors.
- **Generations of APU**

| Generation | Launched in | Low Power APUs | High Power APUs |
| --- | --- | --- | --- |
| 1st | 2011 | Brazos | Llano |
| 2nd | 2012 | Brazos-2 | Trinity |
| 3rd | 2014 | Kabini,Temash | Kaveri |
| 4th | 2017 | Ryzen |



