 ## Security Association
 - SA is a connection in context of IPSsec. SA/Connection is identified by security attributes(Eg: encryption key, encryption algorithm, mode between IPSec peers). 
 - Full bidirectional communication requires at least two SAs, one for each direction.
 - Since there are 2 stages in establishing IPSec tunnel there are 2 types of SAs.   
 
 ### Types of SAs
- **a. IKE SA:** Both participating peers establish their own IKE SA. IKE SA Example:
```c
  Authentication-method:           MD5
  Encryption method:               3DES
  DH group used:                   2
  Life of IKE SA:                  86400(sec)
  Shared secret key for encryption algo: Preshared
```        
- **b. IPSec SA:** 
  - Each Peer need to establish its own SA. IPSec tunnel provides following functions: 
    - *a.* Privacy(Through Encryption)  
    - *b.* Content Integrity(By data Authentication)  
    - *c.* Sender's Authentication(using Certificates)
  - IPSec SA Example:
```c
  Destination-address:        192.168.x.x
  SPI:                        7C123A9C
  Protocol:                   (ESP or AH)
  Authentication:             hmac-sha1-96
  Encryption:                 aes-cbc
```  
