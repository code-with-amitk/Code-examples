## Modules of 8259
- **1. Data bus buffer?** 
  - This Block is used as a mediator between 8259 and 8085/8086 microprocessor by acting as a buffer. 
  - It takes the control word from the 8085/8086 & transfer it to the control logic of 8259 microprocessor.
  -  Also, after selection of Interrupt by 8259 microprocessor, it transfer the opcode of the selected Interrupt and address of the Interrupt service sub routine to the other connected microprocessor. The data bus buffer consists of 8 bits represented as D0-D7 in the block diagram. Thus, shows that a maximum of 8 bits data can be transferred at a time.
- **2. Read/Write logic?** 
This block works only when the value of pin CS is low (as this pin is active low). This block is responsible for the flow of data depending upon the inputs of RD and WR. These two pins are active low pins used for read and write operations.
Control logic –
It is the centre of the microprocessor and controls the functioning of every block. It has pin INTR which is connected with other microprocessor for taking interrupt request and pin INT for giving the output. If 8259 is enabled, and the other microprocessor Interrupt flag is high then this causes the value of the output INT pin high and in this way 8259 responds to the request made by other microprocessor.
Interrupt request register (IRR) –
It stores all the interrupt level which are requesting for Interrupt services.
Interrupt service register (ISR) –
It stores the interrupt level which are currently being executed.
Interrupt mask register (IMR) –
It stores the interrupt level which have to be masked by storing the masking bits of the interrupt level.
Priority resolver –
It examines all the three registers and set the priority of interrupts and according to the priority of the interrupts, interrupt with highest priority is set in ISR register. Also, it reset the interrupt level which is already been serviced in IRR.
Cascade buffer –
To increase the Interrupt handling capability, we can further cascade more number of pins by using cascade buffer. So, during increment of interrupt capability, CSA lines are used to control multiple interrupt structure.
