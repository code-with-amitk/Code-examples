## inaddr_any
- if our server has multiple interfaces, Each interface have different IP address and we want to bind to all interfaces(ie all IP addresses), then instead of inet_addr() we should use inaddr_any
```c
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");    //Binding port to localhost(127.0.0.1)
serverAddr.sin_addr.s_addr = INADDR_ANY;                //Binding port to all available IPs
```
- This is helpful for multihomed network(when server is connected to multiple networks).
```c
MULTIHOMED
  
N/W-1 ---192.168.0.14--
                      |
                    server -----95.95.2.21------ N/W-2
                      |
 N/W-3 ---16.21.4.5----
```
