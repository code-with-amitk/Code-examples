- **Copy Constructor**
  - [When compiler does not provide copy ctr](#n)
  - [When CC is called?](#w)
  - [Compiler provided cc](#cp)
  - [User created copy ctr](#uc)
  - [Forcing compiler to generate copy ctr](#fc)
- **Deep copy, Shallow Copy**
  - [Example](#eg)
- [How many temporary copies are created by copy Ctr?](#how)

## Copy Constructor
Same named member function of class for creating a new object as a copy of an existing object. Achieved using [const L-value reference]().
```c
  A(const A &obj)      //Mostly used.
  A (A &obj)      
  A (volatile A &obj)
  A (const volatile A &obj)
  A (A &obj, int a=0)     //2nd Argument If passed must be default    
  A(const A &obj, int a=10, float b=10.1)
  A ( const A & ) = default;
  A ( const A & ) = delete;  
```
<a name=n></a>
#### When compiler does not provide copy ctr?
1. CC declared by user.
2. If class has virtual function. class A{ public: virtual f();}
3. If class has virtual base class class A:virtual B{}
4. Class has member which cannot be copied to other object(ie not copy construable) Eg: reference variable

<a name=w></a>
#### When CC is called?
1. When compiler generates temporary object
2. When object is created using another object of same class.
3. When Object of class is passed to function as value.    
4. When object of class is returned by value.

<a name=cp></a>
#### Compiler provided copy ctr
```cpp
class A{
        int a=10;
public:
        void disp(){ cout<<a<<"\n"; }
};
int main(){
        A obj1; 
        obj1.disp();    //10
}
```

<a name=uc></a>
#### User created copy ctr
```c++
class A{
       int a;
public:
       A(int b):a(b){}
       A(const A &k){
               this->a = k.a;
       }
       int get(){ return a; }		//Bright Computing(Netherland): Not print anything in class
};
int main(){
  A obj1(4);
  cout << obj1.get();    	 //4
  
  A obj2(obj1);
  cout << obj2.get();    	 //4		//Call cc
  
  A obj3 = obj1;
  cout << obj3.get();    	 //4		//Calls cc
}
```

<a name=fc></a>
#### Forcing compiler to generate copy ctr
```cpp
class A{
        int a=10;
public:
        A() = default;                  //Rule of Big-3
        A(A &) = default;
        void disp(){ cout<<a<<"\n"; }
};
int main(){
        A obj1; 
        obj1.disp();    //10
        A obj2(obj1);  
        obj2.disp();    //10
}
```

### Deep and shallow
#### Shallow Copy ctr
Compiler Provided Copy Ctr provides shallow copy. ie It does member-wise copy. If object has ptr variable, then memory pointed by pointer variable is not duplicated.
#### Deep Copy Ctr
User has to write deep copy. Does duplicate memory pointed by pointer variable.
<a name=eg></a>
#### Example
```cpp
class A{
        int *a;
public:
        A (){
                a = new int;
                *a = 4;
        }
/*      A (const A &obj) {      //obj=obj1. shallow copy
                this->ptr = obj.ptr;
        }*/
        A (const A &obj){       //DEEP COPY CONSTRUCTOR
                this->a = new int;
                *(this->a) = *obj.a;
        }

        void disp(){
                cout<<"a="<<*(this->a)<<endl;
        }
};
int main(){
        A obj1;
        A obj2(obj1);   //obj2 = A(obj1)
        obj1.disp();    //a=4
        obj2.disp();    //a=4
        return 0;
}
```

<a name=how></a>
### How many temporary copies are created by copy Ctr?
- To create a class object using copy ctr, 3 temporary copies of member variables are created.
- For example, we are creating a object by calling copy ctr
  - In this process, 3 temporary copies of member variables are created.
```cpp
class A{
       int a;
public:
       A(int b):a(b){}

       A(const A &k){
               this->a = k.a;
       }
};
int main(){
        A obj1(4);

        A obj2(obj1);
}
```

**ASSEMBLY**
```
A::A(int):
    //Let's not look into Default ctr since we are bothered about copy ctr
    
A::A(A const&):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi    //5
        mov     QWORD PTR [rbp-16], rsi   //5
        mov     rax, QWORD PTR [rbp-16]
        mov     edx, DWORD PTR [rax]
        mov     rax, QWORD PTR [rbp-8]
        mov     DWORD PTR [rax], edx
        nop
        pop     rbp
        ret
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        lea     rax, [rbp-4]
        mov     esi, 4
        mov     rdi, rax
        call    A::A(int)          //NOT LOOK TILL HERE
        lea     rdx, [rbp-4]      //3
        lea     rax, [rbp-8]      //3
        mov     rsi, rdx          //3
        mov     rdi, rax          //3
        call    A::A(A const&)
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
            
3. Store address of (rbp-4) THIS Pointer to rdx
Store address of (rbp-8) THIS Pointer to rax
Store rsi = rdx.  rdi = rax
   ---------------main--------
            rbp1            rsp1              Registers
            0x400           0x384             rdx = 0x396, rax = 0x392  
                                              rsi = 0x396, rdi = 0x392  //rdi, rsi, rdx, rcx, r8, r9: Stores 1st 6 arguments to function.
<<<<<<<<<<1st COPY CREATED>>>>>>>>>>>>>>>
- rsi is this pointer (1st argument)
- rdi = 10 (2nd argument)

4. Function Epilogue
a. Push value of rbp1 somewhere on stack
   -------------------------             Head
             rbp1       rsp1     Stack | rbp1=0x400 | rbp0=0x450 |
   
   b. Move rbp to rsp
   ------------------------------------------
                        rbp2              rsp2
                        0x384          

5. Copy rdi, rsi to copy ctr stack
*(rbp-8) = rdi
*(rbp-16) = rsi
   ------------------------------------------
                        rbp2 0x392 0x396    rsp2
<<<<<<<<<<2nd COPY CREATED>>>>>>>>>>>>>>>>>
- Argument-1 = rdi = this pointer copied to A::A(A const&) stack
- Argument-2 = rsi = 4 copied to A::A(A const&) stack

6. Copy value from stack to eax register(after calculations).
edx = *(rax)
   ------------------------------------------
                        rbp2 0x392 0x396   rsp2      Registers
                                                    edx=*0x392       
                                                    rax(qword) = *(rbp-8)  //rax: stores return value of the function
                                                    rax(dword) = edx
<<<<<<<<<<3rd COPY CREATED>>>>>>>>>>>>>
- rax holds this pointer
- rax also holds value 4
```
