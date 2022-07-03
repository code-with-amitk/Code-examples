IPv4
- [Problems: Address Exhaustion](#p)
- For Host to Host delivery
- [Header](IPv4_Header)
- [IPv4 Characteristics](IPv4_Characteristics)
- [Fragmentation Reassembly](Fragmentation_Reassembly)
  - MTU, MSS

<a name=p></a>
## Problems of IPv4
- **1. Address Exhaustion**
  - IP Address space is managed by [IANA(Internet Assigned Numbers Authority)](https://en.wikipedia.org/wiki/Internet_Assigned_Numbers_Authority) and 5 [RIRs(regional Internet registries)](https://en.wikipedia.org/wiki/Regional_Internet_registry) which provide IP Addresses from pool of unallocated addresses.
  - **Why?** Due to rapid growth of number of Internet users(Eg: PCs, printer, router specially mobile devices) IPv4 address depletion has started. IPv4 address is assigned to each interface.
  - All 5 RIRs have already depleted their IP Addresses. These RIRs still allocate recovered addresses or addresses reserved for a special purpose.
  - **Solutions**
    - [NAT](https://sites.google.com/site/amitinterviewpreparation/networking/layer3/routing). Permenent solution is IPv6 only.
    - [CIDR](https://sites.google.com/site/amitinterviewpreparation/networking/layer3)
    - IPv6
