## IPSec SA Example
```c
    ID: 131073 Virtual-system: root, VPN Name: SERVER-BOX
    Local Gateway: peer-1-ip, Remote Gateway: peer-2-ip
    Version: IKEv1
    DF-bit: clear
    Bind-interface: st0.80
    Port: 500, Nego#: 5, Fail#: 0, Def-Del#: 0 Flag: 0x600a29 
    Direction: inbound, SPI: 5ef52687, AUX-SPI: 0
        Hard lifetime: Expires in 1175 seconds
        Lifesize Remaining:  Unlimited
        Soft lifetime: Expires in 972 seconds
        Mode: Tunnel(0 0), Type: dynamic, State: installed
        Protocol: ESP, Authentication: hmac-sha1-96, Encryption: aes-cbc (128 bits)
        Anti-replay service: counter-based enabled, Replay window size: 64
    Direction: outbound, SPI: c786011d, AUX-SPI: 0, VPN Monitoring: -
        Hard lifetime: Expires in 1175 seconds
        Lifesize Remaining:  Unlimited
        Soft lifetime: Expires in 972 seconds
        Mode: Tunnel(0 0), Type: dynamic, State: installed
        Protocol: ESP, Authentication: hmac-sha1-96, Encryption: aes-cbc (128 bits)
        Anti-replay service: counter-based enabled, Replay window size: 64
```
