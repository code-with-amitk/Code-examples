## Replay / Playback Attack
- Valid data transmission is deliberately repeated or delayed.  
```console
  User-1                                         Active-Directory(Has user-1's password=test stored)
              ---------login------------>
            <---authenticate yourself----
password(test)> |Hash| > XX >
                       Intruder Intercepts
                       (stores hash XX)    
                                   -login using XX->
                                   <-access provided-
```
- **How attack is prevented?** AD provides challenge-string and using MAC instead of Hash.
```console
    user-1                                                            AD
                    ------------login------------->
                    <---challenge-string=str-----
str+password
    \/
  |MAC|>YY-->    Intruder Intercepts
                              cannot use YY
```                              
