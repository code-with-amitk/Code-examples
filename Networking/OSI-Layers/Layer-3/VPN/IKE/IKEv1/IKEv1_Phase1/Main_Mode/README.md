## IKEv1 Main Mode
```c
Peer-1                                                                                                            Peer-2
                                //1st 4 Messages are not Encrypted
      -- Message-1{I propose SA-proposal-1, SA-proposal-2, SA-proposal-3. Sends 1 or more SA-proposal-payloads}-->
        |MAC|IP|UDP|
        IKE Hdr {Initiator SPI=e19218, Responder SPI=0, Next payload=SA, Version=1, Exchange-type=2, Flags=0, MessageID=0, Len=168}  
        Generic Payload Header{Next Payload=Vendor ID(13), Reserved=0, Payload Length=60} + SA-Payload  {DOI: IPSec, Situation: 1}                                    
        Generic Payload Header{Next Payload=None, Reserved=0, Payload Length=48} + Proposal-Payload: {Proposal-no: 1, Protocol-ID=ISAKMP, SPI-Size=0, Number-of-transforms=1}
        Generic Payload Header{Next Payload=None, Reserved=0, Payload Length=40} + Transform-Payload: {Transform-no: 1, Tranform-ID=KEY_IKE, Reserved=0, encryption-Algo=AES-CBC, Key-Length=128, Hash-Algo=SHA, Authentication-Method=Pre-shared Key, Life-type=Seconds, Life-Duration=86400}
        Generic Payload Header{Next Payload=None, Reserved=0, Payload Length=40} + Vendor-Payload {Vendor-id=knasjnao912knka} 

      <----Message-2 {Peer-2 selects 1 SA-proposal-1 from list of SA-proposals received}----------
        |MAC|IP|UDP|
        IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, Next payload=SA, Version=1, Exchange-type=2, Flags=0MessageID=0, Len=108}
        Generic Payload Header{Next Payload=Vendor ID(13), Reserved=0, Payload Length=48} +  SA-Payload  {DOI: IPSec, Situation: 1 (Identity Only:1, Secrecy:0, Integrity:0}} 
        Generic Payload Header{Next Payload=None, Reserved=0, Payload Length=48} + Proposal-Payload: {Proposal-no: 1, Protocol-ID=ISAKMP, SPI-Size=0, Number-of-transforms=1}
        Generic Payload Header{Next Payload=None, Reserved=0, Payload Length=40} + Transform-Payload: {Transform-no: 1, Tranform-ID=KEY_IKE, Reserved=0, encryption-Algo=AES-CBC, Key-Length=128, Hash-Algo=SHA, Authentication-Method=Pre-shared Key, Life-type=Seconds, Life-Duration=86400}
        Generic Payload Header{Next Payload=None, Reserved=0, Payload Length=20} + Vendor-Payload {Vendor-id=knasjnao912knka} 
        Generic Payload Header{Next Payload=None, Reserved=0, Payload Length=60} +

        ----Message-3 {I propose key-exchange-algorithms(DH, RSA ...) and nonce}------------>
        |MAC|IP|UDP|
        IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, Next payload=4, Version=1, Exchange-type=2, Flags=0, MessageID=0, Len=284}
        Generic Payload Header{Next Payload=10, Reserved=0, Payload Length=132} +  Key-exchange-payload  {key-exchange-data=asdae123123as515nn} 
        Generic Payload Header{Next Payload=13, Reserved=0, Payload Length=24} +  nounce-payload  {nonce-data=asdae123123as515nn} 
        Generic Payload Header{Next Payload=20(NAT-D), Reserved=0, Payload Length=20} +  vendor-id-payload  {nonce-data=faknjas19231ka} 
        Generic Payload Header{Next Payload=12, Reserved=0, Payload Length=20} +  natd-payload  {hash-of-address-and-port=kskf1928398ajsdiahs} 

        <--Message-4 {Select key-exchange-algorithm(DH) and [Let's take=Prime-no+Integer], nonce}------------
          |MAC|IP|UDP| IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, Next payload=4, Version=1, Exchange-type=2, Flags=0, MessageID=0, Len=304}
          Generic Payload Header{Next Payload=10, Reserved=0, Payload Length=132} +  Key-exchange-payload  {key-exchange-data=asdae123123as515nn} 
          Generic Payload Header{Next Payload=13, Reserved=0, Payload Length=24} +  nounce-payload  {nonce-data=asdae123123as515nn} 
          Generic Payload Header{Next Payload=20(NAT-D), Reserved=0, Payload Length=20} +  vendor-id-payload  {nonce-data=faknjas19231ka} 
          Generic Payload Header{Next Payload=12, Reserved=0, Payload Length=20} +  natd-payload  {hash-of-address-and-port=kskf1928398ajsdiahs} 

Peer-1 Calculates: DH Secret Key, key2, key3                                                                                                                                                            Peer-2 Calculates: DH Secret Key, key2, key3
Identification payload + Hash payload -> |Encrypt| -> XXX
These authenticate Peer to other Peer

          -------Message-5 {Identification + Hash payload XXX}------------>
            |MAC|IP|UDP| 
            IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, Next payload=5, Version=1, Exchange-type=2, Flags=1, MessageID=0, Len=108} + XXX
                                                                                                                                                                                                                            YYY < |Encrypt| < Identification payload + Hash payload
          <-------Message-6 {Identification + Hash payload YYY}------------
            |MAC|IP|UDP|
            IKE Hdr {Initiator SPI=e19218, Responder SPI=a0089b, Next payload=5, Version=1, Exchange-type=2, Flags=1, MessageID=0, Len=108} + YYY

                          IKE SA Established  [DH Key Pair] [Encryption Algo] [Hash Algo]
```                                                                 
