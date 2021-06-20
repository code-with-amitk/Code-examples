## Online Auction
- **1. Seller:** Will have minimum cost to sell for item = MinCostToSell
- **2. Mediator:** Mediator will be present inbetween bidders and seller.
  - Will start bids from 0, Will increase bids by constant value x. if no bids will expire in time=t.
```c
if (bids < MinCostToSell) 
  - Will not sell item
```
- **3. Bidders:** Will be notified about auction by mediator            //Observer Design Pattern
- **4. External Product: autobidder** This can autobid on behalf of bidder. Bidder need to purchase it.
  - if bidder is online, autobidder should be disabled.
```uml

```
