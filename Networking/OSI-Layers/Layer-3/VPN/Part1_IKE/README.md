## IKE / Internet Key Exchange (UDP src,dst port:500)
- **What?** Protocol used for establishment of [Security Association (SA)](../Terms). IKE comprises of 3 protocols: [Oakley, SKEME, ISAKMP](Oakley_SKEME_ISAKMP.md).
- [IKE Headers and Payloads](IKE_Headers_Payloads)
- **IKE Versions:** IKE has 2 versions **[IKEv1](IKEv1)** and **[IKEv2](IKEv2)**.
  - [IKEv1 vs IKEv2, Advatanges of IKEv2 over IKEv1](IKEv1_vs_IKEv2)
- **IKE Phases:**
|Phase-1/IKE-SA|Phase-2/IPSec-SA|
|---|---|
|Keys exchanges in Phase-1 are used to encrypt Phase-2 keys|Keys exchanges in Phase-1 are used to encrypt actual data traffic|
