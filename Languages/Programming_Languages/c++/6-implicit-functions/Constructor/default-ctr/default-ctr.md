**Default ctr**
- [When compiler provides default ctr](#w1)
- [When compiler does not provide default ctr](#w1)
- [Forcing compiler to create default ctr](#f)


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
