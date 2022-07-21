**Isolation**
- **Achieving Isolation**
  - [1. Read Committed](#rc)
    - **Methods to Achieve Read Committed**
      - [a. No Dirty Reads](#dr)
        - Method to achieve No dirty Read
          - [Snapshot Isolation](#si)
      - [b. No Dirty Writes](#dw)
- **Terms**
  - [Read Skew](#rs)


# Isolation
Concurrently executing [transactions](/System-Design/Concepts/Terms/Transaction) are isolated from each other ie they cannot step on each other.

# Achieving Isolation
<a name=rc></a>
## 1. Read Committed
It ensures No Dirty Reads, No Dirty writes

<a name=dr></a>
### A. No Dirty Read
- When reading from DB, we will only see data that has been committed ie not reading a broken transaction.
- **How to avoid Dirty Read?** Reading to DB only when ongoing [transaction](/System-Design/Concepts/Terms/Transaction) has been committed or aborted.

#### Method to achieve No Dirty Read
<a name=si></a>
**1. Snapshot Isolation/Keeping old value until new is committed:** For every object that is written:
- Writer takes a write lock.
- DB remembers both(old committed value and new ongoing transaction value)
- While transaction is ongoing, any other transactions that tries to read the object are given the old value.
- Only when new value is committed, all new transactions switch over to reading the new value.

<a name=dw></a>
### B. No Dirty Writes
- When writing to DB, we will only overwrite data that has been committed, ie not writing on broken transaction.
- **How to avoid Dirty Write?** Writing to DB only when ongoing [transaction](/System-Design/Concepts/Terms/Transaction) has been committed or aborted.

### Terms
<a name=rs></a>
#### Read Skew / Nonrepeatable Read (Dirty Read)
- Suppose person has 2 bank accounts in same bank and has 500 in each account
- He plans to transfer 100 from Account-1 to Account-2, if person reads account balance(when data is not committed), He will see Account-1(400), Account-2(500)
```c
            Account-1                     Account-2
balance      500                            500
              |----100--->
                    Data not committed
balance      400                            500
```
