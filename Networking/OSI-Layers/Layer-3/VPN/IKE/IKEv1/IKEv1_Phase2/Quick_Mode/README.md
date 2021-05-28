## Quick Mode
```c
    Peer-1                                                                            Peer-2
          ---Message-1------->
        |MAC|IP|UDP|
        IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, Next payload=5, Version=1, 
        Exchange-type=32(QuickMode), Flags=1, MessageID=0x12812, Len=156}    
        Encrypted-data(encrypted using keys exchanged in phase-1)
            |- Generic Payload Header + hash_payload
            |- Generic Payload Header + SA_payload
            |- Generic Payload Header + Nonce_payload
            |- Generic Payload Header + Identification_payload
            
     <---Message-2
        |MAC|IP|UDP| 
        IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, Next payload=5, Version=1, 
        Exchange-type=32(QuickMode), Flags=1, MessageID=0x12812, Len=172} + Encrypted-data---
        
     ---Message-2 
        |MAC|IP|UDP| 
        IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, Next payload=5, Version=1, 
        Exchange-type=32(QuickMode), Flags=1, MessageID=0x12812, Len=172} + Encrypted-data--->
```
