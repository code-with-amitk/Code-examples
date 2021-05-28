## [Aggressive Mode](https://www.cloudshark.org/captures/e51f5c8a6b24)
- [Main Mode](..)
```c
     Peer-1                                                                         Peer-2
        ---Message-1 SA-Proposals(same as Message-1 Main-mode) 
        + Key-exchange-payload+nonce+Identification+Hash(Same as Message-3,5)----->
        
Peer-1 Calculates: DH Secret Key, key2, key3                                  Peer-2 Calculates: DH Secret Key, key2, key3                

        <--Message-2 Selected SA-Proposal(same as Message-2 Main-mode) 
          + Key-exchange-payload+nonce+Identification+Hash(Same as Message-4,6)---
          
          ---Message-3 Encrypted Hash Payload--->
```
