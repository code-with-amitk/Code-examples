## Code
```c
#include<stdint.h>
int64_t fun (int64_t a, int64_t b){
  int64_t c = a+b;
  return c;
}
int main(){
  int64_t a = 1, b = 2;
  fun (a,b);
}
```

## Stack Frame
 - [rbp(Base pointer), rsp(Stack pointer), rax/eax(Accumulator)](/Motherboard/CPU/Memory/CPU_Registers/General_Purpose_Registers)
 - [edi/rdi, rsi, rdx, rcx, r8, r9](/Motherboard/CPU/Memory/CPU_Registers/General_Purpose_Registers): Arguments to function are copied to registers.

- **Steps:**
  - *1.* Push old rbp/ebp on stack. Function Prologue/Premble
  - *2.* Copy arguments on stack in reverse order. rdi=1st arg, rsi=2nd argument
  - *3.* Copy arguments from stack to Registers. rax=1st arg, rdx=2nd arg
  - *4.* Add contents of registers and store on register.
  - *5.* Store return value from rax register to stack.
- **Overall:** 3 copies.
  - {Copy-1} Argument copied from register to stack.
  - {Copy-2} Arguments copied from stack to register. Addition done on register. Stored on register(rax).
  - {Copy-3} Return value/Result copied from register to stack.
```c
|----stack grows-----|------------->
450		   400
rbp     	   rsp

                                             STACK
fun(long, long):
 push rbp                             |-main stack-|old rbp|              //1. Function prologue/Preemble
                                     rbp                  rsp

 mov  rbp, rsp                        |-main stack-|old rbp|               //Function prologue/Preemble
                                                          rbp
							  rsp
 
 mov  QWORD PTR [rbp-24], rdi         |-main stack-|old rbp|   |   |  1  |
                                                          rbp  8   16   24
							  
 mov  QWORD PTR [rbp-32], rsi         |-main stack-|old rbp|   |   |  1  | 2 |    //2
                                                          rbp  8   16   24  32
							  
 mov  rax, QWORD PTR [rbp-24]         rax = 1                                     //3
 mov  rdx, QWORD PTR [rbp-32]         rdx = 2
 
 add  rax, rdx                        rax = rdx+rax = 3                            //4
 
 mov  QWORD PTR [rbp-8], rax          |-main stack-|old rbp|   |   |  1  | 2 |
                                                          rbp  8  16   24   32
 
 mov  rax, QWORD PTR [rbp-8]          rax = 8                                      //5
 
 pop  rbp                             |-main stack-|                               //Function Epilog
 ret
                             
main:
 push rbp                           
 mov  rbp, rsp
 sub  rsp, 16
 mov  QWORD PTR [rbp-8], 1
 mov  QWORD PTR [rbp-16], 2
 mov  rdx, QWORD PTR [rbp-16]
 mov  rax, QWORD PTR [rbp-8]
 mov  rsi, rdx
 mov  rdi, rax
 call fun(long, long)
 mov  eax, 0
 leave
 ret

https://godbolt.org/
# gcc -o RE -g
# insight RE	//insight is GDB front end on fedora
<MIXED VIEW>
```
