## IKEv2 Phase1 / IKE_SA
- Creation of IKE_SA, IKE SA is used to protect Phase-2 Negotiations. 
```c
  Peer-1(Initiator)                                                            Peer-2(Responder)
                              //Message 1,2 are not encrypted
      ----| MAC Hdr|IP Hdr|Ikev2 Hdr|SA Payload|Proposal Payload|Transform Payload|
          key Exchange Payload| Nounce Payload |--> 
          //Peer-1 proposes Transform sets(encryption, authentication Algo list, DH Group, Nounce). 
          Ex: {Policy-1 AES, SHA-1, DH group=2}    {Policy-2   3DES, MD5, DH Group=2}
          |- Ikev2 hdr:  |Initiator SPI: dff| Responder SPI: sas| Next Payload: Encrypted & authenticated(46)|
          |- SA Payload:    |Version: 2| Exchange Type: IKE_AUTH(35) | Flags: 8| Message ID:1| Len: 352 | 
          
          
                                                          //Peer-2 Selects one policy from list of policies.
                                                          
      Selected <-----|SA Payload|Transform Payload|Key Exchange Payload|Nounce Payload|--
      SKEYSEED generated                                                                                                                                                              SKEYSEED generated 
      From SKEYSEED Encryption, Authentication Keys are generated
```
