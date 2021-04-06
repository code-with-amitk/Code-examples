## Example Stack Frame
```c
int fun (int b){
  int c;
  c += b;
  return c;
}
int main(){
  int a = 1;
  cout << fun (a);
}
```

## Stack Frame
 - rbp(Base pointer): points to base of stack
 - rsp(Stack pointer): points to head of stack
 - eax/rax: stores return value of the function. Larger return types like structs are returned using the stack.
 - edi/rdi, rsi, rdx, rcx, r8, r9: Stores 1st 6 arguments to function. If there are more than 6 parameters, then the program’s stack is used to pass in additional parameters to the function.
```c
|----stack grows-----|-------------><------heap grows------
450		   400
rbp     	   rsp

								  STACK
main:
    push rbp		        //save rbp on stack. 		80--------70			//Function prologue/Preemble
								rbp	 rsp
									
    mov  rbp, rsp	        //rbp=rsp			----------70			//Function prologue/Preemble
			    					         rbp
			    							 
    sub  rsp, 16	        //rsp = rsp - 16		----------70----------54	//Function prologue/Preemble
			        //New stack(16 bytes) created	 	 rbp	      rsp
		
    mov DWORD PTR [rbp-4], 1   //*(rbp-4) = 1			----------70--1-------54
    			       //Copy local variable on stack		  rbp	      rsp
			       
    mov eax, DWORD PTR [rbp-4]  //Copy argument of fun() to eax		eax=1
    
    mov edi, eax		//edi=eax				edi=1
    
    call fun(int)
	
fun(int):
    push rbp			//save rbp on stack. 		----------70--1-------54	//Function prologue/Preemble
     									  rbp	      rsp
									  
    mov  rbp, rsp		//rbp=rsp			----------70--1-------54	//Function prologue/Preemble
    										     rbp
										     
    sub  rsp, 32		//rsp = rsp-32			----------70--1-------54------22	//Function prologue/Preemble
    										      rbp     rsp
										      
    mov  DWORD PTR [rbp-20], edi  //*(rbp-20)=edi=1		----------70--1-------54--1----22
    				  //Save function argument			      rbp      rsp
    
    mov  eax, DWORD PTR [rbp-20]  //eax=1
    
    add  DWORD PTR [rbp-4], eax	  //*(rbp-4) += eax
    
    mov  eax, DWORD PTR [rbp-4]	  //eax = *(rbp-4)
    leave
    ret

https://godbolt.org/
# gcc -o RE -g
# insight RE	//insight is GDB front end on fedora
<MIXED VIEW>
```
