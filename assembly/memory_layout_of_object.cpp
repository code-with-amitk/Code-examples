/*      memory_layout_of_object.cpp
  
THINGS TO NOTE:
 a. 1st argument to constructor function is address of object itself which called it
 ie this pointer

About Registers
 - Arguments to function are stored in:  rdi, rsi, rdx, rcx, r8...r15
 - Return value of function is stored in: rax   

MEMORY LAYOUT OF OBJECT:
        | this-pointer=0x401 | member-variable-1 | member-variable-2 |
        0x401
*/

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

/*
ASSEMBLY
A::A(long):
        push    rbp                     //5
        mov     rbp, rsp                //5
        mov     QWORD PTR [rbp-8], rdi  //store (1st argument=address of object=rdi) on stack //6
        mov     QWORD PTR [rbp-16], rsi //store (2nd argument=esii) on stack    //7
        mov     rax, QWORD PTR [rbp-8]  //rax = *(rbp-8)        //8
        mov     rdx, QWORD PTR [rbp-16] //rdx = *(rbp-16)       //9
        mov     QWORD PTR [rax], rdx    //Means (*rax)=rdi      //10
        nop
        pop     rbp                     //11
        ret
main:
        push    rbp                     //1
        mov     rbp, rsp                //1
        sub     rsp, 16                 //2
        lea     rax, [rbp-8]            //rax=&(rbp-8)  //3
        mov     esi, 1                  //2nd argument
        mov     rdi, rax                //1st argument
        call    A::A(long)              //4
        mov     rax, QWORD PTR [rbp-8]  //12
        mov     QWORD PTR [rbp-16], rax //13
        mov     eax, 0                  //return value of main=0
        leave
        ret

STEPS:
1. Function Epilogue.
   Push value of rbp0 somewhere on stack
   ------------                        Head     
   rbp0     rsp0                Stack | rbp0=0x11 |

   --------------------
            rsp1
            rbp1

2. Create stack for main            
   ---------------main----
            rbp1        rsp1    

3. LEA(Load Effective address)
   ----------------main-----            Registers
            rbp1 0x51     rsp1          rax = 0x51
                 /\                     esi = 1(2nd argument)
                 rax                    rdi = rax(1st Argument)<<this pointer

4. Call to function A::A(long) ie constructor

5. Function epilogue
   Push value of rbp1 somewhere on stack
   ----------------main-----                   Head
            rbp1 0x51     rsp1          Stack | rbp1=0x21 | rbp0=0x11 |
                 /\       rbp1
                 rax                    

   ----------------main--------A::A(long)----
            rbp1 0x51     rbp2            rsp2
                 /\
                 rax        

6. Store 1st argument on stack of A::A(long). 1st argument is (address of object=this pointer)
   ----------------main--------A::A(long)----
            rbp1 0x51     rbp2 0x51        rsp2
                 /\
                 rax

7. Store 2nd argument on stack of A::A(long)
   ----------------main--------A::A(long)----
            rbp1 0x51     rbp2 0x51 1      rsp2
                 /\
                 rax

                                                        Registers
8. Store the value in rbp-8 ie 1st argument into rax.   rax=rbp2-8=0x051
9. Store the value in rbp-16 ie end argument into rdx.  rdx=1
10.Store rdx into address of rax.                       *(rax)=*(0x051)=1                                                       
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
*/
