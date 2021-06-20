## Fragmentation Reassembly
- **Why?** Frag & Reassembly only happens If (Packet Size > [MTU(Maximum Transmission Unit)](MTU_and_MSS))
- **Fields which change during Frag, Reassembly?**
  - Identification Number: Used that of Original Frame. Remains same for all IP Fragments.
  - Flags: DF, MF
  - Fragment Offset
- **How packet is broken into fragments?** Every fragment will have IP Header
```c
    Larger Datagram: | len=4000 | ID = x | fragFlag = 0 | offset = 0 |
    
    Fragmented to:   | len=1500 | ID = x | DF:0, MF:1 | offset = 0 |
                     | len=1500 | ID = x | DF:0, MF:1 | offset = 1480 |
                     | len=1040 | ID = x | DF:0, MF0 | offset = 2960 |
```
- **Reciever?**
```
  if(MF bit = 1){
    Place in buffer, start the timer.
    Wait for all packets of same ID-number, seq-number using Fragment offset feild.
    if last fragment receiver (MF=0) start re-assembly
  }
  
  - Its rule that Receiver should allocate a separate Buffer for all fragments having different ID number and wait till MF=0
  - If Fragment is Discarded by Reciever, then Sender should resend it.
```
