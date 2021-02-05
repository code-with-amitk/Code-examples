/* 
  Task: Create a generic Coffee,Tea maker machine
  Steps for Making:
  	    Coffee		Tea
	1. boilWater()		boilWater()
	2. addCoffee()		addTea()	//addBase()
	3. pourInCup()		pourInCup()
	4. addCondiments()	addCondiments()
	   - Milk		 - Lemon
	   - Sugar
   - Common Methods for Tea & Coffee. Eg: boilWater, pourInCup
   - Specific Methods: addBase(), addCondiments()

  Logic:
	Step-1: Create a template method which contains all methods/algorithms to be used.
		- Template method is creted final, so that it should not be overridden in derv class
  Step-2: Concrete Methods: Methods which are common for all derv classes.
		- Implement common methods in Base class
	Step-3: Primitive Methods: Methods for which derv class has their own implementation.
		- Let Primitve methods be implemented by derv classes
	Step-4: Hooks(Optional): Derv class can override these methods or not.

  Java		C++
  abstract = Pure Virtual Functions
  final	
 
  final method cannot be overriden in derived class
*/

//abstract class: Derived classes can provide their own implementation
public abstract class beverageMaker {      

	//1. TEMPLATE METHOD
	final void prepareRecipe() {        
		boilWater();        	
		addBase();        
		pourInCup();        
		addCondiments();    
	}

	/*CONCRETE OPERATIONS:To be implemented by Base class*/
 	void boilWater() {        
		System.out.println("Boiling water");    
	}      
	void pourInCup() {        
		System.out.println("Pouring into cup");    
	}
 
  /*PRIMITIVE OPERATION:To be implemented by Derv classes*/
 	abstract void addBase();      
	abstract void addCondiments();

	/*HOOKS:
	Can override the method, or not. It’s derv class choice.
	If derv class don’t, the abstract class provides a default implementation
	*/
	void hook() {}
}
