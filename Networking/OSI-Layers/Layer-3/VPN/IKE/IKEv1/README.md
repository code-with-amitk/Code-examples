## IKEv1

||[Phase-1 / Create IKE-SA](IKEv1_Phase1)|[Phase-2 / Create IPSec SA](IKEv1_Phase2)|
|---|---|---|
|Carried in|Either of 2 modes: <ul><li>Main Mode(6 Messages)  OR</li></ul> <ul><li>Aggressive Mode(3 Messages)</li></ul>|Only Quick Mode|
|Purpose|Exchange keys to protect Phase-2 Traffic|<ul><li>Negotiates encryption & authentication algorithms to be used to encrypt data traffic</li></ul> <ul><li>Neogitates method to be used to encrypt the data traffic:ESP or AH</li></ul><ul><li>Negotiates Proxy IDs that identify the traffic to be encrypted</li></ul><ul><li>Optional Perfect Forward Secrecy (PFS), is negotiated</li></ul>|

