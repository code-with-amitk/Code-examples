## Hashing
- Message is not modified in between by Intruder. if intruder modifies the message the Receiver should detect and discarded. 

### How to Achieve Integrity
- **1. Using Encryption** 
  - Alice(pub_a, pvt_a) and Bob(pub_b, pvt_b). 
  - Alice encrypts message twice, 1st with self pvt key. Then with Bob' public key. 
  - Bob will decrypt 1st using his own pvt key then with Alice's public key.
```console
      ALICE
message > |Encrypt| > XX > |Encrypt|  > YYYY
              /\              /\
         Self Pvt Key     Bob's Public Key
         
      BOB         
YYYY > |Decrypt| > XX > |Decrypt| > message
          /\                /\
       Self Pvt Key    Alice Public Key
```
- **[2. Digital Signature](Digital_Signature)**
    
