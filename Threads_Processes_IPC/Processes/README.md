**Process**
- **Creating Child Process**
  - [fork()](#f) 
    - [When fork can fail](#fail)
  - [Code: 1 Child, 2 children, fork, n forks](#c)
- **Memory Layout of Process**
  - [1. Code Segment](#cs)
    - [Size of CS](#scs)
  - _2._ Data Segment
    - [Parts of DS: Initialized DS, UnInitialized DS / BSS, Pointer to Heap](#partsds)
  - [3. Stack Segment](#ss)
    - [Stack Frame](#sf)
    - [Stack Overflow](#so)
    - [Stack Smashing](#ss)
    - [MAX Stack Size / Maximum stack allocated to process at start](#maxs)
  - [4. Heap](#h)
    - [Max Heap Size](#maxh)
    - [Heap Overflow](#ho)
- [Process States](#pros)
- [PCB / Process Control Block](#pcb)
- [Process Table](#pt)

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
- n forks

<a name=ml></a>
# Memory Layout of Process
```console
                   |                                                                                               |
                   |                          <------DATA SEGMENT (static, global) ----------->                    |
[Kernel] Process-2 |[STACK] shared_libraries {PTR-To-HEAP} {Uninitialized_BSS} {Initialized DS} [TEXT/CODE SEGMENT]|
                   | ----->                                BlockStartedBySymbol <-RW--><--RO-->              0x0000|
                   |                                                                                               |
```
<img src=memory-layout-of-process.PNG width=700/>

<a name=cs></a>
## 1. Code/Text Segment
- (RO) Have Executable Instructions. Neither grows nor shrinks.
- When a process is run twice OS maintains 1 set of pages kept in main memory. Both processes points to same memory (ie does not have personal CS)
<a name=scs></a>
#### Size = 8k 
Does not change since its Read Only

## 2. Data Segment {Stores Global, Static}
<a name=partsds></a>
### Parts of Data Segment
#### 2a. Initialized DS
Initialized by Coder. Again its divided into 2 parts:
  - *A1. RO(READ ONLY):* Global constants are stored here. Eg: const char `*a = "test"`
  - *A2. RW(READ WRITE):* Stores Initialized globals, extern variables, local static.
```c
char s[] = "test";  //Initialized Globals
int a = 1;        
static int b = 1;

extern int a;     //Extern variable

static int a;     //Local static
```

#### 2b. Unintialized DS / BSS(Block Started by Symbol) 
Stores uninitialized global and static. Data is Initialized to 0(by kernel) before code start executing.
```c
 int a;        
 static int b
```

#### 2c. Pointer-to-Heap 
Data Segment also stored pointer to heap. As memory is allocated/deallocated on heap using malloc() DS grows/shrinks. 
```c
 malloc()->brk()        
 realloc()->sbrk()
``` 

<a name=ss></a>
## 3. Stack Segment
- **Stores:** Local variables, Registers, Stack Frame pointer, return address, stack-based parameters, stack frame as LL

<a name=sf></a>
### Stack Frame
{Input_parameters} {Return_address} {Local_variables}
```c
  add(int a, int b){
    int c;               //Local
  }
  main(argv[0],argv[1]){            
    int a ,b;
    add(a,b);
  }   

--------stack allocated in this direction---->
[ argv[1] argv[0] | 0x45 | b a ]  [ | b a | 0x68 | c | ]     //Input parameters are pushed in reverse order
<---    sf of main()  --------->  <--sf of add()---->
```
**Popping of Stack frame:** 
- Function add() finishes, will clear its stack. add() will pop local variables. popped 'c', add() will pop return address (0x68) and control reaches inside main. 
- Now main() is responsible for cleaning rest of add() stack frame ie (b, a)
  - rsp: Stack Pointer: Head of Stack Frame(Not Stack)
  - rbp: Base Pointer Tail of Stack Frame

<a name=so></a>
### Stack Overflow
When program overflows stack based local variable or when process uses all its stack. At end of process's stack there is a GUARD PAGE, when process goes into it. Its a Segmentation Fault. Code causing stack overflow:
```c
    fun() {
        fun();
    }
``` 

<a name=ss></a>
#### Stack Smashing
Stack overflow caused deliberately as part of an attack.

<a name=maxs></s>
### MAX Stack Size / Maximum stack allocated to process at start
- Why 8MB of stack? In a single-threaded process, the address space reserved for the stack can be large and difficult to overflow
- Why Stack size != Virtual Memory size (As Heap size = Virtual Memory size)? 
  - Every thread has its own Stack.if thread-1 consumes all virtual memory and thread-2 also, nothing left.
```c
 8 MB(Default)  #cat /proc/pid/limits     //Linux
 1 MB(Default)                            //Windows
 
 $ ulimit -u unlimited                    //Changing stack size
```

<a name=h></a>
## 3. Heap
Memory area for dynamic Memory allocation

<a name=maxh></a>
### Max heap Size
Max Heap Size=Virtual memory size. [What is max VM Size](/Motherboard/CPU/Memory/Virtual_Physical_Memory)

<a name=ho></a>
### Heap Overflow / Memory leak
- When process keeps on allocating more and more memory without freeing it causes Heap overflow. 
- Aftermaths: System shutdown, Crash, System becoming dead-slow. 
```c
    while(1){ 
      char *p = (char *) malloc(12); 
    }
```

<a name=pros></a>
## Process States
- When a process executes, it passes through different states.
  - **a. Start:** Initial state when a process is first started/created.
  - **b. Ready:** The process is waiting to be assigned to a processor. 
  - **c. Running(Flag R):** Once the process has been assigned to a processor by the OS scheduler state changes to running.
  - **d. Waiting/Sleeping(Flag S):** Process moves into the waiting state if it needs to wait for a resource, eg: waiting for user input or file.
  - **e. Terminated or Exit:** Once the process finishes its execution, or it is terminated by the OS. Here it waits to be removed from main memory.

<a name=pcb></a>
## PCB / Process Control Block / Process Context
PCB is a data structure([struct task_struct](https://www.cs.fsu.edu/~baker/opsys/examples/task_struct.html)) for storing all information of a process inside kernel.
```c
struct task_struct {
  long                 priority;
  struct task_struct   *next_task, *prev_task;            //DOUBLY LL
  int                  pid;                               //PID
  int                  pgrp;									            //Process Group
  struct task_struct   *p_opptr, *p_pptr, *p_cptr,        //Pointers to parent, youngest child, silbilings etc
  unsigned short       uid,suid,gid,sgid..;               //UID,GID
  struct fs_struct     *fs;                               //File system information
  struct sem_queue     *semsleeping;                      //IPC Information
  struct mm_struct     *mm;                               //memory management info
  struct signal_struct *sig;                              //signal handlers
  //Register information.
};
```
- **Why PCB is needed?** 
  - When process changes state (ie switched from running to waiting/sleeping state(due to context switch or interrupt)) kernel stores info in PCB, so that process can resumed later from same poing using this information. 
  - Information of child processes is stored in PCB of parent process etc.
- **Information stored in PCB?** 
  - [Register values of present process, stack pointer (rbp)](/assembly) etc
  - Process-state: Any of 5
  - pid: process-id
  - [Program Counter/Instruction Pointer](/Motherboard/CPU/Memory/CPU_Registers/Special_Purpose_Registers/Instruction_Pointer): Address of next instruction to be executed on Code segment of this process.
  - priority: This is a number. Process having higher priority execute 1st.
  - [General purpose registers](/Motherboard/CPU/Memory/CPU_Registers/General_Purpose_Registers): Stores results of calculations done by process in Memory segment.
  - list of open files, list of open devices. This all information is called PROCESS CONTEXT.

<a name=pt></a>
## Process Table
- Information of every process is stored in [PCB, process control block](#pcb). Process Table is mapping of PID to PCB inside kernel.
- **PCB vs [Memory layout of process](#ml)** 
```c
        |             PCB                                     |     Process Space                      |
--------|-----------------------------------------------------|----------------------------------------|
What    |Contains data to access state,do context switch etc  | Contains user data in Stack,Heap,CS,DS |
Stored  | in kernel                                           | in User space                          |
```

<img src=pcb.png width=1000/>
