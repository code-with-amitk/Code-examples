**DNS / Domain Name Service**
- Name Resolution
  - [Forward Lookup](#fl)
  - [Reverse Lookup](#rl)

## DNS / Domain Name Service / Port 53
- Protocol for converting hostname to IP address and viceversa. 
- DNS uses udp by default, fall back to tcp if on udp cannot communicate.

### Name resolution
The process of looking up a hostname and finding corresponding IP address.

<a name=fl></a>
#### Forward Lookup (hostname to IP conversion)
- [DNS Query](../DNS_Messages), [Recursive DNS Server](../Terms/DNS_Queries/), [Root_Nameserver](../Terms/Name_Server), [Authoritative_NameServer](../Terms/Name_Server)
<img src=forward-lookup.JPG width=1000 />

<a name=rl></a>
#### Reverse Lookup (IP to hostname)
- **Why?** Case-1: Spam received in mailbox, From-IP header is parsed. Now Email client wants to know from where this Email arrived? Is this IP Address authentic or spam. So Machine enquires ISP for reverse query, giving IP address and asking for URL(if exists)).
<img src=reverse-lookup.png width=800 />

- RECURSIVE DNS SERVER? Recursive means referring to itself. This DNS server caches the DNS records and sends DNS query further if record is not found.
- AUTHORITATIVE DNS SERVER? This server holds information about domain(eg: google.com) and delivers it to internet.


- **Terms:** 
  - [DNS Queries(Recursive, Iterative)](Terms/DNS_Queries)
  - [DNS Zones: Primary, Secondary, Stub](Terms/DNS_Zone)
  - [Domain/Domain Name: TLD(Top Level Domain), 2nd-Level-Domain, 3rd-Level-Domain](Terms/Domain_Name)
  - [Nameservers: Primary, Secondary, Root Nameserver, Authoritative](Terms/Name_Server)
  - [Resource Records, DNS Zone File](Terms/Resource_Records)
- **[Advantages_Disadv_of_DNS](Advantages_Disadv_of_DNS)**
 
