## Methods of Congestion Control
- **1. PROVISIONING:**
  - Building a network(ie connecting devices to network) that is well matched with data it can carry.
- **2. TRAFFIC AWARE ROUTING:**
  - Routes are tailored according the traffic patterns, ie making least load on N/W.
- **3. ADMISSION CONTROL:**
  - New device into network is refused that may cause congestion into network.
- **[4. Nagle Algorithm](Nagle_Algorithm)** Handles small packet problem.
- **5. TCP Delayed ACK:** 
  - Here, TCP doesn't immediately ACK every single received TCP segment. Many ACKs are combined into a single response. ACKs are holed till delay ACK timer(200-500ms).


**NAGLE ALGO + DELAY ACK do not work well in TCP/IP:** 
  - Delayed ACKs waits on sending the ACK while Nagle's algorithm creates packet, waits for ACK to arrive and then send the data. 
  - There's nothing in TCP to automatically turn Nagle's algorithm or Delayed ACKs off, so we need to understand our network well enough to choose the options that will provide the best performance
