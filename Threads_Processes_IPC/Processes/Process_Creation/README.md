## fork()
- Creates a new process(called child process). Parent has `|CS|DS|SS|HS|` in memory, on fork 1 more copy is created and processor is allocated to each randomly.
- fork() is internally implemented as using clone().
```c
pid_t fork(void)        //typedef int pid_t;
 
<---------------- Memory ------------------------->
 Parent's|CS|DS|SS|HS| 
                |                      Child's
              fork()  ----copies --> |CS|DS|SS|HS|
                 
 
 main() {   //Parent    
  if (fork() == 0)    //Child
  else               //Parent
 }

getppid(): To get Parent's ProcessID.    
getpid(): Get self PID
int wait(int *status): Parent process to wait for child to terminate. returns pid of terminated child, sets term_status in status. 
This blocks parent if it has any unterminated child, else returns immediately.
```

## [Code](Code)
- **Creating n children of parent**
   - _1._ 1 child of parent
   - _2._ 2 children of parent
- **COW(Copy On Write):** 
  - CS, DS, SS, HS all are shared between parent & child Initially. If any one of them Modifies, New page is created & modified data is copied

