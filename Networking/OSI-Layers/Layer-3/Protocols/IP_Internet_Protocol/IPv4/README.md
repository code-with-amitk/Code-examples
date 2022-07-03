IPv4
- [Problems: Address Exhaustion](#p)
- [Characteristics](#ch)
- [Header](IPv4_Header)
- [IPv4 Characteristics](IPv4_Characteristics)
- [Fragmentation Reassembly](Fragmentation_Reassembly)
  - MTU, MSS

<a name=p></a>
## Problems of IPv4
### 1. Address Exhaustion
- IP Address space is managed by [IANA(Internet Assigned Numbers Authority)](https://en.wikipedia.org/wiki/Internet_Assigned_Numbers_Authority) and 5 [RIRs(regional Internet registries)](https://en.wikipedia.org/wiki/Regional_Internet_registry) which provide IP Addresses from pool of unallocated addresses.
- **Why?** Due to rapid growth of number of Internet. Every(PCs, printer, router specially mobile devices) have his own IP address. IPv4 address is assigned to each interface. 32 bit means 2<sup>32</sup> = 4,294,967,296 = 4 Billion will deplete.
- All 5 RIRs have already depleted their IP Addresses. These RIRs still allocate recovered addresses or addresses reserved for a special purpose.
- **Solutions**
  - [NAT](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/routing). Permenent solution is IPv6 only.
  - [CIDR](https://sites.google.com/site/amitinterviewpreparation/networking/layer3)
  - IPv6

<a name= ch></a>
## IPv4 Characteristics
#### 1. Connectionless
No state related to IP datagrams is maintained either on source or destination side. Advantages:
- network layer is much simpler.
- Transport layer already provides connection-oriented, should not repeat the work.
- Routers could become overloaded managing too many connections.
#### 2. Unreliable
It not guaranteed that an IP data gram will get delivered to the destination or not. If IP packet gets any error in Transit, at source or destination, its discarded and ICMP message is sent back.
