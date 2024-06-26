**UML (Unified Modelling Language)**
- **[Relationship Types](#r)**
  - [`0..* or 0..n`](#0ton)
  - [`1..* or 1..n`](#1ton)
  - _1._ Generalization/Inheritance
    - _1a._ Relization
  - _2._ Association
    - _2a._ Aggregation
    - _2b._ Composition
    - _2c._ Reflexive Association
    - _2d._ Multiplicty
- **Types of UML Diagram**
  - [1. Class diagram](#cl)
  - [Object, Use Case, Interactive, Collaborative, Activity, State, Deployment, Component Diagram](#o)

## UML
- To build models/class diagrams and their relationship before actual code

<a name=r></a>
## Relationship
How objects/elements have relationship with each other?
<a name=0ton></a>
### **`0..*` = 0 to many = 1 to n**
Means object-1(can belong to) **at least 0 and possibly more** object-2.
```c
|--------|0..*      |--------|
|object-1|----------|object-2|
|--------|          |--------|
```
<a name=1ton></a>
### **`1..*` = 1 to many = 1 to n**
Means book object can belong to **at least 1 and possibly more** library classes.
```c
|----|1..*   |-------|
|book|-------|Library|
|----|       |-------|
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
<img src=relationships.png width=700></img>

## Types of UML Diagrams
<a name=cl></a>
### 1. Class Diagram
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
<a name=o></a>
### 2. Object, Use Case, Interactive, Collaborative, Activity, State, Deployment, Component Diagram
<img src=UML_Diagrams.png width=1000></img>
