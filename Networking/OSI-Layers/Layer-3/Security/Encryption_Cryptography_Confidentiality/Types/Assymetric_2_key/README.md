## Asymmetric / Public Key / 2-Key
- Public key(encrypt), Private key(decrypt). 
- Public Key are published on website publicly.
- Data encrypted with Public can only be decrypted using Pvt key.
- Both are mathematically linked.
- Eg: RSA (Ronald Rivest, Adi Shamir, Len Adleman), Diffe-Helman, Crammer-shoup, El-Gamal

```c
                  \/Public-Key                      \/Pvt-Key        
Plain text > | Encryptor | >   Cipher Text  > | Decryptor | > Plain text
```
