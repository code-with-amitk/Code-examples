### 1. What options do you have, nefarious or otherwise, to stop people on a wireless network you are also on (but have no admin rights to) from hogging bandwidth by streaming videos?
#### Solution-1
- Since you know "people are streaming video", politely ask each person to refrain from streaming video in order that the the WiFi network can be used for other purposes.

#### Solution-2
- Contact the network owners / administrators about increasing capacity on the WiFi network (and related uplinks.)

### Solution-3
- Try forging RST packets and get the sender to abort the connection. 
- Or try man-in-the-middle attack against the downloader, divert their internet connection to something you control, and substitute alternative less interesting videos.
- Or just do a denial-of-service attack against the downloaders to degrade their connection so that they give up and move to another network.

#### Solution-4
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

