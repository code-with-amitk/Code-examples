/*	stack-frame.c
	
https://godbolt.org/
https://amitkumar25nov.wordpress.com/stack-frame-example-code/

----stack grows------><------heap grows------
rbp     	   rsp

rbp: Base pointer, points to base of stack
rsp: Stack pointer, points to head of stack

.LC0:
	.string "Hello"

main:
HIGH-LEVEL  INSTR	     MEANING		Pictorial
<<<<<<<<<<<function prolgue/premble main start>>>>>>>>>>>>>>>>>
int main()  push rbp	 save rbp on stack      ---------
						rbp    rsp

	    mov rbp,rsp	 make rbp point to rsp  ---------
	                                               rbp

	    sub rsp,16   Subtract 16 from rsp.	        --16bytes--
	                 Means New stack created        rbp(20) rsp(10)
			 is of 16 bytes (as of now)
<<<<<<<<<<<function prolgue/premble main end>>>>>>>>>>>>>>>>>
int a=10 mov dword ptr   Store 5 in rbp-4.		----------
	   [rbp-4], 5    Since stack grows -ve	       rbp 5     rsp

	 mov eax, dword  copy 1st function 
	 ptr [rbp-4]     argument to eax=10
	
	 mov edi, eax    edi = eax = 10
	 call f1
	 [[[control comes from f1]]]
	 mov eax,0	 eax=0
	 leave
	 ret

f1:
HIGH-LEVEL  INSTR	     MEANING		  Pictorial
<<<<<<<<<<<function prolgue/premble f1 start>>>>>>>>>>>>>>>>>
void f1()  push rbp	 save rbp on stack      
	   mov rbp,rsp	 make rbp point to rsp  ---main()-- 
	                                        rbp 5     rsp
							  rbp
	   sub rsp,16   rsp = rsp - 16	        ---main()-- -----16bytes--
	                Means New stack        rbp 5      rsp		rsp
							  rbp
	   
int b	   mov dword ptr rbp-20=10		---main()-- -----32bytes--
	   [rbp-20] edi				rbp 5      rsp 	     10 rsp
	   						   rbp

int c=5	   mov dword ptr rbp-4=5		---main()-- -----32bytes--
	   [rbp-4] 5	   			rbp 5      rsp 5     10 rsp
	   						   rbp
printf     mov edi,OFFSET 1st argument of 
	   FLAT:LC0       printf
	 
	   mov eax,0	argument of
	   		printf
	   call	printf
	   nop
	   leave
	   ret	   
*/

#include<stdio.h>
void f1(int b){
	int c=5;
    	printf("Hello");
}
int main(){
	char t[]="hello";
    	int a=10;
    	f1(a);
}

/*
https://godbolt.org/
# gcc -o RE -g
# insight RE	//insight is GDB front end on fedora
<MIXED VIEW>
*/
