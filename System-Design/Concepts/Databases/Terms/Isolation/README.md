- **Terms**
  - [Phenomena](#p)
    - [Dirty Write](https://code-with-amitk.github.io/System_Design/Concepts/Databases/)
    - [Dirty Read](https://code-with-amitk.github.io/System_Design/Concepts/Databases/)
    - [Non repeatable read](https://code-with-amitk.github.io/System_Design/Concepts/Databases/)
    - [Phantom read](#pr)
    - [Read Skew](https://code-with-amitk.github.io/System_Design/Concepts/Databases/)
    - [Write Skew](#ws)
    - [Lost Update](#lu)
- **Isolation**
  - [Isolation Levels](https://code-with-amitk.github.io/System_Design/Concepts/Databases/)
    - [1. Read uncommitted](#ruc)
    - [2. Snapshot Isolation](https://code-with-amitk.github.io/System_Design/Concepts/Databases/)
    - [3. Read Committed](https://code-with-amitk.github.io/System_Design/Concepts/Databases/)
    - [4. Repetable Reads](#rr)
    - [5. Serializable](#ser)
    - [Default Isolation Levels in Postgres, Oracle,](#dil)

# Terms
<a name=p></a>
## Phenomena
- if we relax serializability of transactions in DB(ie transactions Interleave), it  may generate data integrity anomalies which is called Phenomena.
- SQL-92 standard defines following phenomenas:
  - Dirty Read, Dirty write
  - Read Skew, Write Skew
  - Non-repeatable read
  - Phantom read
  - lost update

<a name=pr></a>
### Phantom read
- Associated with multiple Table(s) or rows from table.
- When 1st transaction is updating n DB rows(Still not committed whole transaction) and 2nd transaction comes in (reads some of DB rows) and makes business decision.
- **How to avoid?** Using range lock
<img src=images/phantom_read.JPG width=500/>


<a name=ws></a>
### Write Skew
- This phenomenon involves disjoint writes over 2 different tables which should be updated as a unit.
- **How to avoid?** 
  - _1._ 1st transaction can acquire shared lock on both tables, preventing 2nd transaction from updating any table.
  - _2._ OR if DB Engine can detect table-1 is modified by another transaction and should rollback the same
<img src=images/write_skew.JPG width=500/>

<a name=lu></a>
### Lost update
- This happens when a transaction reads a Table row while another transaction, modifies it prior to the first transaction to finish.
<img src=images/lost_update.JPG width=500/>

<a name=isol></a>
## 4 Isolation levels in Databases

| Isolation Level |[Dirty read](#dr)| [Non-repeatable read](#nrr)| [Phantom read](#pr)|
|---|---|---|---|
|1. Read Uncommitted |Yes |Yes |Yes|
|2. Read Committed| No| Yes| Yes|
|3. Repeatable Read| No| No| Yes|
|4. Serializable| No| No| No|

- Isolation levels provided by vendors:
```c
 Read Committed (Oracle, SQL Server, PostgreSQL)
 Repeatable Read (MySQL)
```
<a name=ruc></a>
#### 1. Read Uncommitted

|Phenomena | SQL Server| PostgreSQL| MySQL|
|---|---|---|---|
|Dirty Write| No| No| No|
|Dirty Read| Yes| No| Yes|
|Non-Repeatable Read| Yes| Yes| Yes|
|Phantom Read| Yes| Yes| Yes|
|Read Skew| Yes| Yes| Yes|
|Write Skew| Yes| Yes| Yes|
|Lost Update| Yes| Yes| Yes|

<a name=rc></a>
#### 2. Read Committed
- Dirty writes and dirty reads not allowed

|Phenomena| Oracle| SQL Server| SQL Server MVCC| PostgreSQL| MySQL|
|---|---|---|---|---|---|
|Dirty Write| No| No| No| No| No|
|Dirty Read No| No| No| No| No|
|Non-Repeatable Read| Yes| Yes| Yes| Yes| Yes|
|Phantom Read Yes| Yes| Yes| Yes| Yes|
|Read Skew Yes| Yes| Yes| Yes| Yes|
|Write Skew Yes| Yes| Yes| Yes| Yes|
|Lost Update Yes| Yes| Yes| Yes| Yes|

<a name=rr></a>
#### 3. Reapetable Read
- Not supported by
  - Oracle, 

|Phenomena| SQL Server| PostgreSQL| MySQL|
|---|---|---|---|
|Dirty Write| No| No| No|
|Dirty Read| No| No| No|
|Non-Repeatable Read| No| No| No|
|Phantom Read| Yes| No| No|
|Read Skew| No| No| No|
|Write Skew| No| Yes| Yes|
|Lost Update| No| No| Yes

<a name=dil></a>
### Default Isolation Levels in Postgres, Oracle
|DB|Default Isolation Level|
|---|---|
|Postgres, Oracle, | Read Committed(no dirty reads allowed) |
