## Scheduler Activation
- When scheduler activations are used, the kernel assigns a certain number of virtual processors(core) to each process. Now user space process can allocate each thread on specific core.
- Intially only 1 virtual processors(core) is given to process, but process can ask more if required. The kernel can also take back virtual processors(core) & assign them to high priority process.

## Upcall
- **What?** upcall is mechanism to resolve [Problem-1 in User Space Threads](/Threads_Processes_IPC/Threads/UserSpace_KernelSpace_Threads/README.md)
- **How?**
  - *1.* Thread-1 has blocked the process. See [Problem-1 in User Space Threads](/Threads_Processes_IPC/Threads/UserSpace_KernelSpace_Threads/README.md)
  - *2.* Kernel is aware the Thread-1 has blocked the process.
  - *3.* Kernel notifies Run-Time system(scheduler) (ie does **upcall**) that Thread-1 of Process-x has blocked, event why thread is blocked by copying data on Scheduler-Process's stack. Run-Time system will marks thread as blocked, takes other runnable threads and starts them.
  - *4.* Later when kernel finds blocking system call is completed, it again makes a **upcall** and run-time system can restart the blocked thread immediately or put it on the ready list to be run later.
- **Objections to upcalls?**
  - *1.* upcalls violates the layered system architecture. ie Layer-n offering services that layer(n + 1) but layer(n+1) cannot pass information to layer-n. Upcalls do not follow this fundamental principle.

