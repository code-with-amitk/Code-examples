**Inheritance**
- [Rules of Inheritance](#r)
- [Function Overriding](#fo)
- Types
 - [Aggregation]


## Inheritance / Is-A Relationship
Creating new class(decendent/derived) from existing class(ansector/base).

<a name=r></a>
### Rules of Inheritance
<img src=rules-of-inheritance.png width=500/> 

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
