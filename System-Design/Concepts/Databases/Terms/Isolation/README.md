- **Terms**
  - [Phenomena](#p)
    - [Dirty Write](#dw)
    - [Dirty Read](#dr)
    - [Non repeatable read](#nrr)
    - [Phantom read](#pr)
    - [Read Skew](#rs)
    - [Write Skew](#ws)
    - [Lost Update](#lu)
- **Isolation**
  - [Isolation Levels](#isol)
    - [1. Read Committed](#rc)
    - [2. Read uncommitted](#ruc)
    - [3. Repetable Reads](#rr)
    - [4. Serializable](#ser)

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

<a name=dw></a>
### Dirty Write
- **Means** after [1 transaction](/System-Design/Concepts/Terms/Transaction) into DB, data is not consistent.
- **When happens?** When 2 concurrent transactions are allowed to modify the same row at the same time, ie 2nd transaction can overwrite 1st transaction's pending change.
- **How to avoid Dirty Write?** Writing to DB only when ongoing [transaction](/System-Design/Concepts/Terms/Transaction) has been committed or aborted.

Example: post is a table
<img src=images/dirty_write.JPG width=500/>

<a name=dr></a>
### Dirty Read
- A dirty read occurs, a transaction reads uncommitted changes of some other ongoing transaction.
#### How to avoid Dirty Read?
- _1._ Reading to DB only when ongoing [transaction](/System-Design/Concepts/Terms/Transaction) has been committed or aborted.
- **2. Snapshot Isolation/Keeping old value until new is committed:** For every object that is written:
  - Writer takes a write lock.
  - DB remembers both(old committed value and new ongoing transaction value)
  - While transaction is ongoing, any other transactions that tries to read the object are given the old value.
  - Only when new value is committed, a:ll new transactions switch over to reading the new value.
- **3. MVCC(Multiversion Concurrency Control)**
  - Instead of keeping 2 copies(as in [Snapshot isolation](#si), MVCC keeps multiple copies(seperate for each query)
<img src=images/dirty_read.JPG width=500/>

<a name=nrr></a>
### Non repeatable read
- When 1st transaction is updating a DB row(Still not committed whole transaction) and 2nd transaction comes in (reads same DB row) and makes business decision.
- **How to avoid?** Using shared lock
<img src=images/non_repeatable_read.JPG width=500/>

<a name=pr></a>
### Phantom read
- When 1st transaction is updating n DB rows(Still not committed whole transaction) and 2nd transaction comes in (reads some of DB rows) and makes business decision.
- **How to avoid?** Using range lock
<img src=images/phantom_read.JPG width=500/>

<a name=rs></a>
### Read Skew
- Suppose person has 2 bank accounts(DB Tables) in same bank(Database) and has 500 in each account.
- He plans to transfer 100 from Account-1(Table-1) to Account-2(table-2), if person reads account balance(when data is not committed), He will see Account-1(400), Account-2(500)
```c
            Account-1                     Account-2
balance      500                            500
              |----100--->
                    Data not committed
balance      400                            500
```

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

# Isolation
- Concurrently executing [transactions](/System-Design/Concepts/Terms/Transaction) are isolated from each other ie they cannot step on each other.
- **How to achieve Complete Isolation:**
  - Complete isolation(Correctness of data) commited by transaction can only be achieved using Locking, ie 1 transaction locks the db row, commits and then another transaction is allowed to do the change.
  - **Disadvantage of locking:** 0 Concurrency, less Scalability.
  - **Solution:** SQL-92 introduced 4 Isolation levels(ie isolation is provided at multiple levels in transaction). 
    - DB Client can choose the Isolation level based on desired concurrency and data correctness.

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
