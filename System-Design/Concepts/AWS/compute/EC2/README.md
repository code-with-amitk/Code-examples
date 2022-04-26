**EC2(Elastic Compute Cloud)**
- [Security Group](#sg)
- [EC2 Instance Types](#it)
- Pricing
  - [1. On-Demand](#p1)
  - [2. Reserved Instances (1 yr, 3 yr)](#p2)
  - [3. Spot Instances](#p3)
  - [4. Dedicated Hosts(Most Expensive)](#p4)
- [EC2 Auto scaling](#as)
  - [Auto Scaling group](#asg)
    - [1. Create Auto Scaling Group](#cas)
    - [2. Delete Auto Scaling Group](#das)
  - [Auto scaling Approaches](#app)
- [EC2 Storage](#s)
- [Launch/Access/Stop EC2 Instance](#l)
  - [1. Creating a EC2 Instance](#cre)
  - [2. Getting Access to this Instance using SSM](#ac)
  - [3. Stop EC2 instance](#se)
  - [4. Create/Launch Replica/AMI](#ca)
- Terms
  - [Tag](#tag)


## EC2(Elastic Compute Cloud)
- This is **VM** created in AWS cloud. EC2 can be spun/deleted when needed & pay only for the compute time.
- **without EC2(Old world):** if we need an new server, 1st decide how big server is required(how many cores etc), purcharse, installation around 2+ months

<a name=sg></a>
### EC2 Security Groups(Stateful)
- Whenever an EC2 instance is created a SG is also created for EC2. A SG is a virtual firewall that controls inbound and outbound traffic for EC2.
- By default, a SG denies all inbound traffic and allows all outbound traffic. You can add custom rules to configure which traffic to allow or deny.
- SG is **stateful** ie they remember previous decisions made for incoming packets. if a packet is allowed into EC2, its not checked when its going out.
- while [Network ACL in Amazon VPC](/System-Design/Concepts/AWS/Terms/README.md#vpc) does same job but are stateless.
- All outgoing traffic is allowed from SG.
- [Security Group vs ACL](/System-Design/Concepts/AWS/Terms/README.md#vpc)
```c
------------------- AWS -----------------------
  |---------  VPC ---------------
  |   |------ Subnet  -------
  |   | |-- Security Group--|
  |   | |   EC2             |
  |   | |-------------------|
  |   |-----------------------
  |------------------------------
```

<a name=it></a>
### EC2 instance types
- EC2 instance is VM
- EC2 instance types are optimized for different tasks. When selecting an instance type, consider the specific needs of your workloads and applications.

|Type|What|Areas where used|
|---|---|---|
|1. General Purpose Instance|provide a balance of compute, memory, and networking resources|application servers, gaming servers, backend servers for enterprise applications, small and medium databases|
|2. Compute optimized instances|Have High-performance processors|web, application, and gaming servers|
|3. Memory optimized instances|For processing large datasets in memory|databases|
|4. Accelerated computing instances|Use hardware accelerators, or coprocessors to perform operations faster|floating-point number calculations, graphics processing, and data pattern matching|
|5. Storage optimized instances|For workloads that require high, sequential read and write access to large datasets on local storage. Measured using input/output operations per second (IOPS).|Distributed file systems, data warehousing applications|

| Family | Speciality | Use case |
| --- | --- | --- |
| D2 | Dense storage | File server/data warehouse/hadoop |
| R4 | Memory optimization | Memory intensive AppDBs |
| M4 | General purpose | Application servers |
| C4 | Compute Optimized | CPU Intensive AppDBs |
| G2 | Graphics Intensive | |
| H2| High speed storage | |
| F1 | Field programmable Gate Array | |
| T2 | Lowest cost general purpose | |
| P2 | Graphics/General Purpose| |
| X1 | Memory optmized |

### EC2 Pricing
<a name=p1></a>
#### 1. On-Demand
Ideal for short term, Irregular work loads. To be paid for whenever time you use it. Eg: Create a instance for learning and tear it

<a name=p2></a>
#### 2. Reserved Instances (1 yr, 3 yr)
Reserve Instance for a 1-year or 3-year term. This ends when we terminate the instance

<a name=p3></a>
#### 3. Spot Instances
- For workloads which have flexible start,end times which can withstand interruptions.
- if you make a Spot request and Amazon EC2 capacity is unavailable, the request is not successful until capacity becomes available.
- Useful for: Batch Processing (Save upto 90%)

<a name=p4></a>
#### 4. Dedicated Hosts(Most Expensive)
EC2 server fully dedicated to your use

## EC2 Auto scaling
This means scaling automatically as load increases and reducing instances as load decreases.
<a name=asg></a>
### Auto Scaling group?
Min/Max number of EC2 instances that would spun up. Configuration:
- _a. Min Capacity = x._ These many intances will always be running. if x=2, then min 2 instances will always be there.
- _b. Desired Capacity = y._ In case of load switch to desired. if y=4, then 4 instances will run in case of load.
- _c. Max Capacity = z:_ Max instances which can spun is z. Even load is more than that, instances will not be spun.
<a name=cas></a>
#### 1. Create Auto Scaling Group
```c
Search > EC2 >
Left side bar(bottom) > Auto Scaling > Auto Scaling Groups > Create Autoscaling Groups
  Name(fresh-asg) > Create Launch Configuration > Instance(t2.micro) > Create
  
AWS Console > Instances
  - You will see 1-2 instance spunned up there
```
<a name=das></a>
#### 2. Delete Auto Scaling Group
```c
Search > EC2 >
Left side bar(bottom) > Auto Scaling > Auto Scaling Groups > Select > Delete.

On Delete ASG will take down created instances as well.
```

<a name=app></a>
#### Auto scaling Approaches
- **1. Dynamic scaling:** As load increases spun up more instances.
- **2. Predictive scaling:** Predict the need in advance and scale as per prediction.

<a name=s></a>
### EC2 Storage (called Instance storage)
- Since EC2 is a VM, it has a storage(Hard Disk) associated with it called Instance Storage.
- This is [Block level storage](/System-Design/Concepts/Databases#obf) and has lifespan same as EC2 instance. ie if EC2 instance goes away storage also goes away.
- [Permanent Solution = EBS](/System-Design/Concepts/AWS/Storage/EBS)

||Instance Storage|EBS|
|---|---|---|
|Permanent|No|Yes|

<a name=l></a>
### Launch/access/stop EC2
<a name=cre></a>
#### 1. Creating a EC2 Instance
```c
AWS Console > Launch Instance > 
  Operating System:                                   Amazon Linux 2(Free Tier)
  Instance Type (Instance means CPU,Memory,Storage):  t2.micro(Free Tier)
  Network Settings:                                   Default VPC, Auto assign public IP(to access from internet)
  IAM Instance Profile:                               Create new IAM Role > 
                                                                  Select EC2 Role (AmazonEC2RoleforSSM)  //SSM(Simple System Manager) > Next
                                                                  Role Name(MyEC2Role) > Create Role
                                                      DropDown (MyEC2Role)
  Launch Instance
  Key Pair (Proceed without keypair) //We will login via SSM
  Launch Instance

AWS Console > Instance (Check status) > Running
```
<a name=ac></a>
#### 2. Getting Access to this Instance using SSM
- SSM(Simple Session Manager) records the history of login into ec2 instances etc.
```c
AWS Console > ssm > Session Manager(on left side) > Start a Session > Select Session > Start Session
sh-4.2$ sudo su - ec2-user
[ec2-user@ip-172-31-92-130 ~]$ pwd
/home/ec2-user
[ec2-user@ip-172-31-92-130 ~]$
```
<a name=se></a>
#### 3. Stop EC2 instance
- With stopping/terminating the instance no money is charged.
```c
AWS Console > EC2 > Left side (Instances) > Stop instance.
```
<a name=am></a>
#### 4. Create/Launch Replica of EC2 / AMI(Amazon Machine Image)
Create AMI
```c
  From [step-3](#se) >
  select instance > Actions > Image and Templates > Create Image > Image name(fresh-000) > Leave others default > Create Image
  AWS Dashboard > Images(on left) > AMIs > Status (pending > Available)

  
```
Launch AMI:
```c
  Select AMI > Launch Instance from AMI > 
  Select all options as done in Step-1(Creating a EC2 Instance)
  Launch
```

### Terms
<a name=tag></a>
#### Tag
- A tag is a label(key,value(optional)) that you assigned to AWS resource. Ex:
```c
  EC2-instance1
    |____|tag=(amit,admin)
  
  EC2-instance2
    |____|tag=(ram,user)
```
