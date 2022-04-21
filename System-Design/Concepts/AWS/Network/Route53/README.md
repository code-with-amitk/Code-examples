**Amazon Route 53**
- [How Route53 works?](#how)
- [Routing Policies](#rp)

## Amazon Route 53 / DNS Web Service
- This is amazon's cloud [DNS server](/Networking/OSI-Layers/Layer-7/Protocols/DNS/).
- Helps to route traffic to applications hosted in AWS or outside AWS also.

<a name=how></a>
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

<a name=rp></a>
### Routing Policies
When we create a record, we choose a routing policy, which determines how Amazon Route 53 responds to queries:

|Routing Policy|When to use|
|---|---|
|1. Simple|Use when only 1 resource is there to performs function of your domain. Ex: A web server that serves content for the example.com website|
|2. Failover|Use when you want to configure active-passive failover|
|3. Geolocation|Route traffic based on the location of your users|
|4. Geoproximity|Route traffic based on the location of resources &, optionally, shift traffic from resources in one location to resources in another|
|5. Latency|When resources are in multiple AWS Regions & we need to route traffic to Region that provides the best latency with less round-trip time|
|6. Multivalue answer|When you want Route 53 to respond to DNS queries with up to eight healthy records selected at random|
|7. Weighted|Route traffic to multiple resources in proportions that you specify|
