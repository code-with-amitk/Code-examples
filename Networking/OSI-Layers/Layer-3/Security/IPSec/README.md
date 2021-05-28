## IPSec (over TCP)
- **What?** 
  - Set of open standards for ensuring secure private communication over Internet. IPSec does not support broadcast & multicast.
- **Parts of IPSec:**
  - Part-1: Key Exchange for Data Encryption + Peer Authentication. Eg: [IKE](../../VPN)
  - Part-2: Encrypting the data with Keys exchanged in part-1. Eg: AH, ESP

||Authentication Header|Encapsulating Security Payload|
|---|---|---|
|Support|Integrity check|Integrity, Encryption|  
|IPv6 support|no|Yes|
|Encryption|No|Yes|

