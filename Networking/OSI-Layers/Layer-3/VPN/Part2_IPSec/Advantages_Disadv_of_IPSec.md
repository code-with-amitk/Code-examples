## Advantages of IPSec
- _1._ Transparent to Application Layer
  - Since IPSec works on [Network Layer](/Networking/OSI-Layers), Application layer need not to bother(even aware) about IPsec.
- _2._ Monitors All packets
  - Since IPSec works Network Layer, it can monitor all traffic from-to device.
- _3._ [Confidentiality](../Encryption_Cryptography_Confidentiality)
  - IPSec uses public keys to encrypt/decrypt data.
- _4._ [Integrity](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security)
  - IPSec provides integrity hence immpossible to forge data inbetween.
- _5._ IPSec does not depend on Application
- _6._ Support IPv6

## Disadvantages of IPSec
- *[1. CPU Overhead](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security)*
  - IPSec requires processing power to encrypt and decrypt data that passes thru server(since it uses S,P boxes).
- *2. Wide access range*
  - Example if IPSec tunnel is established from Router at home to corporate office. Then all devices at home would get connected to corporate network. If any device has malware that can be injected.
- *[3. Broken Encryption Algorithms and Hashes](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security)*
  - if IPsec server is using broken algos that becomes vunerable.
- _4._ Does not support: Multicast, broadcast
  - These are based on the L3 information, we can use GRE tunnel. We can combine both to have the multicast traffic working and security over it.
