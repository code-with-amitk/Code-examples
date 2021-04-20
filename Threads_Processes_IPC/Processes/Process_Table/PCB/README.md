## PCB / Process Control Block
- **What?**
  - When process is switched from running to waiting/sleeping state(due to context switch or interrupt), OS stores process information in PCB, so that process can resumed later using this information. 
  - This information of running process is stored in PCB:  a. Present Register values  b. Present stack pointer etc. How stack pointer moves?
    PCB CONTENTS:    Process-state: Any of above 5,     pid: process-id,     Program Counter/Instruction Pointer: Address of next instruction to be executed on Code segment of this process.     priority: This is a number. Process having higher priority execute 1st.     General purpose registers: Stores results of calculations done by process in Memory segment.    list of open files, list of open devices. This all information is called PROCESS CONTEXT.
