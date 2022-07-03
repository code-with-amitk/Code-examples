IPv4
- [Problems: Address Exhaustion](#p)
- [Characteristics](#ch)
- [Fragmentation Reassembly. MTS, MTU](#fr)
- [Header](IPv4_Header)

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

<a name=fr></a>
## Fragmentation Reassembly
- **Why?** Frag & Reassembly only happens If (Packet Size > [MTU(Maximum Transmission Unit)](#mm)
- **Fields which change during Frag, Reassembly?**
  - Identification Number: Used that of Original Frame. Remains same for all IP Fragments.
  - Flags: DF, MF
  - Fragment Offset
- **How packet is broken into fragments?** Every fragment will have IP Header
```c
    Larger Datagram: | len=4000 | ID = x | fragFlag = 0 | offset = 0 |
    
    Fragmented to:   | len=1500 | ID = x | DF:0, MF:1 | offset = 0 |
                     | len=1500 | ID = x | DF:0, MF:1 | offset = 1480 |
                     | len=1040 | ID = x | DF:0, MF0 | offset = 2960 |
```
- **Reciever?**
```
  if(MF bit = 1){
    Place in buffer, start the timer.
    Wait for all packets of same ID-number, seq-number using Fragment offset feild.
    if last fragment receiver (MF=0) start re-assembly
  }
  
  - Its rule that Receiver should allocate a separate Buffer for all fragments having different ID number and wait till MF=0
  - If Fragment is Discarded by Reciever, then Sender should resend it.
```
<a name=mm></a>
### MTS and MTU
||MTU (maximum Transmission Unit)|MSS (Maximum TCP Segment Size)|
|---|---|---|
|What|IPv4 Maximum IP packet size for a given link. Packets bigger than the MTU is fragmented. If (packet size > MTU) {fraagmentation}|TCP, Maximum amount of data that Receiver or Sender wants to receive(specified in Octets/bytes). It excludes TCP, IP Headers.Each side can have different MSS.This value cannot be changed When connection is Established. if (TCP_packet_size > MSS) {Discard Packet}|
|Default value|1500|536|
|Related to|IPv4|TCP|
|When decided|Routing|3-way handshake|
|If i dont want fragmentation?|Increase MTU size, Use helper protocols:PMTUD||
|Network & respective MTUs(bytes)|802.3(Ethernet):1500, 4Mb token ring:4464, 16Mb token ring:17914||

- MTU = 1500 bytes
```c
| IP(20 bytes) | TCP(20 bytes) | App (1460 bytes) |
```


