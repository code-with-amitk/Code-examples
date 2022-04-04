**DNS / Domain Name Service**
- [Adv, Disadv of DNS](#ad)
- Name Resolution
  - [Forward Lookup](#fl)
  - [Reverse Lookup](#rl)

## DNS / Domain Name Service / Port 53
- Protocol for converting hostname to IP address and viceversa. 
- DNS uses udp by default, fall back to tcp if on udp cannot communicate.

### Adv, Disadv of DNS
- **Advantages of DNS**
  - *1.* To send packet across network we need IP Address and only DNS can provide.
  - *2.* No need for memorizing IP addresses
- **Disadv**
  - *1.* Registry only controlled by [ICANN](Terms) which can become bais to some country/organization.
  - *2.* [DNS Messages](DNS_Messages) does not have information of client asking the information, hacker can bisect the message and send his own message.
  - *3.* [TLD's](Terms) can be bottleneck.

### Name resolution
The process of looking up a hostname and finding corresponding IP address.

<a name=fl></a>
#### Forward Lookup (hostname to IP conversion)
- [DNS Query](DNS_Messages), [Recursive DNS Server, Root Nameserver, Authoritative NameServer](Terms)
<img src=forward-lookup.JPG width=1000 />

<a name=rl></a>
#### Reverse Lookup (IP to hostname)
- **Why?** Case-1: Spam received in mailbox, From-IP header is parsed. Now Email client wants to know from where this Email arrived? Is this IP Address authentic or spam. So Machine enquires ISP for reverse query, giving IP address and asking for URL(if exists)).
<img src=reverse-lookup.png width=800 />

- RECURSIVE DNS SERVER? Recursive means referring to itself. This DNS server caches the DNS records and sends DNS query further if record is not found.
- AUTHORITATIVE DNS SERVER? This server holds information about domain(eg: google.com) and delivers it to internet.
