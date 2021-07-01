#pragma once
#include "common.h"
#include "mediator.h"

class mediator;			//Forward declaration

class seller{		//Abstract
protected:
	float fMinimumSellingCost;
	std::string strItemToSell;
	std::vector<mediator*> vecMediators;		//Mediator list for observer DP
public:
	virtual void NotifyMediators() = 0;	
	virtual void SetObservers(mediator*) =0;
	virtual void RemoveMediators() = 0;
	virtual void InitiateAuction(std::string&, float) = 0;
};
