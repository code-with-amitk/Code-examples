## Process Creation
- **What**
  - Running instance of program. All processes are decedents of swapper process(PID=0)
  - Both(threads, processes) are independent sequence of operations
- **API for creation**
```c
pid_t fork(void)        //typedef int pid_t;
 - Creates a new process(called child process), Called once, returns twice. fork() is internally implemented as using clone().
 
                pid_t pid = fork()
      ------------|----------------
      |                           |
   pid=0(child)                 parent
|CS|DS|SS|HS|               |CS|DS|SS|HS|        
```
- **COW(Copy On Write)**
  - CS, DS, SS, HS all are shared between parent & child Initially. If any one of them Modifies, New page is created & modified data is copied
- **Other APIs**
```c
getppid(): To get Parent's ProcessID.    
getpid(): Get self PID
int wait(int *status): Parent process to wait for child to terminate. returns pid of terminated child, sets term_status in status. 
This blocks parent if it has any unterminated child, else returns immediately.
```  

## Code
```c
#include<unistd.h>
#include <stdio.h>

int main(){
  pid_t pid;
  pid = fork();
  if (pid == 0){                       //Child
    printf ("Inside Child\n");
    printf ("[Child] Parent's PID=%d\n", getppid());      //175. Parent's PID is always smaller since its created earlier.
    printf ("[Child] Self PID=%d\n", getpid());           //176
  }
  else                                    //Parent
  {
    printf ("Inside Parent\n");
    printf ("[Parent] Parent's PID=%d\n", getppid());     //92
    printf ("[Parent] Self PID=%d\n", getpid());          //175
  }
}
$ ./a.out
Inside Parent
Inside Child
[Parent] Parent's PID=92
[Child] Parent's PID=175
[Parent] Self PID=175
[Child] Self PID=176
```
