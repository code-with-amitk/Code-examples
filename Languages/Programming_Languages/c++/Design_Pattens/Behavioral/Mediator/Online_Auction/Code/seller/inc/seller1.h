#pragma once
#include "seller.h"
#include "mediator.h"

class seller1:public seller{		//Abstract
public:
	void NotifyMediators();	
	void SetObservers(mediator*);
	void RemoveMediators();
	void InitiateAuction(std::string&, float);
};
