## How many temporary copies are created by Default Ctr?

### Creating object using Default ctr?
- To create a class object using default ctr, 3 temporary copies of member variables are created.
- For example, we are creating a object by calling default ctr
  - In this process, 3 temporary copies of member variables are created.
  
**EXAMPLE CODE**
```
#include<iostream>
using namespace std;
class A{
    int a;
public:
    A(int b):a(b){}      //1st hidden argument is default ctr
};
int main(){
    A obj1(10);         //1st hidden argument is this pointer
}
```

**ASSEMBLY**
```assembly
A::A(int):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi    //6
        mov     DWORD PTR [rbp-12], esi   //6
        mov     rax, QWORD PTR [rbp-8]
        mov     edx, DWORD PTR [rbp-12]
        mov     DWORD PTR [rax], edx
        nop
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-4]                //3   //rax = address-of(rbp-4)
        mov     esi, 10                     //4
        mov     rdi, rax                    //4
        call    A::A(int)
        mov     eax, 0
        leave
        ret
```

**STEPS**
```
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
            
3. Store address of (rbp-4) THIS Pointer to RAX
   ---------------main--------
            rbp1            rsp1              Registers
            0x400           0x384             rax = 0x396
            
4. Store 10 on esi register. Store rax on rdi.
   ------------------main-----
            rbp1            rsp1               Registers
            0x400           0x384              rax = 0x396, esi=10, rdi=rax   //rdi, rsi, rdx, rcx, r8, r9: Stores 1st 6 arguments to function.
<<<<<<<<<<1st COPY CREATED>>>>>>>>>>>>>>>
- this pointer copied from main()'s stack to rax. //Argument-1: This pointer
- 10 is copied from main stack to esi register.   //Argument-2: Local variable
            
5. Function Epilogue
a. Push value of rbp1 somewhere on stack
   -------------------------             Head
             rbp1       rsp1     Stack | rbp1=0x400 | rbp0=0x450 |
   
   b. Move rbp to rsp
   ------------------------------------------
                        rbp2              rsp2
                        0x384           

6. Copy rax &  esi to default ctr stack
   ------------------------------------------
                        rbp2 0x396 10      rsp2
<<<<<<<<<<2nd COPY CREATED>>>>>>>>>>>>>>>>>
- Argument-1=rax=this pointer copied to A::A(int) stack
- Argument-2=esi=10 copied to A::A(int) stack

7. Copy value from stack to eax register(after calculations).
   ------------------------------------------
                        rbp2 0x396 10     rsp2      Registers
                                                    rax=|0x396,10|       //rax: stores return value of the function
<<<<<<<<<<3rd COPY CREATED>>>>>>>>>>>>>
- rax holds this pointer
- rax also holds value 10
```
