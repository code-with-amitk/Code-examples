## None Networking
- This completely disables the networking stack on the container. Within the container, only the loopback device is created.
- Example of Creating the container with none network
```c
$ docker run --rm -dit  --network none  --name no-net-alpine   alpine:latest   ash

//Check the container’s network stack... no eth0 created
$ docker exec no-net-alpine ip link show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN qlen 1
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
2: tunl0@NONE: <NOARP> mtu 1480 qdisc noop state DOWN qlen 1
    link/ipip 0.0.0.0 brd 0.0.0.0
3: ip6tnl0@NONE: <NOARP> mtu 1452 qdisc noop state DOWN qlen 1
    link/tunnel6 00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00 brd 00:00:00:00:00:00:00:00:00:00:00:00:00:00:00:00
    
//Stop the container. It is removed automatically because it was created with the --rm flag
$ docker stop no-net-alpine    
```
