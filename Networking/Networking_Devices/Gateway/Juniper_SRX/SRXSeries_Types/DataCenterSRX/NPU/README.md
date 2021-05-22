## NPU / Network Processing Unit
- NPU is similar to SPU, resides on NIC or IOC(Input/output card).
- Each NPU can process about 
  - 6.5 million packets per second inbound 
  - 16 million packets outbound.

```c
          10 GB NIC/IOC
         -----------------           |- SPU1 (Handle Session)
 -pkt-> | NPC   |   NPU   | ---------|- SPU2
         -----------------           |- SPU3
```
### Purpose/How it works
  - NPU finds to which SPU to send incoming packet to(based on matching session). if no session is found packet is sent to CP. 
  - NPU decides what needed to be done on packet using **Wing Table/Routing Table**.
  - Wing Table can contain 5 million entries expires in 5 min(if no packet passed thru the flow).
  - SRX device can have Ingress and exgress NPU. Each NPU having its Wing Table.
```c
      NPU
    Look at wing table
    if (matching session)
        -forward to SPU---------->SPU-1
                       ---------->SPU-2
                       ---------->SPU-3
    else  //no matching session
      Forward to CP
```

### NPU Bundling
- Upto 16 NPUs can be bundled together.
- 1st NPU is used as a load balancer to balance packets to the other NPUs, and then the remaining NPUs in the bundle are able to process packets.
