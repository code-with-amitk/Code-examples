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
