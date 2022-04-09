**RDS / Amazon Relational Database Service**
- [Amazon RDS vs Amazon DynamoDB](/System-Design/Concepts/Databases/NOSQL/AWS_DynamoDB/README.md#vs)
- [Features/Advantages](#f)

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
### Features
- **1. Support cross Region Replication:**
  - One RDS DB instance resides in 1 Region. With Amazon RDS, you can create read replicas across Regions.
  - Amazon RDS replicates any data from the primary DB instance to the read replica across Regions.
