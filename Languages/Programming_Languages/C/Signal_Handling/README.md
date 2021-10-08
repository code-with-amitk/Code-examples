**Signals**
- [Signal Examples](#eg)
- 
## Signals
This is Software Interrupt to processor. For Example: Cntl^C, sends SIGINT to running process. Process should handle this. All signals start from SIG.
### Signal Examples
```c
 Signal	| Signal No |   Short Name |	  Meaning Details
--------|-----------|--------------|------------------------------------------------------
 SIGHUP |   1       |    	HUP    	 |  Hang Up    When terminal controlling the process is closed 
 SIGINT |   2       |   	INT 	   |  keyboard Interrupt 	Cntrl C 	
                                      Can be caught?Yes 	If not caught, Terminate the process. Used for graceful termination 
                                      
SIGQUIT |	  3 	    |     QUIT 	   | Keyboard Quit 	Cntl +\    OR    Cntl Z 	
                                    Can be caught? Yes 	Similar to SIGINT but Generates core dump on termination, cleans up resources. 
                                    
SIGBUS 	| 	 	 	 	 	               | signal is sent to a process when it causes a bus error(access memory that 
                                      the CPU cannot physically address: an invalid address for the address bus)
                                      
SIGTRAP |	    5 	 |Trace/breakpoint trap | Debuggers register and handle this signal.
                                            This is sent to debugger process when trap() occurs, for example, when a particular 
                                            function is executed, or when a particular variable changes value. 
Will kill if not caught in signal handler.
SIGABRT 	6 	Abort 	Abort current process 	abort() system call 
$ kill  -SIGABRT  <pid>	 	void main(){
    abort();    //Generates SIGABRT
} 
SIGKILL 	 9	KILL	Kill(POSIX) 	kill -9 pid     OR    kill -SIGKILL pid	NO 	Will always terminate the process. Terminates immediately, does not allows process to do clean up.
SIGSEGV 	11 	 	Segmentation fault 	 	 	Program accessed a memory location that was not assigned.
SIGALRM	 14	 	 Alarm clock	 	 	//Code to print Hi after 1 sec.
fun(){  printf("Hi");  }
void main(){
     signal(SIGALRM, fun); 
     alarm(1);    //alarm(t) generates SIGALRM after t sec.
} 
SIGTERM 	 15	 TERM	Termination(ANSI) 	$ kill pid     OR    $ kill -SIGTERM pid	Yes 	If not caught, Terminate the process. Used for graceful termination. 
SIGCHLD 	 17	 	Child Process has stopped or Exited  	 	Yes 	When child dies it send SIGCHLD to parent.
void signalHandler(int signal){
    if(signal == SIGCHLD){
        printf("Child Dead");
    }
}
main() {
     signal(SIGCHLD,signalHandler);
     if(fork() == 0){    //Child Process
        sleep(5);
        printf("Child dying")
    }
}  
SIGCONT 	 18	CONT 	Continue the suspended process 	 	NO 	Resume the stopped/suspended process. It always resumes the process.
SIGSTOP 	 19	STOP 	Stop Executing.
Suspend the process donot Kill	kill -STOP pid 	NO 	Suspends the process. 
SIGSTP 	20 	 TSP	Keyboard Stop 	Cntl + Z 	Yes 	Suspend the process can be continued later using SIGCONT 
 	





SIGPIPE 	 	 	 	 	 	When SIGPIPE is generated?
Scenario-1: When process attempts to write to a pipe whose Read-end is closed.
       Parent                                    Child
                    Write-end    Read-end
                        |-parent pipe--|
                        |-child pipe---|
Scenario-2: Attempt to write to socket what is no longer open for reading.
Default Action: Terminate the process
SIGUSR1 	 	 	 	 	 	SIGUSR: User Defined Signals. 
They donot have any special meaning as SIGTERM, SIGKILL etc. Kernel will never send SIGUSR to process.
Meaning of signal can be set up by user as per need of application. 
SIGUSR2 	 	 	 	 	 	 
SIGWINCH 	 	 	Signals Window Change 	 	 	sent automatically when a terminal detects a change in it's windows size to allow for a redraw.
In Apache2: unfortunately apache2 process poorly misuses this signal (in the way they divert its first meaning).
What to check?
Do you run apache2 in foreground in an open tty ? If yes, this is not recommended (alas), and you'll probably easily hit this SIGWINCH gracefull shutdown quite easily when resizing your controlling terminal
```
- **SIGNAL MASK?** Collection of Signals blocked is called SM of process. sigprocmask() API is used to define Signal mask but in Single Threaded App.  [Multi-threaded App] use pthread_sigmask() instead of sigprocmask() 
