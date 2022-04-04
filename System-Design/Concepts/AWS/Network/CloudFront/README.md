**Cloudfront**

## Cloudfront
- This is Amazon's caching service. CF pulls the data from datacenter and delivers to customer.
- Suppose Company's main datacenter is Brazil and customer is in China. Getting data from Brazil will cause huge latency.
   - Instead required data is cached near to customer's location(in local datacenter) from where Amazon CloudFront pulls and delivers the data.
```c
                               |-------------China-----------|
                               |       |-data-> Customer     |
                               |       |                     |
                               |  cloudfront                 |
                               |     /\                      |
                               | Local-datacenter(CDN)       |
                               |-----------------------------|
   Brazil
Company's Maindatacenter
```
