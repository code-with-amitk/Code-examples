## Symmetric / Secret / Private Key / 1-Key
- **What?** Only 1 key is shared between sender & receiver. Examples: DES,3DES,AES,RC4
```
                \/  Key-1                      \/ Key-1
    Data > | Encryptor | > cipher Text  > | Decryptor |  > Data 
```
### Comparison

|Algorithm|Key-Size(bits)|Input-Size(bits)|Stages
|---|---|---|---|
|DES(Data encryption standard)(Broken in 1999)|56|64|19|
|Triple-DES(Broken)|168|||                                                                                                                                                         |AES(Advanced Encryption Standard)|128,192,256|128,192,256(block-size)|10,12,14|
|RC4||||

### Problem with Symmetric Key Algo(AES,DES or any)
- With same plaintext they will produce same ciphertext everytime.
- **[Solution: Chaining](/Networking/OSI-Layers/Layer-3/Security/Encryption_Cryptography_Confidentiality/HowEncryptionIsPerformedAtHardware)** 
  - 1st block is XORed with IV(initialization vector) then successive blocks are XORed with output of prev block and IV is sent with cipher text and reverse is done on receveing side.
