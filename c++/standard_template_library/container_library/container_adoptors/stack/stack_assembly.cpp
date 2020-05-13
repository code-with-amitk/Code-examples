/*	stack_assembly.cpp

CONTAINER ADOPTORS(stack, queue, priority_queue)? 
 - These are not full container classes, but classes that provide interface relying on an object of 
 one of the container classes (such as deque or list) to handle the elements.
 - Stacks are internally implemented using deque

**********CTR, DTR CALLED***********
1. stack<int> s1;
   calls:
	stack<int, deque<int, allocator<int>>>::stack<deque<int, allocator<int>>, void>()

2. s1.push(5);
   calls:
   	stack<int, deque<int, allocator<int> > >::push(int&&)

3. stack<int>s2 = s1
   calls copy ctr
	stack<int, deque<int, allocator<int> > >::stack(stack<int, deque<int, allocator<int> > > const&)

4. Destructors called for both stacks after setting this pointer in rax register
	stack<int, deque<int, allocator<int> > >::~stack() [complete object destructor]	//s1
	stack<int, deque<int, allocator<int> > >::~stack() [complete object destructor]	//s2
*************************************
*/

#include<iostream>
#include<stack>
using namespace std;

int main(){
        stack<int> s1;
	s1.push(5);
    	stack<int>s2 = s1;
}

/*
 ASSEMBLY

stack<int, std::deque<int, std::allocator<int> > >::stack<std::deque<int, std::allocator<int> >, void>():
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     QWORD PTR [rbp-8], rdi
        mov     rax, QWORD PTR [rbp-8]
        mov     QWORD PTR [rax], 0
        mov     QWORD PTR [rax+8], 0
        mov     QWORD PTR [rax+16], 0
        mov     QWORD PTR [rax+24], 0
        mov     QWORD PTR [rax+32], 0
        mov     QWORD PTR [rax+40], 0
        mov     QWORD PTR [rax+48], 0
        mov     QWORD PTR [rax+56], 0
        mov     QWORD PTR [rax+64], 0
        mov     QWORD PTR [rax+72], 0
        mov     rax, QWORD PTR [rbp-8]
        mov     rdi, rax
        call    deque<int, std::allocator<int> >::deque() [complete object constructor]
        nop
        leave
        ret

main:
        push    rbp			//1a
        mov     rbp, rsp		//1b
        push    rbx			//2
        sub     rsp, 184		//Stack of main created //3
        lea     rax, [rbp-112]		//rax=address-of(rbp-112) //4
        mov     rdi, rax		//5
        call    stack<int, deque<int, allocator<int>>>::stack<deque<int, allocator<int>>, void>()	//6
        mov     DWORD PTR [rbp-20], 5
        lea     rdx, [rbp-20]
        lea     rax, [rbp-112]
        mov     rsi, rdx
        mov     rdi, rax
        call    stack<int, deque<int, allocator<int>>>::push(int&&)
        lea     rdx, [rbp-112]
        lea     rax, [rbp-192]
        mov     rsi, rdx
        mov     rdi, rax
        call    stack<int, deque<int, allocator<int> > >::stack(stack<int, deque<int, allocator<int> > > const&)
        lea     rax, [rbp-192]
        mov     rdi, rax
        call    stack<int, deque<int, allocator<int> > >::~stack() [complete object destructor]
        lea     rax, [rbp-112]
        mov     rdi, rax
        call    stack<int, deque<int, allocator<int> > >::~stack() [complete object destructor]
        mov     eax, 0
        jmp     .L13
        mov     rbx, rax
        lea     rax, [rbp-112]
        mov     rdi, rax
        call    stack<int, deque<int, allocator<int> > >::~stack() [complete object destructor]
        mov     rax, rbx
        mov     rdi, rax
        call    _Unwind_Resume

STEPS:
1. Function Epilogue.
   a.Push value of rbp0 somewhere on stack
   ------------                        Head
   rbp0     rsp0                Stack | rbp0=0x450 |

   b.Move rbp to rsp
   --------------------
            rsp0
            rbp1

2. Save rbx somewhere on stack.

3. Create stack for main. size 184 bytes.
   ------------------------main-----
            rbp1        	  rsp1
            0x400    		  0x216

4. LEA(Load Effective address)
   ------------------------main-----
            rbp1   /\             rsp1		Registers
            0x400  rax            0x216		rax=address-of(rbp-112)

5. Store 1st argument for function call in rdi.
						rdi=address-of(rbp-112)

6. Call the function
	stack<int, deque<int, allocator<int>>>::stack<deque<int, allocator<int> >, void>()						
*/
