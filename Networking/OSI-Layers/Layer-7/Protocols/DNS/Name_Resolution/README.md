 ## Name Resolution
 - **What?** The process of looking up a hostname and finding corresponding IP address.

### 1. Forward Lookup (hostname to IP conversion)
- [DNS Query](../DNS_Messages), [Recursive DNS Server](../Terms/DNS_Queries/), [Root_Nameserver](../Terms/Name_Server), [Authoritative_NameServer](../Terms/Name_Server)
<img src=forward-lookup.JPG width=1000 />

### 2. Reverse Lookup (IP to hostname)
- **Why?** Case-1: Spam received in mailbox, From-IP header is parsed. Now Email client wants to know from where this Email arrived? Is this IP Address authentic or spam. So Machine enquires ISP for reverse query, giving IP address and asking for URL(if exists)).
<img src=reverse-lookup.png width=800 />

- RECURSIVE DNS SERVER? Recursive means referring to itself. This DNS server caches the DNS records and sends DNS query further if record is not found.
- AUTHORITATIVE DNS SERVER? This server holds information about domain(eg: google.com) and delivers it to internet.
