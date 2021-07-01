#include "mediator1.h"

mediator1::mediator1() {
	fMyMargin = 100.00;
}

void mediator1::RegisterToSeller(seller* pSeller){
	std::cout << "Mediator1 registering itself to Seller"
						<< NEWLINE << NEWLINE;
	pSeller->SetObservers(this);
	std::cout << "Mediator1 registered to Seller1" 
						<< NEWLINE << NEWLINE;
}

void mediator1::SetObservers (bidder* pBidder) {
  std::cout << "[Observer DP]Mediator1 Storing Bidders"
            << NEWLINE;
  vecBidders.push_back(pBidder);
}

void mediator1::GetNotificationFromSeller(std::string& strItem,
	float fItemPrice){
	std::cout << "Mediator1 gets Notification from Seller1 to start Auction"
		<< " Item to sell: " << strItem	<< NEWLINE;

	//Add my Margin and inform bidders

	for (auto i : vecBidders)
		i->GetInformation(strItem, fItemPrice+fMyMargin);
}
