**CloudFormation**
- Terms
  - [Stack](#s)

### CloudFormation
- AWS service which helps creating collection of services using a Template.
- We can define AWS services in cloudformation template(similar to json,yaml) and build the infra. We can build:
  - Storage, DB, Analytics, Machine learning and more
```c
                    |------------------------|
  aws-rds.json  --> | cloudformation service | -> Creates complete infra
  aws-ec2   ------> |------------------------|
```
- This is IaaC(Infrastructure as Code) Tool.

### Terms
<a name=s></a>
#### Stack
- A stack is a collection of AWS resources that you can manage as a single unit.
- We can create/update/delete a collection of resources by creating/updating/deleting stacks.
```c
  Stack1 = resource1,resource2,..
```
