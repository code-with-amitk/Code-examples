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
- **A. Static/Basic NAT**
  - One-to-One Translation of IP Addresses.
  - Private Address Space/Pool has corresponding Public Address Space/Pool. 
  - Every computer on the network must be allocated a single dedicated routable IP address.
- **[B. Dynamic NAT](Dynamic_NAT)**
- **[C. PAT(Port Address Translation)](PAT)**

