## Asymmetric / Public Key / 2-Key
- Public key(encrypt), Private key(decrypt). Data encrypted with Public can only be decrypted using Pvt key. Both are mathematically linked.
- Public Key are published on website publicly.
```c
                  \/Public-Key                      \/Pvt-Key        
Plain text > | Encryptor | >   Cipher Text  > | Decryptor | > Plain text
```
- **[Example Alice and Bob communication](ExampleAlice&BobCommunication.md)**
- **Example**
  - [RSA (Ronald Rivest, Adi Shamir, Len Adleman)](RSA.md)
  - [Diffe-Helman](Diffe_Helman.md)
  - Crammer-shoup
  - El-Gamal
