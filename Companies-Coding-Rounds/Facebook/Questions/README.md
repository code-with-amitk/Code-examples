### 1. What options do you have, nefarious or otherwise, to stop people on a wireless network you are also on (but have no admin rights to) from hogging bandwidth by streaming videos?
- We need to attack wireless router(AP) by sending a fake packets so that AP disconnects connected devices and wait for re-authentication,authorization.
- We will do this by writing User-Space application such as [aircrack-ng](https://www.aircrack-ng.org/) which will ask Wireless network card plugged into our PC using its [device driver](/Device_Drivers/Linux).
```c
  <------------------------------My-Laptop--------------------->
  UserSpaceApp   device_driver   WireLess-Network-Card(Hardware)
  Inject 
  Fake
  packet  -------> Inject_fp()----------> Create Bits & send
                                                        --------fake_packet---->   Wireless_Network   Router(AP)
                                                                                                     Cuts channel with all users
                                                                                                     Re-authenticate
                                                                                                     Re-authorize
                  
```
- **Steps?**
  - *1.* Determine [wireless network card](Wireless_Network/Wireless_Network_card.md) plugged into your linux laptop.
  - *2.* Determine [chipset](Wireless_Network/Wireless_Network_card.md) on wireless card
  - *3.* Determine [device driver](/Device_Drivers/Linux) supported by chipset from [Supported cards list](https://wireless.wiki.kernel.org/en/users/drivers).
    - Install the driver, Write a User space application for Injecting the packets into wireless network. Eg: [aircrack-ng](https://www.aircrack-ng.org/)
    - [How it works](https://www.aircrack-ng.org/doku.php?id=injection_test)?
      - *Step-1:* Connectivity test by broadcasting probes.
      - *Step-2:* Once connectivity is good, Inject Packets and attack.
```c
 User_Space_Application     User_Space       Kernel_Space    
    Air-ng                 /device/file     Wireless_Driver
  1. Connectivity Test
    - Send probe broadcast  -------------send_broadcast() ---->       wireless network  ---> Access_Point
                                                                                                 Router
     callback_recv(){                            <-----------------------ACK----------------------
      //Send 30 more probes
      //This determines how well
      //we can communicate
     }      

  2. Inject Packets
```

