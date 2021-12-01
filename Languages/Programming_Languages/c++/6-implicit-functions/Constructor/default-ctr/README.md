**Default ctr**
- [class_name () = default is forcing compiler to create default ctr](#f)
- **Rules of default Ctr**
  - [1. When user creates parameterzied,default or copy constructor, compiler doesn’t provide default constructor](#r1)
  - [2. When there is no user created parameterzied or copy Constructor, complier provide default constructor](#r2)
  - [3. `A obj()` is not contructor call](#r3)
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
#### 1. When user creates parameterzied,default or copy constructor, compiler doesn’t provide default constructor
{C++11} Deleting Default Constructor using A() = delete; also deletes default ctr
```cpp
class A{
  int a;
public:  
  A(int i):a(i) {}
};
int main() {
  A obj;
}
$ g++ test.cpp
Compilation Error. 
When user create parameterzied constructor or copy constructor, compiler doesn’t provide default constructor
```

<a name=r2></a>
#### 2. When there is no user created parameterzied or copy Constructor, complier provide default constructor
```cpp
class A {
public:
    int get () { 
      return id; 
    }
private    
    uint32_t id;    
};

int main() {
    A a;                        //This calls Compiler provided default ctr and member is initialized
    cout << a.get();            //32567. Some Garbage value
    return 0;
}
```

<a name=r3></a>
#### 3. `A obj()` is not contructor call
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
