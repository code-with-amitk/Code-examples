**RDS / Amazon Relational Database Service**
- [Amazon RDS vs Amazon DynamoDB](/System-Design/Concepts/Databases/NOSQL/AWS_DynamoDB/README.md#vs)
- [Features/Advantages](#f)
- [Creating RDS](#c)

## RDS 
- Runs automated tasks as: hardware provisioning, database setup, patching, and backups.
- Amazon RDS is available on 6 database engines:
  - Amazon Aurora
  - PostgreSQL
  - MySQL
  - MariaDB
  - Oracle Database
  - Microsoft SQL Server

<a name=f></a>
### Features/Advantages
- **1. Multi-AZ/Cross Region Replication:**
  - One RDS DB instance resides in 1 Region. With Amazon RDS, you can create read replicas across Regions.
  - Amazon RDS replicates any data from the primary DB instance to the read replica across Regions.
- **2. Automated backups, Software patching**
- **3. Simplifies DB administration tasks**
- **4. Being managed service, there is no need to manage OS**

<a name=c></a>
### Creating RDS
```c
AWS Console > Dashboard > Create Database > 
  Engine Options:       Postgres
  Templates:            Free Tier
  Credential Settings:  Master password:  postgres123
  DB Instance class:    t2.micro
  Storage:              20 MB
  Connectivity:         Default VPC
```
