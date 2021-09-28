**Inheritance / Is-A Relationship**
- [Types](#ty)
- [Base Member Initialization](#bi)
- [Diamond Problem](#dp)
  - [Virtual Inheritance](#vi)
- **Terms**
  - [Generalization](#g)
  - [Specialization](#sp)
  - **Association**
    - [Aggregation/Collection](#ag)
    - [Composition / Has-A](#co)
- [Rules of Inheritance](#r)
- [Function Overriding](#fo)
- Types
 - [Aggregation]


## Inheritance
Creating new class(decendent/derived) from existing class(ansector/base). This is uni-directional relation.
- **Adv:** Provides re-usability. 
- **Disadv:** 
  - _1._ Since inheritance inherits everything from the super class and interface, it may make the subclass too clustering and sometimes error-prone when dynamic overriding or dynamic overloading in some situation. 
  - _2._ Inheritance creates hierarchical structures, If Inheritance chains gets large these can become cumbersome & tough to maintain

<a name=ty></a>
### Types
```c
Single 
|Base| ---> |Derv|

Multiple
 |Base class 1|     |Base class 2|
    |                     |
    -----> |Derv| <-------

Hierarchical
   |Base class|
/        |     \
DC1    DC2    DC3

Multilevel
    |Base 1| 
       \/
    |Base 2|
       \/
    |Derv |
    
Hybrid(Virtual)
        | Base class |
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
 
Solution: Virtual Inheritance
class derv1: public virtual base{  }
class derv2: virtual public base{  }
class derv3: public derv1, public derv2{ ...};      // In Memory [abcd]
```

## Terms
#### Generalization
Creating Base from 2 or more derv classes by extracting their Similar Characteristics(Attributes & Behavior).
<img src=Generalization.png width=400/>

#### Specialization
New derived classes are created from base to perform Some SPECIAL function is called specialization
<img src=Specialization.png width=400/>

#### Association
**Aggregation**
Contained Object can exist without container Object. Contained object can belong to different classes at same time. Owner-ship is present. Container class have pointer to object of contained class

**Composition**
If container Object is deleted, contained object will also deleted. Deleting contained object is responsibility of container.  Container class have actual object of contained class.

<a name=r></a>
### Rules of Inheritance
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

<a name=fo></a>
### Function Overriding
Same named function in base & derv class.
