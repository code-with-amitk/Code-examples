### Example Alice and Bob communication
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
