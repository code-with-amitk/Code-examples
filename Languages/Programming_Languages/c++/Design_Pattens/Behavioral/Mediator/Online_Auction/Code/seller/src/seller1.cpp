#include "seller1.h"

void seller1::NotifyMediators(){
	std::cout<<"seller1 NotifyMediators()\n";
}

//Setting Observers
void seller1::SetObservers(mediator* pMediator) {
	std::cout << "[Observer DP]Seller1 Storing Mediators" 
					  << NEWLINE;
	vecMediators.push_back(pMediator);
}

void seller1::RemoveMediators() {
	std::cout << "seller1 RemoveMediators()\n";
}

void seller1::InitiateAuction(std::string& strItem, float fitemPrice) {
	std::cout << "Seller Notifies Mediators to about item to sell:" 
						<< strItem << NEWLINE;
	fMinimumSellingCost = fitemPrice;

	for (auto i:vecMediators)
		i->GetNotificationFromSeller(strItem, fMinimumSellingCost);
}
