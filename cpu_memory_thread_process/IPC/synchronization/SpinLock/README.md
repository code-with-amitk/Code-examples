## Spin lock
- **What?** Thread-2 keeps checking the lock continously in while(1). This consumes CPU but is 3 times faster than Mutex.
- **Applications?** Critical sections in ISR(Interrupt service routines){ISRs are defined inside kernel} are implemented using spinlocks.
- **Example Code**
  - Processes wait on shared variable (shared_var)
  - *Process-1* enters Critical section when shared_var=0
  - *Process-2* enters Critical section when shared_var=1
```c
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
- **Problems with spinlocks?** 
  - *1.* Consumes more CPU.
  - *2.* When 1 process is very slow(maybe doing lot of IO) wrt other. Faster process need to wait unneccesarily.
