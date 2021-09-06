**Process**
- **Creating Child Process**
  - [fork()](#f) 
    - [When fork can fail](#fail)
  - [Code](#c)

## Process
Running instance of program. All processes are decedents of swapper process(PID=0). Both(threads, processes) are independent sequence of operations

## Creating Child Process
<a name=f></a>
### fork() {internally implemented using clone()}
- Creates a new child process. Compelte [`|CS|DS|SS|HS|`](https://sites.google.com/site/amitinterviewpreparation/c-1) of parent is duplicated to child.
- New PCB is created for child. Code Segment is Duplicated using [COW(Copy on Write)](/Threads_Processes_IPC/Processes/process_copy_on_write.c)
- Check [fork code](Code)
```c
pid_t fork(void)        //typedef int pid_t;
 
<---------------- Memory ------------------------->
         -------fork() Duplicates-----
        |                            \/
 |Stack|Heap|DS|CS|              |Stack|Heap|DS|CS|
   Parent                           Child
                 
 int k = fork();       //int fork()
 if (k==0){
   cout << "Child"";
 }else{
   cout << "Parent";
 }   
//Code executed by both parent and child

getppid(): To get Parent's ProcessID.    
getpid(): Get self PID
int wait(int *status): Parent process to wait for child to terminate. returns pid of terminated child, sets term_status in status. 
This blocks parent if it has any unterminated child, else returns immediately.
```
<a name=fail></a>
#### When fork can fail
Fork can fail if there are:
- *a.* No free slots left in the [process table](/Threads_Processes_IPC/Processes/Process_Table). 
- *b.* and possibly if there is no memory or [swap space](/Operating_Systems/Linux/Daemons_Processes_Services/Systemd_PID1/Booting_up_With_systemd.md) left.

<a name=c></a>
### [Code](Code)
- 2 Children of parent
- 1 Child of parent
- Copy on Write
- 
