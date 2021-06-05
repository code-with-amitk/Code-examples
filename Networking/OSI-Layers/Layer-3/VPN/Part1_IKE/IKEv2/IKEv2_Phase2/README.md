## IKEv2 Phase2 / CHILD_SA
- Authenticates Previous Messages. Exchange certificates(Optional)
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
