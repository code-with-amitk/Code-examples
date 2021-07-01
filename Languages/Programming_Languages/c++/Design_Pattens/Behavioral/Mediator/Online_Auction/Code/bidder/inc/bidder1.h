#include "bidder.h"

class bidder1:public bidder{
public:
	void RegisterToMediator(mediator*);
	void GetInformation(std::string&,float);	
};
