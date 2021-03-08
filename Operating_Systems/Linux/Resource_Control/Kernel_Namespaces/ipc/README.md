## Interprocess Communication / ipc
- **What?** This isolates interprocess communication (IPC) resources.
  - System V IPC objects and POSIX message queues
- **Use case?** 
  - separate the shared memory (SHM) between two processes to avoid misusage  
  - each process will be able to use the same identifiers for a shared memory segment and produce two distinct regions.
