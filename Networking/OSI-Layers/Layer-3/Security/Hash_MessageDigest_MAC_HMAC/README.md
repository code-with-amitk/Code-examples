## Hash / Message Digest
- **What?** 
  - Transforming String into FIXED-LENGTH-Integer Value.
  - From Hash Message cannot be retrieved back. Hash function should not generate same value for different input strings. 
  - MD5 started producing that and hence considered broken.
```c
Kumar >  | Hash Function |  > 4421
```
- **Why?** Determine if their content has been corrupted or not. 
- **Hashing Algos**

|Hashing Algo|SHA3/Keccak(or 512)|SHA2(or 256)(not broken)|SHA1,SHA0(broken)|MD4,MD5(broken)|
|---|---|---|---|---|
|Published|2015|2012|1995
|Input(bytes)|2128 bit|2128 bit|264 bit|infinite|
|Output Hash(bits)|512|256|160|128|
