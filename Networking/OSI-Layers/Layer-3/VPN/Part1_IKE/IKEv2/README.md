## IKEv2

||[Phase-1/IKE-SA-INIT](IKEv2_Phase1)|[Phase-2 / IKE-AUTH](IKEv2_Phase2)|
|---|---|---|
|Number of Messages|2|2|
|Purpose|Keys exchanges in Phase-1 are used to encrypt Phase-2 keys|Keys exchanges in Phase-1 are used to encrypt actual data traffic|

- **CREATE_CHILD_SA:**
  - This allows the peers to create additional security associations between each other, similar to how multiple proxy IDs function in IKEv1.
- **INFORMATIONAL:**
  - Allows the peers to perform some housekeeping functions, including peer liveliness detection, removing SA relationships, and reporting error messages.
