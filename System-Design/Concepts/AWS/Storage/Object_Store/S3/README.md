**S3 / Simple Storage Service**
- [S3 Storage classes](#sc)
- [S3 vs EBS](#vs)


## S3
- This service provides object-level storage. Amazon S3 stores data as objects in buckets.
- Any data can be stored on S3(eg: images, videos, text files). The maximum file size for an object in Amazon S3 is 5 TB.
### Features/Advantages
- _1. Web Enabled:_ Every Object has a URL, from web it can be seen.
- _2. Regionally Avaialble:_ Highly Durable. 99.999999999% {11 9's}
- _3. [Serverless:](/System-Design/Concepts/AWS/compute/Lambda)_ No EC2 instances are needed.
- _4. Supports data replication across AWS Regions/Cross Regions:_
  - With Cross-Region Replication, you designate a destination S3 bucket in another Region.
  - When Cross-Region Replication is turned on, any new object that is uploaded will be replicated to the destination S3 bucket

<a name=sc></a>
### Amazon S3 storage classes
2 factors when choosing a storage class:
- How often you plan to retrieve your data
- How available you need your data to be

|Storage class|Designed for|Number of AZ in which data is stored|Cost|
|---|---|---|---|
|S3 Standard|Frequently accessed data|3|Costliest|
|S3 Standard-Infrequent Access (S3 Standard-IA)|Infrequent accessed and highly avaialble data|3|Cheaper than Standard|
|S3 One Zone-Infrequent Access (S3 One Zone-IA)||1||
|S3 Intelligent-Tiering|For data with unknown or changing access patterns|||
|S3 Glacier|Data archiving|Able to retrieve objects from 1min-1 Hours|Low|
|S3 Glacier Deep Archive||Able to retrieve objects within 12 hours|Lowest|

<a name=vs></a>
### Amazon S3 vs EBS

|| EBS | Amazon S3 |
|---|---|---|
|Can Store upto|16 TiB|Unlimited, Indivisual Objects upto 5TB|
|Enforce Policies||Yes. WORM(Write Once Read Many)|
