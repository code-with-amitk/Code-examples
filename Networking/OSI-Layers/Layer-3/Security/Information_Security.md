## Information Security
- Consitutues of 4 parts:
  - A. Secrecy/Confidentiality/Encryption
  - B. Authentication: whom you are talking to before revealing sensitive information
  - C. Nonrepudiation: Sender cannot deny that he has not sent the message.
  - D. Integrity: message you received was really the one sent and not something that a malicious adversary Encryption + Integrity
  
### A. ENCRYPTION/CRYPTOGRAPHY/CONFIDENTIALITY 
- **What?** Conversion of Data/Plain-text into unreadable/cipher text.
- **Why DL layer encryption/Link Encryption is not good idea?** 
  - With this approach packets have to be decrypted at each router, leaving them vulnerable to attacks from within the router.
- **Cryptanalysis?** Breaking ciphers. 
- **Kerckhoff’s principle?** Whole world should know how crypto algorithm works, All algorithms must be public. Algorithm is parameterized by key only the keys are secret
- **Key Length?** The longer the key, higher work to be done by breaking algo.    {Email: 64-bit keys will do, Commercial applications: 128 bits, Govt org: 256 bits}
```c
    bits    No of Unique keys
    2                4
    3                8
    32            4,294,967,296    (4 billion)
```
- **CIPHER ALGORITHMS**
  - **1. Substitution Cipher:** each letter or group of letters is replaced by another letter or group of letters. Eg: Caesar ciphers(b becomes E, c becomes F)
  - **2. Block Ciphers(Mostly used):** Encrypt block of characters        
  - **2. Stream Ciphers(Obsolete):** Encrypt Single character at a time
- **How Encryption is performed at H/W Level?** ONLY POSITION OF BITS ARE CHANGED
  - A. PERMUTATION/P-BOX/TRANSPOSITION BOX: Perform internal transposition(change place) and do it at practically the speed of light since no computation is involved, just signal propagation. Internal wiring is not known to world.
  - B. SUBSTITUTION/S-BOX: This can have multiple stages of P-box inside providing more complex method bit position shifting. 
  - Product Cipher
    - Actual Cipher can use multiple P,S box stages inside to provide better cryptography. With large number of stages output can be a complicated function of the input. 
    - Actual implementations have minimum of 10 stages.
    - There are more P-boxes at start and end, called Rounds.

<img src="https://i.ibb.co/548Kg1P/Encryption-at-hardware-level.png" width=1000 />
