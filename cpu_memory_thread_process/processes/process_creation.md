## Process Creation
- **What**
  - Running instance of program. All processes are decedents of swapper process(PID=0)
  - Both(threads, processes) are independent sequence of operations
- **API for creation**
```c
pid_t fork(void)        //typedef int pid_t;

 - Creates a new process(called child process), child runs concurrently with parent process. 
 - fork() is internally implemented as using clone(). Called once, returns twice.
```
- **COW(Copy On Write)**
  - CS, DS, SS, HS all are shared between parent & child Initially. If any one of them Modifies, New page is created & modified data is copied
- **Other APIs**
```c
getppid(): To get Parent's ProcessID.    
getpid(): Get self PID
int wait(int *status): Parent process to wait for child to terminate. returns pid of terminated child, sets term_status in *status. This blocks parent if it has any unterminated child, else returns immediately.
```  

## Code
```c
#include<unistd.h>
#include <stdio.h>

int main(){
  if (fork() == 0){                       //Child
    printf ("Inside Child");
    printf ("Parent's PID=%d", getppid());
    printf ("Self PID=%d", getpid());  
  }
  else                        //Parent
  {
    printf ("Inside Parent");
    printf ("Parent's PID=%d", getppid());
    printf ("Self PID=%d", getpid());  
  }
}
# ./a.out
Inside Parent
  Parent's PID=42
  Self PID=144
Inside Child
  Parent's PID=144
  Self PID=145
```
