## How many Temporary copies are created?

### Creating copy using function call
3 copies

```
#include<iostream>
using namespace std;
int fun(int a){
    return a;
}
int main(){
    int a = 10;
    int b = fun(a);
}

ASSEMBLY:
fun(int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi    //6
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     DWORD PTR [rbp-4], 10     //3
        mov     eax, DWORD PTR [rbp-4]    //4
        mov     edi, eax                  //4
        call    fun(int)
        mov     DWORD PTR [rbp-8], eax
        mov     eax, 0
        leave
        ret
        
STEPS:        
1. Function Epilogue.
   a. Push value of rbp0 somewhere on stack
   ------------                        Head
   rbp0     rsp0                Stack | rbp0=0x450 |
   
   b. Move rbp to rsp
   --------------------
            rsp0
            rbp1
            
2. Create stack for main. size 16 bytes.
   ---------------main-----
            rbp1        rsp1
            0x400       0x384
            
3. Save 10 on stack.
   ---------------main--------
            rbp1 10         rsp1
            0x400           0x384
            
4. Store 10 on eax,edi registers.
   ------------------main-----
            rbp1 10         rsp1                Registers
            0x400           0x384               eax=10, edi=eax   //rdi, rsi, rdx, rcx, r8, r9: Stores 1st 6 arguments to function.
<<<<<<<<<<1st COPY CREATED. Value 10 is copied from main()'s stack to EDI register>>>>>>>>>>>>>>>>>>>>>>
            
5. Function Epilogue
a. Push value of rbp1 somewhere on stack
   -------------------------             Head
             rbp1       rsp1     Stack | rbp1=0x400 | rbp0=0x450 |
   
   b. Move rbp to rsp
   ------------------------------------------
                        rbp2              rsp2
                        0x384           

6. Copy edi to fun() stack
   ------------------------------------------
                        rbp2 10           rsp2
<<<<<<<<<<2nd COPY CREATED. Value 10 is copied from fun()'s stack from EDI register>>>>>>>>>>>>>>>>>>>>>>                        

7. Copy value from stack to eax register(after calculations).
   ------------------------------------------
                        rbp2 10           rsp2      Registers
                                                    eax=10      //rax: stores return value of the function
<<<<<<<<<<3rd COPY CREATED. Value 10 is copied from fun()'s stack from RAX register>>>>>>>>>>>>>>>>>>>>>>                                                     
```
