## VPN Terms
- **Cookie** 
  - This is [MAC(not hash)](../../Security) which is generated during IKE Phase-1 (IKE SA) exchange. 
  - This protects the Peers from DoS & reply Attacks. How cookie is generated:
```c
    [Src-IP] [Dst-IP] [Src-Port-UDP] [Dst-Port-UDP] + [Secret Random Key] --->   | Hash Function |  -->  Cookie or SPI
```    
  - Initiator Generates {Initiator SPI = Initiator Cookie}
  - Responder generates {Responder Cookie = Responder SPI}
- **DOI(Domain on Interpretation)** 
  - IPsec DOI is a document containing definitions for all the security parameters required for the successful negotiation of a VPN tunnel
  - All the attributes required for SA and IKE negotiations. 
- **Nounce** Random generated number by initiator. This protects against reply attacks
- **PFS(Perfect Forward Secrecy)** 
  - IKEv1-Phase-1 derives DH-keys to encrypt data exchange. But it may happen that Peers again initiate DH-key-exchange with encrypted traffic using keys derived in phase-1.
  - This way completely new DH-keys are formed in IKEv1-Phase-2. New keys are generated using new Nonces exchanged between the peers. 
- **[SA(Security Association)](Security_Association)**
6. SAD: Security Association DB
7. SP(SECURITY POLICY): Policies to be enforced on Traffic crossing IPSec boundaries
8. SPD: Security policy Database
9. SPI(SECURITY PARAMETER INDEX) eg:7C123A9C. This tag helps the Peers to distinguish between two IPSec streams. For Example: if there were 2 different IPSEC flows between 2 peers, each using a different secret key, the SPI would allow each peer to determine which key to use on each packet. 
Can SPI be same as cookie? Yes can be same as cookie exchanged in phase-1
Where is used? It should be present in IPSec SA. An SPI has only local significance, since it is defined by the creator of the SA
10. IPSec(Over TCP): IPSec is set of open standards for ensuring secure private communication over Internet. IPSec does not support broadcast & multicast. Parts of IPSec:
    Part-1: Key Exchange for Data Encryption + Peer Authentication. Eg: IKE
    Part-2: Encrypting the data with Keys exchanged in part-1. Eg: AH, ESP
