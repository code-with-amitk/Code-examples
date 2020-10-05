## Copy Assignment Operator
- **What** 
  - Function having name operator= 
  - For a type to be CopyAssignable, it must have a public copy assignment operator.
- **Parameters** Takes only one parameter of type A, A&, const A&, volatile A&, or const volatile A&. 
- **COMPILER DOES NOT PROVIDE COPY ASSIGNMENT OPERATOR WHEN?**
  - *1.* if explicitly declared Copy Assignment Operator in class. 
  - *2.* There is a Member in class that is not default-assignable. Eg: const object, Reference
  - *3.* [In C++11]Deleting assignment operator A& operator=(const A&) = delete; 
- **FORCING COMPLIER TO CREATE DEFAULT ASSIGNMENT OPERATOR:** class-name& operator = (const class-name &)=default;
- **SYNTAX?**
```c++
  class_name & class_name :: operator= ( class_name )
  class_name & class_name :: operator= ( const class_name & )
  class_name & class_name :: operator= ( const class_name & ) = default;(since C++11)
  class_name & class_name :: operator= ( const class_name & ) = delete;(since C++11)
```
- **Remember**
  - **Copy constructor** is called when a new object is created from an existing object, as a copy of the existing object.
  - **Assignment operator** is called when an already initialized object is assigned a new value from another existing object.


### 1. Compiler provided Assignment Operator
```c++
class A{
  int a=1;
public:
  void disp(){ cout<<a<<"\n"; }
};
int main(){
  A obj1; 
  obj1.disp();          //1

  //A obj2 = obj1;      //This will invoke Copy Ctr.
   A obj2;
   obj2 = obj1;
   obj2.disp();         //This calls copy ctr. 
}
```


### 2. Forcing compiler to generate assigment operator
```c++
class A{
  int a=1;
public:
  A& operator = (const A &)=default;
  void disp(){ cout<<a<<"\n"; }
};
int main(){
  A obj1;
  obj1.disp();    //1

  A obj2;
  obj2 = obj1;
  obj2.disp();    //1
}
```

### 3. User created assignment operator
```c++
class A{
  int a=40;
public:
  void operator = (A &k){         //obj2 fun=(obj1)
    this->a = k.a;
  }
  void disp(){ 
    cout<<a<<"\n"; 
  }
};
int main(){
  A obj1; 
  obj1.disp();            //40

  A obj2;
  obj2 = obj1;  
  obj2.disp();           //40
}
```
