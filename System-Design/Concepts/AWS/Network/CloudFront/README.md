**Cloudfront = CDN**
- [Create Cloudfront](#c)

## Cloudfront
- This is Amazon's caching service. This is used as [CDN](/System-Design/Concepts/CDN). CF pulls the data from datacenter and delivers to customer.
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

### Create Cloudfront
#### 1. Create CF Distribution
[Creating a S3 bucket](/System-Design/Concepts/AWS/Storage/Object_Store/S3)
```c
AWS Console > Cloudfront
Origin Domain name:        created-s3-bucket
```
