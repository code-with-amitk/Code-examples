**S3 / Simple Storage Service**
- [S3 Storage classes](#sc)


## S3
- This service provides object-level storage. Amazon S3 stores data as objects in buckets.
- Any data can be stored on S3(eg: images, videos, text files). The maximum file size for an object in Amazon S3 is 5 TB.

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
