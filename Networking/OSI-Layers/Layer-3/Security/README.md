**Information Security constitutes of 4 parts**
- **[1. Secrecy / Confidentiality / Encryption](#sec)**
  - **Types of Encryption**
    - [Assymetric /2 key (DH, RSA, Crammer-Shoup, El-Gamal)](#2key)
      - [ECC](#ecc)
        - [ECC vs Assymetric vs Symmetric](#eccvs)
    - [Symmetric / 1 key (DES,3DES,AES,RC4)](#1key)
      - [Problem with Symmetric Key Algo](#prob)
      - [Algorithms: AES / Rijndael](#salgo)
        - [DES vs 3DES vs AES](#sycomp)
    - [Assymetric vs Symmetric](#asvs)
  - [Cipher Algorithms](#ca)
  - **How Encryption is performed at H/W Level**
    - [a. Permutation / P-box/ Transposition Box](#pb)
    - [b. Substitution / S-box](#sb)
  - **[How safe are 128,256 bit Keys](#how128)**
  - [Encryption at Data link, Transport, Application Layers](#encdta)
- [2.]
- [3.]
- [4.]
- [Terms](#Terms)
- [Security Vulnerabilities](#Security_Vulnerabilities)


<a name=sec></a>
# 1. Secrecy / Confidentiality / Encryption / Cryptography
Conversion of Data/Plain-text into unreadable/cipher text. Once keys are exchanged using asymmetric key algos, encryption/decryption is done using Symmetric algos.

## Types of Encryption
<a name=2key></a>
### 1. Assymetric /2 key / Public,Pvt Key pair (DH, RSA, 
- Public key(encrypt), Private key(decrypt). Data encrypted with Public can only be decrypted using Pvt key. Both are mathematically linked. Public Key are published on website publicly.
- **Example Alice and Bob communication**
  - *1.* Alice created his own Public(Pub_A),Pvt(Pvt_A) key pairs. Published Public key on his website and kept pvt secret.
  - *2.* Bob also created his own public(Pub_B), Pvt(Pvt_B) key pairs and published on his website.
  - *3.* Alice and bob can communicate using each other's public keys.
```html
                         Bob  <--read Alice public key-- http://alice.com
                        Pub_A                                        
                         \/
message(plain text) > |Encrypt| > XXX  

                                                                     Alice <-read Bob public key- http://bob.com
                                                                     Pvt_A
                                                                       \/
                                     ---sent to Alice--->      XXX > |Decrypt| > message
```
#### a. DH(Diffe-Helman)
```c
//DH Keys sizes
Group  | No of Bits |  Combinations  | Strong 
-------|------------|----------------|----------
   1   |   768      | 2<sup>768</sup>|
   2   |   1024     |                |
   5   |   1536     |                | Strongest


//Algorithm
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

#### b. RSA (Ronald Rivest, Adi Shamir, Len Adleman)
Steps of RSA
- A. Pre-calculate Public, pvt key
  - *1.* Choose 2 numbers p(1024 bit),q(1024 bit).  {p=3,q=11}
  - *2.* Find n = p`*`q, z =(p-1)(q-1)  {n=33, z=20}
  - *3.* Choose a number d relatively prime to z.   {d=7} //7 and 20 has no common factor
  - *4.* Find e. So that e × d = 1 mod(z)
```c
    e x 7 = 1 mod(20)
    e = mod(20)/7 = 3 (approx)
```
Public Key = (e,n). Private Key = (d,n)
  
- B. Divide Plain-text into blocks  input=10101111. {block1=1010 block2=1111}
- C. Encrypt:  cipher text(C) = Block-of-plain-text<sup>e</sup> (mod n) 
```c
  C = P^3 mod(33)
```  
- D. Decrypt: Plain text(P) = C<sup>d</sup> (mod n)
```c
  P = C^7 mod(33)
```

```c
Public Key (n,  e)        Private Key (n, d) or 5-value
                Host-A                                                  Host-B
                        -----Prime-1=53, Prime-2=59------>    //In real calculations P & Q are large numbers (64 bytes)
                                                                   Modulus(n)=P*Q=64x64=128 bytes=1024 bit
                                                                   Phy(n)=(P-1)(Q-1)=3016
                                                                   Exponent(e)=coprime of Phy
            Public-key calculated                    Public-key= n&e
                                                                   Pvt key=2 (Phy(n) + 1)/e
           
                                                                    encryption of data: data pow(e)mod(n)
                        <---cipher-text------             89 pow(3)mod(3127)    //if data=89
        Decryption of data
        (cipher Text)pow(Pvt Key) mod(n) 
           (1394) pow(2011) mod(3127) = 89
```

<a name=ecc></a>
#### Ecliptic Curve Cryptography / ECC / 2 key
- Public, Pvt keys are calculated using elliptic curves over (finite field/Galois field? Field containing finite number of elements rather than real numbers).
- Ecliptic curve: y<sup>2</sup> = x<sup>3</sup> + a<sup>x</sup> + b. Place x and y in equation and get Public, Pvt key pairs.
- **Advantage of ECC?** Smaller keys in ECC provides equivalent security to larger non-ECC based algos. 
- **Applications of ECC?**
  - Calculating keys for following: Key agreement, Digital Signature, Pseudo-random generators.
  - ECCs can be used after combining with Symmetric encryption schemes.
  - (ECDH) Ecliptic Curve based Diffie Hellman
    - Allows two parties, each having an elliptic-curve public–private key pair, to establish a shared secret over an insecure channel. 
    - This shared secret maybe used directly as key or derive another key. 
    - The key, or the derived key, can then be used to encrypt subsequent communications using a symmetric-key cipher.

<a name=eccvs></a>
##### ECC vs Symmetric vs Asymmetric
```c
Symmetric | Asymmetric | ECC
----------|------------|-------
80 bit    |   1024 bit | 160 bit
112       |   2048     |  224
128       |   3072     |  256
192       |   7680     |  384
256       |   15260    |  521
```

<a name=1key></a>
### 2. Symmetric / 1 key (DES,3DES,AES,RC4)
Only 1 key is shared between sender & receiver.
```c
                \/  Key-1                      \/ Key-1
    Data > | Encryptor | > cipher Text  > | Decryptor |  > Data 
```

<a name=prob></a>
#### Problem with Symmetric Key Algo
- With same plaintext they will produce same ciphertext everytime. [Solution: Chaining](#sb)
- 1st block is XORed with IV(initialization vector) then successive blocks are XORed with output of prev block and IV is sent with cipher text and reverse is done on receveing side.

<a name=salgo></a>
#### Algorithms
##### a. AES / Rijndael
There are 10 rounds for 128-bit keys, 12 rounds for 192-bit keys and 14 rounds for 256-bit keys.
```c

#define LENGTH 16                     //Input,Output in bytes. 16x8=128
#define NROWS 4                         //For internal use
#define NCOLS 4                          //For algo's internal use
#define ROUNDS 10                     //number of iterations/stages
typedef unsigned char byte;           /// unsigned 8-bit integer

AES(byte plaintext[LENGTH], byte ciphertext[LENGTH], byte key[LENGTH]) {
  int r;
  byte state[4][4];                                     // current state
  struct {byte k[4][4];} rk[10 + 1];          // round keys
  expand key(key, rk);                             // construct the round keys
  copy plaintext to state(state, plaintext); // init current state
  xor roundkey into state(state, rk[0]);     // XOR key into state
  for (r = 1; r <= ROUNDS; r++) {
  substitute(state);                             // apply S-box to each byte
  rotate rows(state);                          // rotate row i by i bytes
  if (r < ROUNDS) mix columns(state); // mix function
    xor roundkey into state(state, rk[r]); / XOR key into state
  }
  copy state to ciphertext(ciphertext, state); / return result
}
```
<a name=sycomp></a>
##### DES vs 3DES vs AES

|Algorithm|KeySize(bits)|InputSize(bits)|Stages|
|---|---|---|---|
|DES. Broken in 1999|56|64|19|
|Triple-DES. Broken|168| | |
|AES / Rijndael|128,192,256|128,192,256(block-size)|10,12,14|
|RC4||||

<a name=asvs></a>
### Assymetric vs Symmetric
||Symmetric/Secret/Private Key/1-Key|Asymmetric/Public Key/2-Key|
|---|---|---|
|Speed|Faster(Since encryption process is less complicated)|Slow. Big Calculations are required to Generate a public-Pvt Key Pair|
|Risk|Distribution of keys||
|Choice|Depends on Use Case.|1024 was assumed to be secure by 2010. 2048 Bit Key is assumed to be secure by 2030|
|Algos|<ul><li>DES(Broken in 1999)</li></ul> <ul><li>3-DES(Broken)</li></ul> <ul><li>AES(Key sizes: 128, 192, 256, 384)</li></ul> <ul><li>RC4</li></ul>|<ul><li>RSA (Ronald Rivest, Adi Shamir, Len Adleman)</li></ul> <ul><li>Diffe-Helman</li></ul> <ul><li>Crammer-shoup</li></ul> <ul><li>El-Gamal</li></ul>|
|Key-size|AES-128, 192, 256|RSA:1024,2048 This is not Key, but sizes of prime numbers. Private Key = (Cipher Text)pow(pvt Key) mod(n) = 103 bit only|

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

<a name=how128></a>
### How safe is 128, 256 bit Keys
The longer the key, higher work to be done by breaking algo.    
  - Email: 64-bit keys will do 
  - Commercial applications: 128 bits
  - Govt org: 256 bits

Number of Unique keys:
  - 2   No of unique keys: 2<sup>2</sup> = 4
  - 3   No of unique keys: 2<sup>3</sup> = 8
  - 32  No of unique keys: 2<sup>32</sup> = 4,294,967,296    (4 billion)
  - 64  No of unique keys: 2<sup>64</sup>  = 18 x 10<sup>18</sup> keys (18 Quintillion)
  - 128 No of unique keys: 2<sup>128</sup> = 34 x 10<sup>36</sup> keys (18 x 10<sup>18</sup> Quintillion)
  - 256 No of unique keys: 2<sup>256</sup> = 

How Long Hacker(having super Computer) need to crack key? 
  - 1 super computer can perform 10<sup>17</sup> FLOPS (a hundred quadrillion FLOPS floating point operations per second)
  - Per Year = 3600(hour) x 24 x 30 x 12 = 31,104,000 x  10<sup>17</sup>= 31,104,00 Quintillion Operations.
  - 340,282,366,920,938,463,463 / 31,104,000 = 109,401,481,134,561 (approx) = 109 Trillion
  - **109 Trillion super computers working parallelly for 1 year can produce all combinations of 128 bit key**


<a name=encdta></a>
### Encryption at DL Layer
**Encryption at DL/ Link encryption**
- Not good idea? With this approach packets have to be decrypted at each router(in internet), leaving them vulnerable to attacks from within the router.
  
**Encryption at Application Layer?**
- Not good? All application worldwide has to be security aware putting extra burden on application developers.

**Encryption at Transport Layer or between Transport and Application**
- Not good? Since Application layer security is already provided by SSL/TLS

  - _B._ Authentication: whom you are talking to before revealing sensitive information
  - [_C._ Nonrepudiation](/Integrity/Digital_Signature): Sender cannot deny that he has not sent the message.
  - [_D._ Integrity:](Integrity) message you received was really the one sent and not something that a malicious adversary Encryption + Integrity

<a name="Terms"></a>
### [Security Terms](Terms)
- Cryptanalysis, Confusion,Connected Security,Difussion,Kerckhoff’s principle,Rounds,Whitening

<a name="Security_Vulnerabilities"></a>
### [Security Vulnerabilities](Security_Vulnerabilities)
- ARP Vulnerability,Brute Force,Dictionary attack,Credential Recycling,DOS,DDOS,Identity Attack,KERNEL MELTDOWN/SPECTRE (1/Mar/18), Replay/Playback Attack,Samba Bugs: Wannacry/Ransomeware, Badlock, SMB Signing disabled, SSL Vulnerabilities
