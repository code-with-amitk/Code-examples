Amazon Route 53

## Amazon Route 53 / DNS Web Service
- This is amazon's cloud [DNS server](/Networking/OSI-Layers/Layer-7/Protocols/DNS/).
- Helps to route traffic to applications hosted in AWS or outside AWS also.

### How Route53 works?
```c
Customer's Browser
 www.testing.com  --DNS_Query--> ISP                                      |-------AWS Datacenter-1----
                                  ----DNS_QUery---> Office_DNS_Server     |
                                                          ----DNS_QUery---> AWS-Route-53
         <-------------------------- 1.2.3.4 --------------------------------
                                                                          |---------------------------
                                                                          
                                     |------AWS Datacenter-2----------------                                     
        ---- Http GET testing.com-----> AWS CloudFront                     |- App on EC2 Instance 
                                     |       -http GET-> App Load-Balancer-|- App on EC2 Instance 
                                     |                                     |- App on EC2 Instance 
          <-------------------------------------content-----------------------
                                     |--------------------------------------
```
