**UML (Unified Modelling Language)**
- **Types of UML Diagram**
  - [1. Structural](#st)
  - [2. Class](#cl)
- **[Relationship Types](#r)**
  - [`0..*`](#0tom)
  - [`1..*`](#1tom)
  - _1._ Generalization/Inheritance
    - _1a._ Relization
  - _2._ Association
    - _2a._ Aggregation
    - _2b._ Composition
    - _2c._ Reflexive Association
    - _2d._ Multiplicty

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
<a name=#1tom></a>
### **`1..*` = 1 to many**
Means book object can belong to **at least 1 and possibly more** library classes.
```c
|----|1..*   |-------|
|book|-------|Library|
|----|       |-------|
```
<a name=#0tom></a>
### **`0..*` = 0 to many**
Means object-1(can belong to) **at least 0 and possibly more** object-2.
```c
|--------|0..*      |--------|
|object-1|----------|object-2|
|--------|          |--------|
```
### [1. Inheritance/Generalization/Specialization](/Languages/Programming_Languages/c%2B%2B/Characteristics_of_OOPS/Inheritance#g)
#### _1a._ Realization
Implementation declared in 1 class is defined in another class. Eg: Virtual Function, Pure Virtual Function

### [2. Association](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Inheritance#as)
#### [2a. Aggregation](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Inheritance#ag)
- Ex: “library” is made up of one or more books. Again those books can be part of other virtual libraries
#### [2b. Composition](/Languages/Programming_Languages/c++/Characteristics_of_OOPS/Inheritance#co)
#### _2c._ Reflexive Association
#### _2d._ Multiplicity
[`0..*`](#tomany) A passenger can belong to minimum=0 and possibly more airplanes
<img src=relationships.png></img>
