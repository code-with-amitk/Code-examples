**Information Security**
- [1. Secrecy / Confidentiality / Encryption](#sec)
  - [Cipher Algo](#ca)
  - How Encryption is performed at H/W Level
    - [Permutation / P-box/ Transposition Box](#pb)
- [Terms](#Terms)
- [Security Vulnerabilities](#Security_Vulnerabilities)


## Information Security
Consitutues of 4 parts

<a name=sec></a>
## 1. Secrecy / Confidentiality / Encryption / Cryptography
Conversion of Data/Plain-text into unreadable/cipher text.

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

#### B. Substitution / S-box
This can have multiple stages of P-box inside providing more complex method bit position shifting. 
- Product Cipher
  - Actual Cipher can use multiple P,S box stages inside to provide better cryptography. With large number of stages output can be a complicated function of the input. 
  - Actual implementations have minimum of 10 stages.
  - There are more P-boxes at start and end, called Rounds.

<img src=Encryption_at_hardware_level.png width=1000 />

  - _B._ Authentication: whom you are talking to before revealing sensitive information
  - [_C._ Nonrepudiation](/Integrity/Digital_Signature): Sender cannot deny that he has not sent the message.
  - [_D._ Integrity:](Integrity) message you received was really the one sent and not something that a malicious adversary Encryption + Integrity

<a name="Terms"></a>
### [Security Terms](Terms)
- Cryptanalysis, Confusion,Connected Security,Difussion,Kerckhoff’s principle,Rounds,Whitening

<a name="Security_Vulnerabilities"></a>
### [Security Vulnerabilities](Security_Vulnerabilities)
- ARP Vulnerability,Brute Force,Dictionary attack,Credential Recycling,DOS,DDOS,Identity Attack,KERNEL MELTDOWN/SPECTRE (1/Mar/18), Replay/Playback Attack,Samba Bugs: Wannacry/Ransomeware, Badlock, SMB Signing disabled, SSL Vulnerabilities
