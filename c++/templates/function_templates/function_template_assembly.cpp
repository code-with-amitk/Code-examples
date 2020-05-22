/*      function_template_assembly.cpp

********POINTS TO REMEMBER:**********
1. Stack grows in reverse direction.
  |----stack grows-----|-------------><------heap grows------
 0x450                0x200
 rbp                  rsp       

2. Arguments to function are stored in registers:  rdi, rsi, rdx, rcx, r8...
*************************************

**************HOW TEMPLATES WORKS INTERNALLY? *********
Function overloading

 - Types are defined using Angular brackets <>
 - User-defined-function        Complier-generated-function
        maximum(4,5)            int maximum<int>(int, int)
        maximum('a','b')        char maximum<char>(char, char)
        maximum(4,4.5)          int maximum<int, double>(int, double)
********************************************************

*/
#include<iostream>
using namespace std;

template <class T>                      //OR template <typename T>
T maximum(T a, T b){
        return (a>b)?a:b;
}

int main(){
        cout<<maximum(4,5);
        cout<<maximum('a','b');
}

/*
 ASSEMBLY:

int maximum<int>(int, int):
        push    rbp                     //4a
        mov     rbp, rsp                //4b
        mov     DWORD PTR [rbp-4], edi  //5 Arguments of function stored on stack. *(rbp-4)=edi=4
        mov     DWORD PTR [rbp-8], esi  //5 Arguments of function stored on stack. *(rbp-4)=esi=5
        mov     eax, DWORD PTR [rbp-4]  //6 eax=*(rbp-4)=4
        cmp     eax, DWORD PTR [rbp-8]  //7 if(eax == *(rbp-8))
        jle     .L4
        mov     eax, DWORD PTR [rbp-4]
        jmp     .L6
.L4:
        mov     eax, DWORD PTR [rbp-8]
.L6:
        pop     rbp
        ret

 main:
        push    rbp             //1a
        mov     rbp, rsp        //1b
        mov     esi, 5          //2a.   2nd Function Argument
        mov     edi, 4          //2b.   1st Function Argument
        call    int maximum<int>(int, int)      //3
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
        mov     esi, 98
        mov     edi, 97
        call    char maximum<char>(char, char)
        movsx   eax, al
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >& std::operator<< <std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char)
        mov     eax, 0
        pop     rbp
        ret

STEPS:
1. Function Epilogue.
   a.Push value of rbp0 somewhere on stack
   ------------                        Head
   rbp0     rsp0                Stack | rbp0=0x450 |

   b.Move rbp to rsp
   --------------main---
            rbp1     rsp1

2. Store function arguments in registers.       Registers
                                                edi=4
                                                esi=5
3. call maximum<int> function.          

4. Function Epilogue.
   a.Push value of rbp1 somewhere on stack
   --------------------                 Head
           rbp1      rsp1         Stack | rbp0=0x450 | rbp1=0x400 |

   b.Move rbp to rsp
   -------main------------maximum<int>(int, int)---
                     rbp2                        rsp2

5. Store parameters of function onto stack                   
   -------main------------maximum<int>(int, int)---
                     rbp2 4 5                    rsp2

6. Store arguments in eax                       Registers
                                                eax=4

7. Compare operands. Subtracts 1st operand from other for comparing them, updates Flag register to show results.
*/
