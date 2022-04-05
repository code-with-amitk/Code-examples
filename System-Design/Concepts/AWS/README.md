- [Global Infrastructure](#gi)
- [Service Categories](#sc)
- [How to interact with AWS Services](#how)
- [Terms:Availabilty zones, Geographic Region, Edge Location, GovCloud, VPC(Virtual Private Cloud), Subnets, Internet gateway, Virtual private gateway, AWS Direct Connect, Security Groups, serverless](Terms)

<a name=gi></a>
## Global Infrastructure
AWS runs in: 69 Availabilty zones, 22 Geographic Regions, 190+ countries have 1 million+ customers

<a name=sc></a>
### Service Categories

|Area|What|Services|
|---|---|---|
|Compute|Provides compute capacity on cloud.|[EC2, LightSail,Lambda, ELB](compute)|
|Storage||[Object Store:S3, Block Store:EBS, File Store:EFS, Glacier, Snowball, StorageGW](Storage)|
|Databases||[Relational:Aurora,RDS, NoSQL:DynamoDB, GraphDB:Neptune, Cache:ElasticCache, Datawarehouse:RedShift](/System-Design/Concepts/Databases)|
|Network||[Cloudfront,VPC, Direct Connect, Load Balancing, Route 53](Network)|
|Security,Identity,Compliance||[IAM,Cognition,Guard Duty,Inspector,Macie,Certificate Manager,Cloud HSMHardware,Directory Services,WAF,Sheild](Security),Artifact|
|Application Integration||[SNS,SQS](Application_Integration)|
|Containers||[ECS,EKS,Fargate](Container)|
|Configuration Management|Provides tools for automation|[Elastic Beanstalk, CloudFormation, Outpost](Configuration_Management)|

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

<a name=how></a>
### How to interact with AWS Services
- **1. Management Console:** This is a web-based interface for accessing and managing AWS services.
- **2. AWS CLI:** Same as linux cli, you can type commands to start/configure AWS service(s). Example:
```c
$ aws ec2 run-instances --image-id xxx --count 1 --instance-type 1
```
- **3. AWS SDK:** Calling AWS [REST API's](/Networking/OSI-Layers/Layer-7/WebServer_WebClient_WebService/WebClient_Connecting_WebServer/REST) from your application code
