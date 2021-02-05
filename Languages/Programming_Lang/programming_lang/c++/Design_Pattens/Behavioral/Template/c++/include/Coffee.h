#ifndef COFFEE_H
#define COFFEE_H
#include"beverageMaker.h"

class Coffee:public beverageMaker 
{
public:
	 void addBase();
	 void addCondiments();
};

#endif
