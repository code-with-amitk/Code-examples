## Copy Constructor
- **What** Same named member function of class for creating a new object as a copy of an existing object. Achieved using const L-value reference.
- **PARAMETERS**
  - 1st parameter is A&, const A&, volatile A&, or const volatile A&
  - Either there are no other parameters, or the rest of the parameters all have default values.

### When compiler does not provide copy ctr?
1. CC declared by user.
2. If class has virtual function. class A{ public: virtual f();}
3. If class has virtual base class class A:virtual B{}
4. Class has member which cannot be copied to other object(ie not copy construable) Eg: reference variable

### WHEN CC IS CALLED?
1. When compiler generates temporary object
2. When object is created using another object of same class.
3. When Object of class is passed to function as value.    
4. When object of class is returned by value.

### Syntax
```c++
class_name ( const class_name & )
class_name ( const class_name & ) = default;
class_name ( const class_name & ) = delete;
```

### Compiler provided copy ctr
```C++
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
```c++
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
```c++
class A{
       int a;
public:
       A(int b):a(b){}

       A(const A &k){
               this->a = k.a;
	       std::cout<<"Inside cc";
       }
       void disp(){ cout<<a<<"\n"; }
};
int main(){
  A obj1(4);  obj1.disp();    //4
  
  A obj2(obj1);  obj2.disp();    //4		//Call cc
  A obj3 = obj1;  obj3.disp();    //4		//Calls cc
}
$ ./a.out
4
Inside cc 4
Inside cc 4
```
