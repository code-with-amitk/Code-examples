## Advantages of IPSec
- *1. Transparent to Application Layer*
  - Since IPSec works on [Network Layer](/Networking/OSI-Layers), Application layer need not to bother(even aware) about IPsec.
- *2. Monitors All packets* 
  - Since IPSec works Network Layer, it can monitor all traffic from-to device.
- *3. [Confidentiality](../Encryption_Cryptography_Confidentiality)*
  - IPSec uses public keys to encrypt/decrypt data.
- *4. [Integrity](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security)*
  - IPSec provides integrity hence immpossible to forge data inbetween.
- *5. IPSec does not depend on Application*

## Disadvantages of IPSec
- *[1. CPU Overhead](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security)*
  - IPSec requires processing power to encrypt and decrypt data that passes thru server(since it uses S,P boxes).
- *2. Wide access range*
  - Example if IPSec tunnel is established from Router at home to corporate office. Then all devices at home would get connected to corporate network. If any device has malware that can be injected.
- *[3. Broken Encryption Algorithms and Hashes](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/security)*
  - if IPsec server is using broken algos that becomes vunerable.
