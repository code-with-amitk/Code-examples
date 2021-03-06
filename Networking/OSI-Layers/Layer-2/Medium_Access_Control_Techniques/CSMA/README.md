## CSMA(CARRIER SENSE MULTIPLE ACCESS)
- **What?** Carrier Sense(Listen to carrier) before sending. LBT(Listen before Transmission). Multiple Access many devices can access the channel.
- **ALGORITHMS**
  - 1-Persistent:    if(channel==busy){//Loop to look channel until free}else{//send}
  - p-Persistent:    if(channel==busy){//Loop to look channel until free}else{//send with probability p}
- **ISSUES WITH CSMA:**
  - In large Network, the transmission time between one end of the cable and another is enough that one station may access the cable even though another has already just accessed it.

### Types of CSMA
- **1. CSMA/CD(Collision Detection)/Used in Wired networks/LAN: 802.3(ethernet).** 
  - LWT(Listen while transmission), Each sender waits for carrier to become Idle(watching Carrier Signal) when Idle sends. If collision is detected Jamming Signal is sent & after random time carrier is again sensed.
    DISADVANTAGE: If bus is busy, Free carrier is not sensed & node has to wait for long time, performance drops drastically. It is estimated that network traffic must be less than 40 percent of the bus capacity for the network to operate efficiently. If distances are long, time lags occur that may result in inappropriate carrier sensing, and hence collisions
- **2. CSMA/CA(Collision Avoidance)/Used in Wireless Networks:** 
  - Used in 802.11 wireless Networks. Here collision cannot be detected, by its avoided by sending Frame (Request to send) before starting data transmission
  - **How it works**
    - RTS, CTS is called MACA protocol
  
  <img src=802_11.png width=800 />
