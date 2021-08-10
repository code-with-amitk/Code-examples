**Information Security**
- [1. Secrecy / Confidentiality / Encryption](#sec)
  - [Cipher Algorithms](#ca)
  - **Types of Encryption**
    - [Assymetric /2 key](#2key)
      - Algorithms
        - [DH](#dh)
        - [RSA](#rsa)
    - [Symmetric / 1 key](#1key)
  - **How Encryption is performed at H/W Level**
    - [a. Permutation / P-box/ Transposition Box](#pb)
    - [b. Substitution / S-box](#sb)
- [Terms](#Terms)
- [Security Vulnerabilities](#Security_Vulnerabilities)


## Information Security
Consitutues of 4 parts

<a name=sec></a>
## 1. Secrecy / Confidentiality / Encryption / Cryptography
Conversion of Data/Plain-text into unreadable/cipher text.

### Types of Encryption
#### 1. Assymetric /2 key
Public key(encrypt), Private key(decrypt). Data encrypted with Public can only be decrypted using Pvt key. Both are mathematically linked. Public Key are published on website publicly.
```c
                  \/Public-Key                      \/Pvt-Key        
Plain text > | Encryptor | >   Cipher Text  > | Decryptor | > Plain text
```
**Example Alice and Bob communication**
  - *1.* Alice created his own Public(Pub_A),Pvt(Pvt_A) key pairs. Published Public key on his website and kept pvt secret.
  - *2.* Bob also created his own public(Pub_B), Pvt(Pvt_B) key pairs and published on his website.
  - *3.* Alice and bob can communicate using each other's public keys.
```html
  Bob  <--read Alice public key---   http://alice.com
  Alice <--read Bob public key--     http://bob.com

    Bob                                                   Alice
            Pub_A                                             Pvt_A
             \/                                                 \/
  message > |Encrypt| > XXX   ---sent to Alice--->      XXX > Decrypt > message
```
**Algorithms**

<a name=dh></a>
**DH(Diffe-Helman)**
DH Keys sizes
```c
Group  | No of Bits |  Combinations  | Strong 
-------|------------|----------------|----------
   1   |   768      | 2<sup>768</sup>|
   2   |   1024     |                |
   5   |   1536     |                | Strongest
```
Algo:
```html
    Host-A                                        Host B 
        ----------Prime=p=13, Integer=q=6------->      //p is prime of min 600 digits
    Random-no=r=3                              Random-no=r=10
    
  Public-Key=qPow(r)modp 
  6pow(3)mod(13) = 8                           6pow(10)mod13 = 4
        -----------Public Key = 8----------------->
        <---------Public Key = 4------------------
        
  Private-Key = (Public Key)pow(Random No) mod(p)             
  4 pow(3)mod(13) = 12                        8pow(10)mod(13) = 12 
```   


<a name=ca></a>
### Cipher Algorithms
1. Substitution Cipher: Each letter or group of letters is replaced by another letter or group of letters. Eg: Caesar ciphers(b becomes E, c becomes F)
2. Block Ciphers(Mostly used): Encrypt block of characters        
3. Stream Ciphers(Obsolete): Encrypt Single character at a time


### How Encryption is performed at H/W Level
ONLY POSITION OF BITS ARE CHANGED

<a name=pb></a>
#### A. Permutation / P-box / Transposition Box
Perform internal transposition(change place) and do it at practically the speed of light since no computation is involved, just signal propagation. Internal wiring is not known to world.

<a name=sb></a>
#### B. Substitution / S-box
This can have multiple stages of P-box inside providing more complex method bit position shifting. 
- Product Cipher
  - Actual Cipher can use multiple P,S box stages inside to provide better cryptography. With large number of stages output can be a complicated function of the input. 
  - Actual implementations have minimum of 10 stages.
  - There are more P-boxes at start and end, called Rounds.

<img src=Encryption_at_hardware_level.png width=700/>

  - _B._ Authentication: whom you are talking to before revealing sensitive information
  - [_C._ Nonrepudiation](/Integrity/Digital_Signature): Sender cannot deny that he has not sent the message.
  - [_D._ Integrity:](Integrity) message you received was really the one sent and not something that a malicious adversary Encryption + Integrity

<a name="Terms"></a>
### [Security Terms](Terms)
- Cryptanalysis, Confusion,Connected Security,Difussion,Kerckhoff’s principle,Rounds,Whitening

<a name="Security_Vulnerabilities"></a>
### [Security Vulnerabilities](Security_Vulnerabilities)
- ARP Vulnerability,Brute Force,Dictionary attack,Credential Recycling,DOS,DDOS,Identity Attack,KERNEL MELTDOWN/SPECTRE (1/Mar/18), Replay/Playback Attack,Samba Bugs: Wannacry/Ransomeware, Badlock, SMB Signing disabled, SSL Vulnerabilities
