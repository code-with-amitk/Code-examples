#pragma once
#include "seller.h"
#include "bidder.h"

class bidder;     //Forward declaration
class seller;

class mediator {
protected:
	std::vector<bidder*> vecBidders;
public:
	virtual void RegisterToSeller(seller*) = 0;	
	virtual void GetNotificationFromSeller(std::string&,float)=0;
	virtual void SetObservers (bidder* pBidder)=0;
};
