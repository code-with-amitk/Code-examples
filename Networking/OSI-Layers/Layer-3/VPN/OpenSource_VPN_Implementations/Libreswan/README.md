## Libreswan / strongswan
- **What?** 
  - This is continuation of openswan. Under active development for over 15 years, going back to The FreeS/WAN Project.
  - Uses NSS crypto library. IKE protocol uses UDP(500, 4500). Encryption/Decryption happens in kernel.
- **Terms?** Uses left and right for remote endspoints
- **Methods for authenticating Endpoints?**
  - *a. PSK(Pre-shared keys):* It is recommended not to use PSKs shorter than 64 random characters. 
  - *b. Raw RSA Keys:* The hosts are manually configured with each other's public RSA key. This method does not scale well when dozens or more hosts all need to setup IPsec tunnels to each other.
  - *c. X.509 certificates:* Certificates are issued to hosts. This is the use case when many hosts connect to central IPSec G/W.
  - *d. NULL Authentication:* This gain mesh encryption without authentication. NULL Authentication can also be used for internet scale Opportunistic IPsec, where clients authenticate the server, but servers do not authenticate the client.
  - *PPK(Post Quantum PSK):* This is an additional authentication method added by quantum computers.

## [Configuring libreswan server, client](https://sites.google.com/site/amitprojectworkhere/rh/ipsec)
