- [Shared Responsibility Model](#sr)
- Types of Security
  - [Customer security responsibilities](#cr)
  - [AWS security responsibilities](#ar)

<a name=sr></a>
## Shared Responsility Model
- AWS is responsible for security of some parts of your environment and you (the customer) are responsible for other parts. 

### Types of Security
<a name=cr></a>
#### 1. Customer security responsibilities(commonly referred to as “security in the cloud”)
Customer is responsible for:
- _His content:_ Customer need to control how access rights are granted, managed, and revoked.
- _Patching his OS:_ AWS cannot patch OS without user's permissions.
- _Permissions to Access resources at S3 Objects, EC2 instances:_ AWS cannot secure a weak root user's password.


<a name=ar></a>
#### 2. AWS security responsibilities (commonly referred to as “security of the cloud”)
- Security of:
  - host operating system
  - the virtualization layer
  - Physical security of the data centers from which services operate. Security guards at gates.

```c
On Machine
  |----------------|
  | Applications   |
  |----------------|  Customer's Responsiblity
  | Operating Sys  |
--|----------------|--------------
  | Hypervisor     |
  |----------------|
  | Network        |
  |----------------|  AWS's security Responsiblity
  | Physical Layer |
  |----------------|
  
Others:
  AWS's security responsibilty: Compute, Storage, DB, Networking, Regions, AZ, Edge Locations
```
