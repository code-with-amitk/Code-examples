## Types of Authentication
- **1. Local Authentication:** 
  - Username,passwd stored locally in a file `/etc/passwd`
  - Stores user information that are needed when user logs into system. Eg: UID, GID, login shell, Home directory.    
  - `/etc/shadow:` stores password in encrypted format
- **2. Centralized Authentication:**  
  - All systems on n/w connect to a central server for authentication. Protocols/Methods used:
    - *a. PPP/Remote Auth:* 
      - Remember PPP protocol is used for connection of Home Based user(Serial Cable User) to IP Network.  Ethernet cannot run on Serial/Telephone lines.    PAP(Password Authentication Protocol), CHAP(Challenge Handshake Authentication Protocol), MSCHAP(Microsoft CHAP), EAP(Extended Authentication Protocol), SPAP(Shiva PAP)
    - *[b. Pre-shared keys (PSK)](Pre_Shared_Key)*
    - _[c. Certificates](/Networking/OSI-Layers/Layer-7/Protocols/Encryption_Authentication/Certificates)_
    - *d. Smart-cards:* smart card authentication is variant of Certificate auth. SC also stores the certificates, when login is asked, SC presents certs & authenticates
```c
Smart Card -> libusb -> libccid(pscs-lite-ccid) <-devicefile-> pcsc-lite(pcscd) -> coolkey.so/opensc(DRIVERS) ->   SSSD-pam_sss,p11_child/pam_pkcs11/pam_krb5(PAM Module) ->   Login(sudo, su, gdm)/ESC
```
    - *[e. AAA Protocols](AAA_Protocols)*
```c
[Home User/SSL Browser]   ---- IP N/W --  [ASA G/W -> AAA Server]
```
