- [What is IKE](#what)
- [IKE Headers and Payloads](IKE_Headers_Payloads)
- [Disadvantages of IKE](#dis)
- IKEv1 vs IKEv2
  - [Feature Differences](#fd)
  - [Difference in Number of Messages](#nom)
- [IKEv1](IKEv1)
- [IKEv2](IKEv2)

<a name=what></a>
## IKE / Internet Key Exchange (UDP src,dst port:500)
- Protocol used for establishment of [Security Association (SA)](../Terms).
- IKE comprises of 3 protocols:
  - *1. Oakley:* Defines series of Key Exchanges
  - *2. SKEME(Secure Key Exchange Mechanism for Internet)*. Provides Anonymity, Repudity, Key refreshment
  - *3. ISAKMP (Internet Security Association and Key Management Protocol)* ISAKMP protocol is a framework for exchanging encryption keys and security association payloads.

<a name=dis></a>
## Disadvantages of IKE
- _1. Setting 1000's of VPN's/sec takes times, consumes resources_
  - Although 1 IKE negotiation might not require too many resources
- _2. If orgnization does not want keys to expire_

## IKEv1 vs IKEv2
<a name=fd></a>
### Feature Differences

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
|[Latency](/System-Design/Concepts/Terms)|High(Because [IKEv1 has 9 messages](..))|Low(Because [IKEv2 has 4 messages](..))|
  
<a name=nom></a>
### Difference in Number of Messages
- **IKEv1** Main Mode:9 Messages. Aggressive Mode: 6 Messages
  - Phase-1(Main or Aggressive mode)
    - Main Mode: 6 messages
    - Aggressive Mode: 3 messages
  - Phase-2(Quick mode: 3 messages)
- **IKEv2** Total: 4 messages
  - Phase-1(2 messages)
  - Phase-2(2 messages)


- **IKE Versions:** IKE has 2 versions **[IKEv1](IKEv1)** and **[IKEv2](IKEv2)**.
  - [IKEv1 vs IKEv2, Advatanges of IKEv2 over IKEv1](IKEv1_vs_IKEv2)
- **IKE Phases:**

|Phase-1/IKE-SA|Phase-2/IPSec-SA|
|---|---|
|Keys exchange to encrypt Phase-2 keys|Keys exchanges to encrypt actual data traffic|

- [IKE Authentication](IKE_Authentication): Pre-shared keys, Certificates
