## Advantages of Certificates
- _1._ More secure wrt [Pre shared keys](../).
- _2._ More ideal in larger scale environments with numerous peer sites that should not all share a preshared key.
- _3._ Certificate Revocation status can be checked, which's not the case with [Pre shared keys](../).
- _4._ Certificates are not easily vulnerable to visual eavesdropping.

## Disadvantages of Certificates
- _1._ certificates can be compromised if access to filesystem on which they are stored is obtained.
- _2._ Complex process wrt psk.
- _3._ Takes more resources wrt psk.
