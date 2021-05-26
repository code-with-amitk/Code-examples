## Freak Attack
```c
  [openssl Server]     [Hacker]                                                                            [Openssl Client]
     |                   |                                                                                                                                                          
     |                   | <-----Client Hello [Version][SessionId][CipherSuiteList][RandomNo][CompMethod]--               
     |                   | ---------Server Hello [Version][Export-grade-Insecure-CipherSuite][RandomNo][CompMethodSelected]-->
                          <-------Hacker can view communication b/w Server & client---------->    
```
