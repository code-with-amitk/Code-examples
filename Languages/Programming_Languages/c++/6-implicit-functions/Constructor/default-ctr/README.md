**Default ctr**
- [When compiler provides default ctr](#w1)
- [When compiler does not provide default ctr](#w1)
- [Forcing compiler to create default ctr](#f)
- **Rules of default Ctr**
  - [1. Mismatch in declaration & call of ctr not allowed](#r1)
  - [2. `A obj()` is not contructor call](#r2)
- [How many temporary copies are created by Default Ctr?](#h)


## Default ctr
Same named function of class
```cpp
  class_name ( ) ;
  class_name :: class_name ( ) {..}
  class_name() = delete ;                         (since C++11)
  class_name() = default ;                        (since C++11)
  class_name :: class_name ( ) = default ;        (since C++11)
```

<a name=w1></a>
#### When Compiler provides default ctr?
1. No user created Constructor is declared in class
```cpp
class A{
        int a=1;
public:
        void disp(){
                cout<<a<<"\n";
        }
};
int main(){ 
        A obj1;              //Calls complier provided default
        obj1.disp();
}
```

<a name=w2></a>
#### When complier does not provide default ctr?
1. If user has  defined ANY constructor(either default or copy ctr)
2. There is a Member in class that is not default-constructible. Eg: Pointer, Reference    
3. {C++11} Deleting Default Constructor using A() = delete;
```cpp
class A{
        int a;
public:
        A(int b):a(b){}                 //User defined Default ctr
        void disp(){
                cout<<a<<"\n";
        }
};
int main(){
        A obj(2);
        obj.disp();    //1
}
```

<a name=f></a>
#### Forcing compiler to create default ctr
Using class_name () = default
```c++
class A{
        int a=1;
public:
        A() = default;            //Forces class to generate default ctr
        void disp(){
                cout<<a<<"\n";
        }
};
int main(){
        A obj1;
        obj1.disp();    //1
}
```

## Rules of Default ctr
<a name=r1></a>
#### 1. Mismatch in declaration & call of ctr not allowed
```cpp
class A {
    int a;
public:
    Test(int x) : x(a) {}
};
int main() {
    Test t;                 //a
    return 0;
}
$ ./a.out
Compilation Error mismatch ctr            //Because ctr takes 1 argument but, a does not provide any argument.
                                          //Resolving Compile time Error. Test(int x=0). Making argument as default
```

<a name=r2></a>
#### 2. `A obj()` is not contructor call
```cpp
class A
{
public:
  A () { cout << "Constructor"; }
};
int main() {
    A t1();
}
$ ./a.out
Nothing printed           //Why? Because Complier considers this t1() as function declaration not ctr call.
```

<a name=h></a>
## How many temporary copies are created by Default Ctr?
- To create a class object using default ctr, 3 temporary copies of member variables are created.
- For example, we are creating a object by calling default ctr
  - In this process, 3 temporary copies of member variables are created.

**Code**
```cpp
class A{
    int a;
public:
    A(int b):a(b){}      //1st hidden argument is default ctr
};
int main(){
    A obj1(10);         //1st hidden argument is this pointer
}
```

**Assembly**
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
