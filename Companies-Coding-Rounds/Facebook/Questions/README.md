### 1. What options do you have, nefarious or otherwise, to stop people on a wireless network you are also on (but have no admin rights to) from hogging bandwidth by streaming videos?
- We need to write device driver for wireless card to inject packets.
- **Steps?**
  - *1.* Determine [wireless network card](Wireless_Network/Wireless_Network_card.md) plugged into your linux laptop.
  - *2.* Determine [chipset](Wireless_Network/Wireless_Network_card.md) on wireless card
  - *3.* Determine [device driver](/Device_Drivers/Linux) supported by chipset from [Supported cards list](https://wireless.wiki.kernel.org/en/users/drivers).
