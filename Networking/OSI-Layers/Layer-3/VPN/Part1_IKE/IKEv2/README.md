- IKEv2 Phases
  - [IKEv2 Phase1 / IKE_SA](#phase1)

## IKEv2 Phases
- IKEv2 comprises of 2 phases

||Phase-1/IKE-SA-INIT|Phase-2 / IKE-AUTH|
|---|---|---|
|Number of Messages|2|2|
|Purpose|Keys exchanges in Phase-1 are used to encrypt Phase-2 keys|Keys exchanges in Phase-1 are used to encrypt actual data traffic|

- **CREATE_CHILD_SA:**
  - This allows the peers to create additional security associations between each other, similar to how multiple proxy IDs function in IKEv1.
- **INFORMATIONAL:**
  - Allows the peers to perform some housekeeping functions, including peer liveliness detection, removing SA relationships, and reporting error messages.

<a name=phase1></a>
### IKEv2 Phase1 / IKE_SA
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

<a name=phase2></a>
### IKEv2 Phase2 / CHILD_SA
- Authenticates Previous Messages. Exchange certificates(Optional)
- Authentication is done using [Pre-shared-keys or Certificates](/Networking/OSI-Layers/Layer-3/VPN/Part1_IKE)
```c
  Peer-1(Initiator)                                                            Peer-2(Responder)
  
            //IDENTIFICATION, AUTHENTICATION Payloads, Security Association are encrypted.
    ---|MAC  hdr|IP Hdr|Ikev2 Hdr|
        SA Payload|IDENTIFICATION payload|AUTHENTICATION payload| 
        Security Association | Traffic Selector: Initiator, Responder |-->
        |- IDENTIFICATION Payload: Contains MAC of  Data+Key |
        |- AUTHENTICATION Payload : Initiator: CERT or PSK,    Responder: Send PSK or Certificate|

        Authentication(Certificate is Authenticated), Identification(MAC is calculated & compared)
                            <--------Same are Message-3-------------        
```
