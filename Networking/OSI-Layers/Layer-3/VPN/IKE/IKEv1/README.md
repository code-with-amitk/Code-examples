## IKEv1
- **Main vs Aggressive Mode**

||Main Mode|Aggressive Mode|
|---|---|---|
|Bandwidth|Contains 6 Messages. Consumes more BW|Contains 3 messages. Quicker than Main Mode|
|Secure|More. Identification payloads sent encrypted.|Identification payloads sent unecrypted|

- **[Phase-1 / IKE-SA:](IKEv1_Phase1)** 
  - Negotiate IKE SA to protect Phase-2 Traffic.
  - [IKE SA Example](../../Terms/Security_Association/)
- **Phase-2 / IPSec SA:](IKEv1_Phase2)**
  - Message exchanges in phase-2 are protected by encryption keys derived in phase-1. 
  - Each IPSec SA has atleast two SAs. Inbound & Outbound
  - 
