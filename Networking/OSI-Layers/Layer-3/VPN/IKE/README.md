## IKE / Internet Key Exchange
> UDP src,dst port:500
- **What?** Hybrid protocol made from 3 protocols:
  - *1. Oakley:* Defines series of Key Exchanges
  - *2. SKEME(Secure Key Exchange Mechanism for Internet)*. Provides Anonymity, Repudity, Key refreshment
  - *3. ISAKMP (Internet Security Association and Key Management Protocol)* ISAKMP protocol is a framework for exchanging encryption keys and security association payloads.
- **Why IKE?** For establishment of [Security Association (SA)](../Terms). 
- **IKE Phases?**
  - *Phase-1/IKE-SA:* For Authentication, Estb of Pvt Keys. These keys will be used to encrypt Phase-2 keys.
  - *Phase-2/IPSec-SA:* Establish Keys using Keys established in Phase-1. Keys will encrypt data traffic.
- [IKE Headers and Payloads](IKE_Headers_Payloads)
