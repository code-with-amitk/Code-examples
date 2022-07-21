## fork
- *1.* Parent process has values on stack,heap,Data segment.
- *2.* with for() everything duplicated.
- *3.* Child changed it's Stack, Heap, Data Segment.
- *4.* Parent, child will have seperate values in Stack, Heap, Data Segment.
```c
             -------------2. fork() Duplicates----------
             |                                         \/                  
             PARENT                                   CHILD
    Stack   Heap     Data Segment              Stack   Heap     Data Segment
 1. | pPtr | "PARN" | g_a=1, g_b=0 |          | pPtr | "PARN" | g_a=1, g_b=0 | 
      |       /\                             
       --------                               3. Child changes its values
                                                Stack   Heap     Data Segment
                                              | pPtr | "CHLD" | g_a=10, g_b=50 |
                                                 |       /\
                                                 -------- 

 4. 
  PARENT pPtr=PARN, g_a=1, g_b=0
  CHILD  pPtr=CLD, g_a=10, g_b=0
```

### Code
```c
#include<unistd.h>  //fork
#include<iostream>
#include<cstring>

//DS
int g_a = 1;    //Initialized
int g_b;        //Uninitialized

int main(){
  string str;                       //Stack

  char *p = new char[7];                //Heap
  strcpy(p, "Parent");

  std::cout << "[Before fork] g_a: " << g_a\
            << ", g_b: " << g_b\
            << ", p: " << p << std::endl;

  int k = fork();

  if (k==0){      //CHILD
    g_a = 10;                        //DS
    strcpy(p,"Child");            //Stack
    std::cout << "\n[CHILD] g_a: " << g_a\
              << ", g_b: " << g_b\
              << ", p: " << p << std::endl;
  }else{
    std::cout << "Parent";
  }

  std::cout << "\n[AFTER fork] g_a: " << g_a\
            << ", g_b: " << g_b\
            << ", p:" << p << std::endl;

  delete p;
  return 0;
}

# ./a.out
[Before fork] g_a: 1, g_b: 0, pPtr: PARN

[PARENT]
[CHILD] g_a: 10, g_b: 0, pPtr: CHLD

[AFTER] g_a: 1, g_b: 0, pPtr: PARN		<<Notice Executed Twice, 1 for Parent, 1 for Child
[AFTER] g_a: 10, g_b: 0, pPtr: CHLD
```

## Commands
```c
//Complete Tree
# pstree -hp |grep a.out
  |-gnome-terminal-(4730)-+-bash(4737)---su(4886)---bash(4908)---a.out(10005)---a.out(10006)
Parent PID=10005   Child PID=10006

//PID of parent in child
  pid_t ppid = getppid();
```
