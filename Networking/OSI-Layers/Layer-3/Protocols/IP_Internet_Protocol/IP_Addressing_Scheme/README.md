- IP Addressing Scheme
- Types of IP Addressing
  - [1. Classful Addressing](#ful)
  - [2. Classless Addressing](#les)
    - 2.1 Terms
      - [1. CIDR(Classless Interdomain Routing) / Netmask / Subnet mask / Prefix](#cidr)
      - [2. Network ID / Network Address](#nidr)
      - [3. Broadcast Address](#baddr)

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
    Class             A                       B                   C               D(MULTICAST)              E(experimental)
  N/W part            a                       a.b                 a.b.c           224.0.0.0-239.255.255.255
  Host part           b.c.d                   c.d                 d
    Range           0-127.x.x.x               128-191.x.x.x       192-223.x.x.x   224-239.x.x.x             240-255.x.x.x     
  No of hosts      2pow24=1677716-2           2pow16=65536-2      2pow8=256-2
                  N/W ID,broadcast removed
  Suitable For      Large Org                 medium Org          Small Org
```

<a name=les></a>
## 2. Classless Addressing
- No portion for n/w & hosts is separated. Subnet mask/netmask is used to get n/w and host parts
### 2.1 Terms
<a name=cidr></a>
#### 1. CIDR(Classless Interdomain Routing) / Netmask / Subnet mask / Prefix: 
- Number of ON bits in 32  bit address going from left to right. Eg:
```c
  11111111.11111111.11111111.00000000    =   255.255.255.0   =    /24   called CIDR/Netmask/subnet Mask/Prefix
```
<a name=nidr></a>
#### 2. Network ID / Network Address 
- Address that identifies subnet or host.  Used to refer all hosts on that n/w. Eg: 46.0.0.0
<a name=baddr></a>
#### 3. Broadcast Address 
- This is an IP Address that allows information to be sent to all machines ON THAT SUBNET rather than specific host. All hosts are members of this group. Eg: 46.255.255.255
