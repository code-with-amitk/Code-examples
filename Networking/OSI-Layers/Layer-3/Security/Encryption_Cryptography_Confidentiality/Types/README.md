## Comparison

||Symmetric(1-key)|Asymmetric(2-key)|
|---|---|---|
|Speed|Faster(Since encryption process is less complicated)|Slow. Big Calculations are required to Generate a public-Pvt Key Pair|
|Risk|Distribution of keys||
|Choice|Depends on Use Case.|1024 was assumed to be secure by 2010. 2048 Bit Key is assumed to be secure by 2030|
|Algos| DES, 3-DES, AES, RC4|RSA (Ronald Rivest, Adi Shamir, Len Adleman), Diffe-Helman, Crammer-shoup, El-Gamal|
|Key-size|AES-128, 192, 256|RSA:1024,2048 This is not Key, but sizes of prime numbers. Private Key = (Cipher Text)pow(pvt Key) mod(n) = 103 bit only|

## Usage
- **Asymmetric key:** Establishing public/pvt key pairs between 2 peers. Pvt key should be same.
- **Symmetric Key Algo:** Once keys are exchanged using asymmetric key algos, encryption/decryption is done using Symmetric algos.
