## Memory layout of Object
- **this pointer?** 1st argument to constructor function is address of object itself which called it ie this pointer
- **Registers?**
  - Arguments to function are stored in:  rdi, rsi, rdx, rcx, r8...r15
  - Return value of function is stored in: rax   
- **MEMORY LAYOUT OF OBJECT**
```c
        | this-pointer=0x401 | member-variable-1 | member-variable-2 |
        0x401
```    

### Code
```c++
#include<iostream>
class A{
        long a;
public:
        A(long b){
                a=b;
        }
};
int main(){
        A obj1(1);              //A obj1(this, 1);
        A obj2(obj1);
}
```

### Assembly
```asm
main:                                               STACK
  push rbp               //save rbp on stack. 	80--------70			//Function prologue/Preemble
                                                rbp      rsp
                                                  
  mov  rbp, rsp          //rbp=rsp		----------70			//Function prologue/Preemble
                                                          rbp
                                                            
  sub  rsp, 16           //rsp = rsp - 16	  ----------70----------54	//Function prologue/Preemble
		//New stack(16 bytes) created               rbp	        rsp
  
  lea  rax, [rbp-8]      //Load effective address           //rax = 62
  
  mov  esi, 1             //esi = 1(2nd argument)
  
  mov  rdi, rax             //rdi = rax(1st Argument)<<this pointer
  
  call A::A(long)              //Call to function A::A(long) ie constructor
  
  mov  rax, QWORD PTR [rbp-8]  //12
  
  mov  QWORD PTR [rbp-16], rax //13
  mov  eax, 0                  //return value of main=0
  leave
  ret
  
A::A(long):
  push rbp                                         ----------70----------54	//Function prologue/Preemble
                                                                        rsp

  mov rbp, rsp                       //rbp=rsp		      ----------54-------------			//Function prologue/Preemble
                                                                        rbp           rsp

  mov QWORD PTR [rbp-8], rdi     //store 1st argument on stack  ----------54---1-------
                                                                          rbp         rsp

  mov QWORD PTR [rbp-16], rsi     //store (2nd argument=esi)    ----------54---this---1----
                                                                          rbp
  mov rax, QWORD PTR [rbp-8]  //rax = *(rbp-8). Store the value in rbp-8 ie 1st argument into rax. rax=this_pointer
  
  mov rdx, QWORD PTR [rbp-16] //rdx = *(rbp-16). Store the value in rbp-16 ie end argument into rdx. rdx=1
    
  mov QWORD PTR [rax], rdx    //Means (*rax)=rdi
    Store rdx into address of rax
  nop
  pop rbp                     //11
  ret

                      *(rax)=*(0x051)=1                                                       
11. Pop stack top=0x21 and make current rbp=0x21
   ----------------main-----
            rbp1 1        rsp1
            /\   /\
         control rax
         here

12. rax is assigned rax=*(rbp-8)=1 
   ----------------main-----
            rbp1 1        rsp1
                 /\
                 rax

13. Value of 1st member of object (scope main()) is given 1. 
    *(rbp1-16)=1
    *(rbp1-16)=1
   ----------------main-----
            rbp1 1  1     rsp1
```
