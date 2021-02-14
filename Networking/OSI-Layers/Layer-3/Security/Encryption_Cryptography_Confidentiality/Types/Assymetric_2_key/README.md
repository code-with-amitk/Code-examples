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

## Example Alice and Bob communication
- *1.* Alice created his own Public(Pub_A),Pvt(Pvt_A) key pairs. Published Public key on his website and kept pvt secret.
- *2.* Bob also created his own public(Pub_B), Pvt(Pvt_B) key pairs and published on his website.
- *3.* Alice and bob can communicate using each other's public keys.
```html
  Bob                           http://alice.com
    <--read Alice public key-----

  Alice                           http://bob.com
    <--read Bob public key-----

    Bob                                                   Alice
            Pub_A                                             Pvt_A
             \/                                                 \/
  message > |Encrypt| > XXX   ---sent to Alice--->      XXX > Decrypt > message
```
