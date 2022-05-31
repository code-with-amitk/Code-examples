**Inheritance / Is-A Relationship**
- [Public, Pvt, Protected Inheritance](#ppp)
- [Types](#ty)
- [Base Member Initialization](#bi)
- [Diamond Problem](#dp)
  - [Virtual Inheritance / Virtual Base class](#vi)
- **Terms**
  - [Generalization = Inheritance](#g)
  - [Specialization](#sp)
  - **[Association](#as)**
    - [Aggregation/Collection](#ag)
    - [Composition / Has-A](#co)
- [Function Overriding](#fo)
- **Rules of Inheritance**
  - [1. Function is linearly searched up in Multilevel Inheritance](#r1)
  - [2. Multiple Inheritance, Ctr of base class is called in derivation order from left to right](#r2)


## Inheritance
- Creating new class(decendent/derived/Sub class) from existing class(ansector/base/Super). This is uni-directional relation.
- Most general classes appear higher in the class hierarchy and the most specific classes appear lower in the class hierarchy.
- **Adv:** Provides re-usability. 
- **Disadv:** 
  - _1._ Since inheritance inherits everything from the super class and interface, it may make the subclass too clustering and sometimes error-prone when dynamic overriding or dynamic overloading in some situation. 
  - _2._ Inheritance creates hierarchical structures, If Inheritance chains gets large these can become cumbersome & tough to maintain

<a name=ppp></a>
### Public, Pvt, Protected Inheritance
<img src=rules-of-inheritance.png width=300/> 

All member variables(public,protected,pvt) of base are inherited inside derv class. See Memory layout of derv class object. Inheriting Base member variables inside derv:
```c

   Inheritance Type  |   Member Variable of base class                       |      Functions of base class
---------------------|-------------------------------------------------------|---------------------------
    Public           | can be accessed in public section.                    | derv class can invoke any public fun of base
                     | NOTE: this does not mean derv gets a COPY/REFERENCE   |
                     |  base public variables. Derv gets access base vars  
                     
    Protected        | All protected members of the base class becomes       | Function present in protected section cannot be called using Object
                       protected members in derv

    Private          | Not inherited in derv class. Can only be accessed     | How to access private data members inside derv? 
                       if friended                                             Using public function in base and calling same from der
```

<a name=ty></a>
### Types
```c
//////////////Single//////////////
|Base| ---> |Derv|

////////////////Multiple/////////////
 |Base class 1|     |Base class 2|
    |                     |
    -----> |Derv| <-------

/////////////Hierarchical//////////////
   |Base class|
/        |     \
DC1    DC2    DC3

/////////////Multilevel//////////////
    |Base 1| 
       \/
    |Base 2|
       \/
    |Derv |
    
//////////////Hybrid(Virtual)//////////
        | Base class |
              |
      |-----------------|  
     \/                 \/
   |Derv 1|        |Derv 2|
     |                |
     ----------------
            |
         |Derv 3|  
```

<a name=bi></a>
### Base Member Initialization
Passing Arguments from derv to base class
```c
class derv: public base {    
public:    
    derv(int a) : base(a){}
};
```

<a name=dp></a>
### Diamond Problem
In multiple inheritance derv class gets 2 copies of base class variables. Solution:Virtual Inheritance
```c
        -------------- class base{ int a;}  ---------------
       |                                                   |
class derv1: public base                            class derv2: public base
    int b;                                                int c;
      |                                                    |
       -- class derv3:public derv1, public derv2---  
                   int d;

derv3 class Object's memory representation
          SS 
 a(base),b,a(base),c,d 	 HS	DS 	CS
```
<a name=vi></a>
#### Solution to Diamond Problem: Virtual Inheritance / Virtual Base class
- Used for preventing multiple “instances” of a given class appearing in an inheritance hierarchy when using multiple inheritances.
- **Why?** When any data / function member of class A is accessed by an object of class D, ambiguity arises as to which data/function member would be called? One inherited through B or the other inherited through C. This confuses compiler and it displays error.
- virtual can be written before or after the public
```cpp
///////////Problem case///////////
class A {
  int a[10];
};
class B : public A {};
class C : public A {};
class D : public B, public C {};    //data members/function of class A are inherited twice to class D.
int main(){
  D obj;
  cout << sizeof (obj);         //80
}

///////////Good Case////////////////
class A {
  int a[10];
};
class B : virtual public A {};  //if virtual not used will give (error: request for member ‘fun’ is ambiguous)
class C : public virtual A {};
class D : public B, public C {};
int main(){
  D obj;
  cout << sizeof (obj);         //40. Only 1 copy inherited.
}
```

## Terms
<a name=g></a>
### 1. Generalization = Inheritance
- Process of extracting shared characteristics(attributes, methods) from 2 or more classes and combining them into a generalized superclass.
- Shared characteristics(variables, methods) are listed in base class but accessible(and used) in all derived/sub classes.
<img src=Generalization1.png width=300/>

<a name=sp></a>
### 2. Specialization
- Creating new subclasses from certain attributes, methods only for some special usecase.
- For example, degree of hazardness will only be applicable to certain types of frieghts not all
<img src=Specialization1.png width=300/>

<a name=as></a>
### 3. Association
Means any kind of relationship between 2 objects.
<a name=ag></a>
#### 3.1 Aggregation
Contained Object can exist without container Object. Owner-ship is present.
```cpp
class A{
    int a;
};

class B{
    A *ptr;
};
```

<a name=co></a>
#### 3.2 Composition
If container Object is deleted, contained object will also deleted.
```cpp
class A{
  int a;
};

class B{
       A  a;    //Composition
};
```

<a name=fo></a>
### Function Overriding
Same named function in base & derv class.

## Rules of Inheritance
<a name=r1></a>
### 1. Function is linearly searched up in Multilevel Inheritance
- The print function is not defined in class C. So it is looked up in the inheritance hierarchy. print() is present in both classes A and B. 
- if there is multilevel inheritance, then function is linearly searched up in the inheritance hierarchy until a matching function is found.
```cpp
class A {
public:
   void print() { cout <<"A"; }
};
class B : public A {
public:
   void print() { cout <<" B"; }
};
class C: public B {};
 
int main(void) {
  C obj;
  obj.print();            //B
}
```

<a name=r2></a>
### 2. Multiple Inheritance, Ctr of base class is called in derivation order from left to right
- Destructor is called in reverse order
```cpp
class A : public B, public C ;
$ ./a.out
B
C
A
```
