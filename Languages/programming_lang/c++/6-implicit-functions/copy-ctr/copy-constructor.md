## Copy Constructor
- member function of class for creating a new object as a copy of an existing object.
- same named function of class A.
- Achieved using const L-value reference.
- **PARAMETERS**
	- 1st parameter is A&, const A&, volatile A&, or const volatile A&
	- Either there are no other parameters, or the rest of the parameters all have default values.

### When compiler does not provide copy ctr?
1. CC declared by user.
2. If class has virtual function. class A{ public: virtual f();}
3. If class has virtual base class class A:virtual B{}
4. Class has member which cannot be copied to other object(ie not copy construable) Eg: reference variable

### Syntax
```
class_name ( const class_name & )
class_name ( const class_name & ) = default;
class_name ( const class_name & ) = delete;
```

### Compiler provided copy ctr
```
class A{
        int a=10;
public:
        void disp(){ cout<<a<<"\n"; }
};
int main(){
        A obj1; 
        obj1.disp();    //10

        A obj2(obj1);  
        obj2.disp();    //10
}
```


### Forcing compiler to generate copy ctr
```
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

### User created copy ctr
```
class A{
       int a;
public:
       A(int b):a(b){}

       A(const A &k){
               this->a = k.a;
       }
       void disp(){ cout<<a<<"\n"; }
};
int main(){
        A obj1(4);
        obj1.disp();    //4

        A obj2(obj1);                  //Two objects created. obj2 is copy of obj1
        obj2.disp();    //4
}
```
