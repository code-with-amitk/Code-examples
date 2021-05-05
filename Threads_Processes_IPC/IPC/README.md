## IPC Design Issues
- **1. Communication:** How one process can pass information to other?
- **2. No Interference:** Making sure two or more processes do not changes each other's data.
- **3. Sequence:** Proper sequencing when dependencies are present: if process A produces data and process B prints them, B has to wait until A has produced some data before starting to print.

### IPC Methods

|Method|Communication|
|---|---|
|1.Pipe|Parent to child viceversa|
|2.Named pipes, fifo|Multiple process can communicate. Process-1 to process-2|
|3.Message Queues|Multiprocess. Process-1 to process-2|
|4.Shared Memory|Multiprocess. Process-1 to process-2. Fastest(No Inherent Synchronization)|
|5.Memory mapped files|Map a file onto process Virtual address space and do RW.  Advantages? 1. Mapping a file is cheaper than using I/O system calls for RW  2. Same file can be mapped to 2-or-more processes at same time. Write by 1 is visible to other instantly.|
