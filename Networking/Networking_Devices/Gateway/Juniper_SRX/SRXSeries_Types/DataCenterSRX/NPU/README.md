## NPU / Network Processing Unit
- NPU is similar to SPU.
- NPU resides on its own Network Processing Card (NPC), NPC is similar to NIC.

### How it works
- The NPU takes each packet and balances it to the correct SPU that is handling that session.
- In the event that there is not a matching session on the NPU, it forwards the packet to the CP to figure out what to do with it.
- Each NPU can process about 
  - 6.5 million packets per second inbound 
  - 16 million packets outbound.
- The method the NPU uses to match a packet to a session is based on matching the packet to its wing table.

### NPU Bundling
- Upto 16 NPUs can be bundled together.
- 1st NPU is used as a load balancer to balance packets to the other NPUs, and then the remaining NPUs in the bundle are able to process packets.
