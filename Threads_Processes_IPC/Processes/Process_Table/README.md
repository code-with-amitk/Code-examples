## Process Table
- **What?** Information of every process is stored in `struct task_struct` which is called [Process Control Block](PCB) or Process Context. PCB is stored inside KERNEL not in user space.
- PLEASE NOTE: CS,DS,SS,ptr_to_HS stores User space data of process. So two are not linked at all.

<img src=pcb.png width=1000/>
