- [Global Infrastructure](#gi)
- Terms
  - [Geographic Region](#gr)
  - [Availabilty zones](#az)
  - [Edge Location](#el)
  - [GovCloud](#gc)

<a name=gi></a>
## Global Infrastructure
AWS runs in:
- 69 Availabilty zones
- 22 Geographic Regions
- 190+ countries have 1 million+ customers

<a name=t></a>
## Terms
<a name=gr></a>
### [Geographic Region](https://aws.amazon.com/about-aws/global-infrastructure/regions_az/?p=ngi&loc=2)
- Each Region has atleast **2 AZ**
- **Largest Region of AWS is US-EAST(ie North Virginia)**, new services becomes available here 1st.
```c
  -------US-east-----------
   |---GR---|
   |AZ1 AZn |
   |--------|
```
<img src=regions_and_az.JPG width=500 />

<img src=north-america-political-map.jpg width=500 />

<a name=az></a>
### Availabilty zones
- 1 or more data center owned by AWS, collectively called AZ.
- Naming convention of AZ is {Geographic location}{letter}. Example AZs for us-east are: us-east-1a, us-east-1b
- Latency between AZ's is <10ms (Hence these AZs are purposely positioned to be that apart).
```c
   |-----------AZ---------------|
   | Data-center1  Data-center2 |  Data-centern
   |----------------------------|
```

<a name=el></a>
### Edge Locations
- Datacenters owned by trusted AWS partner, which has direct connection to AWS network.

<a name=gc></a>
### GovCloud Region
- [Geographic Region](#gr) for highly sensative data storage. Eg: US DOD, US DOJ(dept of justice) etc. Presently only 2 GovCloud Regions: US-West, US-East.
- Person using GovCloud need to be US citizen and located in US only.

## 4 Primary Areas of AWS

|Area|What|Services|
|---|---|---|
|Compute|Provides compute capacity on cloud.|[EC2](/System-Design/Concepts/AWS/compute/EC2_Elastic_Compute_Cloud/README.md), [LightSail](/System-Design/Concepts/AWS/compute/Light_Sail/README.md), [ECS](/System-Design/Concepts/AWS/compute/ECS_Elastic_Container_Service/README.md), [Lambda](/System-Design/Concepts/AWS/compute/Lambda/README.md), [ELB](/System-Design/Concepts/AWS/compute/ELB_Elastic_Load_Balancer/README.md)|
|Storage||[Object Store:S3](/System-Design/Concepts/Databases/Object_Storage), Block Store:[EBS](/System-Design/Concepts/AWS/Storage/EBS_Elastic_Block_Storage/README.md), File Store:[EFS](/System-Design/Concepts/AWS/Storage/EFS_Elastic_File_System/README.md), Glacier, [Snowball](/System-Design/Concepts/AWS/Storage/SnowBall/README.md), [StorageGW](/System-Design/Concepts/AWS/Storage/Storage_Gateway/README.md)|
|Databases||RDS:[Aurora](/System-Design/Concepts/Databases/SQL/Aurora.md), NoSQL:[DynamoDB](/System-Design/Concepts/Databases/NOSQL/AWS_DynamoDB), GraphDB:[Neptune](/System-Design/Concepts/Databases/NOSQL/Graph_DB/AWS_Neptune), Cache:[ElasticCache](/System-Design/Concepts/Cache/AWS_ElasticCache/README.md), Datawarehouse:[RedShift](/System-Design/Concepts/Databases/DataWareHouse/Aws_RedShift/README.md)|
|Network||Cloudfront,VPC, Direct Connect, Load Balancing, Route 53|
|Security,Identity,Compliance||IAM,Cognition,Guard Duty,Inspector,Macie,Certificate Manager,Cloud HSMHardware,Directory Services,[WAF](/System-Design/Concepts/AWS/Security/WAF_Web_Application_Firewall),[Sheild](/System-Design/Concepts/AWS/Security/Sheilg/),Artifact|

- Security
```
 a. IAM (Identity and Access Management)
    - manage users and their levels of access to the AWS resources.
  b. Cognition
    -  used for device authentication / O Auth service
  c. Guard Duty
    - monitor for malicious activity on your AWS account
  d. Inspector
    - Agent installed on your VM and you can run tests for security vulnerabilities
  e. Macie
    - check your entire suite of application for personally identifiable information
    - ML based service which discover, classify, and protect sensitive data in AWS provides dashboard provides alerts.
  f. Certificate Manager
    - Gives certificate to domains registered to AWS/router.
  g. Cloud HSMHardware
    - store your Hardware Private and Public key, that are used to securely access your application/EC2 instances.
  f. Directory Services
    -  Integrate your Microsoft active directory services with AWS services
  h. WAF(Web Application Firewall)
    - sits in front of your web server and it mitigates against injection, cross scripting
  i. Shield
    - Prevents DDoS Attacks. Can be used with load balancers, cloud front, as well as Route 53
  j. Artifact: 
    - Is used for compliance and audit
```
