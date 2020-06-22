#include"Coffee.h"
#include"Tea.h"
#include"config.h"

int main()
{
	cout<<"Making Coffee From BeverageMaker\n";	
	Coffee *c = new Coffee();
	c->prepareRecipe();

	cout<<"\nMaking Tea From BeverageMaker\n";	
	Tea *t = new Tea();
	t->prepareRecipe();
}
