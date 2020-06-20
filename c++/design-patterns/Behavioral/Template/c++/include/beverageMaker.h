#ifndef BEVERAGEMAKER_H 
#define BEVERAGEMAKER_H

class beverageMaker {
public:

	//final: This function cannot be overridden in derv class
	//virtual: Not required, since I will not override & access with same ptr
	virtual void prepareRecipe() final
	{
    boilWater();
    addBase();
    pourInCup();
    addCondiments();
	}
	void boilWater();
	void pourInCup();
	
	//virtual: These methods should be overriden in derv classes
	virtual void addBase()=0;
	virtual void addCondiments()=0;

	void hook(){}
};

#endif
