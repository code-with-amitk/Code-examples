## IKE / Internet Key Exchange
> UDP src,dst port:500
- **What?** Protocol used for establishment of [Security Association (SA)](../Terms). 
- **[IKE comprises of 3 protocols](Oakley_SKEME_ISAKMP.md):** Oakley, SKEME, ISAKMP
- [IKE Headers and Payloads](IKE_Headers_Payloads)
- **IKE Versions:** IKE has 2 versions IKEv1 and IKEv2.
  - [IKEv1 vs IKEv2](IKEv1_vs_IKEv2)
  - *[IKEv1 Explained](IKEv1)*
  - *[IKEv2 Explained](IKEv2)*
- **IKE Phases:** IKE Key exchange happens in 2 phases.
  - *Phase-1/IKE-SA:* Keys exchanges in Phase-1 are used to encrypt Phase-2 keys.
  - *Phase-2/IPSec-SA:* Keys exchanges in Phase-1 are used to encrypt actual data traffic.

