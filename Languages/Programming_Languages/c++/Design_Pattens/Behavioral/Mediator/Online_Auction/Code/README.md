### Build Steps
- **Linux**
```c
$ cd Code
$ mkdir build; cd build
$ cmake ..
```
- **Windows**
```c
cmd> cd Code
cmd> cd build
cmd> cmake -G "Visual Studio 16 2019" ..
```

### Run
- **Windows**
```c
cmd> cd build/driver
C:\Users\amitk\source\cmake\build\driver\Release> driver.exe
Seller1 Created
Mediator1 Created
Mediator1 registering itself to Seller

[Observer DP]Seller1 Storing Mediators
Mediator1 registered to Seller1

Bidder1 Created
bidder1 registering to Mediator

[Observer DP]Mediator1 Storing Bidders

Seller1 has new Item to Sell
Seller Notifies Mediators to about item to sell:Ring
Mediator1 gets Notification from Seller1 to start Auction Item to sell: Ring
[Bidder recieves Notification] Item in AuctionRingStarting Bid: 105

```
