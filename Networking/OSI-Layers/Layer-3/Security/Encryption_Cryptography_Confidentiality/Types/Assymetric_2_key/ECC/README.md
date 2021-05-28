## Ecliptic Curve Cryptography / ECC
- This is Public Key variant. Public, Pvt keys are calculated using elliptic curves over finite field.
```c
  Ecliptic curve: y2 = x3 + ax +b. 
```
- **Finite Field/Galois field?** Field containing finite number of elements rather than real numbers.
- **Advantage of ECC?** Smaller keys in ECC provides equivalent security to larger non-ECC based algos. 
- **Applications of ECC?** 
  - Calculating keys for following: Key agreement, Digital Signature, Pseudo-random generators.
  - ECCs can be used after combining with Symmetric encryption schemes.
  - [Ecliptic Curve based Diffie Hellman / ECDH](ECDH)

### Comparison

|Symmetric|Asymmetric|ECC|
|---|---|---|
|80 bit|1024 bit|160 bit|
|112|2048|224|
|128|3072|256|
|192|7680|384|
|256|15260|521|
