## Heartbleed
- Present in SSLv3 & below. Fixed in TLSv1 & above. 
- SSL client sends heartbeat messages to SSL Server to know, If he's alive or not? Heartbeat message was used to create vulnerability.
- **Good case**
```c
    Client                                               Server
           -- HEART_BEAT Req  [start='T' | size = '4' ]--->
                                                    copy 4 bytes starting from T and reply
           <--- HEART_BEAT Resp  | payload='Test' | size = '4' |
```
- **Intruder Case**
```c
    Attacker                                                 Server
          -- HEART_BEAT Req  | start='T' | size = '65535' |->
                                              copy 65535 bytes starting from T and reply. This can be secret key, encryption passwords
          <--HEART_BEAT Res  | payload='Nkasndkan----' | size = '65535' |
```
