## Asymmetric / Public Key / 2-Key
- Public key(encrypt), Private key(decrypt). Data encrypted with Public can only be decrypted using Pvt key. Both are mathematically linked.
- Public Key are published on website publicly.
- Eg: RSA (Ronald Rivest, Adi Shamir, Len Adleman), Diffe-Helman, Crammer-shoup, El-Gamal
```c
                  \/Public-Key                      \/Pvt-Key        
Plain text > | Encryptor | >   Cipher Text  > | Decryptor | > Plain text
```
- **[Example Alice and Bob communication](ExampleAlice&BobCommunication.md)**
