- [Global Infrastructure](#gi)
- [Service Categories](#sc)

<a name=gi></a>
## Global Infrastructure
AWS runs in:
- 69 Availabilty zones
- 22 Geographic Regions
- 190+ countries have 1 million+ customers

<a name=sc></a>
### Service Categories

|Area|What|Services|
|---|---|---|
|Compute|Provides compute capacity on cloud.|[EC2, LightSail,Lambda, ELB](/System-Design/Concepts/AWS/compute/)|
|Storage||[Object Store:S3](/System-Design/Concepts/Databases/Object_Storage), Block Store:[EBS](/System-Design/Concepts/AWS/Storage/EBS_Elastic_Block_Storage/README.md), File Store:[EFS](/System-Design/Concepts/AWS/Storage/EFS_Elastic_File_System/README.md), Glacier, [Snowball](/System-Design/Concepts/AWS/Storage/SnowBall/README.md), [StorageGW](/System-Design/Concepts/AWS/Storage/Storage_Gateway/README.md)|
|Databases||RDS:[Aurora](/System-Design/Concepts/Databases/SQL/Aurora.md), NoSQL:[DynamoDB](/System-Design/Concepts/Databases/NOSQL/AWS_DynamoDB), GraphDB:[Neptune](/System-Design/Concepts/Databases/NOSQL/Graph_DB/AWS_Neptune), Cache:[ElasticCache](/System-Design/Concepts/Cache/AWS_ElasticCache/README.md), Datawarehouse:[RedShift](/System-Design/Concepts/Databases/DataWareHouse/Aws_RedShift/README.md)|
|Network||Cloudfront,VPC, Direct Connect, Load Balancing, Route 53|
|Security,Identity,Compliance||IAM,Cognition,Guard Duty,Inspector,Macie,Certificate Manager,Cloud HSMHardware,Directory Services,[WAF](/System-Design/Concepts/AWS/Security/WAF_Web_Application_Firewall),[Sheild](/System-Design/Concepts/AWS/Security/Sheilg/),Artifact|
|Application Integration||[SNS](/System-Design/Concepts/AWS/Application_Integration/SNS_SQS/), [SQS](/System-Design/Concepts/AWS/Application_Integration/SNS_SQS/)|
|Containers||[ECS,EKS,Fargate](/System-Design/Concepts/AWS/Container/)|

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
