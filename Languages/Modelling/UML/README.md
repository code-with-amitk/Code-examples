**UML (Unified Modelling Language)**
- **Types of UML Diagram**
  - [1. Structural](#st)
  - [2. Class](#cl)
- **[Relationship Types](#r)**
  - _1._ Generalization/Inheritance
  - _2._ Association
  - _3._ Aggregation
  - _4._ Composition

## UML
- To build models/class diagrams and their relationship before actual code

## Types of UML Diagrams
<a name=st></a>
### 1. Structural

<a name=cl></a>
### 2. Class Diagram
```c
---------------------------------
|      Student //classname      |
---------------------------------
|+name:string       //public    | << Attributes
|-marks:int         //private   |
|#character:string  //protected |
---------------------------------
|+fun1(int)=void //Normal       | << Methods
|+_fun2()__=void    //static is underlined
|+fun3()=void     //virtual=Italized
--------------------------------
```

<a name=r></a>
## Relationship
How objects/elements have relationship with each other?
### [1. Generalization/Inheritance](/Languages/Programming_Languages/c%2B%2B/Characteristics_of_OOPS/Inheritance#g)
### [2. Association](/Languages/Programming_Languages/c%2B%2B/Characteristics_of_OOPS/Inheritance#as)
### [3. Aggregation](/Languages/Programming_Languages/c%2B%2B/Characteristics_of_OOPS/Inheritance#as)
### 4. Composition
