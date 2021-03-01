## DNS Message
- **Format** 
```c
  Header + Msg.  There are 2 types of messages. Queries and replies.
```

### DNS HEADER
```c
| QR(1 bit)  | opCode(4 bit) | AA(1 bit) | TC(1 bit) | RD(1 bit) | RA(1 bit) | Z(3 bits) | RCode(4 bits) |
```
- QR(Query or Response): 0-Query. 1-Response
- OPCODE(Operation Code): Type of Query message
  - 0:Standard Query
  - 1:Inverse Query. Obsolete now. This was defined to perform inverse DNS lookups that is finding names from IP addresses.
  - 2:STATUS:Server status request    
- AA(Authoritative Answer Flag): 1:Server that created the response is authoritative for the zone in which the domain name specified in the Question section is located.    0:nonauthroritative
- TC(Truncation Flag): 1:Message was truncated due to its length being longer than the maximum permitted for the type of transport mechanism used. TCP doesn't have a length limit for messages, while UDP messages are limited to 512 bytes, so this bit being sent usually is an indication that the message was sent using UDP and was too long to fit. The client may need to establish a TCP session to get the full message.
- RD(Recursion Desired): Requests that the server receiving the query attempt to answer the query recursively, if the server supports recursive resolution. The value of this bit is not changed in the response.
- RA(Recursion Available): Set to 1 or cleared to 0 in a response to indicate whether the server creating the response supports recursive queries. This can then be noted by the device that sent the query for future use.
- Z(Zero):    Reserved for future
- RCode:0:setted in query.  Non-zero setted by server
  - 1-Format Error.    Server cannot understand the format or query
  - 2-Server failure.    Server failed internally
  - 3-Name Error.    Name specified in query does not exist in domain. This is used by authoritative server in domain, since it knows all objects & sub domains in domain
  - 4-Not Implemented.    Query received is not supported by server
  - 5-Refused        Server refused to process the query. Generally policy reasons. Eg: Zone transfers are restricted. Server honors zone transfer request only from certain devices.
  - 6-YX Domain:    Name exists when it should not
  - 7-YX RR Set:    The resource record set exist that should not
  - 8-NX RR Set:    The RR set that should exist does not
  - 9-Not Auth:    Server recieveing the query is not authoritative for zone specified
  - 10-Not Zone:    Name specified in message is not within zone specified in message.
- QDCount(2 bytes)/Question Count.    Number of questions in the Question section of the message. 
- ANSCount(2 bytes)/Answer Record Count.    Number of resource records in the Answer section of the message 
- NSCount(2 bytes)/Authority Record Count.     Number of resource records in the Authority section of the message. (“NS” stands for “name server”, of course. J) 
- ARCount(2 bytes)/Additional Record Count.     Number of resource records in the Additional section of the message. 

### [DNS MESSAGE BODY](http://www.zytrax.com/books/dns/ch15/)
- DNS message body is used in 2 ways. 
  - Client: Asks question in dns message body. 
  - Server sends answer to question after filling in message body.
- DNS CLIENT sends message body:      | QName(variable) | QType(2 bytes) | QClass(2 bytes) |
  - QName/Question Name: Contains the object/domain/zone name being queried.
  - QType/Question Type: Resource record being requested. 1: Request A record for domain name,    2: Request NS record(s) for domain name,    5: Request CNAME record(s) for domain name,    6: Request SOA record(s) for domain name,    11: Request WKS record(s) for domain name,    12: Request PTR record(s) for domain name  15: Request MX record(s) for domain name,    33: Request SRV record(s) for domain name,    28: Request AAAA record(s) for domain name,    255: Requests ANY resource record (typically wants SOA, MX, NS and MX)
  - QClass/Question Class: The Resource Record(s) class being requested, for instance, internet, chaos etc.    1: IN or Internet

- DNS SERVER sends message body
```c
<----------        Answer Section      --------------> <------Authority Section------><----Additional Section---->
|  Name(variable) | Type(2 byte) | Class(2 byte) | TTL(4 byte) | RLength(2 byte) | RData(variable) |
```                                                          
- All these section comprise of RR(resource records) and are of same format. 
  - NAME: The name being returned e.g. www or ns1.example.net If the name is in the same domain as the question then typically only the host part (label) is returned, if not then a FQDN is returned.
  - TYPE: 1:A record (same as above)
  - CLASS: Class of resource records being requested, for example, Internet, CHAOS etc. Eg: 1:Internet
  - TTL: The time in seconds that the record may be cached. A value of 0 indicates the record should not be cached. 
  - RR data length: Length in bytes of resource record data field. 
  - RDATA: resource record types have a specific RDATA format which reflect their resource record format 
  - SOA: 
    - Primary NS:    Variable length. The name of the Primary Master for the domain. May be a label, pointer or any combination.
    - Admin MB:    Variable length. The administrator's mailbox. May be a label, pointer or any combination.
    - Serial Number:    4 byte
    - Refresh interval:    4 byte
    - Retry Interval:    4 byte
    - Expiration Limit:    4 byte
    - Minimum TTL:    4 byte
- MX: Preference:  Unsigned 16-bit integer.    Mail Exchanger:  The name host name that provides the service. May be a label, pointer or any combination
- A: IP Address:  Unsigned 32-bit value representing the IP address
- AAAA: IP Address: 16 octets representing the IP address
- PTR, NS: Name: The host name that represents the supplied IP address (in the case of a PTR) or the NS name for the supplied domain (in the case of NS). May be a label, pointer or any combination. 
