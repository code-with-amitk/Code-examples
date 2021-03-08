## Process ID / pid
- **What?** 
  - Gives processes an independent set of process identifiers (PIDs). 
  - processes which reside in different namespaces can own the same PID.
- A process has two PIDs: the PID inside the namespace, and the PID outside the namespace on the host system
- **Creating new pid namespace**
```c
> sudo unshare -fp --mount-proc
# ps aux
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root         1  0.4  0.6  18688  6608 pts/0    S    23:15   0:00 -bash
root        39  0.0  0.1  35480  1768 pts/0    R+   23:15   0:00 ps aux

//--mount-proc flag is needed to re-mount the proc filesystem from the new namespace
```
