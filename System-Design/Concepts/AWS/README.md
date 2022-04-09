**AWS**
- [Service Categories](#sc)
- [How to interact with AWS Services](#how)
- [Terms:Availabilty zones, Geographic Region, Edge Location, GovCloud, VPC(Virtual Private Cloud), Subnets, Internet gateway, Virtual private gateway, AWS Direct Connect, Security Groups, serverless](Terms)

### AWS
- **AWS Infra:** AWS runs in: 69 Availabilty zones, 22 Geographic Regions, 190+ countries have 1 million+ customers
- **[Advantages of AWS](/System-Design/Concepts#adv)**

<a name=sc></a>
### Service Categories

|Area|What|Services|
|---|---|---|
|Application Integration||[SNS,SQS](Application_Integration)|
|Pricing, Billing, Budget, Support|| [Billing, Budgets, Cost Explorer, Pricing, Support, AWS Free Tier, Support, MarketPlace](Pricing_Billing_Budget_Support)|
|Cache|Caching layer before DB|[ElasticCache, DAX](/System-Design/Concepts/Cache/DB_Caches/)|
|Compute|Provides compute capacity on cloud.|[EC2, LightSail,Lambda, ELB](compute)|
|Configuration Management|Provides tools for automation|[Elastic Beanstalk, CloudFormation, Outpost](Configuration_Management)|
|Containers||[ECS,EKS,Fargate](Container)|
|Databases||[Relational:Aurora,RDS, NoSQL:DynamoDB, GraphDB:Neptune, Cache:ElasticCache, Datawarehouse:RedShift](/System-Design/Concepts/Databases)|
|Design|Helps designing systems at scale|[AWS Well-Architected Framework](Design)|
|Management,Monitoring||[CloudWatch, Cloudtrail, Trusted Advisor](Monitoring)|
|Migration||[6Rs, CAF, Snow devices, Machine Learning, AI](Migration_Innovation)|
|Network||[Cloudfront,VPC, Direct Connect, Load Balancing, Route 53](Network)|
|Security,Identity,Compliance||[IAM, Organizations, SCP, OU, Cognition, GuardDuty, Inspector, Macie,C ertificate Manager, Cloud HSMHardware, Directory Services,WAF,Sheild, Artifact, KMS](Security)|
|Storage||[Object Store:S3, Block Store:EBS, File Store:EFS, Glacier, Snowball, StorageGW](Storage)|

- Security
```
  b. Cognition
    -  used for device authentication / O Auth service 
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
```

<a name=how></a>
### How to interact with AWS Services
- **1. Management Console:** This is a web-based interface for accessing and managing AWS services.
- **2. AWS CLI:** Same as linux cli, you can type commands to start/configure AWS service(s). Example:
```c
$ aws ec2 run-instances --image-id xxx --count 1 --instance-type 1
```
- **3. AWS SDK:** Calling AWS [REST API's](/Networking/OSI-Layers/Layer-7/WebServer_WebClient_WebService/WebClient_Connecting_WebServer/REST) from your application code
