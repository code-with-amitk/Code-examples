## [Aggressive Mode](https://www.cloudshark.org/captures/e51f5c8a6b24)
- See [Main Mode](..)
- Authentication is done using [Pre-shared-keys or Certificates](/Networking/OSI-Layers/Layer-3/VPN/Part1_IKE)
```c
  Peer-1(Initiator)                                                                 Peer-2(Responder)
      --(Message-1) 
        a. Proposes Encryption,Auth Algos in Transform Payload(Same as Main Mode Message-1)
        b. Starts DH Key Exchange Process, random no          (Same as Main Mode Message-3)
        c. Sends Identification,Hash payload   //IKE Identity (Same as Main Mode Message-5) -->
                                                                            Authenticated Peer-1
  Calculates Public,Pvt Key          //Same as Main Mode//                  Calculates Public,Pvt Key

        <--  Message-2 
         a. Selected Encryption,Auth Algos in Transform Payload (Same as Main-mode Message-2) 
         b. Calculated Public Key                               (Same as Main-mode Message-4)
         c. Identification,Hash payload   //IKE Identity        (Same as Main Mode Message-6) --
         
  Authenticated Peer-2
  
       --(Message-3) Encrypted[I confirms the exchange] --------------------------->
   
    IKE SA Established for securing Phase-2 [DH Key Pair] [Encryption Algo] [Hash Algo]
```
