#include "mediator.h"

class mediator1:public mediator{
	float fMyMargin;
public:
	mediator1();
	void RegisterToSeller(seller*);
	void GetNotificationFromSeller(std::string&,float);	
	void SetObservers (bidder* pBidder);
};
