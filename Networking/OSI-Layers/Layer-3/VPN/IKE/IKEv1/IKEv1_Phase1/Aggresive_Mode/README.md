## [Aggressive Mode](https://www.cloudshark.org/captures/e51f5c8a6b24)
- See [Main Mode](..)
```c
  Peer-1(Initiator)                                                           Peer-2(Responder)
      --(Message-1) 
        a. Proposes SA's in Transform Payload(Same as Main Mode Message-1)
        b. Starts DH Key Exchange Process    (Same as Main Mode Message-3)
        c. Sends Identification,Hash payload (Same as Main Mode Message-5) -->
        
  Calculates Public,Pvt Key          //Same as Main Mode//                  Calculates Public,Pvt Key

        <--  Message-2 
         a. Selected SA-Proposal (same as Main-mode Message-2) 
         b. Calculated Public Key(same as Main-mode Message-4)
         c. Identification,Hash payload (Same as Main Mode Message-6)  -------
```
