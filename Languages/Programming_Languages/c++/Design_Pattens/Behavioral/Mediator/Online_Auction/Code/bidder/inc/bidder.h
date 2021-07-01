#pragma once
#include "mediator.h"

class mediator;

class bidder {
public:
	virtual void RegisterToMediator(mediator*) = 0;	
	virtual void GetInformation(std::string&,float)=0;
};
