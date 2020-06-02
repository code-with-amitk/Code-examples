/*      process_creation.c
  
pid_t fork(void)        //typedef int pid_t;
 - Creates a new process, which is called child process, which runs concurrently with parent process. 
 - Internally implemented as using clone(). Called once, returns twice
COW(Copy On Write): 
- CS, DS, SS, HS all are shared between parent & child Initially. If any one of them Modifies, New page is created & modified data is copied
getppid(): To get Parent's ProcessID.    
getpid(): Get self PID    
int wait(int *status): Parent process to wait for child to terminate. returns pid of terminated child, sets term_status in *status. This blocks parent if it has any unterminated child, else returns immediately.
*/

#include<unistd.h>
#include <stdio.h>
int main(){
        if (fork() == 0){                       //Child
                printf("Inside Child.\
                        Parent's PID[%d] \
                        selfPID[%d]\n\n", getppid(), getpid());
        }else{                                  //Parent
                printf("Inside Parent. \
                        Parent's parent PID[%d]\
                        selfPID[%d]\n\n", getppid(),getpid());
        }
}
