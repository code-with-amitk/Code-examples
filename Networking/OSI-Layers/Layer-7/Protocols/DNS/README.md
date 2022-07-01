**DNS / Domain Name Service**
- [Adv, Disadv of DNS](#ad)
- Name Resolution
  - [1. Forward Lookup](#fl)
  - [2. Reverse Lookup](#rl)
- [Terms:CyberSquatting, Domain Name, DNS Queries, DNS Zone, Name server, Recursive, Authoritative DNS Server Resource Records](Terms)


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
#### 1. Forward Lookup (hostname to IP conversion)
- [DNS Query](DNS_Messages), [Recursive DNS Server, Root Nameserver, Authoritative NameServer](Terms)
<img src=forward-lookup.JPG width=900 />

<a name=rl></a>
#### 2. Reverse Lookup (IP to hostname)
- **Why?** Case-1: Spam received in mailbox, From-IP header is parsed. Now Email client wants to know from where this Email arrived? Is this IP Address authentic or spam. So Machine enquires ISP for reverse query, giving IP address and asking for URL(if exists)).
<img src=reverse-lookup.png width=600 />

