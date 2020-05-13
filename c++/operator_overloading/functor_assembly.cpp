/*      functors_assembly.cpp
https://godbolt.org/

WHAT/WHY? See functors.cpp for detials

INTERNALLY:
        Overloaded operator () is nothing but a seperate function definition
*/
#include<iostream>
using namespace std;

class A {
        int state_variable;             //STATE VARIABLE
public:
        A(int c):state_variable(c) {};

        int operator ()(int b){
                return b*state_variable;
        }
};
int main(){
        A obj(10);
        cout<<obj(3)<<endl;     //30
        cout<<obj(5)<<endl;     //50
}

/*
 ASSEMBLY
A::operator()(int):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     DWORD PTR [rbp-12], esi
        mov     rax, QWORD PTR [rbp-8]
        mov     eax, DWORD PTR [rax]
        imul    eax, DWORD PTR [rbp-12]
        pop     rbp
        ret

main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-4]
        mov     esi, 10
        mov     rdi, rax
        call    A::A(int)
        lea     rax, [rbp-4]
        mov     esi, 3
        mov     rdi, rax
        call    A::operator()(int)
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    basic_ostream<char, char_traits<char> >::operator<<(int)
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    basic_ostream<char, char_traits<char> >::operator<<(basic_ostream<char, char_traits<char> >& (*)(basic_ostream<char, char_traits<char> >&))
        lea     rax, [rbp-4]
        mov     esi, 5
        mov     rdi, rax
        call    A::operator()(int)
        mov     esi, eax
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    basic_ostream<char, char_traits<char> >::operator<<(int)
        mov     esi, OFFSET FLAT:_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
        mov     rdi, rax
        call    basic_ostream<char, char_traits<char> >::operator<<(basic_ostream<char, char_traits<char> >& (*)(basic_ostream<char, char_traits<char> >&))
        mov     eax, 0
        leave
        ret

*/
