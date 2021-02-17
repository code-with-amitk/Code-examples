/* structured-bindings_assembly.cpp
https://godbolt.org/

WHAT is SB?
TYPES OF SB? See structured_binding.cpp

SB is achieved by:
 1. Placing array elements on stack.
 2. copying elements from stack to SB.
*/

#include<iostream>
#include<tuple>
using namespace std;

int main(){
        int a[2] = { 1,2 };
        auto [ xval, yval ] = a;
        cout<<xval<<" "<<yval<<endl;    //1 2
}

/*
ASSEMBLY

main:
        push    rbp             //1a
        mov     rbp, rsp        //1b
        sub     rsp, 16         //Create stack //2
        mov     DWORD PTR [rbp-8], 1    //*(rbp-8)=1    //3
        mov     DWORD PTR [rbp-4], 2    //store values on stack //3
        mov     rax, QWORD PTR [rbp-8]  //rax=1 //4
        mov     QWORD PTR [rbp-16], rax //*(rbp-16)=1   //5
        mov     eax, DWORD PTR [rbp-16] 
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    basic_ostream<char, char_traits<char> >::operator<<(int)
        mov     esi, OFFSET FLAT:.LC0
        mov     rdi, rax
        call    basic_ostream<char, char_traits<char> >& operator<< <char_traits<char> >(basic_ostream<char, char_traits<char> >&, char const*)
        mov     rdx, rax
        mov     eax, DWORD PTR [rbp-12]
        mov     esi, eax
        mov     rdi, rdx
        call    basic_ostream<char, char_traits<char> >::operator<<(int)
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    basic_ostream<char, char_traits<char> >::operator<<(basic_ostream<char, char_traits<char> >& (*)(basic_ostream<char, char_traits<char> >&))
        mov     eax, 0
        leave
        ret

STEPS:
1. Function Epilogue.
   a.Push value of rbp0 somewhere on stack
   ------------                        Head
   rbp0     rsp0                Stack | rbp0=0x450 |

   b.Move rbp to rsp
   --------------------
            rsp0
            rbp1

2. Create stack for main. size 16 bytes.
   ---------------main-----
            rbp1        rsp1
            0x400       0x384

3. Save 1,2 on stack in reverse order.
   ---------------main--------
            rbp1 2 1        rsp1
            0x400           0x384


4. Store 1 on rax register
   ------------------main-----
            rbp1 2 1        rsp1                Registers
            0x400           0x216               rax=1

5. Store at rbp-16=rax
   ------------------main-----
            rbp1 2 1   1    rsp1                Registers
            0x400           0x216               rax=1

6. eax=1                                        Registers
                                                rax=1
                                                eax=1
7. esi=1                                        esi=1
*/
