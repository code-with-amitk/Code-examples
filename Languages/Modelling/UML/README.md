**UML (Unified Modelling Language)**
- **Types of UML Diagram**
  - [1. Structural](#st)
  - [2. Class](#cl)
- **Relationship Types**
  - [1. Generalization/Inheritance](#gen)
  - [2. Association](#as)
  - [3. Aggregation](#ag)
  - [4. Composition](#com)

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

## Relationship
How objects/elements have relationship with each other?
### [1. Generalization/Inheritance](/Languages/Programming_Languages/c%2B%2B/Characteristics_of_OOPS/Inheritance#g)
### [2. Association](/Languages/Programming_Languages/c%2B%2B/Characteristics_of_OOPS/Inheritance#as)
### [3. Aggregation](/Languages/Programming_Languages/c%2B%2B/Characteristics_of_OOPS/Inheritance#as)
### 4. Composition
