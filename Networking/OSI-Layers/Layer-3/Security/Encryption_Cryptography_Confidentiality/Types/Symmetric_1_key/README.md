## Symmetric / Secret / Private Key / 1-Key
- **What?** Only 1 key is shared between sender & receiver. Examples: DES,3DES,AES,RC4
```
                \/  Key-1                      \/ Key-1
    Data > | Encryptor | > cipher Text  > | Decryptor |  > Data 
```
- **Algorithms**

|Algorithm|Key-Size(bits)|Input-Size(bits)|Stages
|---|---|---|---|
|DES(Data encryption standard)|56|64|19|
|Triple-DES|168|||                                                                                                                                                                  |AES(Advanced Encryption Standard)|128,192,256|128,192,256(block-size)|10,12,14|
|RC4||||
