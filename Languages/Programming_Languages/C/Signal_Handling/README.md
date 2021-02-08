## Signals
- **What?** This is Software Interrupt to processor. For Example: Cntl^C, sends SIGINT to running process. Process should handle this. All signals start from SIG.
- **SIGNAL MASK?** Collection of Signals blocked is called SM of process. sigprocmask() API is used to define Signal mask but in Single Threaded App.  [Multi-threaded App] use pthread_sigmask() instead of sigprocmask() 
