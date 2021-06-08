## VPN Terms
- *Cookie*
  - This is [MAC(not hash)](../../Security) which is generated during IKE Phase-1 (IKE SA) exchange. 
  - Initiator Generates {Initiator SPI = Initiator Cookie}
  - Responder generates {Responder Cookie = Responder SPI}
  - This protects the Peers from DoS & reply Attacks.
```c
    [Src-IP] [Dst-IP] [Src-Port-UDP] [Dst-Port-UDP] + [Secret Random Key] --->   | Hash Function |  -->  Cookie or SPI
```
- **[Dead Peer Detection](Dead_Peer_Detection)**
- **DOI(Domain on Interpretation)**
  - IPsec DOI is a document containing definitions for all the security parameters required for the successful negotiation of a VPN tunnel
  - All the attributes required for SA and IKE negotiations. 
- **Nounce:** Random generated number by initiator. This protects against reply attacks
- **[PFS(Perfect Forward Secrecy)](PFS)**
- **[Pre Shared Keys](Part1_IKE/IKE_Authentication)**
- **[SA(Security Association)](Security_Association)**
  - *SAD(Security Association DB)* Stored SAs
- **[SP(SECURITY POLICY):](SP)** Policies to be enforced on Traffic crossing IPSec boundaries
  - *SPD: Security policy Database*
- **[SPI(SECURITY PARAMETER INDEX)](SPI)**
- **IPSec(Over TCP):** IPSec is set of open standards for ensuring secure private communication over Internet. IPSec does not support broadcast & multicast. Parts of IPSec:
  - Part-1: Key Exchange for Data Encryption + Peer Authentication. Eg: IKE
  - Part-2: Encrypting the data with Keys exchanged in part-1. Eg: AH, ESP
