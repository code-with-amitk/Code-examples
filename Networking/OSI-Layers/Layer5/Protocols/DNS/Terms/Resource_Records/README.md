## Resource Records / RR
- **What?** Data/Information about particular domain. For single host most common resource record is IP Address. 
- **FORMAT:**
```c
DOMAINNAME    TIMETOLIVE(sec)    CLASS(IN:for internet)    TYPE_OF_RR    VALUE

DOMAINNAME: Domain to which this RR applies. Each domain can have RRs of multiple domains. This filed is primary search key for search.
TTL: How stable RR is. Eg: 86400(1 day)
VALUE: Value of RR can be Number, domain name or string.
TYPE OF RR: What kind of RR is. 
    A. SOA(Start of Authority): value 6. Provides name of primary source of information about name server’s zone. Eg(Email of admin etc).    # host -v -t SOA example.com
    B. A Record: 4byte-IP to hostname mapping. Every internet have 1 or more IP addresses. All are returned.     # host A google.com;  dig hostname;  nslookup hostname
    C. AAAA RECORD: 128bit-IPv6 to hostname map.  (google.com, 2404:6800:4003:c00::65)
    D. MX RECORD: Value 15. Host responsible for handling incoming mails for zone. A preference value and the host name for a mail server/exchanger that will service this zone. 
    E. NS(NAME SERVER) RECORD: Value 2. Defines Name server for domain or subdomain.  
    F. CNAME RECORD:  Stores Alternate name(alias) of domain. Example: test.com 86400 IN CNAME test1.com     //test.com and test1.com both belongs to same host. # host    -v    -t  A ca.example.com
    G. PTR RECORD: Value 12  (For Reverse lookup) We need to create PTR record for each IP Address. This Stores hostname corresponding to reverse-dns-name.
    H. SPF RECORD: Which machines in domain are authorized to send/receive Email in domain. This helps in identifying junk/forged mails.
    I. SRV RECORD: Value 33 Defines services available in domain. Example, ldap, http, sip etc.. 
            DNS Client                                                                                        DNS-Server
        # host -v  -t SRV _ldap._tcp.example.com; dig SRV _ldap._tcp.lab.example.net;
                            <- 389    server0.example.com---
    H. TXT RECORD: value 13 Human readable information associated with domain name. Now-a-days spf1 ip4:72.51.34.34 ip4:70.33.254.29 -all--
```    

###  DNS ZONE FILE
- **What?** Plain text file which stores resource records of particular domain. Zone file always start with a Start of Authority (SOA) record.
```c
; Authoritative data for test.com
    test.com.     86400    IN    SOA        star boss (9527,7200,7200,241920,86400)
    star                            IN     A             130.37.56.201       //IP Address of star.test.com is <>
    flits             86400    IN     A            130.37.16.112       //flits.test.com has IP address <>
    test.com.     86400    IN    MX         1 rambo                //Email should be 1st sent to rambo@test.com
    test.com.     86400    IN    MX         2 sambo                //if rambo@test.com fails sambo should be tried as 2nd choice
    test.com.     86400    IN    NS           star
    www           86400    IN    CNAME star.cs.vu.nl        //www is aliased to star.cs.vu.nl
    10.30.20.10.in-addr.arpa. IN PTR    host.domain.com
```
