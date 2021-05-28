## IKEv1 Phase 1
- As we know IKEv1 Phase-1 can be carried in any of 2 modes:
  - [Main Mode (6 Messages)](Main_Mode) OR
  - [Aggressive Mode (4 Messages)](Aggressive_Mode)
- Negotiate IKE SA to protect Phase-2 Traffic.
  - [IKE SA Example](../../../Terms/Security_Association/)

||Main Mode|Aggressive Mode|
|---|---|---|
|Bandwidth|Contains 6 Messages. Consumes more BW|Contains 3 messages. Quicker than Main Mode|
|Secure|More. Identification payloads sent encrypted.|Identification payloads sent unecrypted|
