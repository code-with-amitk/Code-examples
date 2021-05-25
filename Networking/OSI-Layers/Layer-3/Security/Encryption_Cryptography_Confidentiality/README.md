## Encryption / Cryptography / Confidentiality
- **What?** Conversion of Data/Plain-text into unreadable/cipher text.
- **Cryptanalysis?** Breaking ciphers. 
- **Kerckhoff’s principle?** Whole world should know how crypto algorithm works, All algorithms must be public. Algorithm is parameterized by key only the keys are secret
- **Rounds?** There are more P-boxes at start and end.
- **Whitening?** XORing a random 64-bit key with plaintext before feeding it into Encryptor and then XORing a second 64-bit key with the resulting ciphertext before transmitting it. DES uses it.
- **Problem with Symmetric Key Algo?** AES,DES(or any) symmetric key algo have a problem that with same plaintext they will produce same ciphertext everytime.
  - **Solution: Chaining** 1st block is XORed with IV(initialization vector) then successive blocks are XORed with output of prev block and IV is sent with cipher text and reverse is done on receveing side.
- **Decryption?** All steps are just run in reverse order.  

### Cipher Algorithms
  - **1. Substitution Cipher:** each letter or group of letters is replaced by another letter or group of letters. Eg: Caesar ciphers(b becomes E, c becomes F)
  - **2. Block Ciphers(Mostly used):** Encrypt block of characters        
  - **3. Stream Ciphers(Obsolete):** Encrypt Single character at a time
  
### [How Encryption is performed at H/W Level?](HowEncryptionIsPerformedAtHardware)

### [How safe is 128 bit Key?](HowSafeIs_128bit_Key.md)
