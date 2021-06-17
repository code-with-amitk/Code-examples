## Replay / Playback Attack
- Attacker captures valid packets and replay/resend them to server. This causes DOS attack on server.
- **Example of replay attack:**
```console
How AD Handles Replay Attack?
  User-1                                         Active-Directory(Has user-1's password=test stored)
              ---------login------------>
              <--authenticate yourself---
password(test)> |Hash| > XX >
                       Intruder Intercepts
                       (stores hash XX)    
                                   -login using XX->
                                   <-access provided-
```
- **Avoiding attack?**
```console
//AD provides challenge-string and using MAC instead of Hash.
    user-1                                                            AD
                    ------------login------------->
                    <---challenge-string=str-----
str+password
    \/
  |MAC|>YY-->    Intruder Intercepts
                              cannot use YY
```                              
- [How IPSec VPN G/W avoids replay attack](/Networking/OSI-Layers/Layer-3/VPN/Terms/Anti_Replay_Protection/)
