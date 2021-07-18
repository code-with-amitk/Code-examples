- [IKEv1 Phases](#phases)
- IKEv1 Phase-1
  - [Main Mode](#mm)

<a name=phases></a>
## IKEv1 Phases
- IKEv1 is carried in 2 phases

||[Phase-1 / Create IKE-SA](IKEv1_Phase1)|[Phase-2 / Create IPSec SA](IKEv1_Phase2)|
|---|---|---|
|Carried in|Either of 2 modes: <ul><li>Main Mode(6 Messages)  OR</li></ul> <ul><li>Aggressive Mode(3 Messages)</li></ul>|Only Quick Mode|
|Purpose|Exchange keys to protect Phase-2 Traffic|<ul><li>Negotiates encryption & authentication algorithms to be used to encrypt data traffic</li></ul> <ul><li>Neogitates method to be used to encrypt the data traffic:ESP or AH</li></ul><ul><li>Negotiates **[Proxy IDs](ProxyID)** that identify the traffic to be encrypted</li></ul><ul><li>Optional [Perfect Forward Secrecy (PFS)](../../Terms), is negotiated</li></ul>|

## IKEv1 Phase-1
- This is carried either in main mode or aggressive mode
<a name=mm></a>
### [IKEv1 Main Mode](https://www.cloudshark.org/captures/ff740838f1c2)
- Authentication is done using [Pre-shared-keys or Certificates](/Networking/OSI-Layers/Layer-3/VPN)
```c
GPH: Generic Payload Header
SAP: SA-Payload
PP: Proposal Payload
TP: Transform Payload
VP: Vendor Payload
KEP: Key exchange Payload (contains Public Key)
NoP: Nonce Payload

Re: Reserved, NP: Next Payload, PL: Payload Length

Peer-1                                                                                                Peer-2
                                //1st 4 Messages are not Encrypted

//////(Message-1) Initiator proposes Encryption & Authentication algorithms(in 2 TP)//////////////////
--|MAC|IP|UDP|
  IKE Hdr{Initiator SPI=e19218, Responder SPI=0, NP=SA, Version=1, Exchange-type=2, Flags=0, MessageID=0, Len=168}  
  GPH{NP=PP, Res=0, PL=60} + SAP{DOI: IPSec, Situation: 1}
  GPH{NP=VP, Res=0, PL=48} + PP{Proposal-no: 1, Protocol-ID=ISAKMP, SPI-Size=0, Number-of-transforms=1}
  GPH{NP=TP, Res=0, PL=40} + VP{Vendor-id=knasjnao912knka}
  GPH{NP=TP, Res=0, PL=40} + TP{Transform-no: 1, Tranform-ID=KEY_IKE, Res=0,
                                  encryption-Algo=AES-CBC, Key-Length=128, Hash-Algo=SHA2,
                                  Authentication-Method=Pre-shared Key, Life-type=Seconds, 
                                  Life-Duration=86400}
  GPH{NP=None, Res=0, PL=40} + TP{Transform-no: 2, Tranform-ID=KEY_IKE, Res=0,
                                  encryption-Algo=3DES, Key-Length=128, Hash-Algo=SHA3,
                                  Authentication-Method=Pre-shared Key, Life-type=Seconds, 
                                  Life-Duration=86400} ---------->


//////(Message-2) Responder accept the proposal(ie Encryption, Auth) in TP/////////////////////
 <--|MAC|IP|UDP|
    IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, NP=SA, Ver=1, Exchange-type=2, Flags=0, MsgID=0, Len=108}
    GPH{NP=PP, Res=0, PL=48} + SAP{DOI: IPSec, Situation: 1 (Identity Only:1, Secrecy:0, Integrity:0}} 
    GPH{NP=TP, Res=0, PL=48} + PP{Proposal-no: 1, Protocol-ID=ISAKMP, SPI-Size=0, Number-of-transforms=1}
    GPH{NP=VP, Res=0, PL=40} + TP{Transform-no: 1, Tranform-ID=KEY_IKE, Res=0,
                                  encryption-Algo=AES-CBC, Key-Length=128, Hash-Algo=SHA2,
                                  Authentication-Method=Pre-shared Key, Life-type=Seconds, 
                                  Life-Duration=86400}
    GPH{NP=None, Res=0, PL=20} + VP{Vendor-id=knasjnao912knka} 

Peer-1: Calculates PUBLIC KEY
  Random-no=r=3
  Prime=p=13
  Integer=q=6
  Public-Key=qPow(r)modp=XX

////////(Message-3) Initiator starts DH Key Exchange Process. Send its Public-Key+Nonce(Random no)////////////////
                    Initiator can ask Responder to select Key exchange algo (DH, RSA other..)
  --|MAC|IP|UDP|
    IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, NP=, Version=1, Exchange-type=2, Flags=0, MessageID=0, Len=284}
    GPH{NP=NoP, Res=0, PL=132} + KEP{Public-Key = XX}
    GPH{NP=None, Res=0, PL=24} + NoP{nonce(random no) = 3}

                                                                          Peer-2: Calculates PUBLIC KEY
                                                                            Random-no=r=10
                                                                            Prime=p=13
                                                                            Integer=q=6
                                                                            Public-Key=qPow(r)modp=YY

//////////(Message-4) Responder responds with his Public-key/////////////////////////////
 <--|MAC|IP|UDP|
    IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, NP=4, Version=1, Exchange-type=2, Flags=0, MsgID=0, Len=304}
    GPH{NP=NoP, Res=0, PL=132} +  KEP{Public-Key = YY} 
    GPH{NP=VP, Res=0, PL=24} +  NoP{nonce(random no) = 10} 
    GPH{NP=NAT-D, Res=0, PL=20} + VP{nonce-data=faknjas19231ka} 
    GPH{NP=12, Res=0, PL=20} +  natd-payload{hash-of-address-and-port=kskf1928398ajsdiahs} 

Peer-1: Calculates PVT KEY                                               Peer-2: Calculates PVT KEY
              Now Both Communicates over Encrypted Channel

/////////(Message-5) Initiator sends responder its IKE identity to authenticate itself/////////
 --|MAC|IP|UDP| 
  IKE Hdr {InitiatorSPI=e19218, ResponderSPI=a0089b, NP=Identification, Version=1, Exchange-type=2, Flags=1, MessageID=0, Len=108}
  GPH{NP=HP, Res=0, PL=132} + Encrypted[Identification-Payload{...}]
  GPH{NP=None, Res=0, PL=132} + Encrypted[HashPayload{...}]

/////////(Message-6) Responder sends its IKE identity to authenticate itself/////////
 <--|MAC|IP|UDP| 
  IKE Hdr {InitiatorSPI=e19218, ResponderSPI=a0089b, NP=Identification, Version=1, Exchange-type=2, Flags=1, MessageID=0, Len=108}
  GPH{NP=HP, Res=0, PL=132} + Encrypted[Identification-Payload{...}]
  GPH{NP=None, Res=0, PL=132} + Encrypted[Hash-Payload{...}]

                   IKE SA Established  [DH Key Pair] [Encryption Algo] [Hash Algo]
```                                                                 
