**AWS**
- [Service Categories](#sc)
- [How to interact with AWS Services](#how)
- [Terms: Availabilty zones, Direct Connect, Edge Location, GovCloud, Internet gateway, Recommendations, Region, Security Groups, Serverless, Step Function, Subnets, Transit Gateway,  VPC(Virtual Private Cloud), Virtual private gateway](Terms)

| Mega/Million 10<sup>6</sup> | Giga/Billion 10<sup>9</sup> | Tera/Trillion 10<sup>12</sup> | Peta/Quadrillion 10<sup>15</sup> | Exa/Quintillion 10<sup>18</sup> | Zeta/Sextillion 10<sup>21</sup> |
| --- | --- | --- | --- | --- | --- |

### AWS
- **AWS Infra:** AWS runs in: 69 Availabilty zones, 22 Geographic Regions, 190+ countries have 1 million+ customers
- **[6 Benefits of using AWS Cloud](/System-Design/Concepts#adv)**

<a name=sc></a>
### Service Categories
**Learning Aid**
```
  c swwifft goats   <-Services
  h dawvctr tpcad   <-Work
```  

|Config|Sheild|Watch|WAF|Inspector|Fargate|Formation|Trusted-Advisor|Guard Duty|
|---|---|---|---|---|---|---|---|---|
|History|DDos|Alarms|WebAPI protection against Web exploits|Vunerablity|Container runner|Template|Recommendation|Threat detection|

|Opswork|Artifact|Trail|SWF|
|---|---|---|---|
|Puppet,Chef|Compliance|Audit|Distribute tasks among distributed components|

|Area|What|Services|
|---|---|---|
|Analytics||[<ul><li>Athena</li> <li>CodePipeline</li> <li>ElasticSearch/OpenSearch</li> <li>Glue(ETL(Extract, transform, Load))</li></ul>](Analytics)|
|Application Integration||[SNS, SQS, SWF](Application_Integration)|
|Artificial Intelligence||[<ul><li>Rekognition = Image recognition</li></ul>](Artificial_Intelligence)|
|Business Applications|[<ul><li>AWS Connect</li></ul>](Business_Applications)|
|Compute|Provides compute capacity on cloud.|[<ul> <li>EC2=VM(security groups, AMI(Amazon Machine Image))</li> <li>ELB</li> <li>Elastic Beanstalk(Take(a.out + config files) & create EC2 instance)</li> <li>EMR(Elastic Map Reduce)</li> <li>Lambda</li> <li>LightSail(EC2+OS+Service(eg:wordpress))</li> <li>Outpost</li> </ul>](Compute)|
|Cost Management||[<ul> <li>Billing</li> <li>Budgets</li> <li>MarketPlace</li> <li>Cost Explorer(Forecast spending</li> </ul>](Cost_Management)|
|Customer Enablement||[<ul> <li>AWS Free TierPersonal</li> <li>Pricing</li> <li>TCO Calculator(aws vs onprem cost)</li> <li>Support</li> </ul>](Customer_Enablement)|
|Configuration Management|Provides tools for automation|[<ul> <li>Quickstart</li> </ul>](Configuration_Management)|
|Containers||[ECS,EKS,Fargate](Container)|
|Databases||[<ul><li>Relational:Aurora,RDS(no autoscaling)</li> <li>NoSQL:DynamoDB(auto scales),Accelrator</li> <li>GraphDB:Neptune</li> <li>ElasticCache(Cache before DB)</li> <li>Datawarehouse:RedShift, DMS</li></ul>](/System-Design/Concepts/Databases)|
|Design|Helps designing systems at scale|[AWS Well-Architected Framework](Design)|
|Developer Tools||[<ul><li>CodeStar</li> <li>CDK</li></ul>](Developer_Tools)|
|Internet of Things||[<ul> <li>Core</li> </ul>](Internet_of_Things)|
|Machine Learning||[<ul> <li>SageMaker</li> </ul>](Machine_Learning)|
|Management & Governance||[<ul> <li>CloudFormation(IaaS)=Template</li> <li>CloudWatch(Monitor performance of AWS services, generate alarms, metrices)</li> <li>Cloudtrail(Audit)</li> <li>Config=AWS Resources configuration change history</li> <li>Kinesis(Real Time Data)</li> <li>OpsWork(Use Puppet, Chef)</li> <li>Organizations(Has SCP(service control policy for APIs)</li> <li>Health Dashboard(Alerts & remediation guidance for AWS resources)</li> <li>QuickSight</li> <li>(System Manager(SSM)=See Operatinal data of AWS resources take action)</li> <li>Trusted Advisor(Recommendations in 5 categories: Cost optimization, Performance, Security, Fault tolerance, Service limits)</li> <li>X-ray</li></ul>](Management_Governance)|
|Media||[<ul><li>Elastic Transcoder=Convert media in Amazon S3 to audio,video</li></ul>](#Media)|
|Migration||[<ul><li>6Rs</li> <li>CAF</li> <li>Snow devices(Peta byte scale data transfer)</li> <li>Machine Learning</li> <li>AI</li> <li>Datasync</li></ul>](Migration_and_Transfer)|
|Networking & Content Delivery||[<ul> <li>API Gateway=Write HTTP APIs</li> <li>Cloudfront=CDN</li> <li>VPC</li> <li>Direct Connect</li> <li>Load Balancing</li> <li>Route 53(DNS, domain registration, traffic flow, health check, failover)</li><ul>](Network)|
|Security,Identity,Compliance||[<ul><li>Artifact=Compliance</li> <li>Certificate Manager</li> <li>Cloud HSM(Hardware based encryption key generator)</li> <li>Cognition</li> <li>Cognito</li> <li>Detective</li> <li>Directory Services</li> <li>(GuardDuty=Threat detection)</li> <li>IAM</li> <li>Inspector(security vunerabilites scanner)</li> <li>KMS</li>  <li>Sheild(DDoS protection)</li> <li>WAF</li></ul>](Security)|
|Storage||[<ul><li>Block Store:EBS(No Autoscaling)</li> <li>File Store:EFS</li> <li>Object Store:<ul><li>S3(Feature:Autoscale, macie, Storage class:Glacier)</li></ul></li></ul>](Storage)|

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
