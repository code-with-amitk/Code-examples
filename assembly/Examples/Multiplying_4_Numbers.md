### Code
```c++
void fun (int64_t a, int64_t b,int64_t c,int64_t d) {
  int64_t f = a*b*c*d*e;
}

int main() {
  int64_t a =1, b=2, c=3,d=4,e=5;
  fun(a,b,c,d,e);
}
```
### Stack Frame & assembly
- *0.* 4 arguments are passed to function fun() using [rdi,rsi,rdx,rcx](/Motherboard/CPU/Memory/CPU_Registers/General_Purpose_Registers)
- *1.* Push old rbp on stack, move rbp to rsp.
- *2.* Move arguments from registers to stack of function fun.
- *3.* Perform multiplication by moving values to register rax.
- *4.* Move result of multiplication to [HOME AREA](..)
```c
--------------------------
rbp                     rsp

fun(long, long, long, long):
  push rbp                                  //1. Function Premable/Prologue
  mov  rbp, rsp
  mov  QWORD PTR [rbp-24], rdi              //2
  mov  QWORD PTR [rbp-32], rsi
  mov  QWORD PTR [rbp-40], rdx
  mov  QWORD PTR [rbp-48], rcx               |   |   |  1 | 2 | 3 | 4 |
                                            rbp  8  16   24  32  40  48                rsp
                                            
  mov  rax, QWORD PTR [rbp-24]              //3.  rax=1
  imul rax, QWORD PTR [rbp-32]              //rax=rax*2 = 2
  imul rax, QWORD PTR [rbp-40]              //rax=rax*3 = 6
  mov  rdx, QWORD PTR [rbp-48]              //rdx=4
  imul rax, rdx                             //rax=rax*rdx = 24
  
  mov  QWORD PTR [rbp-8], rax               //4
  nop
  pop  rbp
  ret

main:
  push    rbp
  mov     rbp, rsp
  sub     rsp, 32
  mov     QWORD PTR [rbp-8], 1
  mov     QWORD PTR [rbp-16], 2
  mov     QWORD PTR [rbp-24], 3
  mov     QWORD PTR [rbp-32], 4
  mov     rcx, QWORD PTR [rbp-32]
  mov     rdx, QWORD PTR [rbp-24]
  mov     rsi, QWORD PTR [rbp-16]
  mov     rax, QWORD PTR [rbp-8]
  mov     rdi, rax
  call    fun(long, long, long, long)
  mov     eax, 0
  leave
  ret
```
