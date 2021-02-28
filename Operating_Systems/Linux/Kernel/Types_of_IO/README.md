## IO / Input Output
- **What?** Methods with which CPU communicates with I/O Device(Eg: printer, Disk etc).
- **Types of IO?**

||Polling|Interrupt Driven IO|
|---|---|---|
|What?|processor tests each I/O device in sequence and asks each one if it needs communication with the processor|Device itself tells when it need attention. CPU will stop and fulfill device request|
|Disadv|Huge amount of processor time wastes in looping. Poor performance|Increases throughput|
