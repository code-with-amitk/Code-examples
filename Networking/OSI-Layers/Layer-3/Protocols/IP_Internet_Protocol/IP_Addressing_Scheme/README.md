- IP Addressing Scheme
- Types of IP Addressing
  - [1. Classful Addressing](#ful)
  - [2. Classless Addressing](#les)
    - [1. Subnet Mask / Prefix / CIDR(Classless Interdomain Routing) / Netmask](#cidr)
      - [Classes(A,B,C) & their Subnet masks](#csub)
      - [Valid Subnet masks](#valid)
    - [2. Network ID / Network Address](#nidr)
    - [3. Broadcast Address](#baddr)
    - [Finding Network,Broadcast Address using Prefix](#nid)

## IPV4 Addressing Scheme
- This is used to identify Host and network part from an IP address.
- All hosts on same N/W have same N/W-ID. Same network means these hosts can communicate with each other without any router. They are on same LAN.

## Types of IP Addressing
<a name=ful></a>
## 1. Classful Addressing
- Each IP Address is assigned to a class
- 0.0.0.0 - Invalid Address(N/W ID), 255.255.255.255 - Broadcast Address
- class A, B addresses are exhausted. Class C addresses are given to new organizations
```console
  Class        A                       B                   C                D(MULTICAST)      E(experimental)
N/W part       a                       a.b                 a.b.c            NA                 NA
Host part      b.c.d                   c.d                 d                NA                 NA
Range          0-127.x.x.x             128-191.x.x.x       192-223.x.x.x    224-239.x.x.x      240-255.x.x.x     
No of hosts    2pow24=1677716-2        2pow16=65536-2      2pow8=256-2      NA                 NA
               N/W-ID,broadcast removed
Start Bits      0                      10                  110             1110                1111
Start Address   0.0.0.0                128.0.0.0           192.0.0.0       224.0.0.0           240.0.0.0
End Address     127.255.255.255        191.255.255.255     223.255.255.255 239.255.255.255     255.255.255.255
Suitable For    Large Org              Medium Org          Small Org
```

<a name=les></a>
## 2. Classless Addressing
- No portion for n/w & hosts is separated. Subnet mask/netmask is used to get n/w and host parts. 
- It means with subnet mask decides how many hosts are possible on a network.

<a name=cidr></a>
### 1. Subnet Mask / Prefix / CIDR(Classless Interdomain Routing) / Netmask
- This defines Number of available hosts on a network.
- Number of ON bits in 32 bit address going from left to right defines n/w address. 0's defines host.
```console
11111111.11111111.11111111.00000000    =   255.255.255.0   =    /24   called CIDR/Netmask/subnet Mask/Prefix
```
<a name=csub></a>
#### Classes & their Subnet masks
```c
Class                 A                 B                 C                 D       E
Possible Hosts      2pow24            2pow16            2pow8               NA      NA
Subnet mask       255.0.0.0(/8)   255.255.0.0(/16)    255.255.255.0(/24)
Network part      1st 8 bits        1st 16 bits         1st 24 bits
```
<a name=valid></a>
#### Valid Subnet masks
- Only contigious subnet masks are valid. ie Contigious 1's from left.
```c
 Invalid: 255.255.255.1   = 11111111.11111111.11111111.00000001   //Not contiguous
 Valid:   255.255.255.128 = 11111111.11111111.11111111.1000000
``` 
_Why gaps in subnet mask not valid?_
  - Impossible for a router to accurately summarize and aggregate prefix ranges.

<a name=nidr></a>
### 2. Network Address / Network ID 
- First ON bits in subnet mask. This address that identifies subnet.  Used to refer all hosts on that n/w. Eg: 46.0.0.0

<a name=baddr></a>
### 3. Broadcast Address 
- This is an IP Address that allows information to be sent to all machines ON THAT SUBNET rather than specific host. All hosts are members of this group. Eg: 46.255.255.255

<a name=nid></a>
#### Finding Network, Broadcast Address using Prefix
- N/W Address = IPAddress & Prefix
- Broadcast Address = IPAddress | ~Prefix
```console
  IP Address          CIDR            N/W Part     This Host    No of possible hosts   Broadcast Address
192.165.5.130   255.255.255.0(/24)   192.165.5.0     130          2pow8 = 256          192.165.5.130 | 0.0.0.255 = 192.165.5.255
192.168.1.15    255.255.254.0(/23)   192.168.0.0     15           2pow9 = 512          192.168.1.15 | 0.0.1.255 = 192.168.1.255
192.168.0.3     255.255.255.1(/25)   192.168.0.0     3            2pow7 = 128          192.168.0.3 | 0.0.0.127 = 192.168.0.127
             192 .168 .0   .00000011
             1111.1111.1111.10000000
```
