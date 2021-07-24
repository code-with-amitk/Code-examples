/*      unordered_map_assembly.cpp

******POINTS TO REMEMBER******
1. Stack grows in reverse direction.
  |----stack grows-----|-------------><------heap grows------
 0x450                0x200
 rbp                  rsp       

2. rdi, rsi, rdx, rcx, r8, r9: Stores 1st 6 arguments to function. If there are more than 6 parameters, 
   then the program’s stack is used to pass in additional parameters to the function.
   
3. rax: stores return value of the function. Larger return types like structs are returned using the stack.

4. rax, rcx, rdx, rdi, rsi, rsp, r8-r11: These are caller save registers. 
   rbx, rbp, r12-r15: These are callee save registers. These are saved across function calls.   	
   |- As per telephone system. Caller is main(), callee fun()
*************************************

**********CTR, DTR CALLED***********
unordered_map<datatype1, datatype2> calls
  unordered_map<datatype1, datatype2, hash<datatype1>, equal_to<datatype1>, 
                allocator<pair<datatype1 const, datatype2>>> :: unordered_map(){
                ....
  }

And destructor:
unordered_map<datatype1, datatype2, hash<datatype1>, equal_to<datatype1>, 
              allocator<pair<datatype1 const, datatype2>>> :: ~unordered_map(){
              ........
}
*************************************
        
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
        unordered_map<int,char> uam;
}

/* ASSEMBLY:
main:
        push    rbp             //1a    
        mov     rbp, rsp        //1b
        sub     rsp, 64         //2. stack of size=64 created
        lea     rax, [rbp-64]   //3
        mov     rdi, rax        //4
        call    unordered_map<int, char, hash<int>, equal_to<int>, allocator<pair<int const, char> > >::unordered_map() [complete object constructor]
        lea     rax, [rbp-64]
        mov     rdi, rax
        call    unordered_map<int, char, hash<int>, equal_to<int>, allocator<pair<int const, char> > >::~unordered_map() [complete object destructor]
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

2. Create stack for main            
   ---------------main-----
            rbp1        rsp1        
            0x364       0x300

3. LEA(Load Effective address)
   ----------------main-----            Registers
            rbp1         rsp1           rax = 0x300
                         /\
                         rax       

4. Store 1st argument for function call in rdi
                                        rdi = rax(1st Argument) <<this pointer

5. Call the template function
*/
