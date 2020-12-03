## fork()
- Returns:
  - 0 to the child
  - nonzero to the parent.
```c
/* This is a simple code which does following:
 1. Takes two variables:  
	(a)global variable(DS) 
	(b)local pointer(SS)
 2. fork()
 3. Change/Check values of (a),(b) in child and parent memory segments
 4. Check values of (a),(b) at end of program.
*/

#include<stdio.h>
#include<stdlib.h>	//malloc
#include<string.h>	//strcpy
#include<unistd.h>	//fork
//# gcc -Wall fork.c
int globalVar = 10;		//Data Segment
int main(){
printf("\n**********************Basics***********************************\n\
- All Segments CS(COW), DS(Global, Static), HS, SS(Local Var) are duplicated in child\n\
  DS(Static & Global), HS(Dynamic Memory), SS(Local Var)\n\n\
int main(){\n\
	k = fork()\n\
	if(k!=0){\n\
		-PARENT executes here. k is PID of Child\n\
	}else{\n\
		-(k==0) CHILD executes here. getppid() to get Parent Pid\n\
	}\n\
	....	//This Code is executed by Both Parent & Child\n\
}\n\n\
# pstree -hp |grep a.out	//Getting parent and child PIDs\n\
           |-gnome-terminal-(4730)-+-bash(4737)---su(4886)---bash(4908)---a.out(10005)---a.out(10006)\n\
									Parent PID=10005   Child PID=10006\n\
***************************************************************\n\
");
	char p[] = "abcd";
	int k;

	char *localPtr;		//Stack Segment Variable
	localPtr = malloc(sizeof(p));	//Memory Allocated on Heap
	strcpy(localPtr,p);
	printf("\n-> Before Fork\nglobalVar=%d, &globalVar=%p, localPtr=%s, &localPtr=%p\n",globalVar, &globalVar, localPtr, &localPtr);

	printf("\nChild will do globalVar=150, strcpy(localPtr,\"CHLD\")\n");
	printf("Parent will do globalVar=300, strcpy(localPtr,\"PARN\")\n");
	printf("\nfork() called \n");
	k = fork();
	if(k){	//PARENT (k!=0)
		printf("\nInside Parent. Self pid=%d, k(child pid)=%d", getpid(),k);
		globalVar = 150; strcpy(localPtr,"CHLD");
		printf("\nglobalVar(child)=%d, &globalVar(child)=%p, localPtr(child)=%s, &localPtr(child)=%p\n",globalVar,&globalVar,localPtr,&localPtr);
		
	}else{	//CHILD (k==0)
		pid_t ppid;
		ppid = getppid();
		//printf("\nInside CHILD. Self pid=%d, Parent pid=%d, k=%d", getpid(),getppid, k);
		printf("\nInside CHILD. Self pid=%d, Parent pid=%d, k=%d", getpid(),ppid, k);
		globalVar = 300; strcpy(localPtr,"PARN");
		printf("\nglobalVar(parent)=%d, &globalVar(parent)=%p, localPtr(parent)=%s, &localPtr(parent)=%p\n",globalVar,&globalVar,localPtr,&localPtr);
		
	}

	printf("\nOutside if else\nglobalVar = %d, &globalInt =%p, localPtr=%s, &localPtr=%p\n",globalVar, &globalVar, localPtr, &localPtr);
	printf("\nFreeing localPtr\n");
	free(localPtr);
	sleep(10);
	printf("\n***********************Conclusion************************\n\
For CHILD:\n\
	- Seperate CS(COW), DS, HS, SS are created\n\
	- Logical addresses of variables remain same, But Physical addresses would be different\n\
Code After if_else block:\n\
	- Is executed by both parent and child.\n\
	- See this is also executed twice\n\
*******************************************************\n");
	return 0;	
}
```
