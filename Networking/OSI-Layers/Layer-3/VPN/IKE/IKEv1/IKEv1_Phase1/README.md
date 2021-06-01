## IKEv1 Phase 1
- **Modes:**
  - [Main Mode (6 Messages)](Main_Mode) OR
  - [Aggressive Mode (4 Messages)](Aggressive_Mode)
- [IKE SA Example](../../../Terms/Security_Association/)

||Main Mode(Recommended)|Aggressive Mode|
|---|---|---|
|Bandwidth|Contains 6 Messages. Consumes more BW|Contains 3 messages. Quicker than Main Mode|
|Secure|More. Identification payloads sent encrypted.|Identification payloads sent unecrypted|
|Use case||building VPNs from client workstations to VPN gateways|
