## PCB / Process Control Block / Process Context
- **What?** PCB of `struct task_struct` is Data structure for storing all information of a process.
```c
struct task_struct {
  long                 priority;
  struct task_struct   *next_task, *prev_task;            //DOUBLY LL
  int                  pid;                               //PID
  int                  pgrp;									            //Process Group
  struct task_struct   *p_opptr, *p_pptr, *p_cptr,        //Pointers to parent, youngest child, silbilings etc
  unsigned short       uid,suid,gid,sgid..;               //UID,GID
  struct fs_struct     *fs;                               //File system information
  struct sem_queue     *semsleeping;                      //IPC Information
  struct mm_struct     *mm;                               //memory management info
  struct signal_struct *sig;                              //signal handlers
  //Register information.
};
```
- **Why PCB Is needed?** 
  - When process changes state (ie switched from running to waiting/sleeping state(due to context switch or interrupt)) kernel stores info in PCB, so that process can resumed later from same poing using this information. 
  - Information of child processes is stored in PCB of parent process etc.
- **Information stored in PCB?** 
  - [Register values of present process, stack pointer (rbp)](/assembly) etc
  - Process-state: Any of 5
  - pid: process-id
  - [Program Counter/Instruction Pointer](/Motherboard/CPU/Memory/CPU_Registers/Special_Purpose_Registers/Instruction_Pointer): Address of next instruction to be executed on Code segment of this process.
  - priority: This is a number. Process having higher priority execute 1st.
  - [General purpose registers](/Motherboard/CPU/Memory/CPU_Registers/General_Purpose_Registers): Stores results of calculations done by process in Memory segment.
  - list of open files, list of open devices. This all information is called PROCESS CONTEXT.
