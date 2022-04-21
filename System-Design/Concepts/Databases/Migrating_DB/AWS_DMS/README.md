**DMS / Database Migration Service**
- [Migration Types](#mt)
- [DMS Use cases](#uc)

## DMS
Source database can be fully operational during migration minimizing the downtime.

<a name=mt></a>
### Migration Types
**1. Homogenous:** src and target DB are of same types
```c
SQL
    src                             dst
  MySQL                 -> |DMS| -> RDS for MySQL
  Microsoft SQL Server  -> |DMS| -> RDS for SQL Server
  Oracle                -> |DMS| -> RDS for oracle
```
**2. Hetrogeonous:** src and target DB are of different types
- Schema structure, data type, database codes are different
```c
Step-1:
  src(SQL DB-1)
           -> |Schema_Conversion_Tool| -> converted Schema,DB Code
                                          (noSQL DB-1)
Step-2:
  src(noSQL DB-1) -> |DMS| -> target(nosql DB-2)
```

<a name=uc></a>
### DMS Use cases
**1. [Migrate src DB to target DB](#mt)**
**2. Development & Test DB Migration:** 
  - Develop and test features on DB (while its used in production) but without affecting production users.
  - Copy of production DB is migrated using DMS to Dev or test env.
```c
  Application<-->DB_Production  -----> DMS ---> DB_for_dev_test
```
**3. DB Consolidation:** We have several Databases and need to consolidate into 1 DB.
```c
  DB-1 ---\
           \
  DB-2 -----> DMS --> DB_Consolidated
           /
  DB-3 ---/
```
**4. Continious DB Replication:** Replicating data from 1 DB to multiple replicas continously. This can be for disaster recovery etc.
```c
                    /-- DB1
  Prod_DB --> DMS  ---- DB2
                    \-- DB3
```
**5. Migrate from AWS to on-prem**
