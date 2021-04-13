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
```c
fun(long, long, long, long):
  push    rbp
  mov     rbp, rsp
  mov     QWORD PTR [rbp-24], rdi
  mov     QWORD PTR [rbp-32], rsi
  mov     QWORD PTR [rbp-40], rdx
  mov     QWORD PTR [rbp-48], rcx
  mov     rax, QWORD PTR [rbp-24]
  imul    rax, QWORD PTR [rbp-32]
  imul    rax, QWORD PTR [rbp-40]
  mov     rdx, QWORD PTR [rbp-48]
  imul    rax, rdx
  mov     QWORD PTR [rbp-8], rax
  nop
  pop     rbp
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
