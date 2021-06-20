## Pre Shared Key / Shared Password
- This is nothing but a shared text/password via phone, verbal exchange, or email.
- **How Peers Authenticate?**
```c
Peer-1                                          Peer-2
          Meet and exchange PSK=abc
          After DH Key exchange
          
        <-----------Authenticate-----------------
        
  psk > |encrypt| >	XX	     internet          XX >  |decrypt| > psk(abc)
           /\                                                  /\
        Peer-1 DH Pvt key                                  Peer-1 DH Public key
        
                                                            //abc matches stored psk. Peer-1 authentic
```
- [Advantages, Disadvantages of PSK](Adv_Disadv_psk.md)
