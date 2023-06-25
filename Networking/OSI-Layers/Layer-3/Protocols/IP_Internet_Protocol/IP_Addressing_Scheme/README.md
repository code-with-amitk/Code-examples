[Good Microsoft Article](https://docs.microsoft.com/en-us/troubleshoot/windows-client/networking/tcpip-addressing-and-subnetting)

- IP Addressing Scheme
- Types of IP Addressing
  - [1. Classful Addressing. Ancient](#ful)
    - [Valid IPv4 Addresses](#ip4valid)
  - [2. Classless Addressing](#les)
    - [1. Subnet Mask / Prefix / Netmask](#submask)
      - [CIDR(Classless Interdomain Routing) Notation](#cidr)
      - [Classes(A,B,C) & their Subnet masks](#csub)
      - [Valid Subnet masks](#valid)
    - [2. Network ID / Network Address](#nidr)
    - [3. Broadcast Address](#baddr)
    - [Finding Network,Broadcast Address using Prefix](#nid)
- [Subnetting](#subnetting)
- [Supernetting /Prefix Aggregation/ Route Aggregation/ Route Summarization](#supernetting)
- Address Types
  - [A. Private IP Addresses](#inside)
    - [Inside Local IP Address](#inlocal)
    - [Inside Global IP Address](#inglobal)
  - [B. Outside Network](#outside)	
	  - [Inside Global Address](#insideg)	
	  - [Outside Global Address](#outsideg)
  - [C. Reserved and Documentation Addresses](#rd)
    - [Carrier-grade NAT](#cgn) 

## IPV4 Addressing Scheme
- This is used to identify Host and network part from an IP address.
- All hosts on same N/W have same N/W-ID. Same network means these hosts can communicate with each other without any router. They are on same LAN.

## Types of IP Addressing
<a name=ful></a>
## 1. Classful Addressing
- Each IP Address is assigned to a class.
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
<a name=ip4valid></a>
#### Valid IPv4 Addresses
- First and last address in any network or subnet can't be assigned to any individual host. Eg: 192.168.123.0 and 192.168.123.255
  - 0 address is invalid bcoz it's specifies a network not host. 192.168.123.0 is N/W not host
  - 255 address is invalid bcoz it's used to broadcast a message to every host on a network. 192.168.123.255 is broadcast address
```c
0.0.0.0 Invalid Address(N/W ID)
255.255.255.255 - Broadcast Address
```

<a name=les></a>
## 2. Classless Addressing
- No portion for n/w & hosts is separated. Subnet mask/netmask is used to get n/w and host parts. 
- Subnet mask decides how many hosts are possible on a network.

<a name=submask></a>
### 1. Subnet Mask / Prefix / Netmask
Number of ON bits in 32 bit address going from left to right defines n/w address. 1's defines network and 0's defines host.
```console
<---1's defines n/w   ---> <-host->
11111111.11111111.11111111.00000000    =   255.255.255.0   
```

<a name=cidr></a>
#### CIDR(Classless Interdomain Routing) Notation
Representation in which address is written with a suffix indicating number of on bits in subnet mask
```c
11111111.11111111.11111111.00000000    =   255.255.255.0   =    /24   called CIDR notation
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

<a name=subnetting></a>
## Subnetting
- Breaking big network into smaller sub networks.
- **How?** Take some bits from host part & make them into n/w. 
```c
    IP              Network-Part    Host Part       Number of Hosts
 192.168.7.0/24       24 Bits        8 bits       2pow8 = 255-2 = 253
 
- Take 2 bits from Host Part, and include in n/w part

 192.168.7.0/26       26 Bits         8 bits      2pow6 = 64 -2 = 62
//From taken 2 bits we can create 4 new sub networks. 
192.168.7.01000000 -> 192.168.7.64/26
192.168.7.10000000 -> 192.168.7.128/26
192.168.7.11000000 -> 192.168.7.192/26
192.168.7.00000000 -> 192.168.7.0/26
```
<img src=subnetting.png width=900></a>

<a name=supernetting></a>
## Supernetting
- Taking bits from network part and creating Larger number of hosts.
- **Why?** Most of class A, B addresses are given out. And in class C number of available hosts are limited 28=256.
```c
    IP              Network-Part    Host Part       Number of Hosts
 192.168.64.0/24       24 Bits        8 bits      2pow8 = 255-2 = 253
 
- Take 2 bits from Network Part, and include in host part 
 
 192.168.64.0/22       22 Bits        10 bits      2pow10 = 1024-2 = 1022
11111111.11111111.
11111100.00000000
```

## Address Types
<a name=inside></a>
### A. Private Network / Private IP Address Space
- IETF decided not to give following to nodes on public networks. These IPs cannot be public because 2<sup>32</sup> = 4294967296 addresses would soon deplete if given to Public IPs. These can be used by private networks

| CIDR | Host Bits | Hosts | IP Address Range | Used By |
|---|---|---|---|---|
| 10.0.0.0/8 | 24 | 2<sup>24</sup>-2 = 16777216-2 = 16777214 | 10.0.0.0 - 10.255.255.255 | Big Software Companies |
| 172.16.0.0/12 | 20 | 2<sup>20</sup>-2 = 15728640-2 = 15728638 |  172.16.0.0 - 172.31.255.255 |Middle level network |
| 192.168.0.0/16 | 16 | 2<sup>16</sup>-2 = 65536-2 = 65534 |  192.168.0.0 - 192.168.255.255 | Home network |

<a name=inlocal></a>
#### Inside Local IP Address
- IP address assigned to Computer on Inside network

<a name=inglobal></a>
#### Inside Global IP Address
- IP address that is provided as a result of the translation process on the router and it represents the inside local or the range of inside local addresses.

<a name=outside></a>
### B. Outside Network
- All Network outside Private Network scope.

<a name=outsidel></a>
#### Outside Local Address 
- Translated address that is placed on packet in outside network.
<a name=outsideg></a>
#### Outside Global Address 
- IP address assigned to a host on the outside network by the host owner as a result of translation and comes from a globally routable address range.

<a name=rd></a>
### C. Reserved and Documentation Addresses
- Reserved for other special purposes such as documentation, testing, and benchmarking

| CIDR Range | Usage | Host Bits | Hosts | IP Address Range |
|---|---|---|---|---|
| 192.0.2.0/24 | Documentation and example code | 8 | 2<sup>8</sup>-2=254 | 192.0.2.1 - 192.0.2.254 |
| 198.51.100.0/24 | Documentation and example code | 8 | | |
| 203.0.113.0/24 | Documentation and example code | 8 | | |
| 198.18.0.0/25 | Benchmarking network devices | 7 | | |
| 100.64.0.0/10 | Carrier-grade NAT space | 22 |  2<sup>22</sup>-2=4194302 | |

<a name=cgn></a>
#### Carrier-grade NAT 
- This space refers to a range of IP addresses designated specifically for large-scale NAT deployments by internet service providers (ISPs) or network operators.
