## SP / Security Policy
```c
SP Format
Node    3    2
SA sa1    transport 192.168.2.2    ESP 1234
-E    DES_CBC    "Auth-Key"
-A    HMAC_MD5    "encrypt-key"
SP    NA-1.0//src    NA-5.0//dst    ANY    -P    OUT    IPSEC     sa1
SP    192.168.1.0    192.168.5.0    UDP    -P    IN    IPSEC    sa1
``
