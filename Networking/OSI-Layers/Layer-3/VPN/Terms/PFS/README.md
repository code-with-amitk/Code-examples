## PFS / Perfact forward Secrecy
- **What?** Renegotiating Phase-1 keys,encryption-algos,auth-algos AGAIN before proceeding to negotiate Phase-1
- **Why?** keys exchanged in phase-1 are found at risk, particularly in Aggressive mode, because IKE identities are sent in the clear.
- **How?** 
  - New DH-keys are formed in IKEv1-Phase-1. New keys are generated using new Nonces exchanged between the peers. 
  - If PFS is enabled in [IKE Phase-2](..). Then New Key is generated in Phase-2.
