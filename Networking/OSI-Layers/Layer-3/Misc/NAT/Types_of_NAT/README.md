## Type of NAT

```c
    INSIDE N/W                                  
       PC1                                            
    [10.0.0.2]------------------                       
                                |                 
       PC2             10.0.0.1 | 179.2.2.80                    
    [10.0.0.3]----------------[Router]-----------------Internet-----------[213.31.80.2]Host4
                                |                  
       PC3                      |                    
    [10.0.0.4]------------------    
```

### A. Static/Basic NAT
- One-to-One Translation of IP Addresses.
- Private Address Space/Pool has corresponding Public Address Space/Pool. 
- Every computer on the network must be allocated a single dedicated routable IP address.

### B. Dynamic NAT 
- Pool of Public IP Addresses is reserved at beginning. 
- And at run-time Router picks up the IP Address from Pool for address translation.

### C. PAT(Port Address Translation)
> Also called IP Masquerading/ NAPT(N/W address & Port Translation)/ NAT Overloading
- Router will use only Single Public IP Address. Example

|Inside Local IP:Port| Inside Global IP:Port |	Outside Global IP:Port |
|---|---|---|
|10.0.0.3: 1650 |	179.2.2.80: 1650|213.31.80.2: 80|
10.0.0.4: 1722|179.2.2.80: 1722|213.31.80.2: 80|

