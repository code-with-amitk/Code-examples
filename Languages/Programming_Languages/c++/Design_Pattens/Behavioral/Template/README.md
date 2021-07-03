- [1. What is Template Method DP](#what)
  - [1.1 Template?](temp) 
- [2. Examples](#exm)
  - [2.1 Beverage Maker Machine](#bev)

<a name=what></a>
## 1. Template Method DP
- This deﬁnes fixed skeleton of an algorithm. ie some methods are kept in base class(cannot be overridden in derv), some are kept to be overridden in derv classes.
- Template Method lets subclasses to redeﬁne certain steps of an algorithm without changing the algorithm’s structure.
```c
class base{
public:
	//virtual: Not required, since I will not override & access with same ptr
  virtual void template() final     //derv class cannot override fun1,fun2
  {
    fun1();
    fun2();
  }
  void fun3();               //derv class can override fun3
  virtual void fun4()=0;     //derv class must override fun4
}  
```

<a name=temp></a>
### 1.1 What is template?
  - Method present in base class, which defines algorithms of steps(functions called in specific order).
  - Some algorithms are kept intact(should not be overriden), while others allowed to be overridden.
  
<a name=exm></a>  
## 2. Examples

<a name=bev></a>
### 2.1 Generic Beverage Maker machine (Coffee,Tea etc)
- **Steps for Making beverage:**
```c
| Step | Coffee | Tea |
| --- | --- | --- |
|	1 | boilWater() |	boilWater() |
|	2 | addCoffee()	//renamed as addBase() |	addTea() //renamed as addBase() |
|	3 | pourInCup()	|	pourInCup() |
|	4 | addCondiments()	- Milk, Sugar| addCondiments() - Lemon |

- Some steps are common in making any hot beverage
  - `COMMON STEPS`: boilWater, pourInCup
- Some steps are unique to beverage.  
  - `UNIQUE STEPS`: addBase(), addCondiments()
```
- **Logic**
```c
  1. Create a `TEMPLATE METHOD` which contains all methods/algorithms to be used.
		 - Template method is creted `final`, so that it should not be overridden in derv class
  2. Make common methods as `CONCRETE`.
     - Concrete Methods which are common for all derv classes.
		 - Implement common methods in Base class
  3. `PRIMITIVE METHODS`: Methods for which derv class has their own implementation.
		 - Implement primitive methods in derv classes
  4. `Hooks(Optional)`: Derv class can override these methods or not.
  Java		C++
  abstract = Pure Virtual Functions
  final	
```  
  
