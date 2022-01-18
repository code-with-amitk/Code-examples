- [1. Hash / Message Digest](#hash)
  - [Hashing Algos](#ha)
- [2. MAC](#mac)
- [3. HMAC](#hmac)

<a name=hash></a>
## 1. Hash / Message Digest
- Transforming String into FIXED-LENGTH-Integer Value.
- From Hash Message cannot be retrieved back. Hash function should not generate same value for different input strings. 
- MD5 started producing that and hence considered broken.
```c
Kumar >  | Hash Function |  > 4421
```
- **Why?** Determine if their content has been corrupted or not. 

<a name=ha></a>
### Hashing Algo

|Hashing Algo|SHA3/Keccak(or 512)|SHA2(or 256)(not broken)|SHA1,SHA0(broken)|MD4,[MD5(broken)](Hashing_Algo)|[Argon2](Hashing_Algo)|
|---|---|---|---|---|---|
|Published|2015|2012|1995|2015|
|Input(bytes)|2128 bit|2128 bit|264 bit|infinite||
|Output Hash(bits)|512|256|160|128||

<a name=mac></a>
## 2. MAC
*Examples:* CMAC, SHA1-HMAC, MD5-HMAC, UMAC
```c
(Message + Pvt Key) > |Hash function| > MAC    
```

<a name=hmac></a>
## 3. HMAC(Hashed MAC)
More complex way of calculating MAC
```c

 secret Key ->(XOR) <- Inner Pad     Secret Key-> (XOR) <- Outer Pad
                \/                                 \/
                M1                                 M2
                      |M-1| Message | M2 |
```
