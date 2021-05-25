## Comparison

||Symmetric(1-key)|Asymmetric(2-key)|
|---|---|---|
|Speed|Faster(Since encryption process is less complicated)|Slow. Big Calculations are required to Generate a public-Pvt Key Pair|
|Risk|Distribution of keys||
|Choice|Depends on Use Case.|1024 was assumed to be secure by 2010. 2048 Bit Key is assumed to be secure by 2030|
|Algos|<ul><li>DES(Broken in 1999)</li></ul> <ul><li>3-DES(Broken)</li></ul> <ul><li>AES(Key sizes: 128, 192, 256, 354)</li></ul> <ul><li>RC4</li></ul>|<ul><li>RSA (Ronald Rivest, Adi Shamir, Len Adleman)</li></ul> <ul><li>Diffe-Helman</li></ul> <ul><li>Crammer-shoup</li></ul> <ul><li>El-Gamal</li></ul>|
|Key-size|AES-128, 192, 256|RSA:1024,2048 This is not Key, but sizes of prime numbers. Private Key = (Cipher Text)pow(pvt Key) mod(n) = 103 bit only|

## Usage
- **Asymmetric key:** Establishing public/pvt key pairs between 2 peers. Pvt key should be same.
- **Symmetric Key Algo:** Once keys are exchanged using asymmetric key algos, encryption/decryption is done using Symmetric algos.
