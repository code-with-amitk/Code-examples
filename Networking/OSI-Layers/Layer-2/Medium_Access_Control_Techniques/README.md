## Medium Access Control Techniques
- **1. Pure Aloha:** 
  - Any node can send data anytime, if collision occurs nodes wait for random amount of time(Backoff time) and re transmits. Throughput=18%. Vulnerable Time: Time which is wasted due to collision
```c
[Node-1]          [Node-3]            node-2            Node-4
  |                  |                 |                    |
  -----------------------------------------------------------
```

- **2. Slotted Aloha:** Time is divided into slots, Throughput = 37%

- **3. CSMA(CARRIER SENSE MULTIPLE ACCESS):** 
  - Carrier Sense(Listen to carrier) before sending. LBT(Listen before Transmission). Multiple Access many devices can access the channel.
  - ALGORITHMS
    - 1-Persistent:    if(channel==busy){//Loop to look channel until free}else{//send}
    - p-Persistent:    if(channel==busy){//Loop to look channel until free}else{//send with probability p}
  - ISSUES WITH CSMA: 
    - In large Network, the transmission time between one end of the cable and another is enough that one station may access the cable even though another has already just accessed it.

- **4. 
