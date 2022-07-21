**Isolation**
- Achieving Isolation
  - [1. Read Committed](#rc)
    - [a. No Dirty Reads](#dr)
    - [b. No Dirty Writes](#dw)

# Isolation
Concurrently executing [transactions](/System-Design/Concepts/Terms/Transaction) are isolated from each other ie they cannot step on each other.

# Achieving Isolation
<a name=rc></a>
## 1. Read Committed
It ensures No Dirty Reads, No Dirty writes

<a name=dr></a>
### A. No Dirty Read
- When reading from DB, we will only see data that has been committed ie not reading a broken transaction.
- _How to avoid Dirty Read?_ Reading to DB only when ongoing [transaction](/System-Design/Concepts/Terms/Transaction) has been committed or aborted.

<a name=dw></a>
### B. No Dirty Writes
- When writing to DB, we will only overwrite data that has been committed, ie not writing on broken transaction.
- _How to avoid Dirty Write?_ Writing to DB only when ongoing [transaction](/System-Design/Concepts/Terms/Transaction) has been committed or aborted.
