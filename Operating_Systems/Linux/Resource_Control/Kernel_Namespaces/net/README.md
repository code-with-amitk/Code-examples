## Network / net
- **What?** 
  - Used to virtualize the network stack
  - Each network namespace contains its own resources within /proc/net. Resources
    -  Private set of IP addresses, its own routing table, socket listing, connection tracking table, firewall, and other network-related resources.
  - A network namespace contains only a loopback interface on initial creation.
```c
> sudo unshare -n
# ip l
1: lo: <LOOPBACK> mtu 65536 qdisc noop state DOWN mode DEFAULT group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
```

### Creating Network namespace
- *1.* Create a new network namespace
```c
> sudo ip netns add mynet
> sudo ip netns list
mynet                     //new network namespace called mynet
```
- *2.* Inspect network.
```c
> sudo ip netns exec mynet ip l
1: lo: <LOOPBACK> mtu 65536 qdisc noop state DOWN mode DEFAULT group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
> sudo ip netns exec mynet ping 127.0.0.1
connect: Network is unreachable
```
- *3.* Bring the network up.
```c
> sudo ip link add veth0 type veth peer name veth1
> sudo ip link show type veth
11: veth1@veth0: <BROADCAST,MULTICAST,M-DOWN> mtu 1500 qdisc noop state DOWN mode DEFAULT group default qlen 1000
    link/ether b2:d1:fc:31:9c:d3 brd ff:ff:ff:ff:ff:ff
12: veth0@veth1: <BROADCAST,MULTICAST,M-DOWN> mtu 1500 qdisc noop state DOWN mode DEFAULT group default qlen 1000
    link/ether ca:0f:37:18:76:52 brd ff:ff:ff:ff:ff:ff
```
