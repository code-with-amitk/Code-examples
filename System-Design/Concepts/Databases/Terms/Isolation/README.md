**Isolation**
- [Isolation Levels](#isol)
  - [1. Read Committed](#rc)
  - [2. Read uncommitted](#ruc)
  - [3. Repetable Reads](#rr)
  - [4. Serializable](#ser)
- **Terms**
  - [Phenomena](#p)
    - [Dirty Reads](#dr)
    - [Dirty Writes](#dw)
    - [Read Skew](#rs)
- **Methods to Achieve Read Committed**
  - [a. No Dirty Reads](#dr)
    - **Method to achieve No dirty Read**
      - [Snapshot Isolation](#si)
  - [b. No Dirty Writes](#dw)

# Isolation
- Concurrently executing [transactions](/System-Design/Concepts/Terms/Transaction) are isolated from each other ie they cannot step on each other.

<a name=isol></a>
## Isolation levels in Databases
- _a._ Serializable.
- _b._ Repeatable reads.
- _c._ Read committed.
- _d._ Read uncommitted.

| Isolation Level |Dirty read| Non-repeatable read| Phantom read|
|---|---|---|---|
|1. Read Uncommitted |Yes |Yes |Yes|
|2. Read Committed| No| Yes| Yes|
|3. Repeatable Read| No| No| Yes|
|4. Serializable| No| No| No|

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
### Dirty Writes
- **Means** after a transaction, data is not consistent.
- **When happens?** When 2 concurrent transactions are allowed to modify the same row at the same time, ie 2nd transaction can overwrite 1st transaction's pending change.
- 
- When writing to DB, we will only overwrite data that has been committed, ie not writing on broken transaction.
- **How to avoid Dirty Write?** Writing to DB only when ongoing [transaction](/System-Design/Concepts/Terms/Transaction) has been committed or aborted.


<a name=dr></a>
### Dirty Read
- When reading from DB, we will only see data that has been committed ie not reading a broken transaction.
- **How to avoid Dirty Read?** Reading to DB only when ongoing [transaction](/System-Design/Concepts/Terms/Transaction) has been committed or aborted.

<a name=rs></a>
### Read Skew / Nonrepeatable Read (Dirty Read)
- Suppose person has 2 bank accounts in same bank and has 500 in each account
- He plans to transfer 100 from Account-1 to Account-2, if person reads account balance(when data is not committed), He will see Account-1(400), Account-2(500)
```c
            Account-1                     Account-2
balance      500                            500
              |----100--->
                    Data not committed
balance      400                            500
```


<a name=rc></a>
## 1. Read Committed
It ensures No Dirty Reads, No Dirty writes

<a name=dr></a>
### A. No Dirty Read

#### Method to achieve No Dirty Read
<a name=si></a>
**1. Snapshot Isolation/Keeping old value until new is committed:** For every object that is written:
- Writer takes a write lock.
- DB remembers both(old committed value and new ongoing transaction value)
- While transaction is ongoing, any other transactions that tries to read the object are given the old value.
- Only when new value is committed, all new transactions switch over to reading the new value.

**2. MVCC(Multiversion Concurrency Control)**
- Instead of keeping 2 copies(as in [Snapshot isolation](#si), MVCC keeps multiple copies(seperate for each query)

