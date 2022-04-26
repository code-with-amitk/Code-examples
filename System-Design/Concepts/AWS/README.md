**AWS**
- [Service Categories](#sc)
- [How to interact with AWS Services](#how)
- [Terms:Availabilty zones, Geographic Region, Edge Location, GovCloud, VPC(Virtual Private Cloud), Subnets, Internet gateway, Virtual private gateway, AWS Direct Connect, Security Groups, serverless](Terms)

| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

### AWS
- **AWS Infra:** AWS runs in: 69 Availabilty zones, 22 Geographic Regions, 190+ countries have 1 million+ customers
- **[6 Benefits of using AWS Cloud](/System-Design/Concepts#adv)**

<a name=sc></a>
### Service Categories

|Area|What|Services|
|---|---|---|
|Analytics||[Athena, CodePipeline](Analytics)|
|Application Integration||[SNS,SQS](Application_Integration)|
|Artificial Intelligence||[<ul><li>Rekognition = Image recognition</li></ul>](Artificial_Intelligence)|
|Cache|Caching layer before DB|[ElasticCache, DAX](/System-Design/Concepts/Cache/DB_Caches/)|
|Compute|Provides compute capacity on cloud.|[<ul><li>Elastic Beanstalk</li> <li>EC2=VM(on-demand,spot,reserved)</li> <li>EMR(Elastic Map Reduce)</li> <li>LightSail</li> <li>Lambda</li> <li>ELB</li></ul>](compute)|
|Configuration Management|Provides tools for automation|[<ul><li>CloudFormation(IaaS)=Template</li> <li>Cloudformation</li> <li>Config=AWS Resources configuration change history</li> <li>Outpost</li> <li>Quickstart</li><ul>](Configuration_Management)|
|Containers||[ECS,EKS,Fargate](Container)|
|Databases||[<ul><li>Relational:Aurora,RDS</li> <li>NoSQL:DynamoDB,Accelrator</li> <li>GraphDB:Neptune</li> <li>Cache:ElasticCache</li> <li>Datawarehouse:RedShift, DMS</li></ul>](/System-Design/Concepts/Databases)|
|Design|Helps designing systems at scale|[AWS Well-Architected Framework](Design)|
|Developer Tools||[<ul><li>CodeStar</li> <li>CDK</li></ul>](Developer_Tools)|
|Management,Monitoring,Debug,Audit||[<ul><li>CloudWatch(Send Alarms)</li> <li>Cloudtrail(Audit)</li> <li>Kinesis(Real Time Data)</li> <li>OpsWork</li> <li>Personal Health Dashboard</li> <li>QuickSight</li> <li>(System Manager(SSM)=See Operatinal data of AWS resources take action)</li> <li>Trusted Advisor</li> <li>X-ray</li></ul>](Monitoring)|
|Media||[<ul><li>Elastic Transcoder=Convert media in Amazon S3 to audio,video</li></ul>](#Media)|
|Migration||[<ul><li>6Rs</li> <li>CAF</li> <li>Snow devices(Peta byte scale data transfer)</li> <li>Machine Learning</li> <li>AI</li> <li>Datasync</li></ul>](Migration_Innovation)|
|Network||[<ul><li>Cloudfront=CDN</li> <li>VPC</li> <li>Direct Connect</li> <li>Load Balancing</li> <li>Route 53=DNS</li><ul>](Network)|
|Pricing, Billing, Budget, Support|| [Billing, Budgets, Cost Explorer, Pricing, Support, AWS Free Tier, Support, MarketPlace](Pricing_Billing_Budget_Support)|
|Security,Identity,Compliance||[<ul><li>Artifact=Compliance</li> <li>Certificate Manager</li> <li>Cloud HSM</li> <li>Cognition</li> <li>Detective</li> <li>Directory Services</li> <li>(GuardDuty=Threat detection)</li> <li>IAM</li> <li>Inspector(security vunerabilites scanner)</li> <li>KMS</li> <li>Organizations(Has SCP(service control policy for APIs)</li> <li>Sheild(DDoS protection)</li> <li>WAF</li></ul>](Security)|
|Storage||[Block Store:EBS, File Store:EFS, Object Store:S3, macie, Glacier, Storage Gateway](Storage)|

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
