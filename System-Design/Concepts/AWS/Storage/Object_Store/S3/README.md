**S3 / Simple Storage Service**
- [S3 Storage classes](#sc)
- Advantages/Features
  - [Downloadable via URL](#f1)
  - [S3 Transfer Acceleration](#f5)
  - [AWS Macie](#f6)
- [S3 vs EBS](#vs)
- [Creating S3 Bucket](#c)


## S3
- This service stores data(eg: images, videos, text files) using objects. Amazon S3 stores data as objects in buckets.
- The maximum file size for an object in Amazon S3 is 5 TB.

### Features/Advantages
<a name=f1></a>
#### 1. Web Enabled
Every Object has a URL from where it can be downloaded/seen.

#### 2. Regionally Avaialble
Highly Durable. 99.999999999% {11 9's}
#### 3. [Serverless:](/System-Design/Concepts/AWS/compute/Lambda) 
No EC2 instances are needed.
#### 4. Support Cross Region Replication
- You designate a destination S3 bucket in another Region.
- When Cross-Region Replication is turned on, any new object that is uploaded will be replicated to the destination S3 bucket

<a name=f5></a>
#### 5. S3 Transfer Acceleration (have additional chaarges)
- A bucket-level feature for fast,secure transfers of files over long distances between your client and an S3 bucket.
- it uses globally distributed [edge locations](/System-Design/Concepts/AWS/Terms#el) to transfer data.
- As data arrives at an edge location, the data is routed to Amazon S3 over an optimized network path.

<a name=f6></a>
#### 6. AWS Macie
This is data security and data privacy service that uses ML to help identify & protect sensitive data in S3 buckets. Eg:
- Macie can detect personal information eg: names, password, credit card information etc

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
|S3 Intelligent-Tiering|For data which is accessed randomly|||
|S3 Glacier|Data archiving|Able to retrieve objects from 1min-1 Hours|Low|
|S3 Glacier Deep Archive||Able to retrieve objects within 12 hours|Lowest|

<a name=vs></a>
### Amazon S3 vs EBS

|| EBS | Amazon S3 |
|---|---|---|
|Can Store upto|16 TiB|Unlimited, Indivisual Objects upto 5TB|
|Enforce Policies||Yes. WORM(Write Once Read Many)|

<a name=c></a>
### Creating S3 Bucket
```c
AWS Console > s3
  Bucket name:                amit-bucket       //This should be globally unique
  Upload files to bucket:     Upload (Upload files from desktop)
                              We can download files from bucket as well.
```
