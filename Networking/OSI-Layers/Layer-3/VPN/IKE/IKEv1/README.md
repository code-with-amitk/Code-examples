## IKEv1
- **[Phase-1 / Create IKE-SA](IKEv1_Phase1):** Purpose of Phase-1 is to exchange keys to protect Phase-2 Traffic.
  - Phase-1 can be carried in either of 2 modes
    - Main Mode(6 Messages)  OR
    - Aggressive Mode(3 Messages)
- **[Phase-2 / Create IPSec SA](IKEv1_Phase2):** Purpose of Phase-2 is to exchange keys to protect actual data traffic.
  - Phase-2 is carried out **only in 1 mode** ie
    - Quick Mode(3 Messages)
