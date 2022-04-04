- [CyberSquatting](#cs)
- [Domain Name](Domain_Name)
- [DNS Queries](#dq)
- [DNS Zone](DNS_Zone)
- [Name server](#ns)
- [Recursive, Authoritative DNS Server](#ra)
- [Resource Records](Resource_Records)

<a name=cs></a>
### CyberSquatting
Selling a domain to interested party at much higher price.

<a name=dq></a>
### DNS Queries Types
- **1. Recursive?** Recursive NS perform recursive queries to other nameservers and returns complete result to DNS client. Done by Local DNS server.
- **2. Iterative/Non-Recursive?** Root nameservers does not collects all information rather they return partial information and continue to next query. This is called iterative.

<a name=ns></a>
### Name server / Nameserver
- Computer responsible for a particular domain, ie responding to that domain queries. One zone can have 1 or more name servers. 

#### Types of NS
- **1. Primary NS?** Zone have 1 primary name server which gets its information from DNS zone file on its disk.
- **2. Secondary NS?** Get their information from the primary name server, maybe internet facing.
- **3. Root NS?** Server which have IP-Addresses of nameservers handling [TLDs](/Networking/OSI-Layers/Layer5/Protocols/DNS/Terms/Domain_Name). eg: .com, .org
- **4. Authoritative NS?** Server authoritative for particular domain. Eg: nandini.com is handled by 4.4.4.4
- **5. Recursive NS?** NS which takes query from client and returns complete result, does not return partial results.
- **6.Caching NS?** Server sitting at front of Clients, doing DNS queries on behalf of clients, storing results locally in cache. As Cache grows its efficiency improves as it can answer lot from cache.
  - Problem2: Cache Poisoning: Hackers fills in cache of caching nameserver from stale/wrong/bad entries.    Solution: DNSSEC(DNS Security Extension) validation: Doing authentication, integration check of resource records before placing on cache.

<a name=ra></a>
### Recursive, Authoritative DNS Server
- RECURSIVE DNS SERVER? Recursive means referring to itself. This DNS server caches the DNS records and sends DNS query further if record is not found.
- AUTHORITATIVE DNS SERVER? This server holds information about domain(eg: google.com) and delivers it to internet.
