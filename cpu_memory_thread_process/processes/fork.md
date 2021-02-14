## FORK
- **What?** System call for creating child process from parent process.
- When fork() is called, complete [Process Space(SS,HS,DS,CS)](https://sites.google.com/site/amitinterviewpreparation/c-1) of parent is duplicated to child, New PCB is created for child. Code Segment is Duplicated using [COW(Copy on Write)](/cpu_memory_thread_process/processes/process_copy_on_write.c)
- Code After if(fork){}else{} is executed by both parent and child.
```c
         --------Duplicated-----------
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
```

## Code
```c
#include<unistd.h>  //fork
#include<iostream>
#include<cstring>
using namespace std;

//Data Segment
int g_a = 1;    //Initialized
int g_b;        //Uninitialized

int main(){
  //Stack: pPtr
  //Heap: memory allocated
  char *pPtr = new char[5]; memset(pPtr,5,0); strcpy(pPtr,"MAIN");
  cout << "[Before fork] g_a: " << g_a << ", g_b: " << g_b << ", pPtr: " << pPtr << endl;

  int k = fork();
  if (k) {  //Parent
    g_a = 2; strcpy(pPtr,"PARN");
    cout << "\b\n[PARENT] g_a: " << g_a << ", g_b: " << g_b << ", pPtr: " << pPtr << endl;
  }else{  //CHILD (k==0)
    g_a = 3; strcpy(pPtr,"CHLD");
    cout << "\n[CHILD] g_a: " << g_a << ", g_b: " << g_b << ", pPtr: " << pPtr << endl;
  }

  cout << "\n[AFTER] g_a: " << g_a << ", g_b: " << g_b << ", pPtr: " << pPtr << endl;
  cout << "Freeing pPtr" << endl;
  delete pPtr;

  return 0;
}

# ./a.out
[Before fork] g_a: 1, g_b: 0, pPtr: MAIN

[PARENT] g_a: 2, g_b: 0, pPtr: PARN
[CHILD] g_a: 3, g_b: 0, pPtr: CHLD

[AFTER] g_a: 2, g_b: 0, pPtr: PARN		<<Notice Executed Twice, 1 for Parent, 1 for Child
[AFTER] g_a: 3, g_b: 0, pPtr: CHLD
Freeing pPtr
Freeing pPtr
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
