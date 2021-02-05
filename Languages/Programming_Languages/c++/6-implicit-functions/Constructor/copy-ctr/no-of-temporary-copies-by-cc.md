## How many temporary copies are created by copy Ctr?

### Creating object using copy ctr?
- To create a class object using copy ctr, 3 temporary copies of member variables are created.
- For example, we are creating a object by calling copy ctr
  - In this process, 3 temporary copies of member variables are created.
  
**EXAMPLE CODE**
```
class A{
       int a;
public:
       A(int b):a(b){}

       A(const A &k){
               this->a = k.a;
       }
};
int main(){
        A obj1(4);

        A obj2(obj1);
}
```

**ASSEMBLY**
```
A::A(int):
    //Let's not look into Default ctr since we are bothered about copy ctr
    
A::A(A const&):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi    //5
        mov     QWORD PTR [rbp-16], rsi   //5
        mov     rax, QWORD PTR [rbp-16]
        mov     edx, DWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], edx
        nop
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-4]
        mov     esi, 4
        mov     rdi, rax
        call    A::A(int)          //NOT LOOK TILL HERE
        lea     rdx, [rbp-4]      //3
        lea     rax, [rbp-8]      //3
        mov     rsi, rdx          //3
        mov     rdi, rax          //3
        call    A::A(A const&)
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
            
3. Store address of (rbp-4) THIS Pointer to rdx
Store address of (rbp-8) THIS Pointer to rax
Store rsi = rdx.  rdi = rax
   ---------------main--------
            rbp1            rsp1              Registers
            0x400           0x384             rdx = 0x396, rax = 0x392  
                                              rsi = 0x396, rdi = 0x392  //rdi, rsi, rdx, rcx, r8, r9: Stores 1st 6 arguments to function.
<<<<<<<<<<1st COPY CREATED>>>>>>>>>>>>>>>
- rsi is this pointer (1st argument)
- rdi = 10 (2nd argument)

4. Function Epilogue
a. Push value of rbp1 somewhere on stack
   -------------------------             Head
             rbp1       rsp1     Stack | rbp1=0x400 | rbp0=0x450 |
   
   b. Move rbp to rsp
   ------------------------------------------
                        rbp2              rsp2
                        0x384          

5. Copy rdi, rsi to copy ctr stack
*(rbp-8) = rdi
*(rbp-16) = rsi
   ------------------------------------------
                        rbp2 0x392 0x396    rsp2
<<<<<<<<<<2nd COPY CREATED>>>>>>>>>>>>>>>>>
- Argument-1 = rdi = this pointer copied to A::A(A const&) stack
- Argument-2 = rsi = 4 copied to A::A(A const&) stack

6. Copy value from stack to eax register(after calculations).
edx = *(rax)
   ------------------------------------------
                        rbp2 0x392 0x396   rsp2      Registers
                                                    edx=*0x392       
                                                    rax(qword) = *(rbp-8)  //rax: stores return value of the function
                                                    rax(dword) = edx
<<<<<<<<<<3rd COPY CREATED>>>>>>>>>>>>>
- rax holds this pointer
- rax also holds value 4
```
