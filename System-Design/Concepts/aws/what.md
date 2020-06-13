## What is Amazon Web Services?
  - **it offers both**
    - PaaS(Plaform as Service): Dashboard is provided to you, for uploading website, 
    - IaaS(Infrastructure as Service):  Providing virtual machines(including H/W, S/W, servers. storage) over internet. Cloud provider will give access to OS of server/Virtual Machine, you can install/remove/do anything on Server. Highest order of control.
  - **Advantages of AWS**
    - Focus on develpment/management of core applications not worry about deploying/load etc.
    - Orgnization becomes more productive since not need to worry about
      - procurement, capacity planning, software maintenance, patching, heavy lifting tasks.
      
## 4 Primary Areas of AWS
### 1. **Compute**
  - [EC2(Elastic Compute Cloud)](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/compute/ec2.md)
    - create/deploy your own virtual machine.
  - ***LightSail(VPS Service – Virtual Private service)***
      - Lightsail launches virtual private servers which are VMs.
  - ***ECS(Elastice container search)***
    - Runs, manages docker containers. This is something like managed Kubernetes service.
  - [Lambda](https://github.com/amitkumar50/Code-examples/blob/master/System-Design/Concepts/aws/compute/lambda.md)
    - Upload a function on AWS get it executed really fast.
  - ***Batch***
    - used for Batch processing. Batch dynamically provisions the optimal quantity and type of compute resources, based on the volume and specific resource requirements of the batch jobs submitted
      
### 2. **Storage**
 - **S3(Simple Storage Service**
    - Object / Bucket type of storage.
  - **EFS(Network attached storage)**
    - upload your files to an EFS and then mount that on to multiple virtual machines
  - **Glacier**
    - Storage used for data archival. Used to store data that you do not need to use right away.
    - It takes 3 – 5 hours to restore from Glacier. Costs - $0.01 per gigabyte, per month
  - **Snowball**
    - For transporting data from AWS to data center.
    - Snowball hardware device is provided to you. Upload your data on device. AWS will upload data from device to AWS
  - **Storage Gateway**
    - VM installed in your data center, this replicates the data back to S3.
    
### 3. Database
  - **RDS(Relational Database Service)**
    - This is a interface which gives access to several databases:
      a. Aurora
        - AWS proprietary relational Database
        - compatible with MySQL and PostgreSQL
      b. Others: MySQL, PostgreSQL, MariaDB, Oracle, and SQL Server, Redshift
  - **NoSQL DB**
    a. DynamoDB
  - **Graph DB**
    a. Neptune
  - **Cache**
    a. ElasticCache
      - offers fully managed Redis and Memcached
    
### 4. Network
  - CloudFront, VPC, Direct Connect, Load Balancing, Route 53
  
### 5. Security, Identity, Complaince
  - managing the AWS Security Framework. 
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
