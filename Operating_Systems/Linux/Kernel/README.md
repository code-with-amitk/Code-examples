- [Kernel](#k)
- [User Mode vs Kernel Mode](#uk)
- [IO / Input Output](#io)

## kernel
Heart of Linux OS. Kernel is chunk of code doing following tasks:
  - *1. Process management:* Creation/Destruction of processes, IPC(using signals, pipes etc) is handled by kernel.
  - *2. Memory Management:* virtual addressing space for all processes is provided by kernel.
  - *3. File System management:*  kernel builds a structured filesystem on top of unstructured hardware
  - *4. Device Control:* kernel have device drivers for every peripheral device present on system, from the hard drive to the keyboard.
  - *5. Networking(TCP/IP stack):* Routing, address resolution, sending, receiving packets and delivery to application.

<a name=uk></a>
## User Mode vs Kernel Mode
||Kernel Mode|User Mode|
|---|---|---|
|What|Priviledged space, where priviledged application run. Has strong security/access checks|Non-priviledged mode, user application runs|
|Applications|Kernel runs here|Application runs in user space (Eg: shells, command line, GUI)|
|Access Method|Using system calls(400+) or H/W Interrupt||
|[Sizes on 1TB system](/Operating_Systems/Linux/Protection_Rings)|4 GB|966 GB|

<a name=io></a>
## IO / Input Output
Methods with which CPU communicates with I/O Device(Eg: printer, Disk etc).
- **Types of IO?**

||Polling Method|Interrupt Driven IO|DMA(Direct Memory Access) Based IO|
|---|---|---|---|
|What?|processor tests each I/O device in sequence and asks each one if it needs communication with the processor|Device itself tells when it need attention. CPU will stop doing present task, fulfill device request. then resume present task.|DMA Controller does handling interrupts.|
|Disadv|Huge amount of processor time wastes in looping. Poor performance|High number of interrupts can halt currently running process|
|Adv||Increases throughput|


- _[Interrupts](Interrupts):_ Sources of Interrupts, Types of Interrupts, How Interrupt travels from HWDevice to CPU
- _[Shell](Shell):_ How Shell Works, Working code
