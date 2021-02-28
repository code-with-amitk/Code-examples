## IO / Input Output
- **What?** Methods with which CPU communicates with I/O Device(Eg: printer, Disk etc).
- **Types of IO?**

||Polling Method|Interrupt Driven IO|DMA(Direct Memory Access) Based IO|
|---|---|---|---|
|What?|processor tests each I/O device in sequence and asks each one if it needs communication with the processor|Device itself tells when it need attention. CPU will stop doing present task, fulfill device request. then resume present task.|DMA Controller does handling interrupts.|
|Disadv|Huge amount of processor time wastes in looping. Poor performance|High number of interrupts can halt currently running process|
|Adv||Increases throughput|
