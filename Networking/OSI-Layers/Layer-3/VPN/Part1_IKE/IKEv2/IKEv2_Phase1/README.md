## IKEv2 Phase1 / IKE_SA
- Creation of IKE_SA, IKE SA is used to protect Phase-2 Negotiations. 
- [Payloads](../../IKEv1/IKEv1_Phase1/Main_Mode/)
```c
SAP(SA Payload)
PP(Proposal Payload)
TP(Transform Payload)
KEP(Key Exchange Payload)
NP(Nouce Payload)

  Peer-1(Initiator)                                                            Peer-2(Responder)
                              //Message 1,2 are not encrypted
      ----|MAC|IP|
          Ikev2 Hdr(Initiator SPI|Responder SPI: sas|Next Payload)|SAP|PP|TP|KEP|NP--->
          
    Peer-1 proposes Transform payloads(encryption, authentication Algo list, DH Group, Nounce). 
    TP-1:{AES, SHA-1, DH group=2}.  
    TP-2{3DES, MD5, DH Group=2}
          
                                                          //Peer-2 Selects one policy from list of policies.
                                                          
      Selected            <-----|SAP|TP|KEP|NP|--
      
  SKEYSEED generated                                                        SKEYSEED generated 
  
From SKEYSEED Encryption, Authentication Keys are generated
```
