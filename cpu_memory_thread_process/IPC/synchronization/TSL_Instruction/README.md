## TSL Instruction (Test and Set Lock)
> TSL RX, var                 //TSL Register, Shared_Lock_Variable

- **What?** Similar to other Synchronization methods, But here shared_lock_variable is read into register using TSL instruction
  - Reading variable into register is gurantted atomic.
  - Checking register value is also gurantted atomic.
```c
  if (Shared_Lock_Variable == 0)      
    no one in critical section. set lock to 1 and enter CS
  - else if (Shared_Lock_Variable != 0) 
    Lock already acquired, loop until lock==0
``` 
### Code
#### Steps
  - *1.* Read variable into register
  - *2.* if (register==0){ Set register and enter CS}
  - *3.* if (register==1){Someone in CS, wait in loop}
#### Code
```c
enter_region:
  TSL REGISTER, Shared_Lock_Variable    //reg=Shared_Lock_Variable; Shared_Lock_Variable=1  Read Shared_Lock_Variable and set to 1
  CMP REGISTER,#0                       //if(reg == 0) means lock was already acquired. Read old Shared_Lock_Variable value
  JNE enter region                      //if (Shared_Lock_Variable!=0) if it was not zero, lock was set, goto start of loop
  RET 

leave_region:
  MOVE Shared_Lock_Variable,#0          //store a 0 in lock
  RET                                   //return to caller

///////////Thread-1 or Process-1//////////////
while (TRUE) {
  enter_region()                  //Calls enter_region() before entering CS
  critical_section();
  leave_region()                  //Call leave_region() after leaving CS
}

//////////Thread-2 or Process-2/////////////////
while (TRUE) {
  enter_region()                  //Calls enter_region() before entering CS
  critical_section();
  leave_region()                  //Call leave_region() after leaving CS
}
```
