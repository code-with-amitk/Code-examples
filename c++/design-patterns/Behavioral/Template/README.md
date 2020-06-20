### Definition of Template DP
  - This deﬁnes the skeleton of an algorithm in a method, deferring some steps to subclasses. 
  - Template Method lets subclasses to redeﬁne certain steps of an algorithm without changing the algorithm’s structure.

### What is template?
  - Method present in base class, which defines algorithms of steps(functions called in specific order).
  - Some algorithms are kept intact(should not be overriden), while others allowed to be overridden.
  
### PROBLEM/TASK: Create a generic Beverage Maker machine (Coffee,Tea etc)
#### Steps for Making beverage:

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

#### Logic
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

### In Code
- `Final function` cannot be inherited in derived class

|  | Java | C++ |
| --- | --- | --- |
| equals | abstract method | Pure Virtual function |
  
  
