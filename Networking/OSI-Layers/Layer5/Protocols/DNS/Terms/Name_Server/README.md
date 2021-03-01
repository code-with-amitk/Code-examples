## Name server / Nameserver
- **What?** Computer responsible for a particular domain, ie responding to that domain queries. One zone can have 1 or more name servers. 

### Types of NS
  - **1. Primary NS?** Zone have 1 primary name server which gets its information from DNS zone file on its disk.
  - **2. Secondary NS?** Get their information from the primary name server, maybe internet facing.
  - **3. Root NS?** Server which have IP-Addresses of nameservers handling [TLDs](/Networking/OSI-Layers/Layer5/Protocols/DNS/Terms/Domain_Name). eg: .com, .org
  - **4. Authoritative NS?** Server authoritative for particular domain. Eg: nandini.com is handled by 4.4.4.4
  - **5. Recursive NS?** NS which takes query from client and returns complete result, does not return partial results.
  - **6.Caching NS?** Server sitting at front of Clients, doing DNS queries on behalf of clients, storing results locally in cache. As Cache grows its efficiency improves as it can answer lot from cache.
      Problem2: Cache Poisoning: Hackers fills in cache of caching nameserver from stale/wrong/bad entries.    Solution: DNSSEC(DNS Security Extension) validation: Doing authentication, integration check of resource records before placing on cache.
