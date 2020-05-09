/*      arguments_to_function.c
*/

int fun(int a){
        return a;
}
int main(){
        long x=10;
        fun(x);
}

/*
fun:
        push    rbp                     epilogue        //1
        mov     rbp, rsp                epilogue
        mov     DWORD PTR [rbp-4], rdi  store 1st argument on stack//5
        mov     rax, DWORD PTR [rbp-4]  General purpose register
        pop     rbp
        ret
main:
        push    rbp                     epilogue                //1
        mov     rbp, rsp                epilogue
        sub     rsp, 16                 created 16byte stack    //2
        mov     DWORD PTR [rbp-8], 10   stored 10. rbp-4=10     //3
        mov     rax, DWORD PTR [rbp-8]  General purpose register
        mov     rdi, rax                1st argument of fun stored in rdi//4
        call    fun
        mov     eax, 0
        leave
        ret
        
STEPS:  
1.Every function starts with epilogue.  -----------------
   - rbp pushed/stored on stack.        rbp             rsp
   - rbp=rsp                            -----------------
                                                      rbp=rsp
2.Create stack for function                                                   
   - Move rsp to new position           -------------------------
            rsp=rsp-16                                  rbp     rsp

3.Store local variables on top of stack  -------------------------
   mov [rbp-8] 10                                       rbp 10  rsp

4.Function arguments are stored in:
   rdi,rsi,rdx,rcx,r8......r15

5.Arguments passed to function are stored on stack           
*/
