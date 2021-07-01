#include "common.h"
#include "seller1.h"
#include "mediator1.h"
#include "bidder1.h"

int main() {
	seller* pSeller1 = new seller1();
	std::cout << "Seller1 Created" << NEWLINE;

	mediator* pMediator1 = new mediator1();
	std::cout << "Mediator1 Created" << NEWLINE;

	pMediator1->RegisterToSeller(pSeller1);

	bidder* pBidder1 = new bidder1();
	std::cout << "Bidder1 Created" << NEWLINE;

	pBidder1->RegisterToMediator(pMediator1);

	std::cout << NEWLINE << "Seller1 has new Item to Sell" << NEWLINE;
	std::string strItem = "Ring";
	float fMinimumSellingCost = 5.0;
	pSeller1->InitiateAuction(strItem, fMinimumSellingCost);
}
