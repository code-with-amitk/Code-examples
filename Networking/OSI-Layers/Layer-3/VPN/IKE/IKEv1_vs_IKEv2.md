## IKEv1 vs IKEv2

||IKEv1/IPSec-SA|IKEv2/Child-SA(Simple)|
|---|---|---|
|Phases|<ul><li>Phase-1: Create IKE_SA</li></ul><ul><li>Phase-2: Create IPSEC_SA</li><ul>|<ul><li>Phase-1: Create IKE_SA</li></ul><ul><li>Phase-2: Create IPSEC_SA</li></ul>|
|Authentication Types|<ul><li>Pre-shared-keys(PSK), Digital-certs, Public-key-encryption</li></ul><ul><li>Both Peers must use same Authentication Method</li></ul>|<ul><li>PSK, Digital-certs</li></ul><ul><li>Both Peers can use different authentication method</li></ul>|
|Lifetime of SA|Agreement b/w peers is required|Not negotiated. Each Peer can delete SA anytime by exchanging Delete payload|
|Rekey|Not defined|Defined|
|NAT Traversal|Not supported|supported by default|
|Dead Peer detection|Supported as Exception|supported by default|
|Keep alives for SA||
|Remote access VPN|Not defined.|Supported by Default: EAP(Extensible Authentication Protocol), CP(Configuration Payload)|
|Mutli-homing|Not Supported|MOBIKE (Ikev2 mobility & multihoming protocol) |
|DOS Protection|Not Supported|Anti-Reply function supported, 'Cookies' supported for mitigating flooding attacks, Many vulnerabilities of ikev1 fixed|
|Reliable|less than ikev2|More. Procedure to Delete SA defined, Procedure to re-transmit message is defined|
|Extensions|Poor|Useful extensions are present|
