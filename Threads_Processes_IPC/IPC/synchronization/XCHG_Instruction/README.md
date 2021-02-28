## XCHG (Exchange) Instruction
- Similar to [TSL](/cpu_memory_thread_process/IPC/synchronization/TSL_Instruction), But here shared lock variable and Register contents are swapped.
```c
enter_region:
  MOVE REGISTER,#1            //put a 1 in the register
  XCHG REGISTER,LOCK          //Swap the contents of the register and lock var iable
  CMP REGISTER,#0             //was lock zero?
  JNE enter region            //if it was non zero, lock was set, so loop
  RET                         //Return to caller; critical region entered
  
leave_region:
  MOVE LOCK,#0              //store a 0 in lock
  RET                       //return to caller

///////////Thread-1 or Process-1//////////////
while (TRUE) {
  while (shared_var != 0)
    critical_section();
    shared_var = 1;
    noncritical_section();
  }
}

//////////Thread-2 or Process-2/////////////////
while (TRUE) {
  while (shared_var != 1)
    critical_section();
    shared_var = 0;
    noncritical_section();
  }
}
```
